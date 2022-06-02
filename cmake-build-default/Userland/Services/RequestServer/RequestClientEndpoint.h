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

namespace Messages::RequestClient {

enum class MessageID : i32 {
    RequestProgress = 1,
    RequestFinished = 2,
    HeadersBecameAvailable = 3,
    CertificateRequested = 4,
};

class RequestProgress final : public IPC::Message {
public:

    RequestProgress(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RequestProgress(RequestProgress const&) = default;
    RequestProgress(RequestProgress&&) = default;
    RequestProgress& operator=(RequestProgress const&) = default;
    RequestProgress(i32 request_id, Optional<u32> total_size, u32 downloaded_size) : m_request_id(move(request_id)), m_total_size(move(total_size)), m_downloaded_size(move(downloaded_size)) {}
    virtual ~RequestProgress() override {}

    virtual u32 endpoint_magic() const override { return 1502652576; }
    virtual i32 message_id() const override { return (int)MessageID::RequestProgress; }
    static i32 static_message_id() { return (int)MessageID::RequestProgress; }
    virtual const char* message_name() const override { return "RequestClient::RequestProgress"; }

    static OwnPtr<RequestProgress> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 request_id = {};
        if (decoder.decode(request_id).is_error())
            return {};

        Optional<u32> total_size = {};
        if (decoder.decode(total_size).is_error())
            return {};

        u32 downloaded_size = {};
        if (decoder.decode(downloaded_size).is_error())
            return {};

        return make<RequestProgress>(move(request_id), move(total_size), move(downloaded_size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RequestProgress;

        stream << m_request_id;

        stream << m_total_size;

        stream << m_downloaded_size;

        return buffer;
    }

    const i32& request_id() const { return m_request_id; }
    i32 take_request_id() { return move(m_request_id); }

    const Optional<u32>& total_size() const { return m_total_size; }
    Optional<u32> take_total_size() { return move(m_total_size); }

    const u32& downloaded_size() const { return m_downloaded_size; }
    u32 take_downloaded_size() { return move(m_downloaded_size); }

private:
    bool m_ipc_message_valid { true };

    i32 m_request_id {};

    Optional<u32> m_total_size {};

    u32 m_downloaded_size {};

};

class RequestFinished final : public IPC::Message {
public:

    RequestFinished(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RequestFinished(RequestFinished const&) = default;
    RequestFinished(RequestFinished&&) = default;
    RequestFinished& operator=(RequestFinished const&) = default;
    RequestFinished(i32 request_id, bool success, u32 total_size) : m_request_id(move(request_id)), m_success(move(success)), m_total_size(move(total_size)) {}
    virtual ~RequestFinished() override {}

    virtual u32 endpoint_magic() const override { return 1502652576; }
    virtual i32 message_id() const override { return (int)MessageID::RequestFinished; }
    static i32 static_message_id() { return (int)MessageID::RequestFinished; }
    virtual const char* message_name() const override { return "RequestClient::RequestFinished"; }

    static OwnPtr<RequestFinished> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 request_id = {};
        if (decoder.decode(request_id).is_error())
            return {};

        bool success = false;
        if (decoder.decode(success).is_error())
            return {};

        u32 total_size = {};
        if (decoder.decode(total_size).is_error())
            return {};

        return make<RequestFinished>(move(request_id), move(success), move(total_size));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RequestFinished;

        stream << m_request_id;

        stream << m_success;

        stream << m_total_size;

        return buffer;
    }

    const i32& request_id() const { return m_request_id; }
    i32 take_request_id() { return move(m_request_id); }

    const bool& success() const { return m_success; }
    bool take_success() { return move(m_success); }

    const u32& total_size() const { return m_total_size; }
    u32 take_total_size() { return move(m_total_size); }

private:
    bool m_ipc_message_valid { true };

    i32 m_request_id {};

    bool m_success {};

    u32 m_total_size {};

};

class HeadersBecameAvailable final : public IPC::Message {
public:

    HeadersBecameAvailable(decltype(nullptr)) : m_ipc_message_valid(false) { }
    HeadersBecameAvailable(HeadersBecameAvailable const&) = default;
    HeadersBecameAvailable(HeadersBecameAvailable&&) = default;
    HeadersBecameAvailable& operator=(HeadersBecameAvailable const&) = default;
    HeadersBecameAvailable(i32 request_id, IPC::Dictionary response_headers, Optional<u32> status_code) : m_request_id(move(request_id)), m_response_headers(move(response_headers)), m_status_code(move(status_code)) {}
    virtual ~HeadersBecameAvailable() override {}

    virtual u32 endpoint_magic() const override { return 1502652576; }
    virtual i32 message_id() const override { return (int)MessageID::HeadersBecameAvailable; }
    static i32 static_message_id() { return (int)MessageID::HeadersBecameAvailable; }
    virtual const char* message_name() const override { return "RequestClient::HeadersBecameAvailable"; }

    static OwnPtr<HeadersBecameAvailable> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 request_id = {};
        if (decoder.decode(request_id).is_error())
            return {};

        IPC::Dictionary response_headers = {};
        if (decoder.decode(response_headers).is_error())
            return {};

        Optional<u32> status_code = {};
        if (decoder.decode(status_code).is_error())
            return {};

        return make<HeadersBecameAvailable>(move(request_id), move(response_headers), move(status_code));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::HeadersBecameAvailable;

        stream << m_request_id;

        stream << m_response_headers;

        stream << m_status_code;

        return buffer;
    }

    const i32& request_id() const { return m_request_id; }
    i32 take_request_id() { return move(m_request_id); }

    const IPC::Dictionary& response_headers() const { return m_response_headers; }
    IPC::Dictionary take_response_headers() { return move(m_response_headers); }

    const Optional<u32>& status_code() const { return m_status_code; }
    Optional<u32> take_status_code() { return move(m_status_code); }

private:
    bool m_ipc_message_valid { true };

    i32 m_request_id {};

    IPC::Dictionary m_response_headers {};

    Optional<u32> m_status_code {};

};

class CertificateRequested final : public IPC::Message {
public:

