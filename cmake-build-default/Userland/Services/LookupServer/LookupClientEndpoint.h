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

namespace Messages::LookupClient {

enum class MessageID : i32 {
};

} // namespace Messages::LookupClient

template<typename LocalEndpoint, typename PeerEndpoint>
class LookupClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    LookupClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class LookupClientProxy;
class LookupClientStub;

class LookupClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = LookupClientProxy<LocalEndpoint, LookupClientEndpoint>;
    using Stub = LookupClientStub;

    static u32 static_magic() { return 3540717142; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3540717142) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        default:

            return {};
        }

        if (stream.handle_any_error()) {

            return {};
        }

        return message;
    }

};

class LookupClientStub : public IPC::Stub {
public:
    LookupClientStub() { }
    virtual ~LookupClientStub() override { }

    virtual u32 magic() const override { return 3540717142; }
    virtual String name() const override { return "LookupClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        default:
            return {};
        }
    }

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

