#pragma once
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

namespace Messages::LookupServer {

enum class MessageID : i32 {
    LookupName = 1,
    LookupNameResponse = 2,
    LookupAddress = 3,
    LookupAddressResponse = 4,
};

class LookupNameResponse final : public IPC::Message {
public:

    LookupNameResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    LookupNameResponse(LookupNameResponse const&) = default;
    LookupNameResponse(LookupNameResponse&&) = default;
    LookupNameResponse& operator=(LookupNameResponse const&) = default;
    LookupNameResponse(int code, Vector<String> addresses) : m_code(move(code)), m_addresses(move(addresses)) {}
    virtual ~LookupNameResponse() override {}

    virtual u32 endpoint_magic() const override { return 3613307456; }
    virtual i32 message_id() const override { return (int)MessageID::LookupNameResponse; }
    static i32 static_message_id() { return (int)MessageID::LookupNameResponse; }
    virtual const char* message_name() const override { return "LookupServer::LookupNameResponse"; }

    static OwnPtr<LookupNameResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int code = {};
        if (decoder.decode(code).is_error())
            return {};

        Vector<String> addresses = {};
        if (decoder.decode(addresses).is_error())
            return {};

        return make<LookupNameResponse>(move(code), move(addresses));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::LookupNameResponse;

        stream << m_code;

        stream << m_addresses;

        return buffer;
    }

    const int& code() const { return m_code; }
    int take_code() { return move(m_code); }

    const Vector<String>& addresses() const { return m_addresses; }
    Vector<String> take_addresses() { return move(m_addresses); }

private:
    bool m_ipc_message_valid { true };

    int m_code {};

    Vector<String> m_addresses {};

};

class LookupName final : public IPC::Message {
public:

   typedef class LookupNameResponse ResponseType;

    LookupName(decltype(nullptr)) : m_ipc_message_valid(false) { }
    LookupName(LookupName const&) = default;
    LookupName(LookupName&&) = default;
    LookupName& operator=(LookupName const&) = default;
    LookupName(String name) : m_name(move(name)) {}
    virtual ~LookupName() override {}

    virtual u32 endpoint_magic() const override { return 3613307456; }
    virtual i32 message_id() const override { return (int)MessageID::LookupName; }
    static i32 static_message_id() { return (int)MessageID::LookupName; }
    virtual const char* message_name() const override { return "LookupServer::LookupName"; }

    static OwnPtr<LookupName> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String name = {};
        if (decoder.decode(name).is_error())
            return {};

        return make<LookupName>(move(name));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::LookupName;

        stream << m_name;

        return buffer;
    }

    const String& name() const { return m_name; }
    String take_name() { return move(m_name); }

private:
    bool m_ipc_message_valid { true };

    String m_name {};

};

class LookupAddressResponse final : public IPC::Message {
public:

    LookupAddressResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    LookupAddressResponse(LookupAddressResponse const&) = default;
    LookupAddressResponse(LookupAddressResponse&&) = default;
    LookupAddressResponse& operator=(LookupAddressResponse const&) = default;
    LookupAddressResponse(int code, String name) : m_code(move(code)), m_name(move(name)) {}
    virtual ~LookupAddressResponse() override {}

    virtual u32 endpoint_magic() const override { return 3613307456; }
    virtual i32 message_id() const override { return (int)MessageID::LookupAddressResponse; }
    static i32 static_message_id() { return (int)MessageID::LookupAddressResponse; }
    virtual const char* message_name() const override { return "LookupServer::LookupAddressResponse"; }

    static OwnPtr<LookupAddressResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int code = {};
        if (decoder.decode(code).is_error())
            return {};

        String name = {};
        if (decoder.decode(name).is_error())
            return {};

        return make<LookupAddressResponse>(move(code), move(name));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::LookupAddressResponse;

        stream << m_code;

        stream << m_name;

        return buffer;
    }

    const int& code() const { return m_code; }
    int take_code() { return move(m_code); }

    const String& name() const { return m_name; }
    String take_name() { return move(m_name); }

