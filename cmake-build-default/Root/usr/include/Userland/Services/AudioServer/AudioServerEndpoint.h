#pragma once
#include <LibCore/AnonymousBuffer.h>
#include <LibAudio/Queue.h>
#include <AK/MemoryStream.h>
#include <AK/OwnPtr.h>
#include <AK/Result.h>
#include <AK/Utf8View.h>
#include <LibIPC/Connection.h>
#include <LibIPC/Decoder.h>
#include <LibIPC/Dictionary.h>
#include <LibIPC/Encoder.h>
#include <LibIPC/File.h>
#include <LibIPC/Message.h>
#include <LibIPC/Stub.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdefaulted-function-deleted"
#endif

namespace Messages::AudioServer {

enum class MessageID : i32 {
    SetMainMixMuted = 1,
    SetMainMixMutedResponse = 2,
    IsMainMixMuted = 3,
    IsMainMixMutedResponse = 4,
    SetSelfMuted = 5,
    SetSelfMutedResponse = 6,
    IsSelfMuted = 7,
    IsSelfMutedResponse = 8,
    GetMainMixVolume = 9,
    GetMainMixVolumeResponse = 10,
    SetMainMixVolume = 11,
    SetMainMixVolumeResponse = 12,
    GetSelfVolume = 13,
    GetSelfVolumeResponse = 14,
    SetSelfVolume = 15,
    SetSelfVolumeResponse = 16,
    SetSampleRate = 17,
    SetSampleRateResponse = 18,
    GetSampleRate = 19,
    GetSampleRateResponse = 20,
    SetBuffer = 21,
    SetBufferResponse = 22,
    ClearBuffer = 23,
    StartPlayback = 24,
    PausePlayback = 25,
};

class SetMainMixMutedResponse final : public IPC::Message {
public:

    SetMainMixMutedResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetMainMixMutedResponse(SetMainMixMutedResponse const&) = default;
    SetMainMixMutedResponse(SetMainMixMutedResponse&&) = default;
    SetMainMixMutedResponse& operator=(SetMainMixMutedResponse const&) = default;
    SetMainMixMutedResponse() {}
    virtual ~SetMainMixMutedResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetMainMixMutedResponse; }
    static i32 static_message_id() { return (int)MessageID::SetMainMixMutedResponse; }
    virtual const char* message_name() const override { return "AudioServer::SetMainMixMutedResponse"; }

    static OwnPtr<SetMainMixMutedResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SetMainMixMutedResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetMainMixMutedResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetMainMixMuted final : public IPC::Message {
public:

   typedef class SetMainMixMutedResponse ResponseType;

    SetMainMixMuted(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetMainMixMuted(SetMainMixMuted const&) = default;
    SetMainMixMuted(SetMainMixMuted&&) = default;
    SetMainMixMuted& operator=(SetMainMixMuted const&) = default;
    SetMainMixMuted(bool muted) : m_muted(move(muted)) {}
    virtual ~SetMainMixMuted() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetMainMixMuted; }
    static i32 static_message_id() { return (int)MessageID::SetMainMixMuted; }
    virtual const char* message_name() const override { return "AudioServer::SetMainMixMuted"; }

    static OwnPtr<SetMainMixMuted> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool muted = false;
        if (decoder.decode(muted).is_error())
            return {};

        return make<SetMainMixMuted>(move(muted));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetMainMixMuted;

        stream << m_muted;

        return buffer;
    }

    const bool& muted() const { return m_muted; }
    bool take_muted() { return move(m_muted); }

private:
    bool m_ipc_message_valid { true };

    bool m_muted {};

};

class IsMainMixMutedResponse final : public IPC::Message {
public:

    IsMainMixMutedResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsMainMixMutedResponse(IsMainMixMutedResponse const&) = default;
    IsMainMixMutedResponse(IsMainMixMutedResponse&&) = default;
    IsMainMixMutedResponse& operator=(IsMainMixMutedResponse const&) = default;
    IsMainMixMutedResponse(bool muted) : m_muted(move(muted)) {}
    virtual ~IsMainMixMutedResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::IsMainMixMutedResponse; }
    static i32 static_message_id() { return (int)MessageID::IsMainMixMutedResponse; }
    virtual const char* message_name() const override { return "AudioServer::IsMainMixMutedResponse"; }

    static OwnPtr<IsMainMixMutedResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool muted = false;
        if (decoder.decode(muted).is_error())
            return {};

        return make<IsMainMixMutedResponse>(move(muted));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsMainMixMutedResponse;

        stream << m_muted;

        return buffer;
    }

    const bool& muted() const { return m_muted; }
    bool take_muted() { return move(m_muted); }

