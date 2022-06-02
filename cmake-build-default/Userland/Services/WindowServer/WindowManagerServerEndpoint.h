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

namespace Messages::WindowManagerServer {

enum class MessageID : i32 {
    SetEventMask = 1,
    SetManagerWindow = 2,
    SetActiveWindow = 3,
    SetWindowMinimized = 4,
    ToggleShowDesktop = 5,
    StartWindowResize = 6,
    PopupWindowMenu = 7,
    SetWindowTaskbarRect = 8,
    SetAppletAreaPosition = 9,
    SetWorkspace = 10,
};

class SetEventMask final : public IPC::Message {
public:

    SetEventMask(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetEventMask(SetEventMask const&) = default;
    SetEventMask(SetEventMask&&) = default;
    SetEventMask& operator=(SetEventMask const&) = default;
    SetEventMask(u32 event_mask) : m_event_mask(move(event_mask)) {}
    virtual ~SetEventMask() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::SetEventMask; }
    static i32 static_message_id() { return (int)MessageID::SetEventMask; }
    virtual const char* message_name() const override { return "WindowManagerServer::SetEventMask"; }

    static OwnPtr<SetEventMask> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 event_mask = {};
        if (decoder.decode(event_mask).is_error())
            return {};

        return make<SetEventMask>(move(event_mask));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetEventMask;

        stream << m_event_mask;

        return buffer;
    }

    const u32& event_mask() const { return m_event_mask; }
    u32 take_event_mask() { return move(m_event_mask); }

private:
    bool m_ipc_message_valid { true };

    u32 m_event_mask {};

};

class SetManagerWindow final : public IPC::Message {
public:

    SetManagerWindow(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetManagerWindow(SetManagerWindow const&) = default;
    SetManagerWindow(SetManagerWindow&&) = default;
    SetManagerWindow& operator=(SetManagerWindow const&) = default;
    SetManagerWindow(i32 window_id) : m_window_id(move(window_id)) {}
    virtual ~SetManagerWindow() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::SetManagerWindow; }
    static i32 static_message_id() { return (int)MessageID::SetManagerWindow; }
    virtual const char* message_name() const override { return "WindowManagerServer::SetManagerWindow"; }

    static OwnPtr<SetManagerWindow> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<SetManagerWindow>(move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetManagerWindow;

        stream << m_window_id;

        return buffer;
    }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_id {};

};

class SetActiveWindow final : public IPC::Message {
public:

    SetActiveWindow(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetActiveWindow(SetActiveWindow const&) = default;
    SetActiveWindow(SetActiveWindow&&) = default;
    SetActiveWindow& operator=(SetActiveWindow const&) = default;
    SetActiveWindow(i32 client_id, i32 window_id) : m_client_id(move(client_id)), m_window_id(move(window_id)) {}
    virtual ~SetActiveWindow() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::SetActiveWindow; }
    static i32 static_message_id() { return (int)MessageID::SetActiveWindow; }
    virtual const char* message_name() const override { return "WindowManagerServer::SetActiveWindow"; }

    static OwnPtr<SetActiveWindow> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<SetActiveWindow>(move(client_id), move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetActiveWindow;

        stream << m_client_id;

        stream << m_window_id;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_window_id {};

};

class SetWindowMinimized final : public IPC::Message {
public:

    SetWindowMinimized(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowMinimized(SetWindowMinimized const&) = default;
    SetWindowMinimized(SetWindowMinimized&&) = default;
    SetWindowMinimized& operator=(SetWindowMinimized const&) = default;
    SetWindowMinimized(i32 client_id, i32 window_id, bool minimized) : m_client_id(move(client_id)), m_window_id(move(window_id)), m_minimized(move(minimized)) {}
    virtual ~SetWindowMinimized() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowMinimized; }
    static i32 static_message_id() { return (int)MessageID::SetWindowMinimized; }
    virtual const char* message_name() const override { return "WindowManagerServer::SetWindowMinimized"; }

    static OwnPtr<SetWindowMinimized> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        bool minimized = false;
        if (decoder.decode(minimized).is_error())
            return {};

        return make<SetWindowMinimized>(move(client_id), move(window_id), move(minimized));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowMinimized;

