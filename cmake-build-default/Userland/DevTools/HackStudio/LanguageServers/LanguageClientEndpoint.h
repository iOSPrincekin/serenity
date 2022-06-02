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

namespace Messages::LanguageClient {

enum class MessageID : i32 {
    AutoCompleteSuggestions = 1,
    DeclarationLocation = 2,
    DeclarationsInDocument = 3,
    TodoEntriesInDocument = 4,
    ParametersHintResult = 5,
    TokensInfoResult = 6,
};

class AutoCompleteSuggestions final : public IPC::Message {
public:

    AutoCompleteSuggestions(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AutoCompleteSuggestions(AutoCompleteSuggestions const&) = default;
    AutoCompleteSuggestions(AutoCompleteSuggestions&&) = default;
    AutoCompleteSuggestions& operator=(AutoCompleteSuggestions const&) = default;
    AutoCompleteSuggestions(Vector<GUI::AutocompleteProvider::Entry> suggestions) : m_suggestions(move(suggestions)) {}
    virtual ~AutoCompleteSuggestions() override {}

    virtual u32 endpoint_magic() const override { return 114752332; }
    virtual i32 message_id() const override { return (int)MessageID::AutoCompleteSuggestions; }
    static i32 static_message_id() { return (int)MessageID::AutoCompleteSuggestions; }
    virtual const char* message_name() const override { return "LanguageClient::AutoCompleteSuggestions"; }

    static OwnPtr<AutoCompleteSuggestions> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<GUI::AutocompleteProvider::Entry> suggestions = {};
        if (decoder.decode(suggestions).is_error())
            return {};

        return make<AutoCompleteSuggestions>(move(suggestions));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AutoCompleteSuggestions;

        stream << m_suggestions;

        return buffer;
    }

    const Vector<GUI::AutocompleteProvider::Entry>& suggestions() const { return m_suggestions; }
    Vector<GUI::AutocompleteProvider::Entry> take_suggestions() { return move(m_suggestions); }

private:
    bool m_ipc_message_valid { true };

    Vector<GUI::AutocompleteProvider::Entry> m_suggestions {};

};

class DeclarationLocation final : public IPC::Message {
public:

    DeclarationLocation(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DeclarationLocation(DeclarationLocation const&) = default;
    DeclarationLocation(DeclarationLocation&&) = default;
    DeclarationLocation& operator=(DeclarationLocation const&) = default;
    DeclarationLocation(GUI::AutocompleteProvider::ProjectLocation location) : m_location(move(location)) {}
    virtual ~DeclarationLocation() override {}

    virtual u32 endpoint_magic() const override { return 114752332; }
    virtual i32 message_id() const override { return (int)MessageID::DeclarationLocation; }
    static i32 static_message_id() { return (int)MessageID::DeclarationLocation; }
    virtual const char* message_name() const override { return "LanguageClient::DeclarationLocation"; }

    static OwnPtr<DeclarationLocation> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        GUI::AutocompleteProvider::ProjectLocation location = {};
        if (decoder.decode(location).is_error())
            return {};

        return make<DeclarationLocation>(move(location));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DeclarationLocation;

        stream << m_location;

        return buffer;
    }

    const GUI::AutocompleteProvider::ProjectLocation& location() const { return m_location; }
    GUI::AutocompleteProvider::ProjectLocation take_location() { return move(m_location); }

private:
    bool m_ipc_message_valid { true };

    GUI::AutocompleteProvider::ProjectLocation m_location {};

};

class DeclarationsInDocument final : public IPC::Message {
public:

    DeclarationsInDocument(decltype(nullptr)) : m_ipc_message_valid(false) { }
    DeclarationsInDocument(DeclarationsInDocument const&) = default;
    DeclarationsInDocument(DeclarationsInDocument&&) = default;
    DeclarationsInDocument& operator=(DeclarationsInDocument const&) = default;
    DeclarationsInDocument(String filename, Vector<GUI::AutocompleteProvider::Declaration> declarations) : m_filename(move(filename)), m_declarations(move(declarations)) {}
    virtual ~DeclarationsInDocument() override {}

    virtual u32 endpoint_magic() const override { return 114752332; }
    virtual i32 message_id() const override { return (int)MessageID::DeclarationsInDocument; }
    static i32 static_message_id() { return (int)MessageID::DeclarationsInDocument; }
    virtual const char* message_name() const override { return "LanguageClient::DeclarationsInDocument"; }

    static OwnPtr<DeclarationsInDocument> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String filename = {};
        if (decoder.decode(filename).is_error())
            return {};

        Vector<GUI::AutocompleteProvider::Declaration> declarations = {};
        if (decoder.decode(declarations).is_error())
            return {};

        return make<DeclarationsInDocument>(move(filename), move(declarations));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::DeclarationsInDocument;

        stream << m_filename;

        stream << m_declarations;

        return buffer;
    }

    const String& filename() const { return m_filename; }
    String take_filename() { return move(m_filename); }