private:
    bool m_ipc_message_valid { true };

    bool m_muted {};

};

class IsMainMixMuted final : public IPC::Message {
public:

   typedef class IsMainMixMutedResponse ResponseType;

    IsMainMixMuted(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsMainMixMuted(IsMainMixMuted const&) = default;
    IsMainMixMuted(IsMainMixMuted&&) = default;
    IsMainMixMuted& operator=(IsMainMixMuted const&) = default;
    IsMainMixMuted() {}
    virtual ~IsMainMixMuted() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::IsMainMixMuted; }
    static i32 static_message_id() { return (int)MessageID::IsMainMixMuted; }
    virtual const char* message_name() const override { return "AudioServer::IsMainMixMuted"; }

    static OwnPtr<IsMainMixMuted> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<IsMainMixMuted>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsMainMixMuted;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetSelfMutedResponse final : public IPC::Message {
public:

    SetSelfMutedResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSelfMutedResponse(SetSelfMutedResponse const&) = default;
    SetSelfMutedResponse(SetSelfMutedResponse&&) = default;
    SetSelfMutedResponse& operator=(SetSelfMutedResponse const&) = default;
    SetSelfMutedResponse() {}
    virtual ~SetSelfMutedResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetSelfMutedResponse; }
    static i32 static_message_id() { return (int)MessageID::SetSelfMutedResponse; }
    virtual const char* message_name() const override { return "AudioServer::SetSelfMutedResponse"; }

    static OwnPtr<SetSelfMutedResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SetSelfMutedResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSelfMutedResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetSelfMuted final : public IPC::Message {
public:

   typedef class SetSelfMutedResponse ResponseType;

    SetSelfMuted(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSelfMuted(SetSelfMuted const&) = default;
    SetSelfMuted(SetSelfMuted&&) = default;
    SetSelfMuted& operator=(SetSelfMuted const&) = default;
    SetSelfMuted(bool muted) : m_muted(move(muted)) {}
    virtual ~SetSelfMuted() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetSelfMuted; }
    static i32 static_message_id() { return (int)MessageID::SetSelfMuted; }
    virtual const char* message_name() const override { return "AudioServer::SetSelfMuted"; }

    static OwnPtr<SetSelfMuted> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool muted = false;
        if (decoder.decode(muted).is_error())
            return {};

        return make<SetSelfMuted>(move(muted));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSelfMuted;

        stream << m_muted;

        return buffer;
    }

    const bool& muted() const { return m_muted; }
    bool take_muted() { return move(m_muted); }

private:
    bool m_ipc_message_valid { true };

    bool m_muted {};

};

class IsSelfMutedResponse final : public IPC::Message {
public:

    IsSelfMutedResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsSelfMutedResponse(IsSelfMutedResponse const&) = default;
    IsSelfMutedResponse(IsSelfMutedResponse&&) = default;
    IsSelfMutedResponse& operator=(IsSelfMutedResponse const&) = default;
    IsSelfMutedResponse(bool muted) : m_muted(move(muted)) {}
    virtual ~IsSelfMutedResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::IsSelfMutedResponse; }
    static i32 static_message_id() { return (int)MessageID::IsSelfMutedResponse; }
    virtual const char* message_name() const override { return "AudioServer::IsSelfMutedResponse"; }

    static OwnPtr<IsSelfMutedResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool muted = false;
        if (decoder.decode(muted).is_error())
            return {};

        return make<IsSelfMutedResponse>(move(muted));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsSelfMutedResponse;

        stream << m_muted;

        return buffer;
    }

    const bool& muted() const { return m_muted; }
    bool take_muted() { return move(m_muted); }

private:
    bool m_ipc_message_valid { true };

    bool m_muted {};

};

class IsSelfMuted final : public IPC::Message {
public:

   typedef class IsSelfMutedResponse ResponseType;

