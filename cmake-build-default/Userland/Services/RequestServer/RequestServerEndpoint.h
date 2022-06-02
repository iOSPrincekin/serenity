#pragma once
#include <AK/URL.h>
#include <RequestServer/ConnectionCache.h>
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

namespace Messages::RequestServer {

enum class MessageID : i32 {
    IsSupportedProtocol = 1,
    IsSupportedProtocolResponse = 2,
    StartRequest = 3,
    StartRequestResponse = 4,
    StopRequest = 5,
    StopRequestResponse = 6,
    SetCertificate = 7,
    SetCertificateResponse = 8,
    EnsureConnection = 9,
};

class IsSupportedProtocolResponse final : public IPC::Message {
public:

    IsSupportedProtocolResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsSupportedProtocolResponse(IsSupportedProtocolResponse const&) = default;
    IsSupportedProtocolResponse(IsSupportedProtocolResponse&&) = default;
    IsSupportedProtocolResponse& operator=(IsSupportedProtocolResponse const&) = default;
    IsSupportedProtocolResponse(bool supported) : m_supported(move(supported)) {}
    virtual ~IsSupportedProtocolResponse() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::IsSupportedProtocolResponse; }
    static i32 static_message_id() { return (int)MessageID::IsSupportedProtocolResponse; }
    virtual const char* message_name() const override { return "RequestServer::IsSupportedProtocolResponse"; }

    static OwnPtr<IsSupportedProtocolResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool supported = false;
        if (decoder.decode(supported).is_error())
            return {};

        return make<IsSupportedProtocolResponse>(move(supported));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsSupportedProtocolResponse;

        stream << m_supported;

        return buffer;
    }

    const bool& supported() const { return m_supported; }
    bool take_supported() { return move(m_supported); }

private:
    bool m_ipc_message_valid { true };

    bool m_supported {};

};

class IsSupportedProtocol final : public IPC::Message {
public:

   typedef class IsSupportedProtocolResponse ResponseType;

    IsSupportedProtocol(decltype(nullptr)) : m_ipc_message_valid(false) { }
    IsSupportedProtocol(IsSupportedProtocol const&) = default;
    IsSupportedProtocol(IsSupportedProtocol&&) = default;
    IsSupportedProtocol& operator=(IsSupportedProtocol const&) = default;
    IsSupportedProtocol(String protocol) : m_protocol(move(protocol)) {}
    virtual ~IsSupportedProtocol() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::IsSupportedProtocol; }
    static i32 static_message_id() { return (int)MessageID::IsSupportedProtocol; }
    virtual const char* message_name() const override { return "RequestServer::IsSupportedProtocol"; }

    static OwnPtr<IsSupportedProtocol> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String protocol = {};
        if (decoder.decode(protocol).is_error())
            return {};

        return make<IsSupportedProtocol>(move(protocol));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::IsSupportedProtocol;

        stream << m_protocol;

        return buffer;
    }

    const String& protocol() const { return m_protocol; }
    String take_protocol() { return move(m_protocol); }

private:
    bool m_ipc_message_valid { true };

    String m_protocol {};

};

class StartRequestResponse final : public IPC::Message {
public:

    StartRequestResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StartRequestResponse(StartRequestResponse const&) = default;
    StartRequestResponse(StartRequestResponse&&) = default;
    StartRequestResponse& operator=(StartRequestResponse const&) = default;
    StartRequestResponse(i32 request_id, Optional<IPC::File> response_fd) : m_request_id(move(request_id)), m_response_fd(move(response_fd)) {}
    virtual ~StartRequestResponse() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::StartRequestResponse; }
    static i32 static_message_id() { return (int)MessageID::StartRequestResponse; }
    virtual const char* message_name() const override { return "RequestServer::StartRequestResponse"; }

    static OwnPtr<StartRequestResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 request_id = {};
        if (decoder.decode(request_id).is_error())
            return {};

        Optional<IPC::File> response_fd = {};
        if (decoder.decode(response_fd).is_error())
            return {};

        return make<StartRequestResponse>(move(request_id), move(response_fd));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StartRequestResponse;

        stream << m_request_id;

        stream << m_response_fd;

        return buffer;
    }

    const i32& request_id() const { return m_request_id; }
    i32 take_request_id() { return move(m_request_id); }

    const Optional<IPC::File>& response_fd() const { return m_response_fd; }
    Optional<IPC::File> take_response_fd() { return move(m_response_fd); }

private:
    bool m_ipc_message_valid { true };

    i32 m_request_id {};

    Optional<IPC::File> m_response_fd {};

};

