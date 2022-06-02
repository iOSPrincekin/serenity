#pragma once
#include <LibGfx/ShareableBitmap.h>
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

namespace Messages::WindowManagerClient {

enum class MessageID : i32 {
    WindowRemoved = 1,
    WindowStateChanged = 2,
    WindowIconBitmapChanged = 3,
    WindowRectChanged = 4,
    AppletAreaSizeChanged = 5,
    SuperKeyPressed = 6,
    SuperSpaceKeyPressed = 7,
    SuperDigitKeyPressed = 8,
    WorkspaceChanged = 9,
    KeymapChanged = 10,
};

class WindowRemoved final : public IPC::Message {
public:

    WindowRemoved(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowRemoved(WindowRemoved const&) = default;
    WindowRemoved(WindowRemoved&&) = default;
    WindowRemoved& operator=(WindowRemoved const&) = default;
    WindowRemoved(i32 wm_id, i32 client_id, i32 window_id) : m_wm_id(move(wm_id)), m_client_id(move(client_id)), m_window_id(move(window_id)) {}
    virtual ~WindowRemoved() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::WindowRemoved; }
    static i32 static_message_id() { return (int)MessageID::WindowRemoved; }
    virtual const char* message_name() const override { return "WindowManagerClient::WindowRemoved"; }

    static OwnPtr<WindowRemoved> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<WindowRemoved>(move(wm_id), move(client_id), move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowRemoved;

        stream << m_wm_id;

        stream << m_client_id;

        stream << m_window_id;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

    i32 m_client_id {};

    i32 m_window_id {};

};

class WindowStateChanged final : public IPC::Message {
public:

    WindowStateChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowStateChanged(WindowStateChanged const&) = default;
    WindowStateChanged(WindowStateChanged&&) = default;
    WindowStateChanged& operator=(WindowStateChanged const&) = default;
    WindowStateChanged(i32 wm_id, i32 client_id, i32 window_id, i32 parent_client_id, i32 parent_window_id, u32 workspace_row, u32 workspace_column, bool is_active, bool is_minimized, bool is_modal, bool is_frameless, i32 window_type, String title, Gfx::IntRect rect, Optional<i32> progress) : m_wm_id(move(wm_id)), m_client_id(move(client_id)), m_window_id(move(window_id)), m_parent_client_id(move(parent_client_id)), m_parent_window_id(move(parent_window_id)), m_workspace_row(move(workspace_row)), m_workspace_column(move(workspace_column)), m_is_active(move(is_active)), m_is_minimized(move(is_minimized)), m_is_modal(move(is_modal)), m_is_frameless(move(is_frameless)), m_window_type(move(window_type)), m_title(move(title)), m_rect(move(rect)), m_progress(move(progress)) {}
    virtual ~WindowStateChanged() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::WindowStateChanged; }
    static i32 static_message_id() { return (int)MessageID::WindowStateChanged; }
    virtual const char* message_name() const override { return "WindowManagerClient::WindowStateChanged"; }

    static OwnPtr<WindowStateChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        i32 parent_client_id = {};
        if (decoder.decode(parent_client_id).is_error())
            return {};

        i32 parent_window_id = {};
        if (decoder.decode(parent_window_id).is_error())
            return {};

        u32 workspace_row = {};
        if (decoder.decode(workspace_row).is_error())
            return {};

        u32 workspace_column = {};
        if (decoder.decode(workspace_column).is_error())
            return {};

        bool is_active = false;
        if (decoder.decode(is_active).is_error())
            return {};

        bool is_minimized = false;
        if (decoder.decode(is_minimized).is_error())
            return {};

        bool is_modal = false;
        if (decoder.decode(is_modal).is_error())
            return {};

        bool is_frameless = false;
        if (decoder.decode(is_frameless).is_error())
            return {};

        i32 window_type = {};
        if (decoder.decode(window_type).is_error())
            return {};

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        if (!Utf8View(title).validate())
            return {};

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        Optional<i32> progress = {};
        if (decoder.decode(progress).is_error())
            return {};

