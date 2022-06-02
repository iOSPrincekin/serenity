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

namespace Messages::ClipboardServer {

enum class MessageID : i32 {
    GetClipboardData = 1,
    GetClipboardDataResponse = 2,
    SetClipboardData = 3,
};

class GetClipboardDataResponse final : public IPC::Message {
public:

    GetClipboardDataResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetClipboardDataResponse(GetClipboardDataResponse const&) = default;
    GetClipboardDataResponse(GetClipboardDataResponse&&) = default;
    GetClipboardDataResponse& operator=(GetClipboardDataResponse const&) = default;
    GetClipboardDataResponse(Core::AnonymousBuffer data, String mime_type, IPC::Dictionary metadata) : m_data(move(data)), m_mime_type(move(mime_type)), m_metadata(move(metadata)) {}
    virtual ~GetClipboardDataResponse() override {}

    virtual u32 endpoint_magic() const override { return 1329211611; }
    virtual i32 message_id() const override { return (int)MessageID::GetClipboardDataResponse; }
    static i32 static_message_id() { return (int)MessageID::GetClipboardDataResponse; }
    virtual const char* message_name() const override { return "ClipboardServer::GetClipboardDataResponse"; }

    static OwnPtr<GetClipboardDataResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Core::AnonymousBuffer data = {};
        if (decoder.decode(data).is_error())
            return {};

        String mime_type = {};
        if (decoder.decode(mime_type).is_error())
            return {};

        if (!Utf8View(mime_type).validate())
            return {};

        IPC::Dictionary metadata = {};
        if (decoder.decode(metadata).is_error())
            return {};

        return make<GetClipboardDataResponse>(move(data), move(mime_type), move(metadata));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetClipboardDataResponse;

        stream << m_data;

        stream << m_mime_type;

        stream << m_metadata;

        return buffer;
    }

    const Core::AnonymousBuffer& data() const { return m_data; }
    Core::AnonymousBuffer take_data() { return move(m_data); }

    const String& mime_type() const { return m_mime_type; }
    String take_mime_type() { return move(m_mime_type); }

    const IPC::Dictionary& metadata() const { return m_metadata; }
    IPC::Dictionary take_metadata() { return move(m_metadata); }

private:
    bool m_ipc_message_valid { true };

    Core::AnonymousBuffer m_data {};

    String m_mime_type {};

    IPC::Dictionary m_metadata {};

};

class GetClipboardData final : public IPC::Message {
public:

   typedef class GetClipboardDataResponse ResponseType;