    IsSelfMuted(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsSelfMuted(IsSelfMuted const&) = default;
    IsSelfMuted(IsSelfMuted&&) = default;
    IsSelfMuted& operator=(IsSelfMuted const&) = default;
    IsSelfMuted() {}
    virtual ~IsSelfMuted() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::IsSelfMuted; }
    static i32 static_message_id() { return (int)MessageID::IsSelfMuted; }
    virtual const char* message_name() const override { return "AudioServer::IsSelfMuted"; }

    static OwnPtr<IsSelfMuted> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<IsSelfMuted>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsSelfMuted;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class GetMainMixVolumeResponse final : public IPC::Message {
public:

    GetMainMixVolumeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetMainMixVolumeResponse(GetMainMixVolumeResponse const&) = default;
    GetMainMixVolumeResponse(GetMainMixVolumeResponse&&) = default;
    GetMainMixVolumeResponse& operator=(GetMainMixVolumeResponse const&) = default;
    GetMainMixVolumeResponse(double volume) : m_volume(move(volume)) {}
    virtual ~GetMainMixVolumeResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::GetMainMixVolumeResponse; }
    static i32 static_message_id() { return (int)MessageID::GetMainMixVolumeResponse; }
    virtual const char* message_name() const override { return "AudioServer::GetMainMixVolumeResponse"; }

    static OwnPtr<GetMainMixVolumeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        double volume = {};
        if (decoder.decode(volume).is_error())
            return {};

        return make<GetMainMixVolumeResponse>(move(volume));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetMainMixVolumeResponse;

        stream << m_volume;

        return buffer;
    }

    const double& volume() const { return m_volume; }
    double take_volume() { return move(m_volume); }

private:
    bool m_ipc_message_valid { true };

    double m_volume {};

};

class GetMainMixVolume final : public IPC::Message {
public:

   typedef class GetMainMixVolumeResponse ResponseType;

    GetMainMixVolume(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetMainMixVolume(GetMainMixVolume const&) = default;
    GetMainMixVolume(GetMainMixVolume&&) = default;
    GetMainMixVolume& operator=(GetMainMixVolume const&) = default;
    GetMainMixVolume() {}
    virtual ~GetMainMixVolume() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::GetMainMixVolume; }
    static i32 static_message_id() { return (int)MessageID::GetMainMixVolume; }
    virtual const char* message_name() const override { return "AudioServer::GetMainMixVolume"; }

    static OwnPtr<GetMainMixVolume> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetMainMixVolume>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetMainMixVolume;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetMainMixVolumeResponse final : public IPC::Message {
public:

    SetMainMixVolumeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetMainMixVolumeResponse(SetMainMixVolumeResponse const&) = default;
    SetMainMixVolumeResponse(SetMainMixVolumeResponse&&) = default;
    SetMainMixVolumeResponse& operator=(SetMainMixVolumeResponse const&) = default;
    SetMainMixVolumeResponse() {}
    virtual ~SetMainMixVolumeResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetMainMixVolumeResponse; }
    static i32 static_message_id() { return (int)MessageID::SetMainMixVolumeResponse; }
    virtual const char* message_name() const override { return "AudioServer::SetMainMixVolumeResponse"; }

    static OwnPtr<SetMainMixVolumeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SetMainMixVolumeResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetMainMixVolumeResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetMainMixVolume final : public IPC::Message {
public:

   typedef class SetMainMixVolumeResponse ResponseType;

    SetMainMixVolume(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetMainMixVolume(SetMainMixVolume const&) = default;
    SetMainMixVolume(SetMainMixVolume&&) = default;
    SetMainMixVolume& operator=(SetMainMixVolume const&) = default;
    SetMainMixVolume(double volume) : m_volume(move(volume)) {}
    virtual ~SetMainMixVolume() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetMainMixVolume; }
    static i32 static_message_id() { return (int)MessageID::SetMainMixVolume; }
    virtual const char* message_name() const override { return "AudioServer::SetMainMixVolume"; }

    static OwnPtr<SetMainMixVolume> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        double volume = {};
        if (decoder.decode(volume).is_error())
            return {};

        return make<SetMainMixVolume>(move(volume));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetMainMixVolume;

        stream << m_volume;

        return buffer;
    }

    const double& volume() const { return m_volume; }
    double take_volume() { return move(m_volume); }

private:
    bool m_ipc_message_valid { true };

