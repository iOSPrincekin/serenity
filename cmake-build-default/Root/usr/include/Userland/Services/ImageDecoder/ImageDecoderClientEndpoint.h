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

namespace Messages::ImageDecoderClient {

enum class MessageID : i32 {
};

} // namespace Messages::ImageDecoderClient

template<typename LocalEndpoint, typename PeerEndpoint>
class ImageDecoderClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    ImageDecoderClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class ImageDecoderClientProxy;
class ImageDecoderClientStub;

class ImageDecoderClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = ImageDecoderClientProxy<LocalEndpoint, ImageDecoderClientEndpoint>;
    using Stub = ImageDecoderClientStub;

    static u32 static_magic() { return 945471142; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 945471142) {

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

class ImageDecoderClientStub : public IPC::Stub {
public:
    ImageDecoderClientStub() { }
    virtual ~ImageDecoderClientStub() override { }

    virtual u32 magic() const override { return 945471142; }
    virtual String name() const override { return "ImageDecoderClient"; }

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

