#pragma once
#include <AK/URL.h>
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

namespace Messages::WebSocketServer {

enum class MessageID : i32 {
    Connect = 1,
    ConnectResponse = 2,
    ReadyState = 3,
    ReadyStateResponse = 4,
    Send = 5,
    Close = 6,
    SetCertificate = 7,
    SetCertificateResponse = 8,
};

class ConnectResponse final : public IPC::Message {
public:

    ConnectResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ConnectResponse(ConnectResponse const&) = default;
    ConnectResponse(ConnectResponse&&) = default;
    ConnectResponse& operator=(ConnectResponse const&) = default;
    ConnectResponse(i32 connection_id) : m_connection_id(move(connection_id)) {}
    virtual ~ConnectResponse() override {}

    virtual u32 endpoint_magic() const override { return 1144104864; }
    virtual i32 message_id() const override { return (int)MessageID::ConnectResponse; }
    static i32 static_message_id() { return (int)MessageID::ConnectResponse; }
    virtual const char* message_name() const override { return "WebSocketServer::ConnectResponse"; }

    static OwnPtr<ConnectResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        return make<ConnectResponse>(move(connection_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ConnectResponse;

        stream << m_connection_id;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

};

class Connect final : public IPC::Message {
public:

   typedef class ConnectResponse ResponseType;

    Connect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Connect(Connect const&) = default;
    Connect(Connect&&) = default;
    Connect& operator=(Connect const&) = default;
    Connect(URL url, String origin, Vector<String> protocols, Vector<String> extensions, IPC::Dictionary additional_request_headers) : m_url(move(url)), m_origin(move(origin)), m_protocols(move(protocols)), m_extensions(move(extensions)), m_additional_request_headers(move(additional_request_headers)) {}
    virtual ~Connect() override {}

    virtual u32 endpoint_magic() const override { return 1144104864; }
    virtual i32 message_id() const override { return (int)MessageID::Connect; }
    static i32 static_message_id() { return (int)MessageID::Connect; }
    virtual const char* message_name() const override { return "WebSocketServer::Connect"; }

    static OwnPtr<Connect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        String origin = {};
        if (decoder.decode(origin).is_error())
            return {};

        Vector<String> protocols = {};
        if (decoder.decode(protocols).is_error())
            return {};

        Vector<String> extensions = {};
        if (decoder.decode(extensions).is_error())
            return {};

        IPC::Dictionary additional_request_headers = {};
        if (decoder.decode(additional_request_headers).is_error())
            return {};

        return make<Connect>(move(url), move(origin), move(protocols), move(extensions), move(additional_request_headers));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Connect;

        stream << m_url;

        stream << m_origin;

        stream << m_protocols;

        stream << m_extensions;

        stream << m_additional_request_headers;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const String& origin() const { return m_origin; }
    String take_origin() { return move(m_origin); }

    const Vector<String>& protocols() const { return m_protocols; }
    Vector<String> take_protocols() { return move(m_protocols); }

    const Vector<String>& extensions() const { return m_extensions; }
    Vector<String> take_extensions() { return move(m_extensions); }

    const IPC::Dictionary& additional_request_headers() const { return m_additional_request_headers; }
    IPC::Dictionary take_additional_request_headers() { return move(m_additional_request_headers); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

    String m_origin {};

    Vector<String> m_protocols {};

    Vector<String> m_extensions {};

    IPC::Dictionary m_additional_request_headers {};

};

class ReadyStateResponse final : public IPC::Message {
public:

    ReadyStateResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ReadyStateResponse(ReadyStateResponse const&) = default;
    ReadyStateResponse(ReadyStateResponse&&) = default;
    ReadyStateResponse& operator=(ReadyStateResponse const&) = default;
    ReadyStateResponse(u32 ready_state) : m_ready_state(move(ready_state)) {}
    virtual ~ReadyStateResponse() override {}

    virtual u32 endpoint_magic() const override { return 1144104864; }
    virtual i32 message_id() const override { return (int)MessageID::ReadyStateResponse; }
    static i32 static_message_id() { return (int)MessageID::ReadyStateResponse; }
    virtual const char* message_name() const override { return "WebSocketServer::ReadyStateResponse"; }

    static OwnPtr<ReadyStateResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        u32 ready_state = {};
        if (decoder.decode(ready_state).is_error())
            return {};

        return make<ReadyStateResponse>(move(ready_state));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ReadyStateResponse;

        stream << m_ready_state;

        return buffer;
    }

    const u32& ready_state() const { return m_ready_state; }
    u32 take_ready_state() { return move(m_ready_state); }

private:
    bool m_ipc_message_valid { true };

    u32 m_ready_state {};

};

class ReadyState final : public IPC::Message {
public:

   typedef class ReadyStateResponse ResponseType;

    ReadyState(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ReadyState(ReadyState const&) = default;
    ReadyState(ReadyState&&) = default;
    ReadyState& operator=(ReadyState const&) = default;
    ReadyState(i32 connection_id) : m_connection_id(move(connection_id)) {}
    virtual ~ReadyState() override {}

    virtual u32 endpoint_magic() const override { return 1144104864; }
    virtual i32 message_id() const override { return (int)MessageID::ReadyState; }
    static i32 static_message_id() { return (int)MessageID::ReadyState; }
    virtual const char* message_name() const override { return "WebSocketServer::ReadyState"; }

    static OwnPtr<ReadyState> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        return make<ReadyState>(move(connection_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ReadyState;

        stream << m_connection_id;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

};

class Send final : public IPC::Message {
public:

    Send(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Send(Send const&) = default;
    Send(Send&&) = default;
    Send& operator=(Send const&) = default;
    Send(i32 connection_id, bool is_text, ByteBuffer data) : m_connection_id(move(connection_id)), m_is_text(move(is_text)), m_data(move(data)) {}
    virtual ~Send() override {}

    virtual u32 endpoint_magic() const override { return 1144104864; }
    virtual i32 message_id() const override { return (int)MessageID::Send; }
    static i32 static_message_id() { return (int)MessageID::Send; }
    virtual const char* message_name() const override { return "WebSocketServer::Send"; }

    static OwnPtr<Send> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        bool is_text = false;
        if (decoder.decode(is_text).is_error())
            return {};

        ByteBuffer data = {};
        if (decoder.decode(data).is_error())
            return {};

        return make<Send>(move(connection_id), move(is_text), move(data));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Send;

        stream << m_connection_id;

        stream << m_is_text;

        stream << m_data;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

    const bool& is_text() const { return m_is_text; }
    bool take_is_text() { return move(m_is_text); }

    const ByteBuffer& data() const { return m_data; }
    ByteBuffer take_data() { return move(m_data); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

    bool m_is_text {};

    ByteBuffer m_data {};

};

class Close final : public IPC::Message {
public:

    Close(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Close(Close const&) = default;
    Close(Close&&) = default;
    Close& operator=(Close const&) = default;
    Close(i32 connection_id, u16 code, String reason) : m_connection_id(move(connection_id)), m_code(move(code)), m_reason(move(reason)) {}
    virtual ~Close() override {}

    virtual u32 endpoint_magic() const override { return 1144104864; }
    virtual i32 message_id() const override { return (int)MessageID::Close; }
    static i32 static_message_id() { return (int)MessageID::Close; }
    virtual const char* message_name() const override { return "WebSocketServer::Close"; }

    static OwnPtr<Close> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        u16 code = {};
        if (decoder.decode(code).is_error())
            return {};

        String reason = {};
        if (decoder.decode(reason).is_error())
            return {};

        return make<Close>(move(connection_id), move(code), move(reason));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Close;

        stream << m_connection_id;

        stream << m_code;

        stream << m_reason;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

    const u16& code() const { return m_code; }
    u16 take_code() { return move(m_code); }

    const String& reason() const { return m_reason; }
    String take_reason() { return move(m_reason); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

    u16 m_code {};

    String m_reason {};

};

class SetCertificateResponse final : public IPC::Message {
public:

    SetCertificateResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetCertificateResponse(SetCertificateResponse const&) = default;
    SetCertificateResponse(SetCertificateResponse&&) = default;
    SetCertificateResponse& operator=(SetCertificateResponse const&) = default;
    SetCertificateResponse(bool success) : m_success(move(success)) {}
    virtual ~SetCertificateResponse() override {}

    virtual u32 endpoint_magic() const override { return 1144104864; }
    virtual i32 message_id() const override { return (int)MessageID::SetCertificateResponse; }
    static i32 static_message_id() { return (int)MessageID::SetCertificateResponse; }
    virtual const char* message_name() const override { return "WebSocketServer::SetCertificateResponse"; }

    static OwnPtr<SetCertificateResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        return make<SetCertificateResponse>(move(success));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetCertificateResponse;

        stream << m_success;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

};

class SetCertificate final : public IPC::Message {
public:

   typedef class SetCertificateResponse ResponseType;

    SetCertificate(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetCertificate(SetCertificate const&) = default;
    SetCertificate(SetCertificate&&) = default;
    SetCertificate& operator=(SetCertificate const&) = default;
    SetCertificate(i32 connection_id, String certificate, String key) : m_connection_id(move(connection_id)), m_certificate(move(certificate)), m_key(move(key)) {}
    virtual ~SetCertificate() override {}

    virtual u32 endpoint_magic() const override { return 1144104864; }
    virtual i32 message_id() const override { return (int)MessageID::SetCertificate; }
    static i32 static_message_id() { return (int)MessageID::SetCertificate; }
    virtual const char* message_name() const override { return "WebSocketServer::SetCertificate"; }

    static OwnPtr<SetCertificate> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        String certificate = {};
        if (decoder.decode(certificate).is_error())
            return {};

        String key = {};
        if (decoder.decode(key).is_error())
            return {};

        return make<SetCertificate>(move(connection_id), move(certificate), move(key));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetCertificate;

        stream << m_connection_id;

        stream << m_certificate;

        stream << m_key;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

    const String& certificate() const { return m_certificate; }
    String take_certificate() { return move(m_certificate); }

    const String& key() const { return m_key; }
    String take_key() { return move(m_key); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

    String m_certificate {};

    String m_key {};

};

} // namespace Messages::WebSocketServer

template<typename LocalEndpoint, typename PeerEndpoint>
class WebSocketServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    WebSocketServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    i32 connect(
URL url, String origin, Vector<String> protocols, Vector<String> extensions, IPC::Dictionary additional_request_headers) {
        return m_connection.template send_sync<Messages::WebSocketServer::Connect>(move(url), move(origin), move(protocols), move(extensions), move(additional_request_headers))->take_connection_id();
    }

    void async_connect(
URL url, String origin, Vector<String> protocols, Vector<String> extensions, IPC::Dictionary additional_request_headers) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketServer::Connect { move(url), move(origin), move(protocols), move(extensions), move(additional_request_headers) });

    }

    IPC::IPCErrorOr<i32> try_connect(
URL url, String origin, Vector<String> protocols, Vector<String> extensions, IPC::Dictionary additional_request_headers) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebSocketServer::Connect>(move(url), move(origin), move(protocols), move(extensions), move(additional_request_headers));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    u32 ready_state(
i32 connection_id) {
        return m_connection.template send_sync<Messages::WebSocketServer::ReadyState>(connection_id)->take_ready_state();
    }

    void async_ready_state(
i32 connection_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketServer::ReadyState { connection_id });

    }

    IPC::IPCErrorOr<u32> try_ready_state(
i32 connection_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebSocketServer::ReadyState>(connection_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_send(
i32 connection_id, bool is_text, ByteBuffer data) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketServer::Send { connection_id, is_text, move(data) });

    }

    void async_close(
i32 connection_id, u16 code, String reason) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketServer::Close { connection_id, code, move(reason) });

    }

    bool set_certificate(
i32 connection_id, String certificate, String key) {
        return m_connection.template send_sync<Messages::WebSocketServer::SetCertificate>(connection_id, move(certificate), move(key))->take_success();
    }

    void async_set_certificate(
i32 connection_id, String certificate, String key) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketServer::SetCertificate { connection_id, move(certificate), move(key) });

    }

    IPC::IPCErrorOr<bool> try_set_certificate(
i32 connection_id, String certificate, String key) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::WebSocketServer::SetCertificate>(connection_id, move(certificate), move(key));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class WebSocketServerProxy;
class WebSocketServerStub;

class WebSocketServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = WebSocketServerProxy<LocalEndpoint, WebSocketServerEndpoint>;
    using Stub = WebSocketServerStub;

    static u32 static_magic() { return 1144104864; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 1144104864) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::WebSocketServer::MessageID::Connect:
            message = Messages::WebSocketServer::Connect::decode(stream, socket);
            break;

        case (int)Messages::WebSocketServer::MessageID::ConnectResponse:
            message = Messages::WebSocketServer::ConnectResponse::decode(stream, socket);
            break;

        case (int)Messages::WebSocketServer::MessageID::ReadyState:
            message = Messages::WebSocketServer::ReadyState::decode(stream, socket);
            break;

        case (int)Messages::WebSocketServer::MessageID::ReadyStateResponse:
            message = Messages::WebSocketServer::ReadyStateResponse::decode(stream, socket);
            break;

        case (int)Messages::WebSocketServer::MessageID::Send:
            message = Messages::WebSocketServer::Send::decode(stream, socket);
            break;

        case (int)Messages::WebSocketServer::MessageID::Close:
            message = Messages::WebSocketServer::Close::decode(stream, socket);
            break;

        case (int)Messages::WebSocketServer::MessageID::SetCertificate:
            message = Messages::WebSocketServer::SetCertificate::decode(stream, socket);
            break;

        case (int)Messages::WebSocketServer::MessageID::SetCertificateResponse:
            message = Messages::WebSocketServer::SetCertificateResponse::decode(stream, socket);
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

class WebSocketServerStub : public IPC::Stub {
public:
    WebSocketServerStub() { }
    virtual ~WebSocketServerStub() override { }

    virtual u32 magic() const override { return 1144104864; }
    virtual String name() const override { return "WebSocketServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::WebSocketServer::MessageID::Connect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketServer::Connect&>(message);
            auto response = connect(request.url(), request.origin(), request.protocols(), request.extensions(), request.additional_request_headers());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebSocketServer::MessageID::ReadyState: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketServer::ReadyState&>(message);
            auto response = ready_state(request.connection_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::WebSocketServer::MessageID::Send: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketServer::Send&>(message);
            send(request.connection_id(), request.is_text(), request.data());
            return {};

        }

        case (int)Messages::WebSocketServer::MessageID::Close: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketServer::Close&>(message);
            close(request.connection_id(), request.code(), request.reason());
            return {};

        }

        case (int)Messages::WebSocketServer::MessageID::SetCertificate: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketServer::SetCertificate&>(message);
            auto response = set_certificate(request.connection_id(), request.certificate(), request.key());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        default:
            return {};
        }
    }

    virtual Messages::WebSocketServer::ConnectResponse connect(
[[maybe_unused]] URL const& url, [[maybe_unused]] String const& origin, [[maybe_unused]] Vector<String> const& protocols, [[maybe_unused]] Vector<String> const& extensions, [[maybe_unused]] IPC::Dictionary const& additional_request_headers) = 0;

    virtual Messages::WebSocketServer::ReadyStateResponse ready_state(
[[maybe_unused]] i32 connection_id) = 0;

    virtual void send(
[[maybe_unused]] i32 connection_id, [[maybe_unused]] bool is_text, [[maybe_unused]] ByteBuffer const& data) = 0;

    virtual void close(
[[maybe_unused]] i32 connection_id, [[maybe_unused]] u16 code, [[maybe_unused]] String const& reason) = 0;

    virtual Messages::WebSocketServer::SetCertificateResponse set_certificate(
[[maybe_unused]] i32 connection_id, [[maybe_unused]] String const& certificate, [[maybe_unused]] String const& key) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

