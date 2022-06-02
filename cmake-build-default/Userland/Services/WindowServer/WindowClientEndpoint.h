#pragma once
#include <LibCore/AnonymousBuffer.h>
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

namespace Messages::WindowClient {

enum class MessageID : i32 {
    FastGreet = 1,
    Paint = 2,
    MouseMove = 3,
    MouseDown = 4,
    MouseDoubleClick = 5,
    MouseUp = 6,
    MouseWheel = 7,
    WindowEntered = 8,
    WindowLeft = 9,
    WindowInputEntered = 10,
    WindowInputLeft = 11,
    KeyDown = 12,
    KeyUp = 13,
    WindowActivated = 14,
    WindowDeactivated = 15,
    WindowStateChanged = 16,
    WindowCloseRequest = 17,
    WindowResized = 18,
    MenuItemActivated = 19,
    MenuItemEntered = 20,
    MenuItemLeft = 21,
    MenuVisibilityDidChange = 22,
    ScreenRectsChanged = 23,
    AppletAreaRectChanged = 24,
    SetWallpaperFinished = 25,
    DragAccepted = 26,
    DragCancelled = 27,
    DragDropped = 28,
    UpdateSystemTheme = 29,
    UpdateSystemFonts = 30,
    DisplayLinkNotification = 31,
    TrackMouseMove = 32,
    Ping = 33,
};

class FastGreet final : public IPC::Message {
public:

    FastGreet(decltype(nullptr)) : m_ipc_message_valid(false) { }
    FastGreet(FastGreet const&) = default;
    FastGreet(FastGreet&&) = default;
    FastGreet& operator=(FastGreet const&) = default;
    FastGreet(Vector<Gfx::IntRect> screen_rects, u32 main_screen_index, u32 workspace_rows, u32 workspace_columns, Core::AnonymousBuffer theme_buffer, String default_font_query, String fixed_width_font_query, i32 client_id) : m_screen_rects(move(screen_rects)), m_main_screen_index(move(main_screen_index)), m_workspace_rows(move(workspace_rows)), m_workspace_columns(move(workspace_columns)), m_theme_buffer(move(theme_buffer)), m_default_font_query(move(default_font_query)), m_fixed_width_font_query(move(fixed_width_font_query)), m_client_id(move(client_id)) {}
    virtual ~FastGreet() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::FastGreet; }
    static i32 static_message_id() { return (int)MessageID::FastGreet; }
    virtual const char* message_name() const override { return "WindowClient::FastGreet"; }

    static OwnPtr<FastGreet> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<Gfx::IntRect> screen_rects = {};
        if (decoder.decode(screen_rects).is_error())
            return {};

        u32 main_screen_index = {};
        if (decoder.decode(main_screen_index).is_error())
            return {};

        u32 workspace_rows = {};
        if (decoder.decode(workspace_rows).is_error())
            return {};

        u32 workspace_columns = {};
        if (decoder.decode(workspace_columns).is_error())
            return {};

        Core::AnonymousBuffer theme_buffer = {};
        if (decoder.decode(theme_buffer).is_error())
            return {};

        String default_font_query = {};
        if (decoder.decode(default_font_query).is_error())
            return {};

        String fixed_width_font_query = {};
        if (decoder.decode(fixed_width_font_query).is_error())
            return {};

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        return make<FastGreet>(move(screen_rects), move(main_screen_index), move(workspace_rows), move(workspace_columns), move(theme_buffer), move(default_font_query), move(fixed_width_font_query), move(client_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::FastGreet;

        stream << m_screen_rects;

        stream << m_main_screen_index;

        stream << m_workspace_rows;

        stream << m_workspace_columns;

        stream << m_theme_buffer;

        stream << m_default_font_query;

        stream << m_fixed_width_font_query;

        stream << m_client_id;

        return buffer;
    }

    const Vector<Gfx::IntRect>& screen_rects() const { return m_screen_rects; }
    Vector<Gfx::IntRect> take_screen_rects() { return move(m_screen_rects); }

    const u32& main_screen_index() const { return m_main_screen_index; }
    u32 take_main_screen_index() { return move(m_main_screen_index); }

    const u32& workspace_rows() const { return m_workspace_rows; }
    u32 take_workspace_rows() { return move(m_workspace_rows); }

    const u32& workspace_columns() const { return m_workspace_columns; }
    u32 take_workspace_columns() { return move(m_workspace_columns); }

    const Core::AnonymousBuffer& theme_buffer() const { return m_theme_buffer; }
    Core::AnonymousBuffer take_theme_buffer() { return move(m_theme_buffer); }

    const String& default_font_query() const { return m_default_font_query; }
    String take_default_font_query() { return move(m_default_font_query); }

    const String& fixed_width_font_query() const { return m_fixed_width_font_query; }
    String take_fixed_width_font_query() { return move(m_fixed_width_font_query); }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

private:
    bool m_ipc_message_valid { true };

    Vector<Gfx::IntRect> m_screen_rects {};

    u32 m_main_screen_index {};

    u32 m_workspace_rows {};

    u32 m_workspace_columns {};

    Core::AnonymousBuffer m_theme_buffer {};

    String m_default_font_query {};

    String m_fixed_width_font_query {};

    i32 m_client_id {};

};

class Paint final : public IPC::Message {
public:

    Paint(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Paint(Paint const&) = default;
    Paint(Paint&&) = default;
    Paint& operator=(Paint const&) = default;
    Paint(i32 window_id, Gfx::IntSize window_size, Vector<Gfx::IntRect> rects) : m_window_id(move(window_id)), m_window_size(move(window_size)), m_rects(move(rects)) {}
    virtual ~Paint() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::Paint; }
    static i32 static_message_id() { return (int)MessageID::Paint; }
    virtual const char* message_name() const override { return "WindowClient::Paint"; }

    static OwnPtr<Paint> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntSize window_size = {};
        if (decoder.decode(window_size).is_error())
            return {};

        Vector<Gfx::IntRect> rects = {};
        if (decoder.decode(rects).is_error())
            return {};

        return make<Paint>(move(window_id), move(window_size), move(rects));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Paint;

        stream << m_window_id;

        stream << m_window_size;

        stream << m_rects;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntSize& window_size() const { return m_window_size; }
    Gfx::IntSize take_window_size() { return move(m_window_size); }

    const Vector<Gfx::IntRect>& rects() const { return m_rects; }
    Vector<Gfx::IntRect> take_rects() { return move(m_rects); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntSize m_window_size {};

    Vector<Gfx::IntRect> m_rects {};

};

class MouseMove final : public IPC::Message {
public:

    MouseMove(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseMove(MouseMove const&) = default;
    MouseMove(MouseMove&&) = default;
    MouseMove& operator=(MouseMove const&) = default;
    MouseMove(i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y, bool is_drag, Vector<String> mime_types) : m_window_id(move(window_id)), m_mouse_position(move(mouse_position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)), m_wheel_delta_x(move(wheel_delta_x)), m_wheel_delta_y(move(wheel_delta_y)), m_wheel_raw_delta_x(move(wheel_raw_delta_x)), m_wheel_raw_delta_y(move(wheel_raw_delta_y)), m_is_drag(move(is_drag)), m_mime_types(move(mime_types)) {}
    virtual ~MouseMove() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MouseMove; }
    static i32 static_message_id() { return (int)MessageID::MouseMove; }
    virtual const char* message_name() const override { return "WindowClient::MouseMove"; }

    static OwnPtr<MouseMove> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntPoint mouse_position = {};
        if (decoder.decode(mouse_position).is_error())
            return {};

        u32 button = {};
        if (decoder.decode(button).is_error())
            return {};

        u32 buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        u32 modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        i32 wheel_delta_x = {};
        if (decoder.decode(wheel_delta_x).is_error())
            return {};

        i32 wheel_delta_y = {};
        if (decoder.decode(wheel_delta_y).is_error())
            return {};

        i32 wheel_raw_delta_x = {};
        if (decoder.decode(wheel_raw_delta_x).is_error())
            return {};

        i32 wheel_raw_delta_y = {};
        if (decoder.decode(wheel_raw_delta_y).is_error())
            return {};

        bool is_drag = false;
        if (decoder.decode(is_drag).is_error())
            return {};

        Vector<String> mime_types = {};
        if (decoder.decode(mime_types).is_error())
            return {};

        return make<MouseMove>(move(window_id), move(mouse_position), move(button), move(buttons), move(modifiers), move(wheel_delta_x), move(wheel_delta_y), move(wheel_raw_delta_x), move(wheel_raw_delta_y), move(is_drag), move(mime_types));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseMove;

        stream << m_window_id;

        stream << m_mouse_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        stream << m_wheel_delta_x;

        stream << m_wheel_delta_y;

        stream << m_wheel_raw_delta_x;

        stream << m_wheel_raw_delta_y;

        stream << m_is_drag;

        stream << m_mime_types;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntPoint& mouse_position() const { return m_mouse_position; }
    Gfx::IntPoint take_mouse_position() { return move(m_mouse_position); }