private:
    bool m_ipc_message_valid { true };

    int m_code {};

    String m_name {};

};

class LookupAddress final : public IPC::Message {
public:

   typedef class LookupAddressResponse ResponseType;

    LookupAddress(decltype(nullptr)) : m_ipc_message_valid(false) { }
    LookupAddress(LookupAddress const&) = default;
    LookupAddress(LookupAddress&&) = default;
    LookupAddress& operator=(LookupAddress const&) = default;
    LookupAddress(String address) : m_address(move(address)) {}
    virtual ~LookupAddress() override {}

    virtual u32 endpoint_magic() const override { return 3613307456; }
    virtual i32 message_id() const override { return (int)MessageID::LookupAddress; }
    static i32 static_message_id() { return (int)MessageID::LookupAddress; }
    virtual const char* message_name() const override { return "LookupServer::LookupAddress"; }

    static OwnPtr<LookupAddress> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String address = {};
        if (decoder.decode(address).is_error())
            return {};

        return make<LookupAddress>(move(address));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::LookupAddress;

        stream << m_address;

        return buffer;
    }

    const String& address() const { return m_address; }
    String take_address() { return move(m_address); }

private:
    bool m_ipc_message_valid { true };

    String m_address {};

};

} // namespace Messages::LookupServer

template<typename LocalEndpoint, typename PeerEndpoint>
class LookupServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    LookupServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    Messages::LookupServer::LookupNameResponse lookup_name(
String name) {
        return move(*m_connection.template send_sync<Messages::LookupServer::LookupName>(move(name)));
    }

    void async_lookup_name(
String name) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LookupServer::LookupName { move(name) });

    }

    IPC::IPCErrorOr<Messages::LookupServer::LookupNameResponse> try_lookup_name(
String name) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LookupServer::LookupName>(move(name));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Messages::LookupServer::LookupAddressResponse lookup_address(
String address) {
        return move(*m_connection.template send_sync<Messages::LookupServer::LookupAddress>(move(address)));
    }

    void async_lookup_address(
String address) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LookupServer::LookupAddress { move(address) });

    }

    IPC::IPCErrorOr<Messages::LookupServer::LookupAddressResponse> try_lookup_address(
String address) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LookupServer::LookupAddress>(move(address));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class LookupServerProxy;
class LookupServerStub;

class LookupServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = LookupServerProxy<LocalEndpoint, LookupServerEndpoint>;
    using Stub = LookupServerStub;

    static u32 static_magic() { return 3613307456; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3613307456) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::LookupServer::MessageID::LookupName:
            message = Messages::LookupServer::LookupName::decode(stream, socket);
            break;

        case (int)Messages::LookupServer::MessageID::LookupNameResponse:
            message = Messages::LookupServer::LookupNameResponse::decode(stream, socket);
            break;

        case (int)Messages::LookupServer::MessageID::LookupAddress:
            message = Messages::LookupServer::LookupAddress::decode(stream, socket);
            break;

        case (int)Messages::LookupServer::MessageID::LookupAddressResponse:
            message = Messages::LookupServer::LookupAddressResponse::decode(stream, socket);
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

class LookupServerStub : public IPC::Stub {
public:
    LookupServerStub() { }
    virtual ~LookupServerStub() override { }

    virtual u32 magic() const override { return 3613307456; }
    virtual String name() const override { return "LookupServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::LookupServer::MessageID::LookupName: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LookupServer::LookupName&>(message);
            auto response = lookup_name(request.name());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::LookupServer::MessageID::LookupAddress: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LookupServer::LookupAddress&>(message);
            auto response = lookup_address(request.address());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        default:
            return {};
        }
    }

    virtual Messages::LookupServer::LookupNameResponse lookup_name(
[[maybe_unused]] String const& name) = 0;

    virtual Messages::LookupServer::LookupAddressResponse lookup_address(
[[maybe_unused]] String const& address) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