        stream << m_client_id;

        stream << m_window_id;

        stream << m_minimized;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const bool& minimized() const { return m_minimized; }
    bool take_minimized() { return move(m_minimized); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_window_id {};

    bool m_minimized {};

};

class ToggleShowDesktop final : public IPC::Message {
public:

    ToggleShowDesktop(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ToggleShowDesktop(ToggleShowDesktop const&) = default;
    ToggleShowDesktop(ToggleShowDesktop&&) = default;
    ToggleShowDesktop& operator=(ToggleShowDesktop const&) = default;
    ToggleShowDesktop() {}
    virtual ~ToggleShowDesktop() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::ToggleShowDesktop; }
    static i32 static_message_id() { return (int)MessageID::ToggleShowDesktop; }
    virtual const char* message_name() const override { return "WindowManagerServer::ToggleShowDesktop"; }

    static OwnPtr<ToggleShowDesktop> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<ToggleShowDesktop>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ToggleShowDesktop;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class StartWindowResize final : public IPC::Message {
public:

    StartWindowResize(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StartWindowResize(StartWindowResize const&) = default;
    StartWindowResize(StartWindowResize&&) = default;
    StartWindowResize& operator=(StartWindowResize const&) = default;
    StartWindowResize(i32 client_id, i32 window_id) : m_client_id(move(client_id)), m_window_id(move(window_id)) {}
    virtual ~StartWindowResize() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::StartWindowResize; }
    static i32 static_message_id() { return (int)MessageID::StartWindowResize; }
    virtual const char* message_name() const override { return "WindowManagerServer::StartWindowResize"; }

    static OwnPtr<StartWindowResize> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        return make<StartWindowResize>(move(client_id), move(window_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StartWindowResize;

        stream << m_client_id;

        stream << m_window_id;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_window_id {};

};

class PopupWindowMenu final : public IPC::Message {
public:

    PopupWindowMenu(decltype(nullptr)) : m_ipc_message_valid(false) { }
    PopupWindowMenu(PopupWindowMenu const&) = default;
    PopupWindowMenu(PopupWindowMenu&&) = default;
    PopupWindowMenu& operator=(PopupWindowMenu const&) = default;
    PopupWindowMenu(i32 client_id, i32 window_id, Gfx::IntPoint screen_position) : m_client_id(move(client_id)), m_window_id(move(window_id)), m_screen_position(move(screen_position)) {}
    virtual ~PopupWindowMenu() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::PopupWindowMenu; }
    static i32 static_message_id() { return (int)MessageID::PopupWindowMenu; }
    virtual const char* message_name() const override { return "WindowManagerServer::PopupWindowMenu"; }

    static OwnPtr<PopupWindowMenu> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntPoint screen_position = {};
        if (decoder.decode(screen_position).is_error())
            return {};

        return make<PopupWindowMenu>(move(client_id), move(window_id), move(screen_position));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::PopupWindowMenu;

        stream << m_client_id;

        stream << m_window_id;

        stream << m_screen_position;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntPoint& screen_position() const { return m_screen_position; }
    Gfx::IntPoint take_screen_position() { return move(m_screen_position); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_window_id {};

    Gfx::IntPoint m_screen_position {};

};

class SetWindowTaskbarRect final : public IPC::Message {
public:

    SetWindowTaskbarRect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWindowTaskbarRect(SetWindowTaskbarRect const&) = default;
    SetWindowTaskbarRect(SetWindowTaskbarRect&&) = default;
    SetWindowTaskbarRect& operator=(SetWindowTaskbarRect const&) = default;
    SetWindowTaskbarRect(i32 client_id, i32 window_id, Gfx::IntRect rect) : m_client_id(move(client_id)), m_window_id(move(window_id)), m_rect(move(rect)) {}
    virtual ~SetWindowTaskbarRect() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::SetWindowTaskbarRect; }
    static i32 static_message_id() { return (int)MessageID::SetWindowTaskbarRect; }
    virtual const char* message_name() const override { return "WindowManagerServer::SetWindowTaskbarRect"; }

    static OwnPtr<SetWindowTaskbarRect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        Gfx::IntRect rect = {};
        if (decoder.decode(rect).is_error())
            return {};

        return make<SetWindowTaskbarRect>(move(client_id), move(window_id), move(rect));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWindowTaskbarRect;

        stream << m_client_id;

        stream << m_window_id;

        stream << m_rect;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const Gfx::IntRect& rect() const { return m_rect; }
    Gfx::IntRect take_rect() { return move(m_rect); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

    i32 m_window_id {};

    Gfx::IntRect m_rect {};

};

class SetAppletAreaPosition final : public IPC::Message {
public:

    SetAppletAreaPosition(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetAppletAreaPosition(SetAppletAreaPosition const&) = default;
    SetAppletAreaPosition(SetAppletAreaPosition&&) = default;
    SetAppletAreaPosition& operator=(SetAppletAreaPosition const&) = default;
    SetAppletAreaPosition(Gfx::IntPoint position) : m_position(move(position)) {}
    virtual ~SetAppletAreaPosition() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::SetAppletAreaPosition; }
    static i32 static_message_id() { return (int)MessageID::SetAppletAreaPosition; }
    virtual const char* message_name() const override { return "WindowManagerServer::SetAppletAreaPosition"; }

    static OwnPtr<SetAppletAreaPosition> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::IntPoint position = {};
        if (decoder.decode(position).is_error())
            return {};

        return make<SetAppletAreaPosition>(move(position));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetAppletAreaPosition;

        stream << m_position;

        return buffer;
    }

    const Gfx::IntPoint& position() const { return m_position; }
    Gfx::IntPoint take_position() { return move(m_position); }

private:
    bool m_ipc_message_valid { true };

    Gfx::IntPoint m_position {};

};

class SetWorkspace final : public IPC::Message {
public:

    SetWorkspace(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetWorkspace(SetWorkspace const&) = default;
    SetWorkspace(SetWorkspace&&) = default;
    SetWorkspace& operator=(SetWorkspace const&) = default;
    SetWorkspace(u32 row, u32 column) : m_row(move(row)), m_column(move(column)) {}
    virtual ~SetWorkspace() override {}

    virtual u32 endpoint_magic() const override { return 471012077; }
    virtual i32 message_id() const override { return (int)MessageID::SetWorkspace; }
    static i32 static_message_id() { return (int)MessageID::SetWorkspace; }
    virtual const char* message_name() const override { return "WindowManagerServer::SetWorkspace"; }

    static OwnPtr<SetWorkspace> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 row = {};
        if (decoder.decode(row).is_error())
            return {};

        u32 column = {};
        if (decoder.decode(column).is_error())
            return {};

        return make<SetWorkspace>(move(row), move(column));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetWorkspace;

        stream << m_row;

        stream << m_column;

        return buffer;
    }

    const u32& row() const { return m_row; }
    u32 take_row() { return move(m_row); }

    const u32& column() const { return m_column; }
    u32 take_column() { return move(m_column); }

private:
    bool m_ipc_message_valid { true };

    u32 m_row {};

    u32 m_column {};

};

} // namespace Messages::WindowManagerServer

template<typename LocalEndpoint, typename PeerEndpoint>
class WindowManagerServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    WindowManagerServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_set_event_mask(
u32 event_mask) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::SetEventMask { event_mask });

    }