        return make<WindowStateChanged>(move(wm_id), move(client_id), move(window_id), move(parent_client_id), move(parent_window_id), move(workspace_row), move(workspace_column), move(is_active), move(is_minimized), move(is_modal), move(is_frameless), move(window_type), move(title), move(rect), move(progress));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowStateChanged;

        stream << m_wm_id;

        stream << m_client_id;

        stream << m_window_id;

        stream << m_parent_client_id;

        stream << m_parent_window_id;

        stream << m_workspace_row;

        stream << m_workspace_column;

        stream << m_is_active;

        stream << m_is_minimized;

        stream << m_is_modal;

        stream << m_is_frameless;

        stream << m_window_type;

        stream << m_title;

        stream << m_rect;

        stream << m_progress;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const i32& parent_client_id() const { return m_parent_client_id; }
    i32 take_parent_client_id() { return move(m_parent_client_id); }

    const i32& parent_window_id() const { return m_parent_window_id; }
    i32 take_parent_window_id() { return move(m_parent_window_id); }

    const u32& workspace_row() const { return m_workspace_row; }
    u32 take_workspace_row() { return move(m_workspace_row); }

    const u32& workspace_column() const { return m_workspace_column; }
    u32 take_workspace_column() { return move(m_workspace_column); }

    const bool& is_active() const { return m_is_active; }
    bool take_is_active() { return move(m_is_active); }

    const bool& is_minimized() const { return m_is_minimized; }
    bool take_is_minimized() { return move(m_is_minimized); }

    const bool& is_modal() const { return m_is_modal; }
    bool take_is_modal() { return move(m_is_modal); }

    const bool& is_frameless() const { return m_is_frameless; }
    bool take_is_frameless() { return move(m_is_frameless); }

    const i32& window_type() const { return m_window_type; }
    i32 take_window_type() { return move(m_window_type); }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

    const Optional<i32>& progress() const { return m_progress; }
    Optional<i32> take_progress() { return move(m_progress); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

    i32 m_client_id {};

    i32 m_window_id {};

    i32 m_parent_client_id {};

    i32 m_parent_window_id {};

    u32 m_workspace_row {};

    u32 m_workspace_column {};

    bool m_is_active {};

    bool m_is_minimized {};

    bool m_is_modal {};

    bool m_is_frameless {};

    i32 m_window_type {};

    String m_title {};

    Gfx::IntRect m_rect {};

    Optional<i32> m_progress {};

};

class WindowIconBitmapChanged final : public IPC::Message {
public:

    WindowIconBitmapChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowIconBitmapChanged(WindowIconBitmapChanged const&) = default;
    WindowIconBitmapChanged(WindowIconBitmapChanged&&) = default;
    WindowIconBitmapChanged& operator=(WindowIconBitmapChanged const&) = default;
    WindowIconBitmapChanged(i32 wm_id, i32 client_id, i32 window_id, Gfx::ShareableBitmap bitmap) : m_wm_id(move(wm_id)), m_client_id(move(client_id)), m_window_id(move(window_id)), m_bitmap(move(bitmap)) {}
    virtual ~WindowIconBitmapChanged() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::WindowIconBitmapChanged; }
    static i32 static_message_id() { return (int)MessageID::WindowIconBitmapChanged; }
    virtual const char* message_name() const override { return "WindowManagerClient::WindowIconBitmapChanged"; }

    static OwnPtr<WindowIconBitmapChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::ShareableBitmap bitmap = {};
        if (decoder.decode(bitmap).is_error())
            return {};