    double m_volume {};

};

class GetSelfVolumeResponse final : public IPC::Message {
public:

    GetSelfVolumeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSelfVolumeResponse(GetSelfVolumeResponse const&) = default;
    GetSelfVolumeResponse(GetSelfVolumeResponse&&) = default;
    GetSelfVolumeResponse& operator=(GetSelfVolumeResponse const&) = default;
    GetSelfVolumeResponse(double volume) : m_volume(move(volume)) {}
    virtual ~GetSelfVolumeResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::GetSelfVolumeResponse; }
    static i32 static_message_id() { return (int)MessageID::GetSelfVolumeResponse; }
    virtual const char* message_name() const override { return "AudioServer::GetSelfVolumeResponse"; }

    static OwnPtr<GetSelfVolumeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        double volume = {};
        if (decoder.decode(volume).is_error())
            return {};

        return make<GetSelfVolumeResponse>(move(volume));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSelfVolumeResponse;

        stream << m_volume;

        return buffer;
    }

    const double& volume() const { return m_volume; }
    double take_volume() { return move(m_volume); }

private:
    bool m_ipc_message_valid { true };

    double m_volume {};

};

class GetSelfVolume final : public IPC::Message {
public:

   typedef class GetSelfVolumeResponse ResponseType;

    GetSelfVolume(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSelfVolume(GetSelfVolume const&) = default;
    GetSelfVolume(GetSelfVolume&&) = default;
    GetSelfVolume& operator=(GetSelfVolume const&) = default;
    GetSelfVolume() {}
    virtual ~GetSelfVolume() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::GetSelfVolume; }
    static i32 static_message_id() { return (int)MessageID::GetSelfVolume; }
    virtual const char* message_name() const override { return "AudioServer::GetSelfVolume"; }

    static OwnPtr<GetSelfVolume> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetSelfVolume>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSelfVolume;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetSelfVolumeResponse final : public IPC::Message {
public:

    SetSelfVolumeResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSelfVolumeResponse(SetSelfVolumeResponse const&) = default;
    SetSelfVolumeResponse(SetSelfVolumeResponse&&) = default;
    SetSelfVolumeResponse& operator=(SetSelfVolumeResponse const&) = default;
    SetSelfVolumeResponse() {}
    virtual ~SetSelfVolumeResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetSelfVolumeResponse; }
    static i32 static_message_id() { return (int)MessageID::SetSelfVolumeResponse; }
    virtual const char* message_name() const override { return "AudioServer::SetSelfVolumeResponse"; }

    static OwnPtr<SetSelfVolumeResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SetSelfVolumeResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSelfVolumeResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetSelfVolume final : public IPC::Message {
public:

   typedef class SetSelfVolumeResponse ResponseType;

    SetSelfVolume(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSelfVolume(SetSelfVolume const&) = default;
    SetSelfVolume(SetSelfVolume&&) = default;
    SetSelfVolume& operator=(SetSelfVolume const&) = default;
    SetSelfVolume(double volume) : m_volume(move(volume)) {}
    virtual ~SetSelfVolume() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetSelfVolume; }
    static i32 static_message_id() { return (int)MessageID::SetSelfVolume; }
    virtual const char* message_name() const override { return "AudioServer::SetSelfVolume"; }

    static OwnPtr<SetSelfVolume> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        double volume = {};
        if (decoder.decode(volume).is_error())
            return {};

        return make<SetSelfVolume>(move(volume));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSelfVolume;

        stream << m_volume;

        return buffer;
    }

    const double& volume() const { return m_volume; }
    double take_volume() { return move(m_volume); }

private:
    bool m_ipc_message_valid { true };

    double m_volume {};

};

class SetSampleRateResponse final : public IPC::Message {
public:

    SetSampleRateResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSampleRateResponse(SetSampleRateResponse const&) = default;
    SetSampleRateResponse(SetSampleRateResponse&&) = default;
    SetSampleRateResponse& operator=(SetSampleRateResponse const&) = default;
    SetSampleRateResponse() {}
    virtual ~SetSampleRateResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetSampleRateResponse; }
    static i32 static_message_id() { return (int)MessageID::SetSampleRateResponse; }
    virtual const char* message_name() const override { return "AudioServer::SetSampleRateResponse"; }

    static OwnPtr<SetSampleRateResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SetSampleRateResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSampleRateResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetSampleRate final : public IPC::Message {
public:

   typedef class SetSampleRateResponse ResponseType;

    SetSampleRate(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetSampleRate(SetSampleRate const&) = default;
    SetSampleRate(SetSampleRate&&) = default;
    SetSampleRate& operator=(SetSampleRate const&) = default;
    SetSampleRate(u32 sample_rate) : m_sample_rate(move(sample_rate)) {}
    virtual ~SetSampleRate() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetSampleRate; }
    static i32 static_message_id() { return (int)MessageID::SetSampleRate; }
    virtual const char* message_name() const override { return "AudioServer::SetSampleRate"; }

    static OwnPtr<SetSampleRate> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 sample_rate = {};
        if (decoder.decode(sample_rate).is_error())
            return {};

        return make<SetSampleRate>(move(sample_rate));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetSampleRate;

        stream << m_sample_rate;

        return buffer;
    }

    const u32& sample_rate() const { return m_sample_rate; }
    u32 take_sample_rate() { return move(m_sample_rate); }

private:
    bool m_ipc_message_valid { true };

    u32 m_sample_rate {};

};

class GetSampleRateResponse final : public IPC::Message {
public:

    GetSampleRateResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSampleRateResponse(GetSampleRateResponse const&) = default;
    GetSampleRateResponse(GetSampleRateResponse&&) = default;
    GetSampleRateResponse& operator=(GetSampleRateResponse const&) = default;
    GetSampleRateResponse(u32 sample_rate) : m_sample_rate(move(sample_rate)) {}
    virtual ~GetSampleRateResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::GetSampleRateResponse; }
    static i32 static_message_id() { return (int)MessageID::GetSampleRateResponse; }
    virtual const char* message_name() const override { return "AudioServer::GetSampleRateResponse"; }

    static OwnPtr<GetSampleRateResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 sample_rate = {};
        if (decoder.decode(sample_rate).is_error())
            return {};

        return make<GetSampleRateResponse>(move(sample_rate));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSampleRateResponse;

        stream << m_sample_rate;

        return buffer;
    }

    const u32& sample_rate() const { return m_sample_rate; }
    u32 take_sample_rate() { return move(m_sample_rate); }

private:
    bool m_ipc_message_valid { true };

    u32 m_sample_rate {};

};

class GetSampleRate final : public IPC::Message {
public:

   typedef class GetSampleRateResponse ResponseType;

    GetSampleRate(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetSampleRate(GetSampleRate const&) = default;
    GetSampleRate(GetSampleRate&&) = default;
    GetSampleRate& operator=(GetSampleRate const&) = default;
    GetSampleRate() {}
    virtual ~GetSampleRate() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::GetSampleRate; }
    static i32 static_message_id() { return (int)MessageID::GetSampleRate; }
    virtual const char* message_name() const override { return "AudioServer::GetSampleRate"; }

    static OwnPtr<GetSampleRate> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetSampleRate>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetSampleRate;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetBufferResponse final : public IPC::Message {
public:

    SetBufferResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetBufferResponse(SetBufferResponse const&) = default;
    SetBufferResponse(SetBufferResponse&&) = default;
    SetBufferResponse& operator=(SetBufferResponse const&) = default;
    SetBufferResponse() {}
    virtual ~SetBufferResponse() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetBufferResponse; }
    static i32 static_message_id() { return (int)MessageID::SetBufferResponse; }
    virtual const char* message_name() const override { return "AudioServer::SetBufferResponse"; }

    static OwnPtr<SetBufferResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SetBufferResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetBufferResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetBuffer final : public IPC::Message {
public:

   typedef class SetBufferResponse ResponseType;

    SetBuffer(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetBuffer(SetBuffer const&) = default;
    SetBuffer(SetBuffer&&) = default;
    SetBuffer& operator=(SetBuffer const&) = default;
    SetBuffer(Audio::AudioQueue buffer) : m_buffer(move(buffer)) {}
    virtual ~SetBuffer() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::SetBuffer; }
    static i32 static_message_id() { return (int)MessageID::SetBuffer; }
    virtual const char* message_name() const override { return "AudioServer::SetBuffer"; }

    static OwnPtr<SetBuffer> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Audio::AudioQueue buffer = {};
        if (decoder.decode(buffer).is_error())
            return {};

        return make<SetBuffer>(move(buffer));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetBuffer;

        stream << m_buffer;

        return buffer;
    }

