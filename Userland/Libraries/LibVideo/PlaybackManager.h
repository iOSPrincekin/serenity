/*
 * Copyright (c) 2022, Gregory Bertilson <zaggy1024@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Atomic.h>
#include <AK/Function.h>
#include <AK/NonnullOwnPtr.h>
#include <AK/Queue.h>
#include <AK/Time.h>
#include <LibCore/EventLoop.h>
#include <LibCore/SharedCircularQueue.h>
#include <LibGfx/Bitmap.h>
#include <LibThreading/ConditionVariable.h>
#include <LibThreading/Mutex.h>
#include <LibThreading/Thread.h>

#include "Demuxer.h"
#include "MatroskaDocument.h"
#include "VideoDecoder.h"

namespace Video {

enum class PlaybackStatus {
    Playing,
    Paused,
    Buffering,
    Seeking,
    Stopped,
    Corrupted,
};

struct FrameQueueItem {
    enum class Type {
        Frame,
        Error,
    };

    static FrameQueueItem frame(RefPtr<Gfx::Bitmap> bitmap, Time timestamp)
    {
        return FrameQueueItem(move(bitmap), timestamp);
    }

    static FrameQueueItem error_marker(DecoderError&& error)
    {
        return FrameQueueItem(move(error));
    }

    bool is_frame() const { return m_data.has<FrameData>(); }
    RefPtr<Gfx::Bitmap> bitmap() const { return m_data.get<FrameData>().bitmap; }
    Time timestamp() const { return m_data.get<FrameData>().timestamp; }

    bool is_error() const { return m_data.has<DecoderError>(); }
    DecoderError const& error() const { return m_data.get<DecoderError>(); }
    DecoderError release_error()
    {
        auto error = move(m_data.get<DecoderError>());
        m_data.set(Empty());
        return error;
    }

    String debug_string() const
    {
        if (is_error())
            return error().string_literal();
        return String::formatted("frame at {}ms", timestamp().to_milliseconds());
    }

private:
    struct FrameData {
        RefPtr<Gfx::Bitmap> bitmap;
        Time timestamp;
    };

    FrameQueueItem(RefPtr<Gfx::Bitmap> bitmap, Time timestamp)
        : m_data(FrameData { move(bitmap), timestamp })
    {
    }

    FrameQueueItem(DecoderError&& error)
        : m_data(move(error))
    {
    }

    Variant<Empty, FrameData, DecoderError> m_data;
};

static constexpr size_t FRAME_BUFFER_COUNT = 4;
using VideoFrameQueue = Queue<FrameQueueItem, FRAME_BUFFER_COUNT>;

class PlaybackManager : public Core::Object {
    C_OBJECT(PlaybackManager)

public:
    static DecoderErrorOr<NonnullRefPtr<PlaybackManager>> from_file(Object* event_handler, StringView file);
    static DecoderErrorOr<NonnullRefPtr<PlaybackManager>> from_data(Object* event_handler, Span<u8> data);

    PlaybackManager(Object* event_handler, NonnullOwnPtr<Demuxer>& demuxer, Track video_track, NonnullOwnPtr<VideoDecoder>& decoder);
    ~PlaybackManager() override = default;

    void resume_playback();
    void pause_playback();
    void restart_playback();
    bool is_playing() const { return m_status == PlaybackStatus::Playing; }
    bool is_buffering() const { return m_status == PlaybackStatus::Buffering; }
    bool is_stopped() const { return m_status == PlaybackStatus::Stopped; }

    u64 number_of_skipped_frames() const { return m_skipped_frames; }

    void event(Core::Event& event) override;
    void on_decoder_error(DecoderError error);

    Time current_playback_time();
    Time duration();

    Function<void(NonnullRefPtr<Gfx::Bitmap>, Time)> on_frame_present;

private:
    void set_playback_status(PlaybackStatus status);

    bool prepare_next_frame();
    void update_presented_frame();

    // Runs off the main thread
    bool decode_and_queue_one_sample();
    void on_decode_timer();

    Core::EventLoop& m_main_loop;

    PlaybackStatus m_status { PlaybackStatus::Stopped };
    Time m_last_present_in_media_time = Time::zero();
    Time m_last_present_in_real_time = Time::zero();

    NonnullOwnPtr<Demuxer> m_demuxer;
    Track m_selected_video_track;
    NonnullOwnPtr<VideoDecoder> m_decoder;

    NonnullOwnPtr<VideoFrameQueue> m_frame_queue;
    Optional<FrameQueueItem> m_next_frame;

    NonnullRefPtr<Core::Timer> m_present_timer;
    unsigned m_decoding_buffer_time_ms = 16;

    NonnullRefPtr<Core::Timer> m_decode_timer;

    u64 m_skipped_frames;
};

enum EventType : unsigned {
    DecoderErrorOccurred = (('v' << 2) | ('i' << 1) | 'd') << 4,
    VideoFramePresent,
    PlaybackStatusChange,
};

class DecoderErrorEvent : public Core::Event {
public:
    explicit DecoderErrorEvent(DecoderError error)
        : Core::Event(DecoderErrorOccurred)
        , m_error(move(error))
    {
    }
    virtual ~DecoderErrorEvent() = default;

    DecoderError const& error() { return m_error; }

private:
    DecoderError m_error;
};

class VideoFramePresentEvent : public Core::Event {
public:
    VideoFramePresentEvent() = default;
    explicit VideoFramePresentEvent(RefPtr<Gfx::Bitmap> frame)
        : Core::Event(VideoFramePresent)
        , m_frame(move(frame))
    {
    }
    virtual ~VideoFramePresentEvent() = default;

    RefPtr<Gfx::Bitmap> frame() { return m_frame; }

private:
    RefPtr<Gfx::Bitmap> m_frame;
};

class PlaybackStatusChangeEvent : public Core::Event {
public:
    PlaybackStatusChangeEvent() = default;
    explicit PlaybackStatusChangeEvent(PlaybackStatus status, PlaybackStatus previous_status)
        : Core::Event(PlaybackStatusChange)
        , m_status(status)
        , m_previous_status(previous_status)
    {
    }
    virtual ~PlaybackStatusChangeEvent() = default;

    PlaybackStatus status();
    PlaybackStatus previous_status();

private:
    PlaybackStatus m_status;
    PlaybackStatus m_previous_status;
};

inline StringView playback_status_to_string(PlaybackStatus status)
{
    switch (status) {
    case PlaybackStatus::Playing:
        return "Playing"sv;
    case PlaybackStatus::Paused:
        return "Paused"sv;
    case PlaybackStatus::Buffering:
        return "Buffering"sv;
    case PlaybackStatus::Seeking:
        return "Seeking"sv;
    case PlaybackStatus::Stopped:
        return "Stopped"sv;
    case PlaybackStatus::Corrupted:
        return "Corrupted"sv;
    }
    return "Unknown"sv;
};

}