        return make<WindowIconBitmapChanged>(move(wm_id), move(client_id), move(window_id), move(bitmap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowIconBitmapChanged;

        stream << m_wm_id;

        stream << m_client_id;

        stream << m_window_id;

        stream << m_bitmap;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::ShareableBitmap& bitmap() const { return m_bitmap; }
    Gfx::ShareableBitmap take_bitmap() { return move(m_bitmap); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

    i32 m_client_id {};

    i32 m_window_id {};

    Gfx::ShareableBitmap m_bitmap {};

};

class WindowRectChanged final : public IPC::Message {
public:

    WindowRectChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowRectChanged(WindowRectChanged const&) = default;
    WindowRectChanged(WindowRectChanged&&) = default;
    WindowRectChanged& operator=(WindowRectChanged const&) = default;
    WindowRectChanged(i32 wm_id, i32 client_id, i32 window_id, Gfx::IntRect rect) : m_wm_id(move(wm_id)), m_client_id(move(client_id)), m_window_id(move(window_id)), m_rect(move(rect)) {}
    virtual ~WindowRectChanged() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::WindowRectChanged; }
    static i32 static_message_id() { return (int)MessageID::WindowRectChanged; }
    virtual const char* message_name() const override { return "WindowManagerClient::WindowRectChanged"; }

    static OwnPtr<WindowRectChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<WindowRectChanged>(move(wm_id), move(client_id), move(window_id), move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowRectChanged;

        stream << m_wm_id;

        stream << m_client_id;

        stream << m_window_id;

        stream << m_rect;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

    i32 m_client_id {};

    i32 m_window_id {};

    Gfx::IntRect m_rect {};

};

class AppletAreaSizeChanged final : public IPC::Message {
public:

    AppletAreaSizeChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AppletAreaSizeChanged(AppletAreaSizeChanged const&) = default;
    AppletAreaSizeChanged(AppletAreaSizeChanged&&) = default;
    AppletAreaSizeChanged& operator=(AppletAreaSizeChanged const&) = default;
    AppletAreaSizeChanged(i32 wm_id, Gfx::IntSize size) : m_wm_id(move(wm_id)), m_size(move(size)) {}
    virtual ~AppletAreaSizeChanged() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::AppletAreaSizeChanged; }
    static i32 static_message_id() { return (int)MessageID::AppletAreaSizeChanged; }
    virtual const char* message_name() const override { return "WindowManagerClient::AppletAreaSizeChanged"; }

    static OwnPtr<AppletAreaSizeChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        Gfx::IntSize size = {};
        if (decoder.decode(size).is_error())
            return {};

        return make<AppletAreaSizeChanged>(move(wm_id), move(size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AppletAreaSizeChanged;

        stream << m_wm_id;

        stream << m_size;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

    const Gfx::IntSize& size() const { return m_size; }
    Gfx::IntSize take_size() { return move(m_size); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

    Gfx::IntSize m_size {};

};

class SuperKeyPressed final : public IPC::Message {
public:

    SuperKeyPressed(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SuperKeyPressed(SuperKeyPressed const&) = default;
    SuperKeyPressed(SuperKeyPressed&&) = default;
    SuperKeyPressed& operator=(SuperKeyPressed const&) = default;
    SuperKeyPressed(i32 wm_id) : m_wm_id(move(wm_id)) {}
    virtual ~SuperKeyPressed() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::SuperKeyPressed; }
    static i32 static_message_id() { return (int)MessageID::SuperKeyPressed; }
    virtual const char* message_name() const override { return "WindowManagerClient::SuperKeyPressed"; }

    static OwnPtr<SuperKeyPressed> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        return make<SuperKeyPressed>(move(wm_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SuperKeyPressed;

        stream << m_wm_id;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

};

class SuperSpaceKeyPressed final : public IPC::Message {
public:

    SuperSpaceKeyPressed(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SuperSpaceKeyPressed(SuperSpaceKeyPressed const&) = default;
    SuperSpaceKeyPressed(SuperSpaceKeyPressed&&) = default;
    SuperSpaceKeyPressed& operator=(SuperSpaceKeyPressed const&) = default;
    SuperSpaceKeyPressed(i32 wm_id) : m_wm_id(move(wm_id)) {}
    virtual ~SuperSpaceKeyPressed() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::SuperSpaceKeyPressed; }
    static i32 static_message_id() { return (int)MessageID::SuperSpaceKeyPressed; }
    virtual const char* message_name() const override { return "WindowManagerClient::SuperSpaceKeyPressed"; }

    static OwnPtr<SuperSpaceKeyPressed> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        return make<SuperSpaceKeyPressed>(move(wm_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SuperSpaceKeyPressed;

        stream << m_wm_id;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

};

class SuperDigitKeyPressed final : public IPC::Message {
public:

    SuperDigitKeyPressed(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SuperDigitKeyPressed(SuperDigitKeyPressed const&) = default;
    SuperDigitKeyPressed(SuperDigitKeyPressed&&) = default;
    SuperDigitKeyPressed& operator=(SuperDigitKeyPressed const&) = default;
    SuperDigitKeyPressed(i32 wm_id, u8 digit) : m_wm_id(move(wm_id)), m_digit(move(digit)) {}
    virtual ~SuperDigitKeyPressed() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::SuperDigitKeyPressed; }
    static i32 static_message_id() { return (int)MessageID::SuperDigitKeyPressed; }
    virtual const char* message_name() const override { return "WindowManagerClient::SuperDigitKeyPressed"; }

    static OwnPtr<SuperDigitKeyPressed> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        u8 digit = {};
        if (decoder.decode(digit).is_error())
            return {};

        return make<SuperDigitKeyPressed>(move(wm_id), move(digit));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SuperDigitKeyPressed;

        stream << m_wm_id;

        stream << m_digit;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

    const u8& digit() const { return m_digit; }
    u8 take_digit() { return move(m_digit); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

    u8 m_digit {};

};

class WorkspaceChanged final : public IPC::Message {
public:

    WorkspaceChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WorkspaceChanged(WorkspaceChanged const&) = default;
    WorkspaceChanged(WorkspaceChanged&&) = default;
    WorkspaceChanged& operator=(WorkspaceChanged const&) = default;
    WorkspaceChanged(i32 wm_id, u32 row, u32 column) : m_wm_id(move(wm_id)), m_row(move(row)), m_column(move(column)) {}
    virtual ~WorkspaceChanged() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::WorkspaceChanged; }
    static i32 static_message_id() { return (int)MessageID::WorkspaceChanged; }
    virtual const char* message_name() const override { return "WindowManagerClient::WorkspaceChanged"; }

    static OwnPtr<WorkspaceChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        u32 row = {};
        if (decoder.decode(row).is_error())
            return {};

        u32 column = {};
        if (decoder.decode(column).is_error())
            return {};

        return make<WorkspaceChanged>(move(wm_id), move(row), move(column));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WorkspaceChanged;

        stream << m_wm_id;

        stream << m_row;

        stream << m_column;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

    const u32& row() const { return m_row; }
    u32 take_row() { return move(m_row); }

    const u32& column() const { return m_column; }
    u32 take_column() { return move(m_column); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

    u32 m_row {};

    u32 m_column {};

};

class KeymapChanged final : public IPC::Message {
public:

    KeymapChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    KeymapChanged(KeymapChanged const&) = default;
    KeymapChanged(KeymapChanged&&) = default;
    KeymapChanged& operator=(KeymapChanged const&) = default;
    KeymapChanged(i32 wm_id, String keymap) : m_wm_id(move(wm_id)), m_keymap(move(keymap)) {}
    virtual ~KeymapChanged() override {}

    virtual u32 endpoint_magic() const override { return 3317521970; }
    virtual i32 message_id() const override { return (int)MessageID::KeymapChanged; }
    static i32 static_message_id() { return (int)MessageID::KeymapChanged; }
    virtual const char* message_name() const override { return "WindowManagerClient::KeymapChanged"; }

    static OwnPtr<KeymapChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 wm_id = {};
        if (decoder.decode(wm_id).is_error())
            return {};

        String keymap = {};
        if (decoder.decode(keymap).is_error())
            return {};

        if (!Utf8View(keymap).validate())
            return {};

        return make<KeymapChanged>(move(wm_id), move(keymap));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::KeymapChanged;

        stream << m_wm_id;

        stream << m_keymap;

        return buffer;
    }

    const i32& wm_id() const { return m_wm_id; }
    i32 take_wm_id() { return move(m_wm_id); }

    const String& keymap() const { return m_keymap; }
    String take_keymap() { return move(m_keymap); }

private:
    bool m_ipc_message_valid { true };

    i32 m_wm_id {};

    String m_keymap {};

};

} // namespace Messages::WindowManagerClient

template<typename LocalEndpoint, typename PeerEndpoint>
class WindowManagerClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    WindowManagerClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_window_removed(
i32 wm_id, i32 client_id, i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::WindowRemoved { wm_id, client_id, window_id });

    }

    void async_window_state_changed(
i32 wm_id, i32 client_id, i32 window_id, i32 parent_client_id, i32 parent_window_id, u32 workspace_row, u32 workspace_column, bool is_active, bool is_minimized, bool is_modal, bool is_frameless, i32 window_type, String title, Gfx::IntRect rect, Optional<i32> progress) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::WindowStateChanged { wm_id, client_id, window_id, parent_client_id, parent_window_id, workspace_row, workspace_column, is_active, is_minimized, is_modal, is_frameless, window_type, move(title), move(rect), move(progress) });

    }

    void async_window_icon_bitmap_changed(
i32 wm_id, i32 client_id, i32 window_id, Gfx::ShareableBitmap bitmap) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::WindowIconBitmapChanged { wm_id, client_id, window_id, move(bitmap) });

    }

    void async_window_rect_changed(
i32 wm_id, i32 client_id, i32 window_id, Gfx::IntRect rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::WindowRectChanged { wm_id, client_id, window_id, move(rect) });

    }

    void async_applet_area_size_changed(
i32 wm_id, Gfx::IntSize size) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::AppletAreaSizeChanged { wm_id, move(size) });

    }