    const u32& button() const { return m_button; }
    u32 take_button() { return move(m_button); }

    const u32& buttons() const { return m_buttons; }
    u32 take_buttons() { return move(m_buttons); }

    const u32& modifiers() const { return m_modifiers; }
    u32 take_modifiers() { return move(m_modifiers); }

    const i32& wheel_delta_x() const { return m_wheel_delta_x; }
    i32 take_wheel_delta_x() { return move(m_wheel_delta_x); }

    const i32& wheel_delta_y() const { return m_wheel_delta_y; }
    i32 take_wheel_delta_y() { return move(m_wheel_delta_y); }

    const i32& wheel_raw_delta_x() const { return m_wheel_raw_delta_x; }
    i32 take_wheel_raw_delta_x() { return move(m_wheel_raw_delta_x); }

    const i32& wheel_raw_delta_y() const { return m_wheel_raw_delta_y; }
    i32 take_wheel_raw_delta_y() { return move(m_wheel_raw_delta_y); }

    const bool& is_drag() const { return m_is_drag; }
    bool take_is_drag() { return move(m_is_drag); }

    const Vector<String>& mime_types() const { return m_mime_types; }
    Vector<String> take_mime_types() { return move(m_mime_types); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntPoint m_mouse_position {};

    u32 m_button {};

    u32 m_buttons {};

    u32 m_modifiers {};

    i32 m_wheel_delta_x {};

    i32 m_wheel_delta_y {};

    i32 m_wheel_raw_delta_x {};

    i32 m_wheel_raw_delta_y {};

    bool m_is_drag {};

    Vector<String> m_mime_types {};

};

class MouseDown final : public IPC::Message {
public:

    MouseDown(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseDown(MouseDown const&) = default;
    MouseDown(MouseDown&&) = default;
    MouseDown& operator=(MouseDown const&) = default;
    MouseDown(i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y) : m_window_id(move(window_id)), m_mouse_position(move(mouse_position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)), m_wheel_delta_x(move(wheel_delta_x)), m_wheel_delta_y(move(wheel_delta_y)), m_wheel_raw_delta_x(move(wheel_raw_delta_x)), m_wheel_raw_delta_y(move(wheel_raw_delta_y)) {}
    virtual ~MouseDown() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MouseDown; }
    static i32 static_message_id() { return (int)MessageID::MouseDown; }
    virtual const char* message_name() const override { return "WindowClient::MouseDown"; }

    static OwnPtr<MouseDown> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntPoint mouse_position = {};
        if (decoder.decode(mouse_position).is_error())
            return {};

        u32 button = {};
        if (decoder.decode(button).is_error())
            return {};

        u32 buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        u32 modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        i32 wheel_delta_x = {};
        if (decoder.decode(wheel_delta_x).is_error())
            return {};

        i32 wheel_delta_y = {};
        if (decoder.decode(wheel_delta_y).is_error())
            return {};

        i32 wheel_raw_delta_x = {};
        if (decoder.decode(wheel_raw_delta_x).is_error())
            return {};

        i32 wheel_raw_delta_y = {};
        if (decoder.decode(wheel_raw_delta_y).is_error())
            return {};

        return make<MouseDown>(move(window_id), move(mouse_position), move(button), move(buttons), move(modifiers), move(wheel_delta_x), move(wheel_delta_y), move(wheel_raw_delta_x), move(wheel_raw_delta_y));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseDown;

        stream << m_window_id;

        stream << m_mouse_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        stream << m_wheel_delta_x;

        stream << m_wheel_delta_y;

        stream << m_wheel_raw_delta_x;

        stream << m_wheel_raw_delta_y;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntPoint& mouse_position() const { return m_mouse_position; }
    Gfx::IntPoint take_mouse_position() { return move(m_mouse_position); }

    const u32& button() const { return m_button; }
    u32 take_button() { return move(m_button); }

    const u32& buttons() const { return m_buttons; }
    u32 take_buttons() { return move(m_buttons); }

    const u32& modifiers() const { return m_modifiers; }
    u32 take_modifiers() { return move(m_modifiers); }

    const i32& wheel_delta_x() const { return m_wheel_delta_x; }
    i32 take_wheel_delta_x() { return move(m_wheel_delta_x); }

    const i32& wheel_delta_y() const { return m_wheel_delta_y; }
    i32 take_wheel_delta_y() { return move(m_wheel_delta_y); }

    const i32& wheel_raw_delta_x() const { return m_wheel_raw_delta_x; }
    i32 take_wheel_raw_delta_x() { return move(m_wheel_raw_delta_x); }

    const i32& wheel_raw_delta_y() const { return m_wheel_raw_delta_y; }
    i32 take_wheel_raw_delta_y() { return move(m_wheel_raw_delta_y); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntPoint m_mouse_position {};

    u32 m_button {};

    u32 m_buttons {};

    u32 m_modifiers {};

    i32 m_wheel_delta_x {};

    i32 m_wheel_delta_y {};

    i32 m_wheel_raw_delta_x {};

    i32 m_wheel_raw_delta_y {};

};

class MouseDoubleClick final : public IPC::Message {
public:

    MouseDoubleClick(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseDoubleClick(MouseDoubleClick const&) = default;
    MouseDoubleClick(MouseDoubleClick&&) = default;
    MouseDoubleClick& operator=(MouseDoubleClick const&) = default;
    MouseDoubleClick(i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y) : m_window_id(move(window_id)), m_mouse_position(move(mouse_position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)), m_wheel_delta_x(move(wheel_delta_x)), m_wheel_delta_y(move(wheel_delta_y)), m_wheel_raw_delta_x(move(wheel_raw_delta_x)), m_wheel_raw_delta_y(move(wheel_raw_delta_y)) {}
    virtual ~MouseDoubleClick() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MouseDoubleClick; }
    static i32 static_message_id() { return (int)MessageID::MouseDoubleClick; }
    virtual const char* message_name() const override { return "WindowClient::MouseDoubleClick"; }

    static OwnPtr<MouseDoubleClick> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntPoint mouse_position = {};
        if (decoder.decode(mouse_position).is_error())
            return {};

        u32 button = {};
        if (decoder.decode(button).is_error())
            return {};

        u32 buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        u32 modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        i32 wheel_delta_x = {};
        if (decoder.decode(wheel_delta_x).is_error())
            return {};

        i32 wheel_delta_y = {};
        if (decoder.decode(wheel_delta_y).is_error())
            return {};

        i32 wheel_raw_delta_x = {};
        if (decoder.decode(wheel_raw_delta_x).is_error())
            return {};

        i32 wheel_raw_delta_y = {};
        if (decoder.decode(wheel_raw_delta_y).is_error())
            return {};

        return make<MouseDoubleClick>(move(window_id), move(mouse_position), move(button), move(buttons), move(modifiers), move(wheel_delta_x), move(wheel_delta_y), move(wheel_raw_delta_x), move(wheel_raw_delta_y));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseDoubleClick;

        stream << m_window_id;

        stream << m_mouse_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        stream << m_wheel_delta_x;

        stream << m_wheel_delta_y;

        stream << m_wheel_raw_delta_x;

        stream << m_wheel_raw_delta_y;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntPoint& mouse_position() const { return m_mouse_position; }
    Gfx::IntPoint take_mouse_position() { return move(m_mouse_position); }

    const u32& button() const { return m_button; }
    u32 take_button() { return move(m_button); }

    const u32& buttons() const { return m_buttons; }
    u32 take_buttons() { return move(m_buttons); }

    const u32& modifiers() const { return m_modifiers; }
    u32 take_modifiers() { return move(m_modifiers); }

    const i32& wheel_delta_x() const { return m_wheel_delta_x; }
    i32 take_wheel_delta_x() { return move(m_wheel_delta_x); }

    const i32& wheel_delta_y() const { return m_wheel_delta_y; }
    i32 take_wheel_delta_y() { return move(m_wheel_delta_y); }

    const i32& wheel_raw_delta_x() const { return m_wheel_raw_delta_x; }
    i32 take_wheel_raw_delta_x() { return move(m_wheel_raw_delta_x); }

    const i32& wheel_raw_delta_y() const { return m_wheel_raw_delta_y; }
    i32 take_wheel_raw_delta_y() { return move(m_wheel_raw_delta_y); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntPoint m_mouse_position {};

    u32 m_button {};

    u32 m_buttons {};

    u32 m_modifiers {};

    i32 m_wheel_delta_x {};

    i32 m_wheel_delta_y {};

    i32 m_wheel_raw_delta_x {};

    i32 m_wheel_raw_delta_y {};

};

class MouseUp final : public IPC::Message {
public:

