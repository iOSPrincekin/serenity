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

namespace Messages::LanguageServer {

enum class MessageID : i32 {
    Greet = 1,
    FileOpened = 2,
    FileEditInsertText = 3,
    FileEditRemoveText = 4,
    SetFileContent = 5,
    AutoCompleteSuggestions = 6,
    FindDeclaration = 7,
    GetParametersHint = 8,
    GetTokensInfo = 9,
};

class Greet final : public IPC::Message {
public:

    Greet(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Greet(Greet const&) = default;
    Greet(Greet&&) = default;
    Greet& operator=(Greet const&) = default;
    Greet(String project_root) : m_project_root(move(project_root)) {}
    virtual ~Greet() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::Greet; }
    static i32 static_message_id() { return (int)MessageID::Greet; }
    virtual const char* message_name() const override { return "LanguageServer::Greet"; }

    static OwnPtr<Greet> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String project_root = {};
        if (decoder.decode(project_root).is_error())
            return {};

        return make<Greet>(move(project_root));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Greet;

        stream << m_project_root;

        return buffer;
    }

    const String& project_root() const { return m_project_root; }
    String take_project_root() { return move(m_project_root); }

private:
    bool m_ipc_message_valid { true };

    String m_project_root {};

};

class FileOpened final : public IPC::Message {
public:

    FileOpened(decltype(nullptr)) : m_ipc_message_valid(false) { }
    FileOpened(FileOpened const&) = default;
    FileOpened(FileOpened&&) = default;
    FileOpened& operator=(FileOpened const&) = default;
    FileOpened(String filename, IPC::File file) : m_filename(move(filename)), m_file(move(file)) {}
    virtual ~FileOpened() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::FileOpened; }
    static i32 static_message_id() { return (int)MessageID::FileOpened; }
    virtual const char* message_name() const override { return "LanguageServer::FileOpened"; }

    static OwnPtr<FileOpened> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String filename = {};
        if (decoder.decode(filename).is_error())
            return {};

        IPC::File file = {};
        if (decoder.decode(file).is_error())
            return {};

        return make<FileOpened>(move(filename), move(file));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::FileOpened;

        stream << m_filename;

        stream << m_file;

        return buffer;
    }

    const String& filename() const { return m_filename; }
    String take_filename() { return move(m_filename); }

    const IPC::File& file() const { return m_file; }
    IPC::File take_file() { return move(m_file); }

private:
    bool m_ipc_message_valid { true };

    String m_filename {};

    IPC::File m_file {};

};

class FileEditInsertText final : public IPC::Message {
public:

    FileEditInsertText(decltype(nullptr)) : m_ipc_message_valid(false) { }
    FileEditInsertText(FileEditInsertText const&) = default;
    FileEditInsertText(FileEditInsertText&&) = default;
    FileEditInsertText& operator=(FileEditInsertText const&) = default;
    FileEditInsertText(String filename, String text, i32 start_line, i32 start_column) : m_filename(move(filename)), m_text(move(text)), m_start_line(move(start_line)), m_start_column(move(start_column)) {}
    virtual ~FileEditInsertText() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::FileEditInsertText; }
    static i32 static_message_id() { return (int)MessageID::FileEditInsertText; }
    virtual const char* message_name() const override { return "LanguageServer::FileEditInsertText"; }

    static OwnPtr<FileEditInsertText> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String filename = {};
        if (decoder.decode(filename).is_error())
            return {};

        String text = {};
        if (decoder.decode(text).is_error())
            return {};

        i32 start_line = {};
        if (decoder.decode(start_line).is_error())
            return {};

        i32 start_column = {};
        if (decoder.decode(start_column).is_error())
            return {};

        return make<FileEditInsertText>(move(filename), move(text), move(start_line), move(start_column));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::FileEditInsertText;

        stream << m_filename;

        stream << m_text;

        stream << m_start_line;

        stream << m_start_column;

        return buffer;
    }

    const String& filename() const { return m_filename; }
    String take_filename() { return move(m_filename); }

    const String& text() const { return m_text; }
    String take_text() { return move(m_text); }

    const i32& start_line() const { return m_start_line; }
    i32 take_start_line() { return move(m_start_line); }

    const i32& start_column() const { return m_start_column; }
    i32 take_start_column() { return move(m_start_column); }

private:
    bool m_ipc_message_valid { true };

    String m_filename {};

    String m_text {};

    i32 m_start_line {};

    i32 m_start_column {};

};

class FileEditRemoveText final : public IPC::Message {
public:

    FileEditRemoveText(decltype(nullptr)) : m_ipc_message_valid(false) { }
    FileEditRemoveText(FileEditRemoveText const&) = default;
    FileEditRemoveText(FileEditRemoveText&&) = default;
    FileEditRemoveText& operator=(FileEditRemoveText const&) = default;
    FileEditRemoveText(String filename, i32 start_line, i32 start_column, i32 end_line, i32 end_column) : m_filename(move(filename)), m_start_line(move(start_line)), m_start_column(move(start_column)), m_end_line(move(end_line)), m_end_column(move(end_column)) {}
    virtual ~FileEditRemoveText() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::FileEditRemoveText; }
    static i32 static_message_id() { return (int)MessageID::FileEditRemoveText; }
    virtual const char* message_name() const override { return "LanguageServer::FileEditRemoveText"; }

    static OwnPtr<FileEditRemoveText> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String filename = {};
        if (decoder.decode(filename).is_error())
            return {};

        i32 start_line = {};
        if (decoder.decode(start_line).is_error())
            return {};

        i32 start_column = {};
        if (decoder.decode(start_column).is_error())
            return {};

        i32 end_line = {};
        if (decoder.decode(end_line).is_error())
            return {};

        i32 end_column = {};
        if (decoder.decode(end_column).is_error())
            return {};

        return make<FileEditRemoveText>(move(filename), move(start_line), move(start_column), move(end_line), move(end_column));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::FileEditRemoveText;

        stream << m_filename;

        stream << m_start_line;

        stream << m_start_column;

        stream << m_end_line;

        stream << m_end_column;

        return buffer;
    }

    const String& filename() const { return m_filename; }
    String take_filename() { return move(m_filename); }

    const i32& start_line() const { return m_start_line; }
    i32 take_start_line() { return move(m_start_line); }

    const i32& start_column() const { return m_start_column; }
    i32 take_start_column() { return move(m_start_column); }

    const i32& end_line() const { return m_end_line; }
    i32 take_end_line() { return move(m_end_line); }

    const i32& end_column() const { return m_end_column; }
    i32 take_end_column() { return move(m_end_column); }

private:
    bool m_ipc_message_valid { true };

    String m_filename {};

    i32 m_start_line {};

    i32 m_start_column {};

    i32 m_end_line {};

    i32 m_end_column {};

};

class SetFileContent final : public IPC::Message {
public:

    SetFileContent(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SetFileContent(SetFileContent const&) = default;
    SetFileContent(SetFileContent&&) = default;
    SetFileContent& operator=(SetFileContent const&) = default;
    SetFileContent(String filename, String content) : m_filename(move(filename)), m_content(move(content)) {}
    virtual ~SetFileContent() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::SetFileContent; }
    static i32 static_message_id() { return (int)MessageID::SetFileContent; }
    virtual const char* message_name() const override { return "LanguageServer::SetFileContent"; }

    static OwnPtr<SetFileContent> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String filename = {};
        if (decoder.decode(filename).is_error())
            return {};

        String content = {};
        if (decoder.decode(content).is_error())
            return {};

        return make<SetFileContent>(move(filename), move(content));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SetFileContent;

        stream << m_filename;

        stream << m_content;

        return buffer;
    }

    const String& filename() const { return m_filename; }
    String take_filename() { return move(m_filename); }

    const String& content() const { return m_content; }
    String take_content() { return move(m_content); }

private:
    bool m_ipc_message_valid { true };

    String m_filename {};

    String m_content {};

};

class AutoCompleteSuggestions final : public IPC::Message {
public:

    AutoCompleteSuggestions(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AutoCompleteSuggestions(AutoCompleteSuggestions const&) = default;
    AutoCompleteSuggestions(AutoCompleteSuggestions&&) = default;
    AutoCompleteSuggestions& operator=(AutoCompleteSuggestions const&) = default;
    AutoCompleteSuggestions(GUI::AutocompleteProvider::ProjectLocation location) : m_location(move(location)) {}
    virtual ~AutoCompleteSuggestions() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::AutoCompleteSuggestions; }
    static i32 static_message_id() { return (int)MessageID::AutoCompleteSuggestions; }
    virtual const char* message_name() const override { return "LanguageServer::AutoCompleteSuggestions"; }

    static OwnPtr<AutoCompleteSuggestions> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        GUI::AutocompleteProvider::ProjectLocation location = {};
        if (decoder.decode(location).is_error())
            return {};

        return make<AutoCompleteSuggestions>(move(location));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AutoCompleteSuggestions;

        stream << m_location;

        return buffer;
    }

    const GUI::AutocompleteProvider::ProjectLocation& location() const { return m_location; }
    GUI::AutocompleteProvider::ProjectLocation take_location() { return move(m_location); }

private:
    bool m_ipc_message_valid { true };

    GUI::AutocompleteProvider::ProjectLocation m_location {};

};

class FindDeclaration final : public IPC::Message {
public:

    FindDeclaration(decltype(nullptr)) : m_ipc_message_valid(false) { }
    FindDeclaration(FindDeclaration const&) = default;
    FindDeclaration(FindDeclaration&&) = default;
    FindDeclaration& operator=(FindDeclaration const&) = default;
    FindDeclaration(GUI::AutocompleteProvider::ProjectLocation location) : m_location(move(location)) {}
    virtual ~FindDeclaration() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::FindDeclaration; }
    static i32 static_message_id() { return (int)MessageID::FindDeclaration; }
    virtual const char* message_name() const override { return "LanguageServer::FindDeclaration"; }

    static OwnPtr<FindDeclaration> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        GUI::AutocompleteProvider::ProjectLocation location = {};
        if (decoder.decode(location).is_error())
            return {};

        return make<FindDeclaration>(move(location));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::FindDeclaration;

        stream << m_location;

        return buffer;
    }

    const GUI::AutocompleteProvider::ProjectLocation& location() const { return m_location; }
    GUI::AutocompleteProvider::ProjectLocation take_location() { return move(m_location); }

private:
    bool m_ipc_message_valid { true };

    GUI::AutocompleteProvider::ProjectLocation m_location {};

};

class GetParametersHint final : public IPC::Message {
public:

    GetParametersHint(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetParametersHint(GetParametersHint const&) = default;
    GetParametersHint(GetParametersHint&&) = default;
    GetParametersHint& operator=(GetParametersHint const&) = default;
    GetParametersHint(GUI::AutocompleteProvider::ProjectLocation location) : m_location(move(location)) {}
    virtual ~GetParametersHint() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::GetParametersHint; }
    static i32 static_message_id() { return (int)MessageID::GetParametersHint; }
    virtual const char* message_name() const override { return "LanguageServer::GetParametersHint"; }

    static OwnPtr<GetParametersHint> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        GUI::AutocompleteProvider::ProjectLocation location = {};
        if (decoder.decode(location).is_error())
            return {};

        return make<GetParametersHint>(move(location));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetParametersHint;

        stream << m_location;

        return buffer;
    }

    const GUI::AutocompleteProvider::ProjectLocation& location() const { return m_location; }
    GUI::AutocompleteProvider::ProjectLocation take_location() { return move(m_location); }

private:
    bool m_ipc_message_valid { true };

    GUI::AutocompleteProvider::ProjectLocation m_location {};

};

class GetTokensInfo final : public IPC::Message {
public:

    GetTokensInfo(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetTokensInfo(GetTokensInfo const&) = default;
    GetTokensInfo(GetTokensInfo&&) = default;
    GetTokensInfo& operator=(GetTokensInfo const&) = default;
    GetTokensInfo(String filename) : m_filename(move(filename)) {}
    virtual ~GetTokensInfo() override {}

    virtual u32 endpoint_magic() const override { return 3294800782; }
    virtual i32 message_id() const override { return (int)MessageID::GetTokensInfo; }
    static i32 static_message_id() { return (int)MessageID::GetTokensInfo; }
    virtual const char* message_name() const override { return "LanguageServer::GetTokensInfo"; }

    static OwnPtr<GetTokensInfo> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String filename = {};
        if (decoder.decode(filename).is_error())
            return {};

        return make<GetTokensInfo>(move(filename));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetTokensInfo;

        stream << m_filename;

        return buffer;
    }

    const String& filename() const { return m_filename; }
    String take_filename() { return move(m_filename); }

private:
    bool m_ipc_message_valid { true };

    String m_filename {};

};

} // namespace Messages::LanguageServer