    void async_super_key_pressed(
i32 wm_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::SuperKeyPressed { wm_id });

    }

    void async_super_space_key_pressed(
i32 wm_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::SuperSpaceKeyPressed { wm_id });

    }

    void async_super_digit_key_pressed(
i32 wm_id, u8 digit) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::SuperDigitKeyPressed { wm_id, digit });

    }

    void async_workspace_changed(
i32 wm_id, u32 row, u32 column) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::WorkspaceChanged { wm_id, row, column });

    }

    void async_keymap_changed(
i32 wm_id, String keymap) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerClient::KeymapChanged { wm_id, move(keymap) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class WindowManagerClientProxy;
class WindowManagerClientStub;

class WindowManagerClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = WindowManagerClientProxy<LocalEndpoint, WindowManagerClientEndpoint>;
    using Stub = WindowManagerClientStub;

    static u32 static_magic() { return 3317521970; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3317521970) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::WindowManagerClient::MessageID::WindowRemoved:
            message = Messages::WindowManagerClient::WindowRemoved::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::WindowStateChanged:
            message = Messages::WindowManagerClient::WindowStateChanged::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::WindowIconBitmapChanged:
            message = Messages::WindowManagerClient::WindowIconBitmapChanged::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::WindowRectChanged:
            message = Messages::WindowManagerClient::WindowRectChanged::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::AppletAreaSizeChanged:
            message = Messages::WindowManagerClient::AppletAreaSizeChanged::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::SuperKeyPressed:
            message = Messages::WindowManagerClient::SuperKeyPressed::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::SuperSpaceKeyPressed:
            message = Messages::WindowManagerClient::SuperSpaceKeyPressed::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::SuperDigitKeyPressed:
            message = Messages::WindowManagerClient::SuperDigitKeyPressed::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::WorkspaceChanged:
            message = Messages::WindowManagerClient::WorkspaceChanged::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerClient::MessageID::KeymapChanged:
            message = Messages::WindowManagerClient::KeymapChanged::decode(stream, socket);
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

class WindowManagerClientStub : public IPC::Stub {
public:
    WindowManagerClientStub() { }
    virtual ~WindowManagerClientStub() override { }

    virtual u32 magic() const override { return 3317521970; }
    virtual String name() const override { return "WindowManagerClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::WindowManagerClient::MessageID::WindowRemoved: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::WindowRemoved&>(message);
            window_removed(request.wm_id(), request.client_id(), request.window_id());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::WindowStateChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::WindowStateChanged&>(message);
            window_state_changed(request.wm_id(), request.client_id(), request.window_id(), request.parent_client_id(), request.parent_window_id(), request.workspace_row(), request.workspace_column(), request.is_active(), request.is_minimized(), request.is_modal(), request.is_frameless(), request.window_type(), request.title(), request.rect(), request.progress());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::WindowIconBitmapChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::WindowIconBitmapChanged&>(message);
            window_icon_bitmap_changed(request.wm_id(), request.client_id(), request.window_id(), request.bitmap());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::WindowRectChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::WindowRectChanged&>(message);
            window_rect_changed(request.wm_id(), request.client_id(), request.window_id(), request.rect());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::AppletAreaSizeChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::AppletAreaSizeChanged&>(message);
            applet_area_size_changed(request.wm_id(), request.size());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::SuperKeyPressed: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::SuperKeyPressed&>(message);
            super_key_pressed(request.wm_id());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::SuperSpaceKeyPressed: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::SuperSpaceKeyPressed&>(message);
            super_space_key_pressed(request.wm_id());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::SuperDigitKeyPressed: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::SuperDigitKeyPressed&>(message);
            super_digit_key_pressed(request.wm_id(), request.digit());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::WorkspaceChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::WorkspaceChanged&>(message);
            workspace_changed(request.wm_id(), request.row(), request.column());
            return {};

        }

        case (int)Messages::WindowManagerClient::MessageID::KeymapChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerClient::KeymapChanged&>(message);
            keymap_changed(request.wm_id(), request.keymap());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void window_removed(
[[maybe_unused]] i32 wm_id, [[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id) = 0;

    virtual void window_state_changed(
[[maybe_unused]] i32 wm_id, [[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] i32 parent_client_id, [[maybe_unused]] i32 parent_window_id, [[maybe_unused]] u32 workspace_row, [[maybe_unused]] u32 workspace_column, [[maybe_unused]] bool is_active, [[maybe_unused]] bool is_minimized, [[maybe_unused]] bool is_modal, [[maybe_unused]] bool is_frameless, [[maybe_unused]] i32 window_type, [[maybe_unused]] String const& title, [[maybe_unused]] Gfx::IntRect const& rect, [[maybe_unused]] Optional<i32> const& progress) = 0;

    virtual void window_icon_bitmap_changed(
[[maybe_unused]] i32 wm_id, [[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::ShareableBitmap const& bitmap) = 0;

    virtual void window_rect_changed(
[[maybe_unused]] i32 wm_id, [[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntRect const& rect) = 0;

    virtual void applet_area_size_changed(
[[maybe_unused]] i32 wm_id, [[maybe_unused]] Gfx::IntSize const& size) = 0;

    virtual void super_key_pressed(
[[maybe_unused]] i32 wm_id) = 0;

    virtual void super_space_key_pressed(
[[maybe_unused]] i32 wm_id) = 0;

    virtual void super_digit_key_pressed(
[[maybe_unused]] i32 wm_id, [[maybe_unused]] u8 digit) = 0;

    virtual void workspace_changed(
[[maybe_unused]] i32 wm_id, [[maybe_unused]] u32 row, [[maybe_unused]] u32 column) = 0;

    virtual void keymap_changed(
[[maybe_unused]] i32 wm_id, [[maybe_unused]] String const& keymap) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