    MouseUp(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseUp(MouseUp const&) = default;
    MouseUp(MouseUp&&) = default;
    MouseUp& operator=(MouseUp const&) = default;
    MouseUp(i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y) : m_window_id(move(window_id)), m_mouse_position(move(mouse_position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)), m_wheel_delta_x(move(wheel_delta_x)), m_wheel_delta_y(move(wheel_delta_y)), m_wheel_raw_delta_x(move(wheel_raw_delta_x)), m_wheel_raw_delta_y(move(wheel_raw_delta_y)) {}
    virtual ~MouseUp() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MouseUp; }
    static i32 static_message_id() { return (int)MessageID::MouseUp; }
    virtual const char* message_name() const override { return "WindowClient::MouseUp"; }

    static OwnPtr<MouseUp> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntPoint mouse_position = {};
        if (decoder.decode(mouse_position).is_error())
            return {};

        u32 button = {};
        if (decoder.decode(button).is_error())
            return {};

        u32 buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        u32 modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        i32 wheel_delta_x = {};
        if (decoder.decode(wheel_delta_x).is_error())
            return {};

        i32 wheel_delta_y = {};
        if (decoder.decode(wheel_delta_y).is_error())
            return {};

        i32 wheel_raw_delta_x = {};
        if (decoder.decode(wheel_raw_delta_x).is_error())
            return {};

        i32 wheel_raw_delta_y = {};
        if (decoder.decode(wheel_raw_delta_y).is_error())
            return {};

        return make<MouseUp>(move(window_id), move(mouse_position), move(button), move(buttons), move(modifiers), move(wheel_delta_x), move(wheel_delta_y), move(wheel_raw_delta_x), move(wheel_raw_delta_y));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseUp;

        stream << m_window_id;

        stream << m_mouse_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        stream << m_wheel_delta_x;

        stream << m_wheel_delta_y;

        stream << m_wheel_raw_delta_x;

        stream << m_wheel_raw_delta_y;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntPoint& mouse_position() const { return m_mouse_position; }
    Gfx::IntPoint take_mouse_position() { return move(m_mouse_position); }

    const u32& button() const { return m_button; }
    u32 take_button() { return move(m_button); }

    const u32& buttons() const { return m_buttons; }
    u32 take_buttons() { return move(m_buttons); }

    const u32& modifiers() const { return m_modifiers; }
    u32 take_modifiers() { return move(m_modifiers); }

    const i32& wheel_delta_x() const { return m_wheel_delta_x; }
    i32 take_wheel_delta_x() { return move(m_wheel_delta_x); }

    const i32& wheel_delta_y() const { return m_wheel_delta_y; }
    i32 take_wheel_delta_y() { return move(m_wheel_delta_y); }

    const i32& wheel_raw_delta_x() const { return m_wheel_raw_delta_x; }
    i32 take_wheel_raw_delta_x() { return move(m_wheel_raw_delta_x); }

    const i32& wheel_raw_delta_y() const { return m_wheel_raw_delta_y; }
    i32 take_wheel_raw_delta_y() { return move(m_wheel_raw_delta_y); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntPoint m_mouse_position {};

    u32 m_button {};

    u32 m_buttons {};

    u32 m_modifiers {};

    i32 m_wheel_delta_x {};

    i32 m_wheel_delta_y {};

    i32 m_wheel_raw_delta_x {};

    i32 m_wheel_raw_delta_y {};

};

class MouseWheel final : public IPC::Message {
public:

    MouseWheel(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MouseWheel(MouseWheel const&) = default;
    MouseWheel(MouseWheel&&) = default;
    MouseWheel& operator=(MouseWheel const&) = default;
    MouseWheel(i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y) : m_window_id(move(window_id)), m_mouse_position(move(mouse_position)), m_button(move(button)), m_buttons(move(buttons)), m_modifiers(move(modifiers)), m_wheel_delta_x(move(wheel_delta_x)), m_wheel_delta_y(move(wheel_delta_y)), m_wheel_raw_delta_x(move(wheel_raw_delta_x)), m_wheel_raw_delta_y(move(wheel_raw_delta_y)) {}
    virtual ~MouseWheel() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MouseWheel; }
    static i32 static_message_id() { return (int)MessageID::MouseWheel; }
    virtual const char* message_name() const override { return "WindowClient::MouseWheel"; }

    static OwnPtr<MouseWheel> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntPoint mouse_position = {};
        if (decoder.decode(mouse_position).is_error())
            return {};

        u32 button = {};
        if (decoder.decode(button).is_error())
            return {};

        u32 buttons = {};
        if (decoder.decode(buttons).is_error())
            return {};

        u32 modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        i32 wheel_delta_x = {};
        if (decoder.decode(wheel_delta_x).is_error())
            return {};

        i32 wheel_delta_y = {};
        if (decoder.decode(wheel_delta_y).is_error())
            return {};

        i32 wheel_raw_delta_x = {};
        if (decoder.decode(wheel_raw_delta_x).is_error())
            return {};

        i32 wheel_raw_delta_y = {};
        if (decoder.decode(wheel_raw_delta_y).is_error())
            return {};

        return make<MouseWheel>(move(window_id), move(mouse_position), move(button), move(buttons), move(modifiers), move(wheel_delta_x), move(wheel_delta_y), move(wheel_raw_delta_x), move(wheel_raw_delta_y));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MouseWheel;

        stream << m_window_id;

        stream << m_mouse_position;

        stream << m_button;

        stream << m_buttons;

        stream << m_modifiers;

        stream << m_wheel_delta_x;

        stream << m_wheel_delta_y;

        stream << m_wheel_raw_delta_x;

        stream << m_wheel_raw_delta_y;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntPoint& mouse_position() const { return m_mouse_position; }
    Gfx::IntPoint take_mouse_position() { return move(m_mouse_position); }

    const u32& button() const { return m_button; }
    u32 take_button() { return move(m_button); }

    const u32& buttons() const { return m_buttons; }
    u32 take_buttons() { return move(m_buttons); }

    const u32& modifiers() const { return m_modifiers; }
    u32 take_modifiers() { return move(m_modifiers); }

    const i32& wheel_delta_x() const { return m_wheel_delta_x; }
    i32 take_wheel_delta_x() { return move(m_wheel_delta_x); }

    const i32& wheel_delta_y() const { return m_wheel_delta_y; }
    i32 take_wheel_delta_y() { return move(m_wheel_delta_y); }

    const i32& wheel_raw_delta_x() const { return m_wheel_raw_delta_x; }
    i32 take_wheel_raw_delta_x() { return move(m_wheel_raw_delta_x); }

    const i32& wheel_raw_delta_y() const { return m_wheel_raw_delta_y; }
    i32 take_wheel_raw_delta_y() { return move(m_wheel_raw_delta_y); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntPoint m_mouse_position {};

    u32 m_button {};

    u32 m_buttons {};

    u32 m_modifiers {};

    i32 m_wheel_delta_x {};

    i32 m_wheel_delta_y {};

    i32 m_wheel_raw_delta_x {};

    i32 m_wheel_raw_delta_y {};

};

class WindowEntered final : public IPC::Message {
public:

    WindowEntered(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowEntered(WindowEntered const&) = default;
    WindowEntered(WindowEntered&&) = default;
    WindowEntered& operator=(WindowEntered const&) = default;
    WindowEntered(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~WindowEntered() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowEntered; }
    static i32 static_message_id() { return (int)MessageID::WindowEntered; }
    virtual const char* message_name() const override { return "WindowClient::WindowEntered"; }

    static OwnPtr<WindowEntered> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<WindowEntered>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowEntered;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class WindowLeft final : public IPC::Message {
public:

    WindowLeft(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowLeft(WindowLeft const&) = default;
    WindowLeft(WindowLeft&&) = default;
    WindowLeft& operator=(WindowLeft const&) = default;
    WindowLeft(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~WindowLeft() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowLeft; }
    static i32 static_message_id() { return (int)MessageID::WindowLeft; }
    virtual const char* message_name() const override { return "WindowClient::WindowLeft"; }

    static OwnPtr<WindowLeft> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<WindowLeft>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowLeft;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class WindowInputEntered final : public IPC::Message {
public:

    WindowInputEntered(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowInputEntered(WindowInputEntered const&) = default;
    WindowInputEntered(WindowInputEntered&&) = default;
    WindowInputEntered& operator=(WindowInputEntered const&) = default;
    WindowInputEntered(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~WindowInputEntered() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowInputEntered; }
    static i32 static_message_id() { return (int)MessageID::WindowInputEntered; }
    virtual const char* message_name() const override { return "WindowClient::WindowInputEntered"; }

    static OwnPtr<WindowInputEntered> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<WindowInputEntered>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowInputEntered;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class WindowInputLeft final : public IPC::Message {
public:

    WindowInputLeft(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowInputLeft(WindowInputLeft const&) = default;
    WindowInputLeft(WindowInputLeft&&) = default;
    WindowInputLeft& operator=(WindowInputLeft const&) = default;
    WindowInputLeft(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~WindowInputLeft() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowInputLeft; }
    static i32 static_message_id() { return (int)MessageID::WindowInputLeft; }
    virtual const char* message_name() const override { return "WindowClient::WindowInputLeft"; }

    static OwnPtr<WindowInputLeft> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<WindowInputLeft>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowInputLeft;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class KeyDown final : public IPC::Message {
public:

    KeyDown(decltype(nullptr)) : m_ipc_message_valid(false) { }
    KeyDown(KeyDown const&) = default;
    KeyDown(KeyDown&&) = default;
    KeyDown& operator=(KeyDown const&) = default;
    KeyDown(i32 window_id, u32 code_point, u32 key, u32 modifiers, u32 scancode) : m_window_id(move(window_id)), m_code_point(move(code_point)), m_key(move(key)), m_modifiers(move(modifiers)), m_scancode(move(scancode)) {}
    virtual ~KeyDown() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::KeyDown; }
    static i32 static_message_id() { return (int)MessageID::KeyDown; }
    virtual const char* message_name() const override { return "WindowClient::KeyDown"; }

    static OwnPtr<KeyDown> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        u32 code_point = {};
        if (decoder.decode(code_point).is_error())
            return {};

        u32 key = {};
        if (decoder.decode(key).is_error())
            return {};

        u32 modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        u32 scancode = {};
        if (decoder.decode(scancode).is_error())
            return {};

        return make<KeyDown>(move(window_id), move(code_point), move(key), move(modifiers), move(scancode));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::KeyDown;

        stream << m_window_id;

        stream << m_code_point;

        stream << m_key;

        stream << m_modifiers;

        stream << m_scancode;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const u32& code_point() const { return m_code_point; }
    u32 take_code_point() { return move(m_code_point); }

    const u32& key() const { return m_key; }
    u32 take_key() { return move(m_key); }

    const u32& modifiers() const { return m_modifiers; }
    u32 take_modifiers() { return move(m_modifiers); }

    const u32& scancode() const { return m_scancode; }
    u32 take_scancode() { return move(m_scancode); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    u32 m_code_point {};

    u32 m_key {};

    u32 m_modifiers {};

    u32 m_scancode {};

};

class KeyUp final : public IPC::Message {
public:

    KeyUp(decltype(nullptr)) : m_ipc_message_valid(false) { }
    KeyUp(KeyUp const&) = default;
    KeyUp(KeyUp&&) = default;
    KeyUp& operator=(KeyUp const&) = default;
    KeyUp(i32 window_id, u32 code_point, u32 key, u32 modifiers, u32 scancode) : m_window_id(move(window_id)), m_code_point(move(code_point)), m_key(move(key)), m_modifiers(move(modifiers)), m_scancode(move(scancode)) {}
    virtual ~KeyUp() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::KeyUp; }
    static i32 static_message_id() { return (int)MessageID::KeyUp; }
    virtual const char* message_name() const override { return "WindowClient::KeyUp"; }

    static OwnPtr<KeyUp> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        u32 code_point = {};
        if (decoder.decode(code_point).is_error())
            return {};

        u32 key = {};
        if (decoder.decode(key).is_error())
            return {};

        u32 modifiers = {};
        if (decoder.decode(modifiers).is_error())
            return {};

        u32 scancode = {};
        if (decoder.decode(scancode).is_error())
            return {};

        return make<KeyUp>(move(window_id), move(code_point), move(key), move(modifiers), move(scancode));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::KeyUp;

        stream << m_window_id;

        stream << m_code_point;

        stream << m_key;

        stream << m_modifiers;

        stream << m_scancode;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const u32& code_point() const { return m_code_point; }
    u32 take_code_point() { return move(m_code_point); }

    const u32& key() const { return m_key; }
    u32 take_key() { return move(m_key); }

    const u32& modifiers() const { return m_modifiers; }
    u32 take_modifiers() { return move(m_modifiers); }

    const u32& scancode() const { return m_scancode; }
    u32 take_scancode() { return move(m_scancode); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    u32 m_code_point {};

    u32 m_key {};

    u32 m_modifiers {};

    u32 m_scancode {};

};

class WindowActivated final : public IPC::Message {
public:

    WindowActivated(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowActivated(WindowActivated const&) = default;
    WindowActivated(WindowActivated&&) = default;
    WindowActivated& operator=(WindowActivated const&) = default;
    WindowActivated(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~WindowActivated() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowActivated; }
    static i32 static_message_id() { return (int)MessageID::WindowActivated; }
    virtual const char* message_name() const override { return "WindowClient::WindowActivated"; }

    static OwnPtr<WindowActivated> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<WindowActivated>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowActivated;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class WindowDeactivated final : public IPC::Message {
public:

    WindowDeactivated(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowDeactivated(WindowDeactivated const&) = default;
    WindowDeactivated(WindowDeactivated&&) = default;
    WindowDeactivated& operator=(WindowDeactivated const&) = default;
    WindowDeactivated(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~WindowDeactivated() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowDeactivated; }
    static i32 static_message_id() { return (int)MessageID::WindowDeactivated; }
    virtual const char* message_name() const override { return "WindowClient::WindowDeactivated"; }

    static OwnPtr<WindowDeactivated> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<WindowDeactivated>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowDeactivated;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class WindowStateChanged final : public IPC::Message {
public:

    WindowStateChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowStateChanged(WindowStateChanged const&) = default;
    WindowStateChanged(WindowStateChanged&&) = default;
    WindowStateChanged& operator=(WindowStateChanged const&) = default;
    WindowStateChanged(i32 window_id, bool minimized, bool maximized, bool occluded) : m_window_id(move(window_id)), m_minimized(move(minimized)), m_maximized(move(maximized)), m_occluded(move(occluded)) {}
    virtual ~WindowStateChanged() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowStateChanged; }
    static i32 static_message_id() { return (int)MessageID::WindowStateChanged; }
    virtual const char* message_name() const override { return "WindowClient::WindowStateChanged"; }

    static OwnPtr<WindowStateChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        bool minimized = false;
        if (decoder.decode(minimized).is_error())
            return {};

        bool maximized = false;
        if (decoder.decode(maximized).is_error())
            return {};

        bool occluded = false;
        if (decoder.decode(occluded).is_error())
            return {};

        return make<WindowStateChanged>(move(window_id), move(minimized), move(maximized), move(occluded));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowStateChanged;

        stream << m_window_id;

        stream << m_minimized;

        stream << m_maximized;

        stream << m_occluded;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const bool& minimized() const { return m_minimized; }
    bool take_minimized() { return move(m_minimized); }

    const bool& maximized() const { return m_maximized; }
    bool take_maximized() { return move(m_maximized); }

    const bool& occluded() const { return m_occluded; }
    bool take_occluded() { return move(m_occluded); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    bool m_minimized {};

    bool m_maximized {};

    bool m_occluded {};

};

class WindowCloseRequest final : public IPC::Message {
public:

    WindowCloseRequest(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowCloseRequest(WindowCloseRequest const&) = default;
    WindowCloseRequest(WindowCloseRequest&&) = default;
    WindowCloseRequest& operator=(WindowCloseRequest const&) = default;
    WindowCloseRequest(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~WindowCloseRequest() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowCloseRequest; }
    static i32 static_message_id() { return (int)MessageID::WindowCloseRequest; }
    virtual const char* message_name() const override { return "WindowClient::WindowCloseRequest"; }

    static OwnPtr<WindowCloseRequest> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<WindowCloseRequest>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowCloseRequest;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class WindowResized final : public IPC::Message {
public:

    WindowResized(decltype(nullptr)) : m_ipc_message_valid(false) { }
    WindowResized(WindowResized const&) = default;
    WindowResized(WindowResized&&) = default;
    WindowResized& operator=(WindowResized const&) = default;
    WindowResized(i32 window_id, Gfx::IntRect new_rect) : m_window_id(move(window_id)), m_new_rect(move(new_rect)) {}
    virtual ~WindowResized() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::WindowResized; }
    static i32 static_message_id() { return (int)MessageID::WindowResized; }
    virtual const char* message_name() const override { return "WindowClient::WindowResized"; }

    static OwnPtr<WindowResized> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntRect new_rect = {};
        if (decoder.decode(new_rect).is_error())
            return {};

        return make<WindowResized>(move(window_id), move(new_rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::WindowResized;

        stream << m_window_id;

        stream << m_new_rect;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntRect& new_rect() const { return m_new_rect; }
    Gfx::IntRect take_new_rect() { return move(m_new_rect); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntRect m_new_rect {};

};

class MenuItemActivated final : public IPC::Message {
public:

    MenuItemActivated(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MenuItemActivated(MenuItemActivated const&) = default;
    MenuItemActivated(MenuItemActivated&&) = default;
    MenuItemActivated& operator=(MenuItemActivated const&) = default;
    MenuItemActivated(i32 menu_id, u32 identifier) : m_menu_id(move(menu_id)), m_identifier(move(identifier)) {}
    virtual ~MenuItemActivated() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MenuItemActivated; }
    static i32 static_message_id() { return (int)MessageID::MenuItemActivated; }
    virtual const char* message_name() const override { return "WindowClient::MenuItemActivated"; }

    static OwnPtr<MenuItemActivated> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        u32 identifier = {};
        if (decoder.decode(identifier).is_error())
            return {};

        return make<MenuItemActivated>(move(menu_id), move(identifier));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MenuItemActivated;

        stream << m_menu_id;

        stream << m_identifier;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const u32& identifier() const { return m_identifier; }
    u32 take_identifier() { return move(m_identifier); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    u32 m_identifier {};

};

class MenuItemEntered final : public IPC::Message {
public:

    MenuItemEntered(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MenuItemEntered(MenuItemEntered const&) = default;
    MenuItemEntered(MenuItemEntered&&) = default;
    MenuItemEntered& operator=(MenuItemEntered const&) = default;
    MenuItemEntered(i32 menu_id, u32 identifier) : m_menu_id(move(menu_id)), m_identifier(move(identifier)) {}
    virtual ~MenuItemEntered() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MenuItemEntered; }
    static i32 static_message_id() { return (int)MessageID::MenuItemEntered; }
    virtual const char* message_name() const override { return "WindowClient::MenuItemEntered"; }

    static OwnPtr<MenuItemEntered> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        u32 identifier = {};
        if (decoder.decode(identifier).is_error())
            return {};

        return make<MenuItemEntered>(move(menu_id), move(identifier));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MenuItemEntered;

        stream << m_menu_id;

        stream << m_identifier;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const u32& identifier() const { return m_identifier; }
    u32 take_identifier() { return move(m_identifier); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    u32 m_identifier {};

};

class MenuItemLeft final : public IPC::Message {
public:

    MenuItemLeft(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MenuItemLeft(MenuItemLeft const&) = default;
    MenuItemLeft(MenuItemLeft&&) = default;
    MenuItemLeft& operator=(MenuItemLeft const&) = default;
    MenuItemLeft(i32 menu_id, u32 identifier) : m_menu_id(move(menu_id)), m_identifier(move(identifier)) {}
    virtual ~MenuItemLeft() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MenuItemLeft; }
    static i32 static_message_id() { return (int)MessageID::MenuItemLeft; }
    virtual const char* message_name() const override { return "WindowClient::MenuItemLeft"; }

    static OwnPtr<MenuItemLeft> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        u32 identifier = {};
        if (decoder.decode(identifier).is_error())
            return {};

        return make<MenuItemLeft>(move(menu_id), move(identifier));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MenuItemLeft;

        stream << m_menu_id;

        stream << m_identifier;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const u32& identifier() const { return m_identifier; }
    u32 take_identifier() { return move(m_identifier); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    u32 m_identifier {};

};

class MenuVisibilityDidChange final : public IPC::Message {
public:

    MenuVisibilityDidChange(decltype(nullptr)) : m_ipc_message_valid(false) { }
    MenuVisibilityDidChange(MenuVisibilityDidChange const&) = default;
    MenuVisibilityDidChange(MenuVisibilityDidChange&&) = default;
    MenuVisibilityDidChange& operator=(MenuVisibilityDidChange const&) = default;
    MenuVisibilityDidChange(i32 menu_id, bool visible) : m_menu_id(move(menu_id)), m_visible(move(visible)) {}
    virtual ~MenuVisibilityDidChange() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::MenuVisibilityDidChange; }
    static i32 static_message_id() { return (int)MessageID::MenuVisibilityDidChange; }
    virtual const char* message_name() const override { return "WindowClient::MenuVisibilityDidChange"; }

    static OwnPtr<MenuVisibilityDidChange> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 menu_id = {};
        if (decoder.decode(menu_id).is_error())
            return {};

        bool visible = false;
        if (decoder.decode(visible).is_error())
            return {};

        return make<MenuVisibilityDidChange>(move(menu_id), move(visible));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::MenuVisibilityDidChange;

        stream << m_menu_id;

        stream << m_visible;

        return buffer;
    }

    const i32& menu_id() const { return m_menu_id; }
    i32 take_menu_id() { return move(m_menu_id); }

    const bool& visible() const { return m_visible; }
    bool take_visible() { return move(m_visible); }

private:
    bool m_ipc_message_valid { true };

    i32 m_menu_id {};

    bool m_visible {};

};

class ScreenRectsChanged final : public IPC::Message {
public:

    ScreenRectsChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ScreenRectsChanged(ScreenRectsChanged const&) = default;
    ScreenRectsChanged(ScreenRectsChanged&&) = default;
    ScreenRectsChanged& operator=(ScreenRectsChanged const&) = default;
    ScreenRectsChanged(Vector<Gfx::IntRect> rects, u32 main_screen_index, u32 workspace_rows, u32 workspace_columns) : m_rects(move(rects)), m_main_screen_index(move(main_screen_index)), m_workspace_rows(move(workspace_rows)), m_workspace_columns(move(workspace_columns)) {}
    virtual ~ScreenRectsChanged() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::ScreenRectsChanged; }
    static i32 static_message_id() { return (int)MessageID::ScreenRectsChanged; }
    virtual const char* message_name() const override { return "WindowClient::ScreenRectsChanged"; }

    static OwnPtr<ScreenRectsChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<Gfx::IntRect> rects = {};
        if (decoder.decode(rects).is_error())
            return {};

        u32 main_screen_index = {};
        if (decoder.decode(main_screen_index).is_error())
            return {};

        u32 workspace_rows = {};
        if (decoder.decode(workspace_rows).is_error())
            return {};

        u32 workspace_columns = {};
        if (decoder.decode(workspace_columns).is_error())
            return {};

        return make<ScreenRectsChanged>(move(rects), move(main_screen_index), move(workspace_rows), move(workspace_columns));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ScreenRectsChanged;

        stream << m_rects;

        stream << m_main_screen_index;

        stream << m_workspace_rows;

        stream << m_workspace_columns;

        return buffer;
    }

    const Vector<Gfx::IntRect>& rects() const { return m_rects; }
    Vector<Gfx::IntRect> take_rects() { return move(m_rects); }

    const u32& main_screen_index() const { return m_main_screen_index; }
    u32 take_main_screen_index() { return move(m_main_screen_index); }

    const u32& workspace_rows() const { return m_workspace_rows; }
    u32 take_workspace_rows() { return move(m_workspace_rows); }

    const u32& workspace_columns() const { return m_workspace_columns; }
    u32 take_workspace_columns() { return move(m_workspace_columns); }

private:
    bool m_ipc_message_valid { true };

    Vector<Gfx::IntRect> m_rects {};

    u32 m_main_screen_index {};

    u32 m_workspace_rows {};

    u32 m_workspace_columns {};

};

class AppletAreaRectChanged final : public IPC::Message {
public:

    AppletAreaRectChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AppletAreaRectChanged(AppletAreaRectChanged const&) = default;
    AppletAreaRectChanged(AppletAreaRectChanged&&) = default;
    AppletAreaRectChanged& operator=(AppletAreaRectChanged const&) = default;
    AppletAreaRectChanged(Gfx::IntRect rect) : m_rect(move(rect)) {}
    virtual ~AppletAreaRectChanged() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::AppletAreaRectChanged; }
    static i32 static_message_id() { return (int)MessageID::AppletAreaRectChanged; }
    virtual const char* message_name() const override { return "WindowClient::AppletAreaRectChanged"; }

    static OwnPtr<AppletAreaRectChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<AppletAreaRectChanged>(move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AppletAreaRectChanged;

        stream << m_rect;

        return buffer;
    }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntRect m_rect {};

};

class SetWallpaperFinished final : public IPC::Message {
public:

    SetWallpaperFinished(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWallpaperFinished(SetWallpaperFinished const&) = default;
    SetWallpaperFinished(SetWallpaperFinished&&) = default;
    SetWallpaperFinished& operator=(SetWallpaperFinished const&) = default;
    SetWallpaperFinished(bool success) : m_success(move(success)) {}
    virtual ~SetWallpaperFinished() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::SetWallpaperFinished; }
    static i32 static_message_id() { return (int)MessageID::SetWallpaperFinished; }
    virtual const char* message_name() const override { return "WindowClient::SetWallpaperFinished"; }

    static OwnPtr<SetWallpaperFinished> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        return make<SetWallpaperFinished>(move(success));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWallpaperFinished;

        stream << m_success;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

};

class DragAccepted final : public IPC::Message {
public:

    DragAccepted(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DragAccepted(DragAccepted const&) = default;
    DragAccepted(DragAccepted&&) = default;
    DragAccepted& operator=(DragAccepted const&) = default;
    DragAccepted() {}
    virtual ~DragAccepted() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::DragAccepted; }
    static i32 static_message_id() { return (int)MessageID::DragAccepted; }
    virtual const char* message_name() const override { return "WindowClient::DragAccepted"; }

    static OwnPtr<DragAccepted> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DragAccepted>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DragAccepted;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class DragCancelled final : public IPC::Message {
public:

    DragCancelled(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DragCancelled(DragCancelled const&) = default;
    DragCancelled(DragCancelled&&) = default;
    DragCancelled& operator=(DragCancelled const&) = default;
    DragCancelled() {}
    virtual ~DragCancelled() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::DragCancelled; }
    static i32 static_message_id() { return (int)MessageID::DragCancelled; }
    virtual const char* message_name() const override { return "WindowClient::DragCancelled"; }

    static OwnPtr<DragCancelled> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DragCancelled>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DragCancelled;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class DragDropped final : public IPC::Message {
public:

    DragDropped(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DragDropped(DragDropped const&) = default;
    DragDropped(DragDropped&&) = default;
    DragDropped& operator=(DragDropped const&) = default;
    DragDropped(i32 window_id, Gfx::IntPoint mouse_position, String text, HashMap<String,ByteBuffer> mime_data) : m_window_id(move(window_id)), m_mouse_position(move(mouse_position)), m_text(move(text)), m_mime_data(move(mime_data)) {}
    virtual ~DragDropped() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::DragDropped; }
    static i32 static_message_id() { return (int)MessageID::DragDropped; }
    virtual const char* message_name() const override { return "WindowClient::DragDropped"; }

    static OwnPtr<DragDropped> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntPoint mouse_position = {};
        if (decoder.decode(mouse_position).is_error())
            return {};

        String text = {};
        if (decoder.decode(text).is_error())
            return {};

        if (!Utf8View(text).validate())
            return {};

        HashMap<String,ByteBuffer> mime_data = {};
        if (decoder.decode(mime_data).is_error())
            return {};

        return make<DragDropped>(move(window_id), move(mouse_position), move(text), move(mime_data));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DragDropped;

        stream << m_window_id;

        stream << m_mouse_position;

        stream << m_text;

        stream << m_mime_data;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntPoint& mouse_position() const { return m_mouse_position; }
    Gfx::IntPoint take_mouse_position() { return move(m_mouse_position); }

    const String& text() const { return m_text; }
    String take_text() { return move(m_text); }

    const HashMap<String,ByteBuffer>& mime_data() const { return m_mime_data; }
    HashMap<String,ByteBuffer> take_mime_data() { return move(m_mime_data); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

    Gfx::IntPoint m_mouse_position {};

    String m_text {};

    HashMap<String,ByteBuffer> m_mime_data {};

};

class UpdateSystemTheme final : public IPC::Message {
public:

    UpdateSystemTheme(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateSystemTheme(UpdateSystemTheme const&) = default;
    UpdateSystemTheme(UpdateSystemTheme&&) = default;
    UpdateSystemTheme& operator=(UpdateSystemTheme const&) = default;
    UpdateSystemTheme(Core::AnonymousBuffer theme_buffer) : m_theme_buffer(move(theme_buffer)) {}
    virtual ~UpdateSystemTheme() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateSystemTheme; }
    static i32 static_message_id() { return (int)MessageID::UpdateSystemTheme; }
    virtual const char* message_name() const override { return "WindowClient::UpdateSystemTheme"; }

    static OwnPtr<UpdateSystemTheme> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Core::AnonymousBuffer theme_buffer = {};
        if (decoder.decode(theme_buffer).is_error())
            return {};

        return make<UpdateSystemTheme>(move(theme_buffer));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateSystemTheme;

        stream << m_theme_buffer;

        return buffer;
    }

    const Core::AnonymousBuffer& theme_buffer() const { return m_theme_buffer; }
    Core::AnonymousBuffer take_theme_buffer() { return move(m_theme_buffer); }

private:
    bool m_ipc_message_valid { true };

    Core::AnonymousBuffer m_theme_buffer {};

};

class UpdateSystemFonts final : public IPC::Message {
public:

    UpdateSystemFonts(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateSystemFonts(UpdateSystemFonts const&) = default;
    UpdateSystemFonts(UpdateSystemFonts&&) = default;
    UpdateSystemFonts& operator=(UpdateSystemFonts const&) = default;
    UpdateSystemFonts(String default_font_query, String fixed_width_font_query) : m_default_font_query(move(default_font_query)), m_fixed_width_font_query(move(fixed_width_font_query)) {}
    virtual ~UpdateSystemFonts() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateSystemFonts; }
    static i32 static_message_id() { return (int)MessageID::UpdateSystemFonts; }
    virtual const char* message_name() const override { return "WindowClient::UpdateSystemFonts"; }

    static OwnPtr<UpdateSystemFonts> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String default_font_query = {};
        if (decoder.decode(default_font_query).is_error())
            return {};

        String fixed_width_font_query = {};
        if (decoder.decode(fixed_width_font_query).is_error())
            return {};

        return make<UpdateSystemFonts>(move(default_font_query), move(fixed_width_font_query));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateSystemFonts;

        stream << m_default_font_query;

        stream << m_fixed_width_font_query;

        return buffer;
    }

    const String& default_font_query() const { return m_default_font_query; }
    String take_default_font_query() { return move(m_default_font_query); }

    const String& fixed_width_font_query() const { return m_fixed_width_font_query; }
    String take_fixed_width_font_query() { return move(m_fixed_width_font_query); }

private:
    bool m_ipc_message_valid { true };

    String m_default_font_query {};

    String m_fixed_width_font_query {};

};

class DisplayLinkNotification final : public IPC::Message {
public:

    DisplayLinkNotification(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DisplayLinkNotification(DisplayLinkNotification const&) = default;
    DisplayLinkNotification(DisplayLinkNotification&&) = default;
    DisplayLinkNotification& operator=(DisplayLinkNotification const&) = default;
    DisplayLinkNotification() {}
    virtual ~DisplayLinkNotification() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::DisplayLinkNotification; }
    static i32 static_message_id() { return (int)MessageID::DisplayLinkNotification; }
    virtual const char* message_name() const override { return "WindowClient::DisplayLinkNotification"; }

    static OwnPtr<DisplayLinkNotification> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<DisplayLinkNotification>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DisplayLinkNotification;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class TrackMouseMove final : public IPC::Message {
public:

    TrackMouseMove(decltype(nullptr)) : m_ipc_message_valid(false) { }
    TrackMouseMove(TrackMouseMove const&) = default;
    TrackMouseMove(TrackMouseMove&&) = default;
    TrackMouseMove& operator=(TrackMouseMove const&) = default;
    TrackMouseMove(Gfx::IntPoint mouse_position) : m_mouse_position(move(mouse_position)) {}
    virtual ~TrackMouseMove() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::TrackMouseMove; }
    static i32 static_message_id() { return (int)MessageID::TrackMouseMove; }
    virtual const char* message_name() const override { return "WindowClient::TrackMouseMove"; }

    static OwnPtr<TrackMouseMove> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint mouse_position = {};
        if (decoder.decode(mouse_position).is_error())
            return {};

        return make<TrackMouseMove>(move(mouse_position));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::TrackMouseMove;

        stream << m_mouse_position;

        return buffer;
    }

    const Gfx::IntPoint& mouse_position() const { return m_mouse_position; }
    Gfx::IntPoint take_mouse_position() { return move(m_mouse_position); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_mouse_position {};

};

class Ping final : public IPC::Message {
public:

    Ping(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Ping(Ping const&) = default;
    Ping(Ping&&) = default;
    Ping& operator=(Ping const&) = default;
    Ping() {}
    virtual ~Ping() override {}

    virtual u32 endpoint_magic() const override { return 3794023488; }
    virtual i32 message_id() const override { return (int)MessageID::Ping; }
    static i32 static_message_id() { return (int)MessageID::Ping; }
    virtual const char* message_name() const override { return "WindowClient::Ping"; }

    static OwnPtr<Ping> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<Ping>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Ping;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

} // namespace Messages::WindowClient

template<typename LocalEndpoint, typename PeerEndpoint>
class WindowClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    WindowClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_fast_greet(
Vector<Gfx::IntRect> screen_rects, u32 main_screen_index, u32 workspace_rows, u32 workspace_columns, Core::AnonymousBuffer theme_buffer, String default_font_query, String fixed_width_font_query, i32 client_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::FastGreet { move(screen_rects), main_screen_index, workspace_rows, workspace_columns, move(theme_buffer), move(default_font_query), move(fixed_width_font_query), client_id });

    }

    void async_paint(
i32 window_id, Gfx::IntSize window_size, Vector<Gfx::IntRect> rects) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::Paint { window_id, move(window_size), move(rects) });

    }

    void async_mouse_move(
i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y, bool is_drag, Vector<String> mime_types) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MouseMove { window_id, move(mouse_position), button, buttons, modifiers, wheel_delta_x, wheel_delta_y, wheel_raw_delta_x, wheel_raw_delta_y, is_drag, move(mime_types) });

    }

    void async_mouse_down(
i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MouseDown { window_id, move(mouse_position), button, buttons, modifiers, wheel_delta_x, wheel_delta_y, wheel_raw_delta_x, wheel_raw_delta_y });

    }

    void async_mouse_double_click(
i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MouseDoubleClick { window_id, move(mouse_position), button, buttons, modifiers, wheel_delta_x, wheel_delta_y, wheel_raw_delta_x, wheel_raw_delta_y });

    }

    void async_mouse_up(
i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MouseUp { window_id, move(mouse_position), button, buttons, modifiers, wheel_delta_x, wheel_delta_y, wheel_raw_delta_x, wheel_raw_delta_y });

    }

    void async_mouse_wheel(
i32 window_id, Gfx::IntPoint mouse_position, u32 button, u32 buttons, u32 modifiers, i32 wheel_delta_x, i32 wheel_delta_y, i32 wheel_raw_delta_x, i32 wheel_raw_delta_y) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MouseWheel { window_id, move(mouse_position), button, buttons, modifiers, wheel_delta_x, wheel_delta_y, wheel_raw_delta_x, wheel_raw_delta_y });

    }

    void async_window_entered(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowEntered { window_id });

    }

    void async_window_left(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowLeft { window_id });

    }

    void async_window_input_entered(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowInputEntered { window_id });

    }

    void async_window_input_left(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowInputLeft { window_id });

    }

    void async_key_down(
i32 window_id, u32 code_point, u32 key, u32 modifiers, u32 scancode) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::KeyDown { window_id, code_point, key, modifiers, scancode });

    }

