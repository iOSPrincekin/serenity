#pragma once
#include <AK/URL.h>
#include <LibCore/IODevice.h>
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

namespace Messages::FileSystemAccessServer {

enum class MessageID : i32 {
    RequestFileReadOnlyApproved = 1,
    RequestFile = 2,
    PromptOpenFile = 3,
    PromptSaveFile = 4,
    ExposeWindowServerClientId = 5,
    ExposeWindowServerClientIdResponse = 6,
};

class RequestFileReadOnlyApproved final : public IPC::Message {
public:

    RequestFileReadOnlyApproved(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RequestFileReadOnlyApproved(RequestFileReadOnlyApproved const&) = default;
    RequestFileReadOnlyApproved(RequestFileReadOnlyApproved&&) = default;
    RequestFileReadOnlyApproved& operator=(RequestFileReadOnlyApproved const&) = default;
    RequestFileReadOnlyApproved(i32 window_server_client_id, i32 window_id, String path) : m_window_server_client_id(move(window_server_client_id)), m_window_id(move(window_id)), m_path(move(path)) {}
    virtual ~RequestFileReadOnlyApproved() override {}

    virtual u32 endpoint_magic() const override { return 729082329; }
    virtual i32 message_id() const override { return (int)MessageID::RequestFileReadOnlyApproved; }
    static i32 static_message_id() { return (int)MessageID::RequestFileReadOnlyApproved; }
    virtual const char* message_name() const override { return "FileSystemAccessServer::RequestFileReadOnlyApproved"; }

    static OwnPtr<RequestFileReadOnlyApproved> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_server_client_id = {};
        if (decoder.decode(window_server_client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        String path = {};
        if (decoder.decode(path).is_error())
            return {};

        return make<RequestFileReadOnlyApproved>(move(window_server_client_id), move(window_id), move(path));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RequestFileReadOnlyApproved;

        stream << m_window_server_client_id;

        stream << m_window_id;

        stream << m_path;

        return buffer;
    }

    const i32& window_server_client_id() const { return m_window_server_client_id; }
    i32 take_window_server_client_id() { return move(m_window_server_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const String& path() const { return m_path; }
    String take_path() { return move(m_path); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_server_client_id {};

    i32 m_window_id {};

    String m_path {};

};

class RequestFile final : public IPC::Message {
public:

    RequestFile(decltype(nullptr)) : m_ipc_message_valid(false) { }
    RequestFile(RequestFile const&) = default;
    RequestFile(RequestFile&&) = default;
    RequestFile& operator=(RequestFile const&) = default;
    RequestFile(i32 window_server_client_id, i32 window_id, String path, Core::OpenMode requested_access) : m_window_server_client_id(move(window_server_client_id)), m_window_id(move(window_id)), m_path(move(path)), m_requested_access(move(requested_access)) {}
    virtual ~RequestFile() override {}

    virtual u32 endpoint_magic() const override { return 729082329; }
    virtual i32 message_id() const override { return (int)MessageID::RequestFile; }
    static i32 static_message_id() { return (int)MessageID::RequestFile; }
    virtual const char* message_name() const override { return "FileSystemAccessServer::RequestFile"; }

    static OwnPtr<RequestFile> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_server_client_id = {};
        if (decoder.decode(window_server_client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        String path = {};
        if (decoder.decode(path).is_error())
            return {};

        Core::OpenMode requested_access = {};
        if (decoder.decode(requested_access).is_error())
            return {};

        return make<RequestFile>(move(window_server_client_id), move(window_id), move(path), move(requested_access));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::RequestFile;

        stream << m_window_server_client_id;

        stream << m_window_id;

        stream << m_path;

        stream << m_requested_access;

        return buffer;
    }

    const i32& window_server_client_id() const { return m_window_server_client_id; }
    i32 take_window_server_client_id() { return move(m_window_server_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const String& path() const { return m_path; }
    String take_path() { return move(m_path); }

    const Core::OpenMode& requested_access() const { return m_requested_access; }
    Core::OpenMode take_requested_access() { return move(m_requested_access); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_server_client_id {};

    i32 m_window_id {};

    String m_path {};

    Core::OpenMode m_requested_access {};

};

class PromptOpenFile final : public IPC::Message {
public:

    PromptOpenFile(decltype(nullptr)) : m_ipc_message_valid(false) { }
    PromptOpenFile(PromptOpenFile const&) = default;
    PromptOpenFile(PromptOpenFile&&) = default;
    PromptOpenFile& operator=(PromptOpenFile const&) = default;
    PromptOpenFile(i32 window_server_client_id, i32 window_id, String window_title, String path_to_view, Core::OpenMode requested_access) : m_window_server_client_id(move(window_server_client_id)), m_window_id(move(window_id)), m_window_title(move(window_title)), m_path_to_view(move(path_to_view)), m_requested_access(move(requested_access)) {}
    virtual ~PromptOpenFile() override {}

    virtual u32 endpoint_magic() const override { return 729082329; }
    virtual i32 message_id() const override { return (int)MessageID::PromptOpenFile; }
    static i32 static_message_id() { return (int)MessageID::PromptOpenFile; }
    virtual const char* message_name() const override { return "FileSystemAccessServer::PromptOpenFile"; }

    static OwnPtr<PromptOpenFile> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_server_client_id = {};
        if (decoder.decode(window_server_client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        String window_title = {};
        if (decoder.decode(window_title).is_error())
            return {};

        String path_to_view = {};
        if (decoder.decode(path_to_view).is_error())
            return {};

        Core::OpenMode requested_access = {};
        if (decoder.decode(requested_access).is_error())
            return {};

        return make<PromptOpenFile>(move(window_server_client_id), move(window_id), move(window_title), move(path_to_view), move(requested_access));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::PromptOpenFile;

        stream << m_window_server_client_id;

        stream << m_window_id;

        stream << m_window_title;

        stream << m_path_to_view;

        stream << m_requested_access;

        return buffer;
    }

    const i32& window_server_client_id() const { return m_window_server_client_id; }
    i32 take_window_server_client_id() { return move(m_window_server_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const String& window_title() const { return m_window_title; }
    String take_window_title() { return move(m_window_title); }

    const String& path_to_view() const { return m_path_to_view; }
    String take_path_to_view() { return move(m_path_to_view); }

    const Core::OpenMode& requested_access() const { return m_requested_access; }
    Core::OpenMode take_requested_access() { return move(m_requested_access); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_server_client_id {};

    i32 m_window_id {};

    String m_window_title {};

    String m_path_to_view {};

    Core::OpenMode m_requested_access {};

};

class PromptSaveFile final : public IPC::Message {
public:

    PromptSaveFile(decltype(nullptr)) : m_ipc_message_valid(false) { }
    PromptSaveFile(PromptSaveFile const&) = default;
    PromptSaveFile(PromptSaveFile&&) = default;
    PromptSaveFile& operator=(PromptSaveFile const&) = default;
    PromptSaveFile(i32 window_server_client_id, i32 window_id, String title, String ext, String path_to_view, Core::OpenMode requested_access) : m_window_server_client_id(move(window_server_client_id)), m_window_id(move(window_id)), m_title(move(title)), m_ext(move(ext)), m_path_to_view(move(path_to_view)), m_requested_access(move(requested_access)) {}
    virtual ~PromptSaveFile() override {}

    virtual u32 endpoint_magic() const override { return 729082329; }
    virtual i32 message_id() const override { return (int)MessageID::PromptSaveFile; }
    static i32 static_message_id() { return (int)MessageID::PromptSaveFile; }
    virtual const char* message_name() const override { return "FileSystemAccessServer::PromptSaveFile"; }

    static OwnPtr<PromptSaveFile> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 window_server_client_id = {};
        if (decoder.decode(window_server_client_id).is_error())
            return {};

        i32 window_id = {};
        if (decoder.decode(window_id).is_error())
            return {};

        String title = {};
        if (decoder.decode(title).is_error())
            return {};

        String ext = {};
        if (decoder.decode(ext).is_error())
            return {};

        String path_to_view = {};
        if (decoder.decode(path_to_view).is_error())
            return {};

        Core::OpenMode requested_access = {};
        if (decoder.decode(requested_access).is_error())
            return {};

        return make<PromptSaveFile>(move(window_server_client_id), move(window_id), move(title), move(ext), move(path_to_view), move(requested_access));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::PromptSaveFile;

        stream << m_window_server_client_id;

        stream << m_window_id;

        stream << m_title;

        stream << m_ext;

        stream << m_path_to_view;

        stream << m_requested_access;

        return buffer;
    }

    const i32& window_server_client_id() const { return m_window_server_client_id; }
    i32 take_window_server_client_id() { return move(m_window_server_client_id); }

    const i32& window_id() const { return m_window_id; }
    i32 take_window_id() { return move(m_window_id); }

    const String& title() const { return m_title; }
    String take_title() { return move(m_title); }

    const String& ext() const { return m_ext; }
    String take_ext() { return move(m_ext); }

    const String& path_to_view() const { return m_path_to_view; }
    String take_path_to_view() { return move(m_path_to_view); }

    const Core::OpenMode& requested_access() const { return m_requested_access; }
    Core::OpenMode take_requested_access() { return move(m_requested_access); }

private:
    bool m_ipc_message_valid { true };

    i32 m_window_server_client_id {};

    i32 m_window_id {};

    String m_title {};

    String m_ext {};

    String m_path_to_view {};

    Core::OpenMode m_requested_access {};

};

class ExposeWindowServerClientIdResponse final : public IPC::Message {
public:

    ExposeWindowServerClientIdResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ExposeWindowServerClientIdResponse(ExposeWindowServerClientIdResponse const&) = default;
    ExposeWindowServerClientIdResponse(ExposeWindowServerClientIdResponse&&) = default;
    ExposeWindowServerClientIdResponse& operator=(ExposeWindowServerClientIdResponse const&) = default;
    ExposeWindowServerClientIdResponse(i32 client_id) : m_client_id(move(client_id)) {}
    virtual ~ExposeWindowServerClientIdResponse() override {}

    virtual u32 endpoint_magic() const override { return 729082329; }
    virtual i32 message_id() const override { return (int)MessageID::ExposeWindowServerClientIdResponse; }
    static i32 static_message_id() { return (int)MessageID::ExposeWindowServerClientIdResponse; }
    virtual const char* message_name() const override { return "FileSystemAccessServer::ExposeWindowServerClientIdResponse"; }

    static OwnPtr<ExposeWindowServerClientIdResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 client_id = {};
        if (decoder.decode(client_id).is_error())
            return {};

        return make<ExposeWindowServerClientIdResponse>(move(client_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ExposeWindowServerClientIdResponse;

        stream << m_client_id;

        return buffer;
    }

    const i32& client_id() const { return m_client_id; }
    i32 take_client_id() { return move(m_client_id); }

private:
    bool m_ipc_message_valid { true };

    i32 m_client_id {};

};

class ExposeWindowServerClientId final : public IPC::Message {
public:

   typedef class ExposeWindowServerClientIdResponse ResponseType;

    ExposeWindowServerClientId(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ExposeWindowServerClientId(ExposeWindowServerClientId const&) = default;
    ExposeWindowServerClientId(ExposeWindowServerClientId&&) = default;
    ExposeWindowServerClientId& operator=(ExposeWindowServerClientId const&) = default;
    ExposeWindowServerClientId() {}
    virtual ~ExposeWindowServerClientId() override {}

    virtual u32 endpoint_magic() const override { return 729082329; }
    virtual i32 message_id() const override { return (int)MessageID::ExposeWindowServerClientId; }
    static i32 static_message_id() { return (int)MessageID::ExposeWindowServerClientId; }
    virtual const char* message_name() const override { return "FileSystemAccessServer::ExposeWindowServerClientId"; }

    static OwnPtr<ExposeWindowServerClientId> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<ExposeWindowServerClientId>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ExposeWindowServerClientId;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

} // namespace Messages::FileSystemAccessServer

template<typename LocalEndpoint, typename PeerEndpoint>
class FileSystemAccessServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    FileSystemAccessServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_request_file_read_only_approved(
i32 window_server_client_id, i32 window_id, String path) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::FileSystemAccessServer::RequestFileReadOnlyApproved { window_server_client_id, window_id, move(path) });

    }

    void async_request_file(
i32 window_server_client_id, i32 window_id, String path, Core::OpenMode requested_access) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::FileSystemAccessServer::RequestFile { window_server_client_id, window_id, move(path), move(requested_access) });

    }

    void async_prompt_open_file(
i32 window_server_client_id, i32 window_id, String window_title, String path_to_view, Core::OpenMode requested_access) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::FileSystemAccessServer::PromptOpenFile { window_server_client_id, window_id, move(window_title), move(path_to_view), move(requested_access) });

    }

    void async_prompt_save_file(
i32 window_server_client_id, i32 window_id, String title, String ext, String path_to_view, Core::OpenMode requested_access) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::FileSystemAccessServer::PromptSaveFile { window_server_client_id, window_id, move(title), move(ext), move(path_to_view), move(requested_access) });

    }

    i32 expose_window_server_client_id(
) {
        return m_connection.template send_sync<Messages::FileSystemAccessServer::ExposeWindowServerClientId>()->take_client_id();
    }

    void async_expose_window_server_client_id(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::FileSystemAccessServer::ExposeWindowServerClientId {  });

    }

    IPC::IPCErrorOr<i32> try_expose_window_server_client_id(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::FileSystemAccessServer::ExposeWindowServerClientId>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class FileSystemAccessServerProxy;
class FileSystemAccessServerStub;

class FileSystemAccessServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = FileSystemAccessServerProxy<LocalEndpoint, FileSystemAccessServerEndpoint>;
    using Stub = FileSystemAccessServerStub;

    static u32 static_magic() { return 729082329; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 729082329) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::FileSystemAccessServer::MessageID::RequestFileReadOnlyApproved:
            message = Messages::FileSystemAccessServer::RequestFileReadOnlyApproved::decode(stream, socket);
            break;

        case (int)Messages::FileSystemAccessServer::MessageID::RequestFile:
            message = Messages::FileSystemAccessServer::RequestFile::decode(stream, socket);
            break;

        case (int)Messages::FileSystemAccessServer::MessageID::PromptOpenFile:
            message = Messages::FileSystemAccessServer::PromptOpenFile::decode(stream, socket);
            break;

        case (int)Messages::FileSystemAccessServer::MessageID::PromptSaveFile:
            message = Messages::FileSystemAccessServer::PromptSaveFile::decode(stream, socket);
            break;

        case (int)Messages::FileSystemAccessServer::MessageID::ExposeWindowServerClientId:
            message = Messages::FileSystemAccessServer::ExposeWindowServerClientId::decode(stream, socket);
            break;

        case (int)Messages::FileSystemAccessServer::MessageID::ExposeWindowServerClientIdResponse:
            message = Messages::FileSystemAccessServer::ExposeWindowServerClientIdResponse::decode(stream, socket);
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

class FileSystemAccessServerStub : public IPC::Stub {
public:
    FileSystemAccessServerStub() { }
    virtual ~FileSystemAccessServerStub() override { }

    virtual u32 magic() const override { return 729082329; }
    virtual String name() const override { return "FileSystemAccessServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::FileSystemAccessServer::MessageID::RequestFileReadOnlyApproved: {

            [[maybe_unused]] auto& request = static_cast<const Messages::FileSystemAccessServer::RequestFileReadOnlyApproved&>(message);
            request_file_read_only_approved(request.window_server_client_id(), request.window_id(), request.path());
            return {};

        }

        case (int)Messages::FileSystemAccessServer::MessageID::RequestFile: {

            [[maybe_unused]] auto& request = static_cast<const Messages::FileSystemAccessServer::RequestFile&>(message);
            request_file(request.window_server_client_id(), request.window_id(), request.path(), request.requested_access());
            return {};

        }

        case (int)Messages::FileSystemAccessServer::MessageID::PromptOpenFile: {

            [[maybe_unused]] auto& request = static_cast<const Messages::FileSystemAccessServer::PromptOpenFile&>(message);
            prompt_open_file(request.window_server_client_id(), request.window_id(), request.window_title(), request.path_to_view(), request.requested_access());
            return {};

        }

        case (int)Messages::FileSystemAccessServer::MessageID::PromptSaveFile: {

            [[maybe_unused]] auto& request = static_cast<const Messages::FileSystemAccessServer::PromptSaveFile&>(message);
            prompt_save_file(request.window_server_client_id(), request.window_id(), request.title(), request.ext(), request.path_to_view(), request.requested_access());
            return {};

        }

        case (int)Messages::FileSystemAccessServer::MessageID::ExposeWindowServerClientId: {

            [[maybe_unused]] auto& request = static_cast<const Messages::FileSystemAccessServer::ExposeWindowServerClientId&>(message);
            auto response = expose_window_server_client_id();
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        default:
            return {};
        }
    }

    virtual void request_file_read_only_approved(
[[maybe_unused]] i32 window_server_client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] String const& path) = 0;

    virtual void request_file(
[[maybe_unused]] i32 window_server_client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] String const& path, [[maybe_unused]] Core::OpenMode const& requested_access) = 0;

    virtual void prompt_open_file(
[[maybe_unused]] i32 window_server_client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] String const& window_title, [[maybe_unused]] String const& path_to_view, [[maybe_unused]] Core::OpenMode const& requested_access) = 0;

    virtual void prompt_save_file(
[[maybe_unused]] i32 window_server_client_id, [[maybe_unused]] i32 window_id, [[maybe_unused]] String const& title, [[maybe_unused]] String const& ext, [[maybe_unused]] String const& path_to_view, [[maybe_unused]] Core::OpenMode const& requested_access) = 0;

    virtual Messages::FileSystemAccessServer::ExposeWindowServerClientIdResponse expose_window_server_client_id(
) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

