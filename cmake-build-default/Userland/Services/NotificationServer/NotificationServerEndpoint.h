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

namespace Messages::NotificationServer {

enum class MessageID : i32 {
    ShowNotification = 1,
    ShowNotificationResponse = 2,
    UpdateNotificationText = 3,
    UpdateNotificationTextResponse = 4,
    UpdateNotificationIcon = 5,
    UpdateNotificationIconResponse = 6,
    IsShowing = 7,
    IsShowingResponse = 8,
    CloseNotification = 9,
    CloseNotificationResponse = 10,
};

class ShowNotificationResponse final : public IPC::Message {
public:

    ShowNotificationResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ShowNotificationResponse(ShowNotificationResponse const&) = default;
    ShowNotificationResponse(ShowNotificationResponse&&) = default;
    ShowNotificationResponse& operator=(ShowNotificationResponse const&) = default;
    ShowNotificationResponse() {}
    virtual ~ShowNotificationResponse() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::ShowNotificationResponse; }
    static i32 static_message_id() { return (int)MessageID::ShowNotificationResponse; }
    virtual const char* message_name() const override { return "NotificationServer::ShowNotificationResponse"; }

    static OwnPtr<ShowNotificationResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<ShowNotificationResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ShowNotificationResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class ShowNotification final : public IPC::Message {
public:

   typedef class ShowNotificationResponse ResponseType;

    ShowNotification(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ShowNotification(ShowNotification const&) = default;
    ShowNotification(ShowNotification&&) = default;
    ShowNotification& operator=(ShowNotification const&) = default;
    ShowNotification(String text, String title, Gfx::ShareableBitmap icon) : m_text(move(text)), m_title(move(title)), m_icon(move(icon)) {}
    virtual ~ShowNotification() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::ShowNotification; }
    static i32 static_message_id() { return (int)MessageID::ShowNotification; }
    virtual const char* message_name() const override { return "NotificationServer::ShowNotification"; }

    static OwnPtr<ShowNotification> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String text = {};
        if (decoder.decode(text).is_error())
            return {};

        if (!Utf8View(text).validate())
            return {};

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        if (!Utf8View(title).validate())
            return {};

        Gfx::ShareableBitmap icon = {};
        if (decoder.decode(icon).is_error())
            return {};

        return make<ShowNotification>(move(text), move(title), move(icon));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ShowNotification;

        stream << m_text;

        stream << m_title;

        stream << m_icon;

        return buffer;
    }

    const String& text() const { return m_text; }
    String take_text() { return move(m_text); }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

    const Gfx::ShareableBitmap& icon() const { return m_icon; }
    Gfx::ShareableBitmap take_icon() { return move(m_icon); }

private:
    bool m_ipc_message_valid { true };

    String m_text {};

    String m_title {};

    Gfx::ShareableBitmap m_icon {};

};

class UpdateNotificationTextResponse final : public IPC::Message {
public:

    UpdateNotificationTextResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateNotificationTextResponse(UpdateNotificationTextResponse const&) = default;
    UpdateNotificationTextResponse(UpdateNotificationTextResponse&&) = default;
    UpdateNotificationTextResponse& operator=(UpdateNotificationTextResponse const&) = default;
    UpdateNotificationTextResponse(bool still_showing) : m_still_showing(move(still_showing)) {}
    virtual ~UpdateNotificationTextResponse() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateNotificationTextResponse; }
    static i32 static_message_id() { return (int)MessageID::UpdateNotificationTextResponse; }
    virtual const char* message_name() const override { return "NotificationServer::UpdateNotificationTextResponse"; }

    static OwnPtr<UpdateNotificationTextResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool still_showing = false;
        if (decoder.decode(still_showing).is_error())
            return {};

        return make<UpdateNotificationTextResponse>(move(still_showing));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateNotificationTextResponse;

        stream << m_still_showing;

        return buffer;
    }

    const bool& still_showing() const { return m_still_showing; }
    bool take_still_showing() { return move(m_still_showing); }

private:
    bool m_ipc_message_valid { true };

    bool m_still_showing {};

};

class UpdateNotificationText final : public IPC::Message {
public:

   typedef class UpdateNotificationTextResponse ResponseType;