    void async_key_up(
i32 window_id, u32 code_point, u32 key, u32 modifiers, u32 scancode) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::KeyUp { window_id, code_point, key, modifiers, scancode });

    }

    void async_window_activated(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowActivated { window_id });

    }

    void async_window_deactivated(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowDeactivated { window_id });

    }

    void async_window_state_changed(
i32 window_id, bool minimized, bool maximized, bool occluded) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowStateChanged { window_id, minimized, maximized, occluded });

    }

    void async_window_close_request(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowCloseRequest { window_id });

    }

    void async_window_resized(
i32 window_id, Gfx::IntRect new_rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::WindowResized { window_id, move(new_rect) });

    }

    void async_menu_item_activated(
i32 menu_id, u32 identifier) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MenuItemActivated { menu_id, identifier });

    }

    void async_menu_item_entered(
i32 menu_id, u32 identifier) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MenuItemEntered { menu_id, identifier });

    }

    void async_menu_item_left(
i32 menu_id, u32 identifier) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MenuItemLeft { menu_id, identifier });

    }

    void async_menu_visibility_did_change(
i32 menu_id, bool visible) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::MenuVisibilityDidChange { menu_id, visible });

    }

    void async_screen_rects_changed(
Vector<Gfx::IntRect> rects, u32 main_screen_index, u32 workspace_rows, u32 workspace_columns) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::ScreenRectsChanged { move(rects), main_screen_index, workspace_rows, workspace_columns });

    }

    void async_applet_area_rect_changed(
Gfx::IntRect rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::AppletAreaRectChanged { move(rect) });

    }

    void async_set_wallpaper_finished(
bool success) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::SetWallpaperFinished { success });

    }

    void async_drag_accepted(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::DragAccepted {  });

    }

    void async_drag_cancelled(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::DragCancelled {  });

    }

    void async_drag_dropped(
i32 window_id, Gfx::IntPoint mouse_position, String text, HashMap<String,ByteBuffer> mime_data) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::DragDropped { window_id, move(mouse_position), move(text), move(mime_data) });

    }

    void async_update_system_theme(
Core::AnonymousBuffer theme_buffer) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::UpdateSystemTheme { move(theme_buffer) });

    }

    void async_update_system_fonts(
String default_font_query, String fixed_width_font_query) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::UpdateSystemFonts { move(default_font_query), move(fixed_width_font_query) });

    }

    void async_display_link_notification(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::DisplayLinkNotification {  });

    }

    void async_track_mouse_move(
Gfx::IntPoint mouse_position) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::TrackMouseMove { move(mouse_position) });

    }

    void async_ping(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowClient::Ping {  });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class WindowClientProxy;