    const Vector<GUI::AutocompleteProvider::Declaration>& declarations() const { return m_declarations; }
    Vector<GUI::AutocompleteProvider::Declaration> take_declarations() { return move(m_declarations); }

private:
    bool m_ipc_message_valid { true };

    String m_filename {};

    Vector<GUI::AutocompleteProvider::Declaration> m_declarations {};

};

class TodoEntriesInDocument final : public IPC::Message {
public:

    TodoEntriesInDocument(decltype(nullptr)) : m_ipc_message_valid(false) { }
    TodoEntriesInDocument(TodoEntriesInDocument const&) = default;
    TodoEntriesInDocument(TodoEntriesInDocument&&) = default;
    TodoEntriesInDocument& operator=(TodoEntriesInDocument const&) = default;
    TodoEntriesInDocument(String filename, Vector<Cpp::Parser::TodoEntry> todo_entries) : m_filename(move(filename)), m_todo_entries(move(todo_entries)) {}
    virtual ~TodoEntriesInDocument() override {}

    virtual u32 endpoint_magic() const override { return 114752332; }
    virtual i32 message_id() const override { return (int)MessageID::TodoEntriesInDocument; }
    static i32 static_message_id() { return (int)MessageID::TodoEntriesInDocument; }
    virtual const char* message_name() const override { return "LanguageClient::TodoEntriesInDocument"; }

    static OwnPtr<TodoEntriesInDocument> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String filename = {};
        if (decoder.decode(filename).is_error())
            return {};

        Vector<Cpp::Parser::TodoEntry> todo_entries = {};
        if (decoder.decode(todo_entries).is_error())
            return {};

        return make<TodoEntriesInDocument>(move(filename), move(todo_entries));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::TodoEntriesInDocument;

        stream << m_filename;

        stream << m_todo_entries;

        return buffer;
    }

    const String& filename() const { return m_filename; }
    String take_filename() { return move(m_filename); }

    const Vector<Cpp::Parser::TodoEntry>& todo_entries() const { return m_todo_entries; }
    Vector<Cpp::Parser::TodoEntry> take_todo_entries() { return move(m_todo_entries); }

private:
    bool m_ipc_message_valid { true };

    String m_filename {};

    Vector<Cpp::Parser::TodoEntry> m_todo_entries {};

};

class ParametersHintResult final : public IPC::Message {
public:

    ParametersHintResult(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ParametersHintResult(ParametersHintResult const&) = default;
    ParametersHintResult(ParametersHintResult&&) = default;
    ParametersHintResult& operator=(ParametersHintResult const&) = default;
    ParametersHintResult(Vector<String> params, int current_index) : m_params(move(params)), m_current_index(move(current_index)) {}
    virtual ~ParametersHintResult() override {}

    virtual u32 endpoint_magic() const override { return 114752332; }
    virtual i32 message_id() const override { return (int)MessageID::ParametersHintResult; }
    static i32 static_message_id() { return (int)MessageID::ParametersHintResult; }
    virtual const char* message_name() const override { return "LanguageClient::ParametersHintResult"; }

    static OwnPtr<ParametersHintResult> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<String> params = {};
        if (decoder.decode(params).is_error())
            return {};

        int current_index = {};
        if (decoder.decode(current_index).is_error())
            return {};

        return make<ParametersHintResult>(move(params), move(current_index));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ParametersHintResult;

        stream << m_params;

        stream << m_current_index;

        return buffer;
    }

    const Vector<String>& params() const { return m_params; }
    Vector<String> take_params() { return move(m_params); }

    const int& current_index() const { return m_current_index; }
    int take_current_index() { return move(m_current_index); }

private:
    bool m_ipc_message_valid { true };

    Vector<String> m_params {};

    int m_current_index {};

};

class TokensInfoResult final : public IPC::Message {
public:

    TokensInfoResult(decltype(nullptr)) : m_ipc_message_valid(false) { }
    TokensInfoResult(TokensInfoResult const&) = default;
    TokensInfoResult(TokensInfoResult&&) = default;
    TokensInfoResult& operator=(TokensInfoResult const&) = default;
    TokensInfoResult(Vector<GUI::AutocompleteProvider::TokenInfo> tokens_info) : m_tokens_info(move(tokens_info)) {}
    virtual ~TokensInfoResult() override {}

    virtual u32 endpoint_magic() const override { return 114752332; }
    virtual i32 message_id() const override { return (int)MessageID::TokensInfoResult; }
    static i32 static_message_id() { return (int)MessageID::TokensInfoResult; }
    virtual const char* message_name() const override { return "LanguageClient::TokensInfoResult"; }

    static OwnPtr<TokensInfoResult> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<GUI::AutocompleteProvider::TokenInfo> tokens_info = {};
        if (decoder.decode(tokens_info).is_error())
            return {};

        return make<TokensInfoResult>(move(tokens_info));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::TokensInfoResult;

        stream << m_tokens_info;

        return buffer;
    }

    const Vector<GUI::AutocompleteProvider::TokenInfo>& tokens_info() const { return m_tokens_info; }
    Vector<GUI::AutocompleteProvider::TokenInfo> take_tokens_info() { return move(m_tokens_info); }