class StartRequest final : public IPC::Message {
public:

   typedef class StartRequestResponse ResponseType;

    StartRequest(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StartRequest(StartRequest const&) = default;
    StartRequest(StartRequest&&) = default;
    StartRequest& operator=(StartRequest const&) = default;
    StartRequest(String method, URL url, IPC::Dictionary request_headers, ByteBuffer request_body, Core::ProxyData proxy_data) : m_method(move(method)), m_url(move(url)), m_request_headers(move(request_headers)), m_request_body(move(request_body)), m_proxy_data(move(proxy_data)) {}
    virtual ~StartRequest() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::StartRequest; }
    static i32 static_message_id() { return (int)MessageID::StartRequest; }
    virtual const char* message_name() const override { return "RequestServer::StartRequest"; }

    static OwnPtr<StartRequest> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String method = {};
        if (decoder.decode(method).is_error())
            return {};

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        IPC::Dictionary request_headers = {};
        if (decoder.decode(request_headers).is_error())
            return {};

        ByteBuffer request_body = {};
        if (decoder.decode(request_body).is_error())
            return {};

        Core::ProxyData proxy_data = {};
        if (decoder.decode(proxy_data).is_error())
            return {};

        return make<StartRequest>(move(method), move(url), move(request_headers), move(request_body), move(proxy_data));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StartRequest;

        stream << m_method;

        stream << m_url;

        stream << m_request_headers;

        stream << m_request_body;

        stream << m_proxy_data;

        return buffer;
    }

    const String& method() const { return m_method; }
    String take_method() { return move(m_method); }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const IPC::Dictionary& request_headers() const { return m_request_headers; }
    IPC::Dictionary take_request_headers() { return move(m_request_headers); }

    const ByteBuffer& request_body() const { return m_request_body; }
    ByteBuffer take_request_body() { return move(m_request_body); }

    const Core::ProxyData& proxy_data() const { return m_proxy_data; }
    Core::ProxyData take_proxy_data() { return move(m_proxy_data); }

private:
    bool m_ipc_message_valid { true };

    String m_method {};

    URL m_url {};

    IPC::Dictionary m_request_headers {};

    ByteBuffer m_request_body {};

    Core::ProxyData m_proxy_data {};

};

class StopRequestResponse final : public IPC::Message {
public:

    StopRequestResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StopRequestResponse(StopRequestResponse const&) = default;
    StopRequestResponse(StopRequestResponse&&) = default;
    StopRequestResponse& operator=(StopRequestResponse const&) = default;
    StopRequestResponse(bool success) : m_success(move(success)) {}
    virtual ~StopRequestResponse() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::StopRequestResponse; }
    static i32 static_message_id() { return (int)MessageID::StopRequestResponse; }
    virtual const char* message_name() const override { return "RequestServer::StopRequestResponse"; }

    static OwnPtr<StopRequestResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        return make<StopRequestResponse>(move(success));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StopRequestResponse;

        stream << m_success;

        return buffer;
    }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

private:
    bool m_ipc_message_valid { true };

    bool m_success {};

};

class StopRequest final : public IPC::Message {
public:

   typedef class StopRequestResponse ResponseType;

    StopRequest(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StopRequest(StopRequest const&) = default;
    StopRequest(StopRequest&&) = default;
    StopRequest& operator=(StopRequest const&) = default;
    StopRequest(i32 request_id) : m_request_id(move(request_id)) {}
    virtual ~StopRequest() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::StopRequest; }
    static i32 static_message_id() { return (int)MessageID::StopRequest; }
    virtual const char* message_name() const override { return "RequestServer::StopRequest"; }

    static OwnPtr<StopRequest> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 request_id = {};
        if (decoder.decode(request_id).is_error())
            return {};

