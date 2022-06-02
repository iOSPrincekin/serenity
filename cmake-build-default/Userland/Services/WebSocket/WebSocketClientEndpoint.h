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

namespace Messages::WebSocketClient {

enum class MessageID : i32 {
    Connected = 1,
    Received = 2,
    Errored = 3,
    Closed = 4,
    CertificateRequested = 5,
};

class Connected final : public IPC::Message {
public:

    Connected(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Connected(Connected const&) = default;
    Connected(Connected&&) = default;
    Connected& operator=(Connected const&) = default;
    Connected(i32 connection_id) : m_connection_id(move(connection_id)) {}
    virtual ~Connected() override {}

    virtual u32 endpoint_magic() const override { return 3157685592; }
    virtual i32 message_id() const override { return (int)MessageID::Connected; }
    static i32 static_message_id() { return (int)MessageID::Connected; }
    virtual const char* message_name() const override { return "WebSocketClient::Connected"; }

    static OwnPtr<Connected> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        return make<Connected>(move(connection_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Connected;

        stream << m_connection_id;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

};

class Received final : public IPC::Message {
public:

    Received(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Received(Received const&) = default;
    Received(Received&&) = default;
    Received& operator=(Received const&) = default;
    Received(i32 connection_id, bool is_text, ByteBuffer data) : m_connection_id(move(connection_id)), m_is_text(move(is_text)), m_data(move(data)) {}
    virtual ~Received() override {}

    virtual u32 endpoint_magic() const override { return 3157685592; }
    virtual i32 message_id() const override { return (int)MessageID::Received; }
    static i32 static_message_id() { return (int)MessageID::Received; }
    virtual const char* message_name() const override { return "WebSocketClient::Received"; }

    static OwnPtr<Received> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        return make<Received>(move(connection_id), move(is_text), move(data));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Received;

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

class Errored final : public IPC::Message {
public:

    Errored(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Errored(Errored const&) = default;
    Errored(Errored&&) = default;
    Errored& operator=(Errored const&) = default;
    Errored(i32 connection_id, i32 message) : m_connection_id(move(connection_id)), m_message(move(message)) {}
    virtual ~Errored() override {}

    virtual u32 endpoint_magic() const override { return 3157685592; }
    virtual i32 message_id() const override { return (int)MessageID::Errored; }
    static i32 static_message_id() { return (int)MessageID::Errored; }
    virtual const char* message_name() const override { return "WebSocketClient::Errored"; }

    static OwnPtr<Errored> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        i32 message = {};
        if (decoder.decode(message).is_error())
            return {};

        return make<Errored>(move(connection_id), move(message));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Errored;

        stream << m_connection_id;

        stream << m_message;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

    const i32& message() const { return m_message; }
    i32 take_message() { return move(m_message); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

    i32 m_message {};

};

class Closed final : public IPC::Message {
public:

    Closed(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Closed(Closed const&) = default;
    Closed(Closed&&) = default;
    Closed& operator=(Closed const&) = default;
    Closed(i32 connection_id, u16 code, String reason, bool clean) : m_connection_id(move(connection_id)), m_code(move(code)), m_reason(move(reason)), m_clean(move(clean)) {}
    virtual ~Closed() override {}

    virtual u32 endpoint_magic() const override { return 3157685592; }
    virtual i32 message_id() const override { return (int)MessageID::Closed; }
    static i32 static_message_id() { return (int)MessageID::Closed; }
    virtual const char* message_name() const override { return "WebSocketClient::Closed"; }

    static OwnPtr<Closed> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
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

        bool clean = false;
        if (decoder.decode(clean).is_error())
            return {};

        return make<Closed>(move(connection_id), move(code), move(reason), move(clean));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Closed;

        stream << m_connection_id;

        stream << m_code;

        stream << m_reason;

        stream << m_clean;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

    const u16& code() const { return m_code; }
    u16 take_code() { return move(m_code); }

    const String& reason() const { return m_reason; }
    String take_reason() { return move(m_reason); }

    const bool& clean() const { return m_clean; }
    bool take_clean() { return move(m_clean); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

    u16 m_code {};

    String m_reason {};

    bool m_clean {};

};

class CertificateRequested final : public IPC::Message {
public:

    CertificateRequested(decltype(nullptr)) : m_ipc_message_valid(false) { }
    CertificateRequested(CertificateRequested const&) = default;
    CertificateRequested(CertificateRequested&&) = default;
    CertificateRequested& operator=(CertificateRequested const&) = default;
    CertificateRequested(i32 connection_id) : m_connection_id(move(connection_id)) {}
    virtual ~CertificateRequested() override {}

    virtual u32 endpoint_magic() const override { return 3157685592; }
    virtual i32 message_id() const override { return (int)MessageID::CertificateRequested; }
    static i32 static_message_id() { return (int)MessageID::CertificateRequested; }
    virtual const char* message_name() const override { return "WebSocketClient::CertificateRequested"; }

    static OwnPtr<CertificateRequested> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        return make<CertificateRequested>(move(connection_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::CertificateRequested;

        stream << m_connection_id;

        return buffer;
    }

    const i32& connection_id() const { return m_connection_id; }
    i32 take_connection_id() { return move(m_connection_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_connection_id {};

};

} // namespace Messages::WebSocketClient

template<typename LocalEndpoint, typename PeerEndpoint>
class WebSocketClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    WebSocketClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_connected(
i32 connection_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketClient::Connected { connection_id });

    }

    void async_received(
i32 connection_id, bool is_text, ByteBuffer data) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketClient::Received { connection_id, is_text, move(data) });

    }

    void async_errored(
i32 connection_id, i32 message) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketClient::Errored { connection_id, message });

    }

    void async_closed(
i32 connection_id, u16 code, String reason, bool clean) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketClient::Closed { connection_id, code, move(reason), clean });

    }

    void async_certificate_requested(
i32 connection_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::WebSocketClient::CertificateRequested { connection_id });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class WebSocketClientProxy;
class WebSocketClientStub;

class WebSocketClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = WebSocketClientProxy<LocalEndpoint, WebSocketClientEndpoint>;
    using Stub = WebSocketClientStub;

    static u32 static_magic() { return 3157685592; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3157685592) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::WebSocketClient::MessageID::Connected:
            message = Messages::WebSocketClient::Connected::decode(stream, socket);
            break;

        case (int)Messages::WebSocketClient::MessageID::Received:
            message = Messages::WebSocketClient::Received::decode(stream, socket);
            break;

        case (int)Messages::WebSocketClient::MessageID::Errored:
            message = Messages::WebSocketClient::Errored::decode(stream, socket);
            break;

        case (int)Messages::WebSocketClient::MessageID::Closed:
            message = Messages::WebSocketClient::Closed::decode(stream, socket);
            break;

        case (int)Messages::WebSocketClient::MessageID::CertificateRequested:
            message = Messages::WebSocketClient::CertificateRequested::decode(stream, socket);
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

class WebSocketClientStub : public IPC::Stub {
public:
    WebSocketClientStub() { }
    virtual ~WebSocketClientStub() override { }

    virtual u32 magic() const override { return 3157685592; }
    virtual String name() const override { return "WebSocketClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::WebSocketClient::MessageID::Connected: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketClient::Connected&>(message);
            connected(request.connection_id());
            return {};

        }

        case (int)Messages::WebSocketClient::MessageID::Received: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketClient::Received&>(message);
            received(request.connection_id(), request.is_text(), request.data());
            return {};

        }

        case (int)Messages::WebSocketClient::MessageID::Errored: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketClient::Errored&>(message);
            errored(request.connection_id(), request.message());
            return {};

        }

        case (int)Messages::WebSocketClient::MessageID::Closed: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketClient::Closed&>(message);
            closed(request.connection_id(), request.code(), request.reason(), request.clean());
            return {};

        }

        case (int)Messages::WebSocketClient::MessageID::CertificateRequested: {

            [[maybe_unused]] auto& request = static_cast<const Messages::WebSocketClient::CertificateRequested&>(message);
            certificate_requested(request.connection_id());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void connected(
[[maybe_unused]] i32 connection_id) = 0;

    virtual void received(
[[maybe_unused]] i32 connection_id, [[maybe_unused]] bool is_text, [[maybe_unused]] ByteBuffer const& data) = 0;

    virtual void errored(
[[maybe_unused]] i32 connection_id, [[maybe_unused]] i32 message) = 0;

    virtual void closed(
[[maybe_unused]] i32 connection_id, [[maybe_unused]] u16 code, [[maybe_unused]] String const& reason, [[maybe_unused]] bool clean) = 0;

    virtual void certificate_requested(
[[maybe_unused]] i32 connection_id) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