    UpdateNotificationText(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateNotificationText(UpdateNotificationText const&) = default;
    UpdateNotificationText(UpdateNotificationText&&) = default;
    UpdateNotificationText& operator=(UpdateNotificationText const&) = default;
    UpdateNotificationText(String text, String title) : m_text(move(text)), m_title(move(title)) {}
    virtual ~UpdateNotificationText() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateNotificationText; }
    static i32 static_message_id() { return (int)MessageID::UpdateNotificationText; }
    virtual const char* message_name() const override { return "NotificationServer::UpdateNotificationText"; }

    static OwnPtr<UpdateNotificationText> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String text = {};
        if (decoder.decode(text).is_error())
            return {};

        if (!Utf8View(text).validate())
            return {};

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        if (!Utf8View(title).validate())
            return {};

        return make<UpdateNotificationText>(move(text), move(title));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateNotificationText;

        stream << m_text;

        stream << m_title;

        return buffer;
    }

    const String& text() const { return m_text; }
    String take_text() { return move(m_text); }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

private:
    bool m_ipc_message_valid { true };

    String m_text {};

    String m_title {};

};

class UpdateNotificationIconResponse final : public IPC::Message {
public:

    UpdateNotificationIconResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateNotificationIconResponse(UpdateNotificationIconResponse const&) = default;
    UpdateNotificationIconResponse(UpdateNotificationIconResponse&&) = default;
    UpdateNotificationIconResponse& operator=(UpdateNotificationIconResponse const&) = default;
    UpdateNotificationIconResponse(bool still_showing) : m_still_showing(move(still_showing)) {}
    virtual ~UpdateNotificationIconResponse() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateNotificationIconResponse; }
    static i32 static_message_id() { return (int)MessageID::UpdateNotificationIconResponse; }
    virtual const char* message_name() const override { return "NotificationServer::UpdateNotificationIconResponse"; }

    static OwnPtr<UpdateNotificationIconResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool still_showing = false;
        if (decoder.decode(still_showing).is_error())
            return {};

        return make<UpdateNotificationIconResponse>(move(still_showing));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateNotificationIconResponse;

        stream << m_still_showing;

        return buffer;
    }

    const bool& still_showing() const { return m_still_showing; }
    bool take_still_showing() { return move(m_still_showing); }

private:
    bool m_ipc_message_valid { true };

    bool m_still_showing {};

};

class UpdateNotificationIcon final : public IPC::Message {
public:

   typedef class UpdateNotificationIconResponse ResponseType;

    UpdateNotificationIcon(decltype(nullptr)) : m_ipc_message_valid(false) { }
    UpdateNotificationIcon(UpdateNotificationIcon const&) = default;
    UpdateNotificationIcon(UpdateNotificationIcon&&) = default;
    UpdateNotificationIcon& operator=(UpdateNotificationIcon const&) = default;
    UpdateNotificationIcon(Gfx::ShareableBitmap icon) : m_icon(move(icon)) {}
    virtual ~UpdateNotificationIcon() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::UpdateNotificationIcon; }
    static i32 static_message_id() { return (int)MessageID::UpdateNotificationIcon; }
    virtual const char* message_name() const override { return "NotificationServer::UpdateNotificationIcon"; }

    static OwnPtr<UpdateNotificationIcon> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Gfx::ShareableBitmap icon = {};
        if (decoder.decode(icon).is_error())
            return {};

        return make<UpdateNotificationIcon>(move(icon));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::UpdateNotificationIcon;

        stream << m_icon;

        return buffer;
    }

    const Gfx::ShareableBitmap& icon() const { return m_icon; }
    Gfx::ShareableBitmap take_icon() { return move(m_icon); }

private:
    bool m_ipc_message_valid { true };

    Gfx::ShareableBitmap m_icon {};

};

class IsShowingResponse final : public IPC::Message {
public:

    IsShowingResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsShowingResponse(IsShowingResponse const&) = default;
    IsShowingResponse(IsShowingResponse&&) = default;
    IsShowingResponse& operator=(IsShowingResponse const&) = default;
    IsShowingResponse(bool still_showing) : m_still_showing(move(still_showing)) {}
    virtual ~IsShowingResponse() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::IsShowingResponse; }
    static i32 static_message_id() { return (int)MessageID::IsShowingResponse; }
    virtual const char* message_name() const override { return "NotificationServer::IsShowingResponse"; }

    static OwnPtr<IsShowingResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool still_showing = false;
        if (decoder.decode(still_showing).is_error())
            return {};

        return make<IsShowingResponse>(move(still_showing));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsShowingResponse;

        stream << m_still_showing;

        return buffer;
    }

    const bool& still_showing() const { return m_still_showing; }
    bool take_still_showing() { return move(m_still_showing); }

private:
    bool m_ipc_message_valid { true };

    bool m_still_showing {};

};

class IsShowing final : public IPC::Message {
public:

   typedef class IsShowingResponse ResponseType;

    IsShowing(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsShowing(IsShowing const&) = default;
    IsShowing(IsShowing&&) = default;
    IsShowing& operator=(IsShowing const&) = default;
    IsShowing() {}
    virtual ~IsShowing() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::IsShowing; }
    static i32 static_message_id() { return (int)MessageID::IsShowing; }
    virtual const char* message_name() const override { return "NotificationServer::IsShowing"; }

    static OwnPtr<IsShowing> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<IsShowing>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsShowing;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class CloseNotificationResponse final : public IPC::Message {
public:

    CloseNotificationResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    CloseNotificationResponse(CloseNotificationResponse const&) = default;
    CloseNotificationResponse(CloseNotificationResponse&&) = default;
    CloseNotificationResponse& operator=(CloseNotificationResponse const&) = default;
    CloseNotificationResponse() {}
    virtual ~CloseNotificationResponse() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::CloseNotificationResponse; }
    static i32 static_message_id() { return (int)MessageID::CloseNotificationResponse; }
    virtual const char* message_name() const override { return "NotificationServer::CloseNotificationResponse"; }

    static OwnPtr<CloseNotificationResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<CloseNotificationResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::CloseNotificationResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class CloseNotification final : public IPC::Message {
public:

   typedef class CloseNotificationResponse ResponseType;

    CloseNotification(decltype(nullptr)) : m_ipc_message_valid(false) { }
    CloseNotification(CloseNotification const&) = default;
    CloseNotification(CloseNotification&&) = default;
    CloseNotification& operator=(CloseNotification const&) = default;
    CloseNotification() {}
    virtual ~CloseNotification() override {}

    virtual u32 endpoint_magic() const override { return 2714249765; }
    virtual i32 message_id() const override { return (int)MessageID::CloseNotification; }
    static i32 static_message_id() { return (int)MessageID::CloseNotification; }
    virtual const char* message_name() const override { return "NotificationServer::CloseNotification"; }

    static OwnPtr<CloseNotification> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<CloseNotification>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::CloseNotification;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

} // namespace Messages::NotificationServer

template<typename LocalEndpoint, typename PeerEndpoint>
class NotificationServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    NotificationServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void show_notification(
String text, String title, Gfx::ShareableBitmap icon) {
        (void) m_connection.template send_sync<Messages::NotificationServer::ShowNotification>(move(text), move(title), move(icon));
    }