    GetClipboardData(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetClipboardData(GetClipboardData const&) = default;
    GetClipboardData(GetClipboardData&&) = default;
    GetClipboardData& operator=(GetClipboardData const&) = default;
    GetClipboardData() {}
    virtual ~GetClipboardData() override {}

    virtual u32 endpoint_magic() const override { return 1329211611; }
    virtual i32 message_id() const override { return (int)MessageID::GetClipboardData; }
    static i32 static_message_id() { return (int)MessageID::GetClipboardData; }
    virtual const char* message_name() const override { return "ClipboardServer::GetClipboardData"; }

    static OwnPtr<GetClipboardData> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<GetClipboardData>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetClipboardData;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SetClipboardData final : public IPC::Message {
public:

    SetClipboardData(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetClipboardData(SetClipboardData const&) = default;
    SetClipboardData(SetClipboardData&&) = default;
    SetClipboardData& operator=(SetClipboardData const&) = default;
    SetClipboardData(Core::AnonymousBuffer data, String mime_type, IPC::Dictionary metadata) : m_data(move(data)), m_mime_type(move(mime_type)), m_metadata(move(metadata)) {}
    virtual ~SetClipboardData() override {}

    virtual u32 endpoint_magic() const override { return 1329211611; }
    virtual i32 message_id() const override { return (int)MessageID::SetClipboardData; }
    static i32 static_message_id() { return (int)MessageID::SetClipboardData; }
    virtual const char* message_name() const override { return "ClipboardServer::SetClipboardData"; }

    static OwnPtr<SetClipboardData> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Core::AnonymousBuffer data = {};
        if (decoder.decode(data).is_error())
            return {};

        String mime_type = {};
        if (decoder.decode(mime_type).is_error())
            return {};

        if (!Utf8View(mime_type).validate())
            return {};

        IPC::Dictionary metadata = {};
        if (decoder.decode(metadata).is_error())
            return {};

        return make<SetClipboardData>(move(data), move(mime_type), move(metadata));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetClipboardData;

        stream << m_data;

        stream << m_mime_type;

        stream << m_metadata;

        return buffer;
    }

    const Core::AnonymousBuffer& data() const { return m_data; }
    Core::AnonymousBuffer take_data() { return move(m_data); }

    const String& mime_type() const { return m_mime_type; }
    String take_mime_type() { return move(m_mime_type); }

    const IPC::Dictionary& metadata() const { return m_metadata; }
    IPC::Dictionary take_metadata() { return move(m_metadata); }

private:
    bool m_ipc_message_valid { true };

    Core::AnonymousBuffer m_data {};

    String m_mime_type {};

    IPC::Dictionary m_metadata {};

};

} // namespace Messages::ClipboardServer

template<typename LocalEndpoint, typename PeerEndpoint>
class ClipboardServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    ClipboardServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    Messages::ClipboardServer::GetClipboardDataResponse get_clipboard_data(
) {
        return move(*m_connection.template send_sync<Messages::ClipboardServer::GetClipboardData>());
    }

    void async_get_clipboard_data(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ClipboardServer::GetClipboardData {  });

    }

    IPC::IPCErrorOr<Messages::ClipboardServer::GetClipboardDataResponse> try_get_clipboard_data(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::ClipboardServer::GetClipboardData>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_set_clipboard_data(
Core::AnonymousBuffer data, String mime_type, IPC::Dictionary metadata) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::ClipboardServer::SetClipboardData { move(data), move(mime_type), move(metadata) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class ClipboardServerProxy;
class ClipboardServerStub;

class ClipboardServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = ClipboardServerProxy<LocalEndpoint, ClipboardServerEndpoint>;
    using Stub = ClipboardServerStub;

    static u32 static_magic() { return 1329211611; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 1329211611) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::ClipboardServer::MessageID::GetClipboardData:
            message = Messages::ClipboardServer::GetClipboardData::decode(stream, socket);
            break;

        case (int)Messages::ClipboardServer::MessageID::GetClipboardDataResponse:
            message = Messages::ClipboardServer::GetClipboardDataResponse::decode(stream, socket);
            break;

        case (int)Messages::ClipboardServer::MessageID::SetClipboardData:
            message = Messages::ClipboardServer::SetClipboardData::decode(stream, socket);
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

class ClipboardServerStub : public IPC::Stub {
public:
    ClipboardServerStub() { }
    virtual ~ClipboardServerStub() override { }

    virtual u32 magic() const override { return 1329211611; }
    virtual String name() const override { return "ClipboardServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::ClipboardServer::MessageID::GetClipboardData: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ClipboardServer::GetClipboardData&>(message);
            auto response = get_clipboard_data();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::ClipboardServer::MessageID::SetClipboardData: {

            [[maybe_unused]] auto& request = static_cast<const Messages::ClipboardServer::SetClipboardData&>(message);
            set_clipboard_data(request.data(), request.mime_type(), request.metadata());
            return {};

        }

        default:
            return {};
        }
    }

    virtual Messages::ClipboardServer::GetClipboardDataResponse get_clipboard_data(
) = 0;

    virtual void set_clipboard_data(
[[maybe_unused]] Core::AnonymousBuffer const& data, [[maybe_unused]] String const& mime_type, [[maybe_unused]] IPC::Dictionary const& metadata) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