    CertificateRequested(decltype(nullptr)) : m_ipc_message_valid(false) { }
    CertificateRequested(CertificateRequested const&) = default;
    CertificateRequested(CertificateRequested&&) = default;
    CertificateRequested& operator=(CertificateRequested const&) = default;
    CertificateRequested(i32 request_id) : m_request_id(move(request_id)) {}
    virtual ~CertificateRequested() override {}

    virtual u32 endpoint_magic() const override { return 1502652576; }
    virtual i32 message_id() const override { return (int)MessageID::CertificateRequested; }
    static i32 static_message_id() { return (int)MessageID::CertificateRequested; }
    virtual const char* message_name() const override { return "RequestClient::CertificateRequested"; }

    static OwnPtr<CertificateRequested> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 request_id = {};
        if (decoder.decode(request_id).is_error())
            return {};

        return make<CertificateRequested>(move(request_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::CertificateRequested;

        stream << m_request_id;

        return buffer;
    }

    const i32& request_id() const { return m_request_id; }
    i32 take_request_id() { return move(m_request_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_request_id {};

};

} // namespace Messages::RequestClient

template<typename LocalEndpoint, typename PeerEndpoint>
class RequestClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    RequestClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_request_progress(
i32 request_id, Optional<u32> total_size, u32 downloaded_size) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestClient::RequestProgress { request_id, move(total_size), downloaded_size });

    }

    void async_request_finished(
i32 request_id, bool success, u32 total_size) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestClient::RequestFinished { request_id, success, total_size });

    }

    void async_headers_became_available(
i32 request_id, IPC::Dictionary response_headers, Optional<u32> status_code) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestClient::HeadersBecameAvailable { request_id, move(response_headers), move(status_code) });

    }

    void async_certificate_requested(
i32 request_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::RequestClient::CertificateRequested { request_id });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class RequestClientProxy;
class RequestClientStub;

class RequestClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = RequestClientProxy<LocalEndpoint, RequestClientEndpoint>;
    using Stub = RequestClientStub;

    static u32 static_magic() { return 1502652576; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 1502652576) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::RequestClient::MessageID::RequestProgress:
            message = Messages::RequestClient::RequestProgress::decode(stream, socket);
            break;

        case (int)Messages::RequestClient::MessageID::RequestFinished:
            message = Messages::RequestClient::RequestFinished::decode(stream, socket);
            break;

        case (int)Messages::RequestClient::MessageID::HeadersBecameAvailable:
            message = Messages::RequestClient::HeadersBecameAvailable::decode(stream, socket);
            break;

        case (int)Messages::RequestClient::MessageID::CertificateRequested:
            message = Messages::RequestClient::CertificateRequested::decode(stream, socket);
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

class RequestClientStub : public IPC::Stub {
public:
    RequestClientStub() { }
    virtual ~RequestClientStub() override { }

    virtual u32 magic() const override { return 1502652576; }
    virtual String name() const override { return "RequestClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::RequestClient::MessageID::RequestProgress: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestClient::RequestProgress&>(message);
            request_progress(request.request_id(), request.total_size(), request.downloaded_size());
            return {};

        }

        case (int)Messages::RequestClient::MessageID::RequestFinished: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestClient::RequestFinished&>(message);
            request_finished(request.request_id(), request.success(), request.total_size());
            return {};

        }

        case (int)Messages::RequestClient::MessageID::HeadersBecameAvailable: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestClient::HeadersBecameAvailable&>(message);
            headers_became_available(request.request_id(), request.response_headers(), request.status_code());
            return {};

        }

        case (int)Messages::RequestClient::MessageID::CertificateRequested: {

            [[maybe_unused]] auto& request = static_cast<const Messages::RequestClient::CertificateRequested&>(message);
            certificate_requested(request.request_id());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void request_progress(
[[maybe_unused]] i32 request_id, [[maybe_unused]] Optional<u32> const& total_size, [[maybe_unused]] u32 downloaded_size) = 0;

    virtual void request_finished(
[[maybe_unused]] i32 request_id, [[maybe_unused]] bool success, [[maybe_unused]] u32 total_size) = 0;

    virtual void headers_became_available(
[[maybe_unused]] i32 request_id, [[maybe_unused]] IPC::Dictionary const& response_headers, [[maybe_unused]] Optional<u32> const& status_code) = 0;

    virtual void certificate_requested(
[[maybe_unused]] i32 request_id) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