    void async_show_notification(
String text, String title, Gfx::ShareableBitmap icon) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::NotificationServer::ShowNotification { move(text), move(title), move(icon) });

    }

    IPC::IPCErrorOr<void> try_show_notification(
String text, String title, Gfx::ShareableBitmap icon) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::NotificationServer::ShowNotification>(move(text), move(title), move(icon));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    bool update_notification_text(
String text, String title) {
        return m_connection.template send_sync<Messages::NotificationServer::UpdateNotificationText>(move(text), move(title))->take_still_showing();
    }

    void async_update_notification_text(
String text, String title) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::NotificationServer::UpdateNotificationText { move(text), move(title) });

    }

    IPC::IPCErrorOr<bool> try_update_notification_text(
String text, String title) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::NotificationServer::UpdateNotificationText>(move(text), move(title));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool update_notification_icon(
Gfx::ShareableBitmap icon) {
        return m_connection.template send_sync<Messages::NotificationServer::UpdateNotificationIcon>(move(icon))->take_still_showing();
    }

    void async_update_notification_icon(
Gfx::ShareableBitmap icon) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::NotificationServer::UpdateNotificationIcon { move(icon) });

    }

    IPC::IPCErrorOr<bool> try_update_notification_icon(
Gfx::ShareableBitmap icon) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::NotificationServer::UpdateNotificationIcon>(move(icon));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool is_showing(
) {
        return m_connection.template send_sync<Messages::NotificationServer::IsShowing>()->take_still_showing();
    }

    void async_is_showing(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::NotificationServer::IsShowing {  });

    }

    IPC::IPCErrorOr<bool> try_is_showing(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::NotificationServer::IsShowing>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void close_notification(
) {
        (void) m_connection.template send_sync<Messages::NotificationServer::CloseNotification>();
    }

    void async_close_notification(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::NotificationServer::CloseNotification {  });

    }

    IPC::IPCErrorOr<void> try_close_notification(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::NotificationServer::CloseNotification>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class NotificationServerProxy;
class NotificationServerStub;

class NotificationServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = NotificationServerProxy<LocalEndpoint, NotificationServerEndpoint>;
    using Stub = NotificationServerStub;

    static u32 static_magic() { return 2714249765; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 2714249765) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::NotificationServer::MessageID::ShowNotification:
            message = Messages::NotificationServer::ShowNotification::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::ShowNotificationResponse:
            message = Messages::NotificationServer::ShowNotificationResponse::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::UpdateNotificationText:
            message = Messages::NotificationServer::UpdateNotificationText::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::UpdateNotificationTextResponse:
            message = Messages::NotificationServer::UpdateNotificationTextResponse::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::UpdateNotificationIcon:
            message = Messages::NotificationServer::UpdateNotificationIcon::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::UpdateNotificationIconResponse:
            message = Messages::NotificationServer::UpdateNotificationIconResponse::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::IsShowing:
            message = Messages::NotificationServer::IsShowing::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::IsShowingResponse:
            message = Messages::NotificationServer::IsShowingResponse::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::CloseNotification:
            message = Messages::NotificationServer::CloseNotification::decode(stream, socket);
            break;

        case (int)Messages::NotificationServer::MessageID::CloseNotificationResponse:
            message = Messages::NotificationServer::CloseNotificationResponse::decode(stream, socket);
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

class NotificationServerStub : public IPC::Stub {
public:
    NotificationServerStub() { }
    virtual ~NotificationServerStub() override { }

    virtual u32 magic() const override { return 2714249765; }
    virtual String name() const override { return "NotificationServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::NotificationServer::MessageID::ShowNotification: {

            [[maybe_unused]] auto& request = static_cast<const Messages::NotificationServer::ShowNotification&>(message);
            show_notification(request.text(), request.title(), request.icon());
            auto response = Messages::NotificationServer::ShowNotificationResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::NotificationServer::MessageID::UpdateNotificationText: {

            [[maybe_unused]] auto& request = static_cast<const Messages::NotificationServer::UpdateNotificationText&>(message);
            auto response = update_notification_text(request.text(), request.title());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::NotificationServer::MessageID::UpdateNotificationIcon: {

            [[maybe_unused]] auto& request = static_cast<const Messages::NotificationServer::UpdateNotificationIcon&>(message);
            auto response = update_notification_icon(request.icon());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::NotificationServer::MessageID::IsShowing: {

            [[maybe_unused]] auto& request = static_cast<const Messages::NotificationServer::IsShowing&>(message);
            auto response = is_showing();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::NotificationServer::MessageID::CloseNotification: {

            [[maybe_unused]] auto& request = static_cast<const Messages::NotificationServer::CloseNotification&>(message);
            close_notification();
            auto response = Messages::NotificationServer::CloseNotificationResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        default:
            return {};
        }
    }

    virtual void show_notification(
[[maybe_unused]] String const& text, [[maybe_unused]] String const& title, [[maybe_unused]] Gfx::ShareableBitmap const& icon) = 0;

    virtual Messages::NotificationServer::UpdateNotificationTextResponse update_notification_text(
[[maybe_unused]] String const& text, [[maybe_unused]] String const& title) = 0;

    virtual Messages::NotificationServer::UpdateNotificationIconResponse update_notification_icon(
[[maybe_unused]] Gfx::ShareableBitmap const& icon) = 0;

    virtual Messages::NotificationServer::IsShowingResponse is_showing(
) = 0;

    virtual void close_notification(
) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

