#pragma once
#include <LibCore/AnonymousBuffer.h>
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

namespace Messages::ClipboardClient {

enum class MessageID : i32 {
    ClipboardDataChanged = 1,
};

class ClipboardDataChanged final : public IPC::Message {
public:

    ClipboardDataChanged(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ClipboardDataChanged(ClipboardDataChanged const&) = default;
    ClipboardDataChanged(ClipboardDataChanged&&) = default;
    ClipboardDataChanged& operator=(ClipboardDataChanged const&) = default;
    ClipboardDataChanged(String mime_type) : m_mime_type(move(mime_type)) {}
    virtual ~ClipboardDataChanged() override {}

    virtual u32 endpoint_magic() const override { return 4008793515; }
    virtual i32 message_id() const override { return (int)MessageID::ClipboardDataChanged; }
    static i32 static_message_id() { return (int)MessageID::ClipboardDataChanged; }
    virtual const char* message_name() const override { return "ClipboardClient::ClipboardDataChanged"; }

    static OwnPtr<ClipboardDataChanged> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String mime_type = {};
        if (decoder.decode(mime_type).is_error())
            return {};

        if (!Utf8View(mime_type).validate())
            return {};

        return make<ClipboardDataChanged>(move(mime_type));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ClipboardDataChanged;

        stream << m_mime_type;

        return buffer;
    }

    const String& mime_type() const { return m_mime_type; }
    String take_mime_type() { return move(m_mime_type); }

private:
    bool m_ipc_message_valid { true };

    String m_mime_type {};

};

} // namespace Messages::ClipboardClient

template<typename LocalEndpoint, typename PeerEndpoint>
class ClipboardClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    ClipboardClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_clipboard_data_changed(
String mime_type) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ClipboardClient::ClipboardDataChanged { move(mime_type) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class ClipboardClientProxy;
class ClipboardClientStub;

class ClipboardClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = ClipboardClientProxy<LocalEndpoint, ClipboardClientEndpoint>;
    using Stub = ClipboardClientStub;

    static u32 static_magic() { return 4008793515; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 4008793515) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::ClipboardClient::MessageID::ClipboardDataChanged:
            message = Messages::ClipboardClient::ClipboardDataChanged::decode(stream, socket);
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

class ClipboardClientStub : public IPC::Stub {
public:
    ClipboardClientStub() { }
    virtual ~ClipboardClientStub() override { }

    virtual u32 magic() const override { return 4008793515; }
    virtual String name() const override { return "ClipboardClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::ClipboardClient::MessageID::ClipboardDataChanged: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ClipboardClient::ClipboardDataChanged&>(message);
            clipboard_data_changed(request.mime_type());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void clipboard_data_changed(
[[maybe_unused]] String const& mime_type) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