template<typename LocalEndpoint, typename PeerEndpoint>
class LanguageServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    LanguageServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_greet(
String project_root) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::Greet { move(project_root) });

    }

    void async_file_opened(
String filename, IPC::File file) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::FileOpened { move(filename), move(file) });

    }

    void async_file_edit_insert_text(
String filename, String text, i32 start_line, i32 start_column) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::FileEditInsertText { move(filename), move(text), start_line, start_column });

    }

    void async_file_edit_remove_text(
String filename, i32 start_line, i32 start_column, i32 end_line, i32 end_column) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::FileEditRemoveText { move(filename), start_line, start_column, end_line, end_column });

    }

    void async_set_file_content(
String filename, String content) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::SetFileContent { move(filename), move(content) });

    }

    void async_auto_complete_suggestions(
GUI::AutocompleteProvider::ProjectLocation location) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::AutoCompleteSuggestions { move(location) });

    }

    void async_find_declaration(
GUI::AutocompleteProvider::ProjectLocation location) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::FindDeclaration { move(location) });

    }

    void async_get_parameters_hint(
GUI::AutocompleteProvider::ProjectLocation location) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::GetParametersHint { move(location) });

    }

    void async_get_tokens_info(
String filename) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageServer::GetTokensInfo { move(filename) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class LanguageServerProxy;
class LanguageServerStub;

class LanguageServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = LanguageServerProxy<LocalEndpoint, LanguageServerEndpoint>;
    using Stub = LanguageServerStub;

    static u32 static_magic() { return 3294800782; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3294800782) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::LanguageServer::MessageID::Greet:
            message = Messages::LanguageServer::Greet::decode(stream, socket);
            break;

        case (int)Messages::LanguageServer::MessageID::FileOpened:
            message = Messages::LanguageServer::FileOpened::decode(stream, socket);
            break;

        case (int)Messages::LanguageServer::MessageID::FileEditInsertText:
            message = Messages::LanguageServer::FileEditInsertText::decode(stream, socket);
            break;

        case (int)Messages::LanguageServer::MessageID::FileEditRemoveText:
            message = Messages::LanguageServer::FileEditRemoveText::decode(stream, socket);
            break;

        case (int)Messages::LanguageServer::MessageID::SetFileContent:
            message = Messages::LanguageServer::SetFileContent::decode(stream, socket);
            break;

        case (int)Messages::LanguageServer::MessageID::AutoCompleteSuggestions:
            message = Messages::LanguageServer::AutoCompleteSuggestions::decode(stream, socket);
            break;

        case (int)Messages::LanguageServer::MessageID::FindDeclaration:
            message = Messages::LanguageServer::FindDeclaration::decode(stream, socket);
            break;

        case (int)Messages::LanguageServer::MessageID::GetParametersHint:
            message = Messages::LanguageServer::GetParametersHint::decode(stream, socket);
            break;

        case (int)Messages::LanguageServer::MessageID::GetTokensInfo:
            message = Messages::LanguageServer::GetTokensInfo::decode(stream, socket);
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

class LanguageServerStub : public IPC::Stub {
public:
    LanguageServerStub() { }
    virtual ~LanguageServerStub() override { }

    virtual u32 magic() const override { return 3294800782; }
    virtual String name() const override { return "LanguageServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::LanguageServer::MessageID::Greet: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::Greet&>(message);
            greet(request.project_root());
            return {};

        }

        case (int)Messages::LanguageServer::MessageID::FileOpened: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::FileOpened&>(message);
            file_opened(request.filename(), request.file());
            return {};

        }

        case (int)Messages::LanguageServer::MessageID::FileEditInsertText: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::FileEditInsertText&>(message);
            file_edit_insert_text(request.filename(), request.text(), request.start_line(), request.start_column());
            return {};

        }

        case (int)Messages::LanguageServer::MessageID::FileEditRemoveText: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::FileEditRemoveText&>(message);
            file_edit_remove_text(request.filename(), request.start_line(), request.start_column(), request.end_line(), request.end_column());
            return {};

        }

        case (int)Messages::LanguageServer::MessageID::SetFileContent: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::SetFileContent&>(message);
            set_file_content(request.filename(), request.content());
            return {};

        }

        case (int)Messages::LanguageServer::MessageID::AutoCompleteSuggestions: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::AutoCompleteSuggestions&>(message);
            auto_complete_suggestions(request.location());
            return {};

        }

        case (int)Messages::LanguageServer::MessageID::FindDeclaration: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::FindDeclaration&>(message);
            find_declaration(request.location());
            return {};

        }

        case (int)Messages::LanguageServer::MessageID::GetParametersHint: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::GetParametersHint&>(message);
            get_parameters_hint(request.location());
            return {};

        }

        case (int)Messages::LanguageServer::MessageID::GetTokensInfo: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageServer::GetTokensInfo&>(message);
            get_tokens_info(request.filename());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void greet(
[[maybe_unused]] String const& project_root) = 0;

    virtual void file_opened(
[[maybe_unused]] String const& filename, [[maybe_unused]] IPC::File const& file) = 0;

    virtual void file_edit_insert_text(
[[maybe_unused]] String const& filename, [[maybe_unused]] String const& text, [[maybe_unused]] i32 start_line, [[maybe_unused]] i32 start_column) = 0;

    virtual void file_edit_remove_text(
[[maybe_unused]] String const& filename, [[maybe_unused]] i32 start_line, [[maybe_unused]] i32 start_column, [[maybe_unused]] i32 end_line, [[maybe_unused]] i32 end_column) = 0;

    virtual void set_file_content(
[[maybe_unused]] String const& filename, [[maybe_unused]] String const& content) = 0;

    virtual void auto_complete_suggestions(
[[maybe_unused]] GUI::AutocompleteProvider::ProjectLocation const& location) = 0;

    virtual void find_declaration(
[[maybe_unused]] GUI::AutocompleteProvider::ProjectLocation const& location) = 0;

    virtual void get_parameters_hint(
[[maybe_unused]] GUI::AutocompleteProvider::ProjectLocation const& location) = 0;

    virtual void get_tokens_info(
[[maybe_unused]] String const& filename) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