class WindowClientStub;

class WindowClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = WindowClientProxy<LocalEndpoint, WindowClientEndpoint>;
    using Stub = WindowClientStub;

    static u32 static_magic() { return 3794023488; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3794023488) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::WindowClient::MessageID::FastGreet:
            message = Messages::WindowClient::FastGreet::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::Paint:
            message = Messages::WindowClient::Paint::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MouseMove:
            message = Messages::WindowClient::MouseMove::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MouseDown:
            message = Messages::WindowClient::MouseDown::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MouseDoubleClick:
            message = Messages::WindowClient::MouseDoubleClick::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MouseUp:
            message = Messages::WindowClient::MouseUp::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MouseWheel:
            message = Messages::WindowClient::MouseWheel::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowEntered:
            message = Messages::WindowClient::WindowEntered::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowLeft:
            message = Messages::WindowClient::WindowLeft::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowInputEntered:
            message = Messages::WindowClient::WindowInputEntered::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowInputLeft:
            message = Messages::WindowClient::WindowInputLeft::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::KeyDown:
            message = Messages::WindowClient::KeyDown::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::KeyUp:
            message = Messages::WindowClient::KeyUp::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowActivated:
            message = Messages::WindowClient::WindowActivated::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowDeactivated:
            message = Messages::WindowClient::WindowDeactivated::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowStateChanged:
            message = Messages::WindowClient::WindowStateChanged::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowCloseRequest:
            message = Messages::WindowClient::WindowCloseRequest::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::WindowResized:
            message = Messages::WindowClient::WindowResized::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MenuItemActivated:
            message = Messages::WindowClient::MenuItemActivated::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MenuItemEntered:
            message = Messages::WindowClient::MenuItemEntered::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MenuItemLeft:
            message = Messages::WindowClient::MenuItemLeft::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::MenuVisibilityDidChange:
            message = Messages::WindowClient::MenuVisibilityDidChange::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::ScreenRectsChanged:
            message = Messages::WindowClient::ScreenRectsChanged::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::AppletAreaRectChanged:
            message = Messages::WindowClient::AppletAreaRectChanged::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::SetWallpaperFinished:
            message = Messages::WindowClient::SetWallpaperFinished::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::DragAccepted:
            message = Messages::WindowClient::DragAccepted::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::DragCancelled:
            message = Messages::WindowClient::DragCancelled::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::DragDropped:
            message = Messages::WindowClient::DragDropped::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::UpdateSystemTheme:
            message = Messages::WindowClient::UpdateSystemTheme::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::UpdateSystemFonts:
            message = Messages::WindowClient::UpdateSystemFonts::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::DisplayLinkNotification:
            message = Messages::WindowClient::DisplayLinkNotification::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::TrackMouseMove:
            message = Messages::WindowClient::TrackMouseMove::decode(stream, socket);
            break;

        case (int)Messages::WindowClient::MessageID::Ping:
            message = Messages::WindowClient::Ping::decode(stream, socket);
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