    const Audio::AudioQueue& buffer() const { return m_buffer; }
    Audio::AudioQueue take_buffer() { return move(m_buffer); }

private:
    bool m_ipc_message_valid { true };

    Audio::AudioQueue m_buffer {};

};

class ClearBuffer final : public IPC::Message {
public:

    ClearBuffer(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ClearBuffer(ClearBuffer const&) = default;
    ClearBuffer(ClearBuffer&&) = default;
    ClearBuffer& operator=(ClearBuffer const&) = default;
    ClearBuffer() {}
    virtual ~ClearBuffer() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::ClearBuffer; }
    static i32 static_message_id() { return (int)MessageID::ClearBuffer; }
    virtual const char* message_name() const override { return "AudioServer::ClearBuffer"; }

    static OwnPtr<ClearBuffer> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<ClearBuffer>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ClearBuffer;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class StartPlayback final : public IPC::Message {
public:

    StartPlayback(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StartPlayback(StartPlayback const&) = default;
    StartPlayback(StartPlayback&&) = default;
    StartPlayback& operator=(StartPlayback const&) = default;
    StartPlayback() {}
    virtual ~StartPlayback() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::StartPlayback; }
    static i32 static_message_id() { return (int)MessageID::StartPlayback; }
    virtual const char* message_name() const override { return "AudioServer::StartPlayback"; }

    static OwnPtr<StartPlayback> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<StartPlayback>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StartPlayback;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class PausePlayback final : public IPC::Message {
public:

    PausePlayback(decltype(nullptr)) : m_ipc_message_valid(false) { }
    PausePlayback(PausePlayback const&) = default;
    PausePlayback(PausePlayback&&) = default;
    PausePlayback& operator=(PausePlayback const&) = default;
    PausePlayback() {}
    virtual ~PausePlayback() override {}

    virtual u32 endpoint_magic() const override { return 3887509455; }
    virtual i32 message_id() const override { return (int)MessageID::PausePlayback; }
    static i32 static_message_id() { return (int)MessageID::PausePlayback; }
    virtual const char* message_name() const override { return "AudioServer::PausePlayback"; }

    static OwnPtr<PausePlayback> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<PausePlayback>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::PausePlayback;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

} // namespace Messages::AudioServer

template<typename LocalEndpoint, typename PeerEndpoint>
class AudioServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    AudioServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void set_main_mix_muted(
bool muted) {
        (void) m_connection.template send_sync<Messages::AudioServer::SetMainMixMuted>(muted);
    }

    void async_set_main_mix_muted(
bool muted) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::SetMainMixMuted { muted });

    }

    IPC::IPCErrorOr<void> try_set_main_mix_muted(
bool muted) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::SetMainMixMuted>(muted);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    bool is_main_mix_muted(
) {
        return m_connection.template send_sync<Messages::AudioServer::IsMainMixMuted>()->take_muted();
    }

    void async_is_main_mix_muted(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::IsMainMixMuted {  });

    }

    IPC::IPCErrorOr<bool> try_is_main_mix_muted(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::IsMainMixMuted>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void set_self_muted(
bool muted) {
        (void) m_connection.template send_sync<Messages::AudioServer::SetSelfMuted>(muted);
    }

    void async_set_self_muted(
bool muted) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::SetSelfMuted { muted });

    }

    IPC::IPCErrorOr<void> try_set_self_muted(
bool muted) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::SetSelfMuted>(muted);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    bool is_self_muted(
) {
        return m_connection.template send_sync<Messages::AudioServer::IsSelfMuted>()->take_muted();
    }

    void async_is_self_muted(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::IsSelfMuted {  });

    }

    IPC::IPCErrorOr<bool> try_is_self_muted(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::IsSelfMuted>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    double get_main_mix_volume(
) {
        return m_connection.template send_sync<Messages::AudioServer::GetMainMixVolume>()->take_volume();
    }

    void async_get_main_mix_volume(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::GetMainMixVolume {  });

    }

    IPC::IPCErrorOr<double> try_get_main_mix_volume(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::GetMainMixVolume>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void set_main_mix_volume(
double volume) {
        (void) m_connection.template send_sync<Messages::AudioServer::SetMainMixVolume>(volume);
    }

    void async_set_main_mix_volume(
double volume) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::SetMainMixVolume { volume });

    }

    IPC::IPCErrorOr<void> try_set_main_mix_volume(
double volume) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::SetMainMixVolume>(volume);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    double get_self_volume(
) {
        return m_connection.template send_sync<Messages::AudioServer::GetSelfVolume>()->take_volume();
    }

    void async_get_self_volume(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::GetSelfVolume {  });

    }

    IPC::IPCErrorOr<double> try_get_self_volume(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::GetSelfVolume>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void set_self_volume(
double volume) {
        (void) m_connection.template send_sync<Messages::AudioServer::SetSelfVolume>(volume);
    }

    void async_set_self_volume(
double volume) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::SetSelfVolume { volume });

    }

    IPC::IPCErrorOr<void> try_set_self_volume(
double volume) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::SetSelfVolume>(volume);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void set_sample_rate(
u32 sample_rate) {
        (void) m_connection.template send_sync<Messages::AudioServer::SetSampleRate>(sample_rate);
    }

    void async_set_sample_rate(
u32 sample_rate) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::SetSampleRate { sample_rate });

    }

    IPC::IPCErrorOr<void> try_set_sample_rate(
u32 sample_rate) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::SetSampleRate>(sample_rate);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    u32 get_sample_rate(
) {
        return m_connection.template send_sync<Messages::AudioServer::GetSampleRate>()->take_sample_rate();
    }

    void async_get_sample_rate(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::GetSampleRate {  });

    }

    IPC::IPCErrorOr<u32> try_get_sample_rate(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::GetSampleRate>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void set_buffer(
Audio::AudioQueue buffer) {
        (void) m_connection.template send_sync<Messages::AudioServer::SetBuffer>(move(buffer));
    }

    void async_set_buffer(
Audio::AudioQueue buffer) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::SetBuffer { move(buffer) });

    }

    IPC::IPCErrorOr<void> try_set_buffer(
Audio::AudioQueue buffer) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::AudioServer::SetBuffer>(move(buffer));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void async_clear_buffer(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::ClearBuffer {  });

    }

    void async_start_playback(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::StartPlayback {  });

    }

    void async_pause_playback(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::AudioServer::PausePlayback {  });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class AudioServerProxy;
