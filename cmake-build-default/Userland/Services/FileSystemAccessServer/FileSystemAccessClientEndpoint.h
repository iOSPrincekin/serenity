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

namespace Messages::FileSystemAccessClient {

enum class MessageID : i32 {
    HandlePromptEnd = 1,
};

class HandlePromptEnd final : public IPC::Message {
public:

    HandlePromptEnd(decltype(nullptr)) : m_ipc_message_valid(false) { }
    HandlePromptEnd(HandlePromptEnd const&) = default;
    HandlePromptEnd(HandlePromptEnd&&) = default;
    HandlePromptEnd& operator=(HandlePromptEnd const&) = default;
    HandlePromptEnd(i32 error, Optional<IPC::File> fd, Optional<String> chosen_file) : m_error(move(error)), m_fd(move(fd)), m_chosen_file(move(chosen_file)) {}
    virtual ~HandlePromptEnd() override {}

    virtual u32 endpoint_magic() const override { return 3747304165; }
    virtual i32 message_id() const override { return (int)MessageID::HandlePromptEnd; }
    static i32 static_message_id() { return (int)MessageID::HandlePromptEnd; }
    virtual const char* message_name() const override { return "FileSystemAccessClient::HandlePromptEnd"; }

    static OwnPtr<HandlePromptEnd> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        i32 error = {};
        if (decoder.decode(error).is_error())
            return {};

        Optional<IPC::File> fd = {};
        if (decoder.decode(fd).is_error())
            return {};

        Optional<String> chosen_file = {};
        if (decoder.decode(chosen_file).is_error())
            return {};

        return make<HandlePromptEnd>(move(error), move(fd), move(chosen_file));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::HandlePromptEnd;

        stream << m_error;

        stream << m_fd;

        stream << m_chosen_file;

        return buffer;
    }

    const i32& error() const { return m_error; }
    i32 take_error() { return move(m_error); }

    const Optional<IPC::File>& fd() const { return m_fd; }
    Optional<IPC::File> take_fd() { return move(m_fd); }

    const Optional<String>& chosen_file() const { return m_chosen_file; }
    Optional<String> take_chosen_file() { return move(m_chosen_file); }

private:
    bool m_ipc_message_valid { true };

    i32 m_error {};

    Optional<IPC::File> m_fd {};

    Optional<String> m_chosen_file {};

};

} // namespace Messages::FileSystemAccessClient

template<typename LocalEndpoint, typename PeerEndpoint>
class FileSystemAccessClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    FileSystemAccessClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_handle_prompt_end(
i32 error, Optional<IPC::File> fd, Optional<String> chosen_file) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::FileSystemAccessClient::HandlePromptEnd { error, move(fd), move(chosen_file) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class FileSystemAccessClientProxy;
class FileSystemAccessClientStub;

class FileSystemAccessClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = FileSystemAccessClientProxy<LocalEndpoint, FileSystemAccessClientEndpoint>;
    using Stub = FileSystemAccessClientStub;

    static u32 static_magic() { return 3747304165; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3747304165) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::FileSystemAccessClient::MessageID::HandlePromptEnd:
            message = Messages::FileSystemAccessClient::HandlePromptEnd::decode(stream, socket);
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

class FileSystemAccessClientStub : public IPC::Stub {
public:
    FileSystemAccessClientStub() { }
    virtual ~FileSystemAccessClientStub() override { }

    virtual u32 magic() const override { return 3747304165; }
    virtual String name() const override { return "FileSystemAccessClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::FileSystemAccessClient::MessageID::HandlePromptEnd: {

            [[maybe_unused]] auto& request = static_cast<const Messages::FileSystemAccessClient::HandlePromptEnd&>(message);
            handle_prompt_end(request.error(), request.fd(), request.chosen_file());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void handle_prompt_end(
[[maybe_unused]] i32 error, [[maybe_unused]] Optional<IPC::File> const& fd, [[maybe_unused]] Optional<String> const& chosen_file) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