    void async_set_manager_window(
i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::SetManagerWindow { window_id });

    }

    void async_set_active_window(
i32 client_id, i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::SetActiveWindow { client_id, window_id });

    }

    void async_set_window_minimized(
i32 client_id, i32 window_id, bool minimized) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::SetWindowMinimized { client_id, window_id, minimized });

    }

    void async_toggle_show_desktop(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::ToggleShowDesktop {  });

    }

    void async_start_window_resize(
i32 client_id, i32 window_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::StartWindowResize { client_id, window_id });

    }

    void async_popup_window_menu(
i32 client_id, i32 window_id, Gfx::IntPoint screen_position) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::PopupWindowMenu { client_id, window_id, move(screen_position) });

    }

    void async_set_window_taskbar_rect(
i32 client_id, i32 window_id, Gfx::IntRect rect) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::SetWindowTaskbarRect { client_id, window_id, move(rect) });

    }

    void async_set_applet_area_position(
Gfx::IntPoint position) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::SetAppletAreaPosition { move(position) });

    }

    void async_set_workspace(
u32 row, u32 column) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WindowManagerServer::SetWorkspace { row, column });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class WindowManagerServerProxy;
class WindowManagerServerStub;

class WindowManagerServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = WindowManagerServerProxy<LocalEndpoint, WindowManagerServerEndpoint>;
    using Stub = WindowManagerServerStub;

    static u32 static_magic() { return 471012077; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 471012077) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::WindowManagerServer::MessageID::SetEventMask:
            message = Messages::WindowManagerServer::SetEventMask::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::SetManagerWindow:
            message = Messages::WindowManagerServer::SetManagerWindow::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::SetActiveWindow:
            message = Messages::WindowManagerServer::SetActiveWindow::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::SetWindowMinimized:
            message = Messages::WindowManagerServer::SetWindowMinimized::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::ToggleShowDesktop:
            message = Messages::WindowManagerServer::ToggleShowDesktop::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::StartWindowResize:
            message = Messages::WindowManagerServer::StartWindowResize::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::PopupWindowMenu:
            message = Messages::WindowManagerServer::PopupWindowMenu::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::SetWindowTaskbarRect:
            message = Messages::WindowManagerServer::SetWindowTaskbarRect::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::SetAppletAreaPosition:
            message = Messages::WindowManagerServer::SetAppletAreaPosition::decode(stream, socket);
            break;

        case (int)Messages::WindowManagerServer::MessageID::SetWorkspace:
            message = Messages::WindowManagerServer::SetWorkspace::decode(stream, socket);
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