class AudioServerStub;

class AudioServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = AudioServerProxy<LocalEndpoint, AudioServerEndpoint>;
    using Stub = AudioServerStub;

    static u32 static_magic() { return 3887509455; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3887509455) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::AudioServer::MessageID::SetMainMixMuted:
            message = Messages::AudioServer::SetMainMixMuted::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetMainMixMutedResponse:
            message = Messages::AudioServer::SetMainMixMutedResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::IsMainMixMuted:
            message = Messages::AudioServer::IsMainMixMuted::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::IsMainMixMutedResponse:
            message = Messages::AudioServer::IsMainMixMutedResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetSelfMuted:
            message = Messages::AudioServer::SetSelfMuted::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetSelfMutedResponse:
            message = Messages::AudioServer::SetSelfMutedResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::IsSelfMuted:
            message = Messages::AudioServer::IsSelfMuted::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::IsSelfMutedResponse:
            message = Messages::AudioServer::IsSelfMutedResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::GetMainMixVolume:
            message = Messages::AudioServer::GetMainMixVolume::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::GetMainMixVolumeResponse:
            message = Messages::AudioServer::GetMainMixVolumeResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetMainMixVolume:
            message = Messages::AudioServer::SetMainMixVolume::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetMainMixVolumeResponse:
            message = Messages::AudioServer::SetMainMixVolumeResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::GetSelfVolume:
            message = Messages::AudioServer::GetSelfVolume::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::GetSelfVolumeResponse:
            message = Messages::AudioServer::GetSelfVolumeResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetSelfVolume:
            message = Messages::AudioServer::SetSelfVolume::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetSelfVolumeResponse:
            message = Messages::AudioServer::SetSelfVolumeResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetSampleRate:
            message = Messages::AudioServer::SetSampleRate::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetSampleRateResponse:
            message = Messages::AudioServer::SetSampleRateResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::GetSampleRate:
            message = Messages::AudioServer::GetSampleRate::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::GetSampleRateResponse:
            message = Messages::AudioServer::GetSampleRateResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetBuffer:
            message = Messages::AudioServer::SetBuffer::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::SetBufferResponse:
            message = Messages::AudioServer::SetBufferResponse::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::ClearBuffer:
            message = Messages::AudioServer::ClearBuffer::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::StartPlayback:
            message = Messages::AudioServer::StartPlayback::decode(stream, socket);
            break;

        case (int)Messages::AudioServer::MessageID::PausePlayback:
            message = Messages::AudioServer::PausePlayback::decode(stream, socket);
            break;

        default:

            return {};
        }

        if (stream.handle_any_error()) {

            return {};
        }

        return message;
    }

};