class WindowClientStub : public IPC::Stub {
public:
    WindowClientStub() { }
    virtual ~WindowClientStub() override { }

    virtual u32 magic() const override { return 3794023488; }
    virtual String name() const override { return "WindowClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::WindowClient::MessageID::FastGreet: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::FastGreet&>(message);
            fast_greet(request.screen_rects(), request.main_screen_index(), request.workspace_rows(), request.workspace_columns(), request.theme_buffer(), request.default_font_query(), request.fixed_width_font_query(), request.client_id());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::Paint: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::Paint&>(message);
            paint(request.window_id(), request.window_size(), request.rects());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MouseMove: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MouseMove&>(message);
            mouse_move(request.window_id(), request.mouse_position(), request.button(), request.buttons(), request.modifiers(), request.wheel_delta_x(), request.wheel_delta_y(), request.wheel_raw_delta_x(), request.wheel_raw_delta_y(), request.is_drag(), request.mime_types());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MouseDown: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MouseDown&>(message);
            mouse_down(request.window_id(), request.mouse_position(), request.button(), request.buttons(), request.modifiers(), request.wheel_delta_x(), request.wheel_delta_y(), request.wheel_raw_delta_x(), request.wheel_raw_delta_y());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MouseDoubleClick: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MouseDoubleClick&>(message);
            mouse_double_click(request.window_id(), request.mouse_position(), request.button(), request.buttons(), request.modifiers(), request.wheel_delta_x(), request.wheel_delta_y(), request.wheel_raw_delta_x(), request.wheel_raw_delta_y());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MouseUp: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MouseUp&>(message);
            mouse_up(request.window_id(), request.mouse_position(), request.button(), request.buttons(), request.modifiers(), request.wheel_delta_x(), request.wheel_delta_y(), request.wheel_raw_delta_x(), request.wheel_raw_delta_y());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MouseWheel: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MouseWheel&>(message);
            mouse_wheel(request.window_id(), request.mouse_position(), request.button(), request.buttons(), request.modifiers(), request.wheel_delta_x(), request.wheel_delta_y(), request.wheel_raw_delta_x(), request.wheel_raw_delta_y());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowEntered: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowEntered&>(message);
            window_entered(request.window_id());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowLeft: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowLeft&>(message);
            window_left(request.window_id());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowInputEntered: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowInputEntered&>(message);
            window_input_entered(request.window_id());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowInputLeft: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowInputLeft&>(message);
            window_input_left(request.window_id());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::KeyDown: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::KeyDown&>(message);
            key_down(request.window_id(), request.code_point(), request.key(), request.modifiers(), request.scancode());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::KeyUp: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::KeyUp&>(message);
            key_up(request.window_id(), request.code_point(), request.key(), request.modifiers(), request.scancode());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowActivated: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowActivated&>(message);
            window_activated(request.window_id());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowDeactivated: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowDeactivated&>(message);
            window_deactivated(request.window_id());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowStateChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowStateChanged&>(message);
            window_state_changed(request.window_id(), request.minimized(), request.maximized(), request.occluded());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowCloseRequest: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowCloseRequest&>(message);
            window_close_request(request.window_id());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::WindowResized: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::WindowResized&>(message);
            window_resized(request.window_id(), request.new_rect());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MenuItemActivated: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MenuItemActivated&>(message);
            menu_item_activated(request.menu_id(), request.identifier());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MenuItemEntered: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MenuItemEntered&>(message);
            menu_item_entered(request.menu_id(), request.identifier());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MenuItemLeft: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MenuItemLeft&>(message);
            menu_item_left(request.menu_id(), request.identifier());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::MenuVisibilityDidChange: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::MenuVisibilityDidChange&>(message);
            menu_visibility_did_change(request.menu_id(), request.visible());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::ScreenRectsChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::ScreenRectsChanged&>(message);
            screen_rects_changed(request.rects(), request.main_screen_index(), request.workspace_rows(), request.workspace_columns());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::AppletAreaRectChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::AppletAreaRectChanged&>(message);
            applet_area_rect_changed(request.rect());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::SetWallpaperFinished: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::SetWallpaperFinished&>(message);
            set_wallpaper_finished(request.success());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::DragAccepted: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::DragAccepted&>(message);
            drag_accepted();
            return {};

        }

