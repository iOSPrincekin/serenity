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

namespace Messages::NotificationClient {

enum class MessageID : i32 {
};

} // namespace Messages::NotificationClient

template<typename LocalEndpoint, typename PeerEndpoint>
class NotificationClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    NotificationClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class NotificationClientProxy;
class NotificationClientStub;

class NotificationClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = NotificationClientProxy<LocalEndpoint, NotificationClientEndpoint>;
    using Stub = NotificationClientStub;

    static u32 static_magic() { return 2857680997; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 2857680997) {

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

class NotificationClientStub : public IPC::Stub {
public:
    NotificationClientStub() { }
    virtual ~NotificationClientStub() override { }

    virtual u32 magic() const override { return 2857680997; }
    virtual String name() const override { return "NotificationClient"; }

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