        return make<StopRequest>(move(request_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StopRequest;

        stream << m_request_id;

        return buffer;
    }

    const i32& request_id() const { return m_request_id; }
    i32 take_request_id() { return move(m_request_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_request_id {};

};

class SetCertificateResponse final : public IPC::Message {
public:

    SetCertificateResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetCertificateResponse(SetCertificateResponse const&) = default;
    SetCertificateResponse(SetCertificateResponse&&) = default;
    SetCertificateResponse& operator=(SetCertificateResponse const&) = default;
    SetCertificateResponse(bool success) : m_success(move(success)) {}
    virtual ~SetCertificateResponse() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::SetCertificateResponse; }
    static i32 static_message_id() { return (int)MessageID::SetCertificateResponse; }
    virtual const char* message_name() const override { return "RequestServer::SetCertificateResponse"; }

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
    SetCertificate(i32 request_id, String certificate, String key) : m_request_id(move(request_id)), m_certificate(move(certificate)), m_key(move(key)) {}
    virtual ~SetCertificate() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::SetCertificate; }
    static i32 static_message_id() { return (int)MessageID::SetCertificate; }
    virtual const char* message_name() const override { return "RequestServer::SetCertificate"; }

    static OwnPtr<SetCertificate> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 request_id = {};
        if (decoder.decode(request_id).is_error())
            return {};

        String certificate = {};
        if (decoder.decode(certificate).is_error())
            return {};

        String key = {};
        if (decoder.decode(key).is_error())
            return {};

        return make<SetCertificate>(move(request_id), move(certificate), move(key));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetCertificate;

        stream << m_request_id;

        stream << m_certificate;

        stream << m_key;

        return buffer;
    }

    const i32& request_id() const { return m_request_id; }
    i32 take_request_id() { return move(m_request_id); }

    const String& certificate() const { return m_certificate; }
    String take_certificate() { return move(m_certificate); }

    const String& key() const { return m_key; }
    String take_key() { return move(m_key); }

private:
    bool m_ipc_message_valid { true };

    i32 m_request_id {};

    String m_certificate {};

    String m_key {};

};

class EnsureConnection final : public IPC::Message {
public:

    EnsureConnection(decltype(nullptr)) : m_ipc_message_valid(false) { }
    EnsureConnection(EnsureConnection const&) = default;
    EnsureConnection(EnsureConnection&&) = default;
    EnsureConnection& operator=(EnsureConnection const&) = default;
    EnsureConnection(URL url, ::RequestServer::CacheLevel cache_level) : m_url(move(url)), m_cache_level(move(cache_level)) {}
    virtual ~EnsureConnection() override {}

    virtual u32 endpoint_magic() const override { return 1270977860; }
    virtual i32 message_id() const override { return (int)MessageID::EnsureConnection; }
    static i32 static_message_id() { return (int)MessageID::EnsureConnection; }
    virtual const char* message_name() const override { return "RequestServer::EnsureConnection"; }

    static OwnPtr<EnsureConnection> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        ::RequestServer::CacheLevel cache_level = {};
        if (decoder.decode(cache_level).is_error())
            return {};

        return make<EnsureConnection>(move(url), move(cache_level));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::EnsureConnection;

        stream << m_url;

        stream << m_cache_level;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const ::RequestServer::CacheLevel& cache_level() const { return m_cache_level; }
    ::RequestServer::CacheLevel take_cache_level() { return move(m_cache_level); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

    ::RequestServer::CacheLevel m_cache_level {};

};

} // namespace Messages::RequestServer