        case (int)Messages::WindowClient::MessageID::DragCancelled: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::DragCancelled&>(message);
            drag_cancelled();
            return {};

        }

        case (int)Messages::WindowClient::MessageID::DragDropped: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::DragDropped&>(message);
            drag_dropped(request.window_id(), request.mouse_position(), request.text(), request.mime_data());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::UpdateSystemTheme: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::UpdateSystemTheme&>(message);
            update_system_theme(request.theme_buffer());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::UpdateSystemFonts: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::UpdateSystemFonts&>(message);
            update_system_fonts(request.default_font_query(), request.fixed_width_font_query());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::DisplayLinkNotification: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::DisplayLinkNotification&>(message);
            display_link_notification();
            return {};

        }

        case (int)Messages::WindowClient::MessageID::TrackMouseMove: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::TrackMouseMove&>(message);
            track_mouse_move(request.mouse_position());
            return {};

        }

        case (int)Messages::WindowClient::MessageID::Ping: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowClient::Ping&>(message);
            ping();
            return {};

        }

        default:
            return {};
        }
    }

    virtual void fast_greet(
[[maybe_unused]] Vector<Gfx::IntRect> const& screen_rects, [[maybe_unused]] u32 main_screen_index, [[maybe_unused]] u32 workspace_rows, [[maybe_unused]] u32 workspace_columns, [[maybe_unused]] Core::AnonymousBuffer const& theme_buffer, [[maybe_unused]] String const& default_font_query, [[maybe_unused]] String const& fixed_width_font_query, [[maybe_unused]] i32 client_id) = 0;

    virtual void paint(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntSize const& window_size, [[maybe_unused]] Vector<Gfx::IntRect> const& rects) = 0;

    virtual void mouse_move(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntPoint const& mouse_position, [[maybe_unused]] u32 button, [[maybe_unused]] u32 buttons, [[maybe_unused]] u32 modifiers, [[maybe_unused]] i32 wheel_delta_x, [[maybe_unused]] i32 wheel_delta_y, [[maybe_unused]] i32 wheel_raw_delta_x, [[maybe_unused]] i32 wheel_raw_delta_y, [[maybe_unused]] bool is_drag, [[maybe_unused]] Vector<String> const& mime_types) = 0;

    virtual void mouse_down(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntPoint const& mouse_position, [[maybe_unused]] u32 button, [[maybe_unused]] u32 buttons, [[maybe_unused]] u32 modifiers, [[maybe_unused]] i32 wheel_delta_x, [[maybe_unused]] i32 wheel_delta_y, [[maybe_unused]] i32 wheel_raw_delta_x, [[maybe_unused]] i32 wheel_raw_delta_y) = 0;

    virtual void mouse_double_click(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntPoint const& mouse_position, [[maybe_unused]] u32 button, [[maybe_unused]] u32 buttons, [[maybe_unused]] u32 modifiers, [[maybe_unused]] i32 wheel_delta_x, [[maybe_unused]] i32 wheel_delta_y, [[maybe_unused]] i32 wheel_raw_delta_x, [[maybe_unused]] i32 wheel_raw_delta_y) = 0;

    virtual void mouse_up(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntPoint const& mouse_position, [[maybe_unused]] u32 button, [[maybe_unused]] u32 buttons, [[maybe_unused]] u32 modifiers, [[maybe_unused]] i32 wheel_delta_x, [[maybe_unused]] i32 wheel_delta_y, [[maybe_unused]] i32 wheel_raw_delta_x, [[maybe_unused]] i32 wheel_raw_delta_y) = 0;

    virtual void mouse_wheel(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntPoint const& mouse_position, [[maybe_unused]] u32 button, [[maybe_unused]] u32 buttons, [[maybe_unused]] u32 modifiers, [[maybe_unused]] i32 wheel_delta_x, [[maybe_unused]] i32 wheel_delta_y, [[maybe_unused]] i32 wheel_raw_delta_x, [[maybe_unused]] i32 wheel_raw_delta_y) = 0;

    virtual void window_entered(
[[maybe_unused]] i32 window_id) = 0;

    virtual void window_left(
[[maybe_unused]] i32 window_id) = 0;

    virtual void window_input_entered(
[[maybe_unused]] i32 window_id) = 0;

    virtual void window_input_left(
[[maybe_unused]] i32 window_id) = 0;

    virtual void key_down(
[[maybe_unused]] i32 window_id, [[maybe_unused]] u32 code_point, [[maybe_unused]] u32 key, [[maybe_unused]] u32 modifiers, [[maybe_unused]] u32 scancode) = 0;

    virtual void key_up(
[[maybe_unused]] i32 window_id, [[maybe_unused]] u32 code_point, [[maybe_unused]] u32 key, [[maybe_unused]] u32 modifiers, [[maybe_unused]] u32 scancode) = 0;

    virtual void window_activated(
[[maybe_unused]] i32 window_id) = 0;

    virtual void window_deactivated(
[[maybe_unused]] i32 window_id) = 0;

    virtual void window_state_changed(
[[maybe_unused]] i32 window_id, [[maybe_unused]] bool minimized, [[maybe_unused]] bool maximized, [[maybe_unused]] bool occluded) = 0;

    virtual void window_close_request(
[[maybe_unused]] i32 window_id) = 0;

    virtual void window_resized(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntRect const& new_rect) = 0;

    virtual void menu_item_activated(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] u32 identifier) = 0;

    virtual void menu_item_entered(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] u32 identifier) = 0;

    virtual void menu_item_left(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] u32 identifier) = 0;

    virtual void menu_visibility_did_change(
[[maybe_unused]] i32 menu_id, [[maybe_unused]] bool visible) = 0;

    virtual void screen_rects_changed(
[[maybe_unused]] Vector<Gfx::IntRect> const& rects, [[maybe_unused]] u32 main_screen_index, [[maybe_unused]] u32 workspace_rows, [[maybe_unused]] u32 workspace_columns) = 0;

    virtual void applet_area_rect_changed(
[[maybe_unused]] Gfx::IntRect const& rect) = 0;

    virtual void set_wallpaper_finished(
[[maybe_unused]] bool success) = 0;

    virtual void drag_accepted(
) = 0;

    virtual void drag_cancelled(
) = 0;

    virtual void drag_dropped(
[[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntPoint const& mouse_position, [[maybe_unused]] String const& text, [[maybe_unused]] HashMap<String,ByteBuffer> const& mime_data) = 0;

    virtual void update_system_theme(
[[maybe_unused]] Core::AnonymousBuffer const& theme_buffer) = 0;

    virtual void update_system_fonts(
[[maybe_unused]] String const& default_font_query, [[maybe_unused]] String const& fixed_width_font_query) = 0;

    virtual void display_link_notification(
) = 0;

    virtual void track_mouse_move(
[[maybe_unused]] Gfx::IntPoint const& mouse_position) = 0;

    virtual void ping(
) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