private:
    bool m_ipc_message_valid { true };

    Vector<GUI::AutocompleteProvider::TokenInfo> m_tokens_info {};

};

} // namespace Messages::LanguageClient

template<typename LocalEndpoint, typename PeerEndpoint>
class LanguageClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    LanguageClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_auto_complete_suggestions(
Vector<GUI::AutocompleteProvider::Entry> suggestions) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageClient::AutoCompleteSuggestions { move(suggestions) });

    }

    void async_declaration_location(
GUI::AutocompleteProvider::ProjectLocation location) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageClient::DeclarationLocation { move(location) });

    }

    void async_declarations_in_document(
String filename, Vector<GUI::AutocompleteProvider::Declaration> declarations) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageClient::DeclarationsInDocument { move(filename), move(declarations) });

    }

    void async_todo_entries_in_document(
String filename, Vector<Cpp::Parser::TodoEntry> todo_entries) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageClient::TodoEntriesInDocument { move(filename), move(todo_entries) });

    }

    void async_parameters_hint_result(
Vector<String> params, int current_index) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageClient::ParametersHintResult { move(params), current_index });

    }

    void async_tokens_info_result(
Vector<GUI::AutocompleteProvider::TokenInfo> tokens_info) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LanguageClient::TokensInfoResult { move(tokens_info) });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class LanguageClientProxy;
class LanguageClientStub;

class LanguageClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = LanguageClientProxy<LocalEndpoint, LanguageClientEndpoint>;
    using Stub = LanguageClientStub;

    static u32 static_magic() { return 114752332; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 114752332) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::LanguageClient::MessageID::AutoCompleteSuggestions:
            message = Messages::LanguageClient::AutoCompleteSuggestions::decode(stream, socket);
            break;

        case (int)Messages::LanguageClient::MessageID::DeclarationLocation:
            message = Messages::LanguageClient::DeclarationLocation::decode(stream, socket);
            break;

        case (int)Messages::LanguageClient::MessageID::DeclarationsInDocument:
            message = Messages::LanguageClient::DeclarationsInDocument::decode(stream, socket);
            break;

        case (int)Messages::LanguageClient::MessageID::TodoEntriesInDocument:
            message = Messages::LanguageClient::TodoEntriesInDocument::decode(stream, socket);
            break;

        case (int)Messages::LanguageClient::MessageID::ParametersHintResult:
            message = Messages::LanguageClient::ParametersHintResult::decode(stream, socket);
            break;

        case (int)Messages::LanguageClient::MessageID::TokensInfoResult:
            message = Messages::LanguageClient::TokensInfoResult::decode(stream, socket);
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

class LanguageClientStub : public IPC::Stub {
public:
    LanguageClientStub() { }
    virtual ~LanguageClientStub() override { }

    virtual u32 magic() const override { return 114752332; }
    virtual String name() const override { return "LanguageClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::LanguageClient::MessageID::AutoCompleteSuggestions: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageClient::AutoCompleteSuggestions&>(message);
            auto_complete_suggestions(request.suggestions());
            return {};

        }

        case (int)Messages::LanguageClient::MessageID::DeclarationLocation: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageClient::DeclarationLocation&>(message);
            declaration_location(request.location());
            return {};

        }

        case (int)Messages::LanguageClient::MessageID::DeclarationsInDocument: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageClient::DeclarationsInDocument&>(message);
            declarations_in_document(request.filename(), request.declarations());
            return {};

        }

        case (int)Messages::LanguageClient::MessageID::TodoEntriesInDocument: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageClient::TodoEntriesInDocument&>(message);
            todo_entries_in_document(request.filename(), request.todo_entries());
            return {};

        }

        case (int)Messages::LanguageClient::MessageID::ParametersHintResult: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageClient::ParametersHintResult&>(message);
            parameters_hint_result(request.params(), request.current_index());
            return {};

        }

        case (int)Messages::LanguageClient::MessageID::TokensInfoResult: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LanguageClient::TokensInfoResult&>(message);
            tokens_info_result(request.tokens_info());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void auto_complete_suggestions(
[[maybe_unused]] Vector<GUI::AutocompleteProvider::Entry> const& suggestions) = 0;

    virtual void declaration_location(
[[maybe_unused]] GUI::AutocompleteProvider::ProjectLocation const& location) = 0;

    virtual void declarations_in_document(
[[maybe_unused]] String const& filename, [[maybe_unused]] Vector<GUI::AutocompleteProvider::Declaration> const& declarations) = 0;

    virtual void todo_entries_in_document(
[[maybe_unused]] String const& filename, [[maybe_unused]] Vector<Cpp::Parser::TodoEntry> const& todo_entries) = 0;

    virtual void parameters_hint_result(
[[maybe_unused]] Vector<String> const& params, [[maybe_unused]] int current_index) = 0;

    virtual void tokens_info_result(
[[maybe_unused]] Vector<GUI::AutocompleteProvider::TokenInfo> const& tokens_info) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