class WindowManagerServerStub : public IPC::Stub {
public:
    WindowManagerServerStub() { }
    virtual ~WindowManagerServerStub() override { }

    virtual u32 magic() const override { return 471012077; }
    virtual String name() const override { return "WindowManagerServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::WindowManagerServer::MessageID::SetEventMask: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::SetEventMask&>(message);
            set_event_mask(request.event_mask());
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::SetManagerWindow: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::SetManagerWindow&>(message);
            set_manager_window(request.window_id());
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::SetActiveWindow: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::SetActiveWindow&>(message);
            set_active_window(request.client_id(), request.window_id());
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::SetWindowMinimized: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::SetWindowMinimized&>(message);
            set_window_minimized(request.client_id(), request.window_id(), request.minimized());
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::ToggleShowDesktop: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::ToggleShowDesktop&>(message);
            toggle_show_desktop();
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::StartWindowResize: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::StartWindowResize&>(message);
            start_window_resize(request.client_id(), request.window_id());
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::PopupWindowMenu: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::PopupWindowMenu&>(message);
            popup_window_menu(request.client_id(), request.window_id(), request.screen_position());
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::SetWindowTaskbarRect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::SetWindowTaskbarRect&>(message);
            set_window_taskbar_rect(request.client_id(), request.window_id(), request.rect());
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::SetAppletAreaPosition: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::SetAppletAreaPosition&>(message);
            set_applet_area_position(request.position());
            return {};

        }

        case (int)Messages::WindowManagerServer::MessageID::SetWorkspace: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WindowManagerServer::SetWorkspace&>(message);
            set_workspace(request.row(), request.column());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void set_event_mask(
[[maybe_unused]] u32 event_mask) = 0;

    virtual void set_manager_window(
[[maybe_unused]] i32 window_id) = 0;

    virtual void set_active_window(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id) = 0;

    virtual void set_window_minimized(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] bool minimized) = 0;

    virtual void toggle_show_desktop(
) = 0;

    virtual void start_window_resize(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id) = 0;

    virtual void popup_window_menu(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntPoint const& screen_position) = 0;

    virtual void set_window_taskbar_rect(
[[maybe_unused]] i32 client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] Gfx::IntRect const& rect) = 0;

    virtual void set_applet_area_position(
[[maybe_unused]] Gfx::IntPoint const& position) = 0;

    virtual void set_workspace(
[[maybe_unused]] u32 row, [[maybe_unused]] u32 column) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