template<typename LocalEndpoint, typename PeerEndpoint>
class RequestServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    RequestServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    bool is_supported_protocol(
String protocol) {
        return m_connection.template send_sync<Messages::RequestServer::IsSupportedProtocol>(move(protocol))->take_supported();
    }

    void async_is_supported_protocol(
String protocol) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestServer::IsSupportedProtocol { move(protocol) });

    }

    IPC::IPCErrorOr<bool> try_is_supported_protocol(
String protocol) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::RequestServer::IsSupportedProtocol>(move(protocol));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Messages::RequestServer::StartRequestResponse start_request(
String method, URL url, IPC::Dictionary request_headers, ByteBuffer request_body, Core::ProxyData proxy_data) {
        return move(*m_connection.template send_sync<Messages::RequestServer::StartRequest>(move(method), move(url), move(request_headers), move(request_body), move(proxy_data)));
    }

    void async_start_request(
String method, URL url, IPC::Dictionary request_headers, ByteBuffer request_body, Core::ProxyData proxy_data) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestServer::StartRequest { move(method), move(url), move(request_headers), move(request_body), move(proxy_data) });

    }

    IPC::IPCErrorOr<Messages::RequestServer::StartRequestResponse> try_start_request(
String method, URL url, IPC::Dictionary request_headers, ByteBuffer request_body, Core::ProxyData proxy_data) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::RequestServer::StartRequest>(move(method), move(url), move(request_headers), move(request_body), move(proxy_data));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool stop_request(
i32 request_id) {
        return m_connection.template send_sync<Messages::RequestServer::StopRequest>(request_id)->take_success();
    }

    void async_stop_request(
i32 request_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestServer::StopRequest { request_id });

    }

    IPC::IPCErrorOr<bool> try_stop_request(
i32 request_id) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::RequestServer::StopRequest>(request_id);
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    bool set_certificate(
i32 request_id, String certificate, String key) {
        return m_connection.template send_sync<Messages::RequestServer::SetCertificate>(request_id, move(certificate), move(key))->take_success();
    }

    void async_set_certificate(
i32 request_id, String certificate, String key) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestServer::SetCertificate { request_id, move(certificate), move(key) });

    }

    IPC::IPCErrorOr<bool> try_set_certificate(
i32 request_id, String certificate, String key) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::RequestServer::SetCertificate>(request_id, move(certificate), move(key));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_ensure_connection(
URL url, ::RequestServer::CacheLevel cache_level) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestServer::EnsureConnection { move(url), move(cache_level) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class RequestServerProxy;
class RequestServerStub;

class RequestServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = RequestServerProxy<LocalEndpoint, RequestServerEndpoint>;
    using Stub = RequestServerStub;

    static u32 static_magic() { return 1270977860; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 1270977860) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::RequestServer::MessageID::IsSupportedProtocol:
            message = Messages::RequestServer::IsSupportedProtocol::decode(stream, socket);
            break;

        case (int)Messages::RequestServer::MessageID::IsSupportedProtocolResponse:
            message = Messages::RequestServer::IsSupportedProtocolResponse::decode(stream, socket);
            break;

        case (int)Messages::RequestServer::MessageID::StartRequest:
            message = Messages::RequestServer::StartRequest::decode(stream, socket);
            break;

        case (int)Messages::RequestServer::MessageID::StartRequestResponse:
            message = Messages::RequestServer::StartRequestResponse::decode(stream, socket);
            break;

        case (int)Messages::RequestServer::MessageID::StopRequest:
            message = Messages::RequestServer::StopRequest::decode(stream, socket);
            break;

        case (int)Messages::RequestServer::MessageID::StopRequestResponse:
            message = Messages::RequestServer::StopRequestResponse::decode(stream, socket);
            break;

        case (int)Messages::RequestServer::MessageID::SetCertificate:
            message = Messages::RequestServer::SetCertificate::decode(stream, socket);
            break;

        case (int)Messages::RequestServer::MessageID::SetCertificateResponse:
            message = Messages::RequestServer::SetCertificateResponse::decode(stream, socket);
            break;

        case (int)Messages::RequestServer::MessageID::EnsureConnection:
            message = Messages::RequestServer::EnsureConnection::decode(stream, socket);
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

class RequestServerStub : public IPC::Stub {
public:
    RequestServerStub() { }
    virtual ~RequestServerStub() override { }

    virtual u32 magic() const override { return 1270977860; }
    virtual String name() const override { return "RequestServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::RequestServer::MessageID::IsSupportedProtocol: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestServer::IsSupportedProtocol&>(message);
            auto response = is_supported_protocol(request.protocol());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::RequestServer::MessageID::StartRequest: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestServer::StartRequest&>(message);
            auto response = start_request(request.method(), request.url(), request.request_headers(), request.request_body(), request.proxy_data());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::RequestServer::MessageID::StopRequest: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestServer::StopRequest&>(message);
            auto response = stop_request(request.request_id());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::RequestServer::MessageID::SetCertificate: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestServer::SetCertificate&>(message);
            auto response = set_certificate(request.request_id(), request.certificate(), request.key());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::RequestServer::MessageID::EnsureConnection: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestServer::EnsureConnection&>(message);
            ensure_connection(request.url(), request.cache_level());
            return {};

        }

        default:
            return {};
        }
    }

    virtual Messages::RequestServer::IsSupportedProtocolResponse is_supported_protocol(
[[maybe_unused]] String const& protocol) = 0;

    virtual Messages::RequestServer::StartRequestResponse start_request(
[[maybe_unused]] String const& method, [[maybe_unused]] URL const& url, [[maybe_unused]] IPC::Dictionary const& request_headers, [[maybe_unused]] ByteBuffer const& request_body, [[maybe_unused]] Core::ProxyData const& proxy_data) = 0;

    virtual Messages::RequestServer::StopRequestResponse stop_request(
[[maybe_unused]] i32 request_id) = 0;

    virtual Messages::RequestServer::SetCertificateResponse set_certificate(
[[maybe_unused]] i32 request_id, [[maybe_unused]] String const& certificate, [[maybe_unused]] String const& key) = 0;

    virtual void ensure_connection(
[[maybe_unused]] URL const& url, [[maybe_unused]] ::RequestServer::CacheLevel const& cache_level) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