class AudioServerStub : public IPC::Stub {
public:
    AudioServerStub() { }
    virtual ~AudioServerStub() override { }

    virtual u32 magic() const override { return 3887509455; }
    virtual String name() const override { return "AudioServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::AudioServer::MessageID::SetMainMixMuted: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::SetMainMixMuted&>(message);
            set_main_mix_muted(request.muted());
            auto response = Messages::AudioServer::SetMainMixMutedResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::IsMainMixMuted: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::IsMainMixMuted&>(message);
            auto response = is_main_mix_muted();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::SetSelfMuted: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::SetSelfMuted&>(message);
            set_self_muted(request.muted());
            auto response = Messages::AudioServer::SetSelfMutedResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::IsSelfMuted: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::IsSelfMuted&>(message);
            auto response = is_self_muted();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::GetMainMixVolume: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::GetMainMixVolume&>(message);
            auto response = get_main_mix_volume();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::SetMainMixVolume: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::SetMainMixVolume&>(message);
            set_main_mix_volume(request.volume());
            auto response = Messages::AudioServer::SetMainMixVolumeResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::GetSelfVolume: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::GetSelfVolume&>(message);
            auto response = get_self_volume();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::SetSelfVolume: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::SetSelfVolume&>(message);
            set_self_volume(request.volume());
            auto response = Messages::AudioServer::SetSelfVolumeResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::SetSampleRate: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::SetSampleRate&>(message);
            set_sample_rate(request.sample_rate());
            auto response = Messages::AudioServer::SetSampleRateResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::GetSampleRate: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::GetSampleRate&>(message);
            auto response = get_sample_rate();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::SetBuffer: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::SetBuffer&>(message);
            set_buffer(request.buffer());
            auto response = Messages::AudioServer::SetBufferResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::AudioServer::MessageID::ClearBuffer: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::ClearBuffer&>(message);
            clear_buffer();
            return {};

        }

        case (int)Messages::AudioServer::MessageID::StartPlayback: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::StartPlayback&>(message);
            start_playback();
            return {};

        }

        case (int)Messages::AudioServer::MessageID::PausePlayback: {

            [[maybe_unused]] auto& request = static_cast<const Messages::AudioServer::PausePlayback&>(message);
            pause_playback();
            return {};

        }

        default:
            return {};
        }
    }

    virtual void set_main_mix_muted(
[[maybe_unused]] bool muted) = 0;

    virtual Messages::AudioServer::IsMainMixMutedResponse is_main_mix_muted(
) = 0;

    virtual void set_self_muted(
[[maybe_unused]] bool muted) = 0;

    virtual Messages::AudioServer::IsSelfMutedResponse is_self_muted(
) = 0;

    virtual Messages::AudioServer::GetMainMixVolumeResponse get_main_mix_volume(
) = 0;

    virtual void set_main_mix_volume(
[[maybe_unused]] double volume) = 0;

    virtual Messages::AudioServer::GetSelfVolumeResponse get_self_volume(
) = 0;

    virtual void set_self_volume(
[[maybe_unused]] double volume) = 0;

    virtual void set_sample_rate(
[[maybe_unused]] u32 sample_rate) = 0;

    virtual Messages::AudioServer::GetSampleRateResponse get_sample_rate(
) = 0;

    virtual void set_buffer(
[[maybe_unused]] Audio::AudioQueue const& buffer) = 0;

    virtual void clear_buffer(
) = 0;

    virtual void start_playback(
) = 0;

    virtual void pause_playback(
) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

