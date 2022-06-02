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

namespace Messages::SQLClient {

enum class MessageID : i32 {
    Connected = 1,
    ConnectionError = 2,
    ExecutionSuccess = 3,
    NextResult = 4,
    ResultsExhausted = 5,
    ExecutionError = 6,
    Disconnected = 7,
};

class Connected final : public IPC::Message {
public:

    Connected(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Connected(Connected const&) = default;
    Connected(Connected&&) = default;
    Connected& operator=(Connected const&) = default;
    Connected(int connection_id, String connected_to_database) : m_connection_id(move(connection_id)), m_connected_to_database(move(connected_to_database)) {}
    virtual ~Connected() override {}

    virtual u32 endpoint_magic() const override { return 531353361; }
    virtual i32 message_id() const override { return (int)MessageID::Connected; }
    static i32 static_message_id() { return (int)MessageID::Connected; }
    virtual const char* message_name() const override { return "SQLClient::Connected"; }

    static OwnPtr<Connected> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        String connected_to_database = {};
        if (decoder.decode(connected_to_database).is_error())
            return {};

        return make<Connected>(move(connection_id), move(connected_to_database));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Connected;

        stream << m_connection_id;

        stream << m_connected_to_database;

        return buffer;
    }

    const int& connection_id() const { return m_connection_id; }
    int take_connection_id() { return move(m_connection_id); }

    const String& connected_to_database() const { return m_connected_to_database; }
    String take_connected_to_database() { return move(m_connected_to_database); }

private:
    bool m_ipc_message_valid { true };

    int m_connection_id {};

    String m_connected_to_database {};

};

class ConnectionError final : public IPC::Message {
public:

    ConnectionError(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ConnectionError(ConnectionError const&) = default;
    ConnectionError(ConnectionError&&) = default;
    ConnectionError& operator=(ConnectionError const&) = default;
    ConnectionError(int connection_id, int code, String message) : m_connection_id(move(connection_id)), m_code(move(code)), m_message(move(message)) {}
    virtual ~ConnectionError() override {}

    virtual u32 endpoint_magic() const override { return 531353361; }
    virtual i32 message_id() const override { return (int)MessageID::ConnectionError; }
    static i32 static_message_id() { return (int)MessageID::ConnectionError; }
    virtual const char* message_name() const override { return "SQLClient::ConnectionError"; }

    static OwnPtr<ConnectionError> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        int code = {};
        if (decoder.decode(code).is_error())
            return {};

        String message = {};
        if (decoder.decode(message).is_error())
            return {};

        return make<ConnectionError>(move(connection_id), move(code), move(message));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ConnectionError;

        stream << m_connection_id;

        stream << m_code;

        stream << m_message;

        return buffer;
    }

    const int& connection_id() const { return m_connection_id; }
    int take_connection_id() { return move(m_connection_id); }

    const int& code() const { return m_code; }
    int take_code() { return move(m_code); }

    const String& message() const { return m_message; }
    String take_message() { return move(m_message); }

private:
    bool m_ipc_message_valid { true };

    int m_connection_id {};

    int m_code {};

    String m_message {};

};

class ExecutionSuccess final : public IPC::Message {
public:

    ExecutionSuccess(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ExecutionSuccess(ExecutionSuccess const&) = default;
    ExecutionSuccess(ExecutionSuccess&&) = default;
    ExecutionSuccess& operator=(ExecutionSuccess const&) = default;
    ExecutionSuccess(int statement_id, bool has_results, int created, int updated, int deleted) : m_statement_id(move(statement_id)), m_has_results(move(has_results)), m_created(move(created)), m_updated(move(updated)), m_deleted(move(deleted)) {}
    virtual ~ExecutionSuccess() override {}

    virtual u32 endpoint_magic() const override { return 531353361; }
    virtual i32 message_id() const override { return (int)MessageID::ExecutionSuccess; }
    static i32 static_message_id() { return (int)MessageID::ExecutionSuccess; }
    virtual const char* message_name() const override { return "SQLClient::ExecutionSuccess"; }

    static OwnPtr<ExecutionSuccess> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int statement_id = {};
        if (decoder.decode(statement_id).is_error())
            return {};

        bool has_results = false;
        if (decoder.decode(has_results).is_error())
            return {};

        int created = {};
        if (decoder.decode(created).is_error())
            return {};

        int updated = {};
        if (decoder.decode(updated).is_error())
            return {};

        int deleted = {};
        if (decoder.decode(deleted).is_error())
            return {};

        return make<ExecutionSuccess>(move(statement_id), move(has_results), move(created), move(updated), move(deleted));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ExecutionSuccess;

        stream << m_statement_id;

        stream << m_has_results;

        stream << m_created;

        stream << m_updated;

        stream << m_deleted;

        return buffer;
    }

    const int& statement_id() const { return m_statement_id; }
    int take_statement_id() { return move(m_statement_id); }

    const bool& has_results() const { return m_has_results; }
    bool take_has_results() { return move(m_has_results); }

    const int& created() const { return m_created; }
    int take_created() { return move(m_created); }

    const int& updated() const { return m_updated; }
    int take_updated() { return move(m_updated); }

    const int& deleted() const { return m_deleted; }
    int take_deleted() { return move(m_deleted); }

private:
    bool m_ipc_message_valid { true };

    int m_statement_id {};

    bool m_has_results {};

    int m_created {};

    int m_updated {};

    int m_deleted {};

};

class NextResult final : public IPC::Message {
public:

    NextResult(decltype(nullptr)) : m_ipc_message_valid(false) { }
    NextResult(NextResult const&) = default;
    NextResult(NextResult&&) = default;
    NextResult& operator=(NextResult const&) = default;
    NextResult(int statement_id, Vector<String> row) : m_statement_id(move(statement_id)), m_row(move(row)) {}
    virtual ~NextResult() override {}

    virtual u32 endpoint_magic() const override { return 531353361; }
    virtual i32 message_id() const override { return (int)MessageID::NextResult; }
    static i32 static_message_id() { return (int)MessageID::NextResult; }
    virtual const char* message_name() const override { return "SQLClient::NextResult"; }

    static OwnPtr<NextResult> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int statement_id = {};
        if (decoder.decode(statement_id).is_error())
            return {};

        Vector<String> row = {};
        if (decoder.decode(row).is_error())
            return {};

        return make<NextResult>(move(statement_id), move(row));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::NextResult;

        stream << m_statement_id;

        stream << m_row;

        return buffer;
    }

    const int& statement_id() const { return m_statement_id; }
    int take_statement_id() { return move(m_statement_id); }

    const Vector<String>& row() const { return m_row; }
    Vector<String> take_row() { return move(m_row); }

private:
    bool m_ipc_message_valid { true };

    int m_statement_id {};

    Vector<String> m_row {};

};

class ResultsExhausted final : public IPC::Message {
public:

    ResultsExhausted(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ResultsExhausted(ResultsExhausted const&) = default;
    ResultsExhausted(ResultsExhausted&&) = default;
    ResultsExhausted& operator=(ResultsExhausted const&) = default;
    ResultsExhausted(int statement_id, int total_rows) : m_statement_id(move(statement_id)), m_total_rows(move(total_rows)) {}
    virtual ~ResultsExhausted() override {}

    virtual u32 endpoint_magic() const override { return 531353361; }
    virtual i32 message_id() const override { return (int)MessageID::ResultsExhausted; }
    static i32 static_message_id() { return (int)MessageID::ResultsExhausted; }
    virtual const char* message_name() const override { return "SQLClient::ResultsExhausted"; }

    static OwnPtr<ResultsExhausted> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int statement_id = {};
        if (decoder.decode(statement_id).is_error())
            return {};

        int total_rows = {};
        if (decoder.decode(total_rows).is_error())
            return {};

        return make<ResultsExhausted>(move(statement_id), move(total_rows));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ResultsExhausted;

        stream << m_statement_id;

        stream << m_total_rows;

        return buffer;
    }

    const int& statement_id() const { return m_statement_id; }
    int take_statement_id() { return move(m_statement_id); }

    const int& total_rows() const { return m_total_rows; }
    int take_total_rows() { return move(m_total_rows); }

private:
    bool m_ipc_message_valid { true };

    int m_statement_id {};

    int m_total_rows {};

};

class ExecutionError final : public IPC::Message {
public:

    ExecutionError(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ExecutionError(ExecutionError const&) = default;
    ExecutionError(ExecutionError&&) = default;
    ExecutionError& operator=(ExecutionError const&) = default;
    ExecutionError(int statement_id, int code, String message) : m_statement_id(move(statement_id)), m_code(move(code)), m_message(move(message)) {}
    virtual ~ExecutionError() override {}

    virtual u32 endpoint_magic() const override { return 531353361; }
    virtual i32 message_id() const override { return (int)MessageID::ExecutionError; }
    static i32 static_message_id() { return (int)MessageID::ExecutionError; }
    virtual const char* message_name() const override { return "SQLClient::ExecutionError"; }

    static OwnPtr<ExecutionError> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int statement_id = {};
        if (decoder.decode(statement_id).is_error())
            return {};

        int code = {};
        if (decoder.decode(code).is_error())
            return {};

        String message = {};
        if (decoder.decode(message).is_error())
            return {};

        return make<ExecutionError>(move(statement_id), move(code), move(message));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ExecutionError;

        stream << m_statement_id;

        stream << m_code;

        stream << m_message;

        return buffer;
    }

    const int& statement_id() const { return m_statement_id; }
    int take_statement_id() { return move(m_statement_id); }

    const int& code() const { return m_code; }
    int take_code() { return move(m_code); }

    const String& message() const { return m_message; }
    String take_message() { return move(m_message); }

private:
    bool m_ipc_message_valid { true };

    int m_statement_id {};

    int m_code {};

    String m_message {};

};

class Disconnected final : public IPC::Message {
public:

    Disconnected(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Disconnected(Disconnected const&) = default;
    Disconnected(Disconnected&&) = default;
    Disconnected& operator=(Disconnected const&) = default;
    Disconnected(int connection_id) : m_connection_id(move(connection_id)) {}
    virtual ~Disconnected() override {}

    virtual u32 endpoint_magic() const override { return 531353361; }
    virtual i32 message_id() const override { return (int)MessageID::Disconnected; }
    static i32 static_message_id() { return (int)MessageID::Disconnected; }
    virtual const char* message_name() const override { return "SQLClient::Disconnected"; }

    static OwnPtr<Disconnected> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        return make<Disconnected>(move(connection_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Disconnected;

        stream << m_connection_id;

        return buffer;
    }

    const int& connection_id() const { return m_connection_id; }
    int take_connection_id() { return move(m_connection_id); }

private:
    bool m_ipc_message_valid { true };

    int m_connection_id {};

};

} // namespace Messages::SQLClient

template<typename LocalEndpoint, typename PeerEndpoint>
class SQLClientProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    SQLClientProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    void async_connected(
int connection_id, String connected_to_database) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLClient::Connected { connection_id, move(connected_to_database) });

    }

    void async_connection_error(
int connection_id, int code, String message) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLClient::ConnectionError { connection_id, code, move(message) });

    }

    void async_execution_success(
int statement_id, bool has_results, int created, int updated, int deleted) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLClient::ExecutionSuccess { statement_id, has_results, created, updated, deleted });

    }

    void async_next_result(
int statement_id, Vector<String> row) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLClient::NextResult { statement_id, move(row) });

    }

    void async_results_exhausted(
int statement_id, int total_rows) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLClient::ResultsExhausted { statement_id, total_rows });

    }

    void async_execution_error(
int statement_id, int code, String message) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLClient::ExecutionError { statement_id, code, move(message) });

    }

    void async_disconnected(
int connection_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLClient::Disconnected { connection_id });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class SQLClientProxy;
class SQLClientStub;

class SQLClientEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = SQLClientProxy<LocalEndpoint, SQLClientEndpoint>;
    using Stub = SQLClientStub;

    static u32 static_magic() { return 531353361; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 531353361) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::SQLClient::MessageID::Connected:
            message = Messages::SQLClient::Connected::decode(stream, socket);
            break;

        case (int)Messages::SQLClient::MessageID::ConnectionError:
            message = Messages::SQLClient::ConnectionError::decode(stream, socket);
            break;

        case (int)Messages::SQLClient::MessageID::ExecutionSuccess:
            message = Messages::SQLClient::ExecutionSuccess::decode(stream, socket);
            break;

        case (int)Messages::SQLClient::MessageID::NextResult:
            message = Messages::SQLClient::NextResult::decode(stream, socket);
            break;

        case (int)Messages::SQLClient::MessageID::ResultsExhausted:
            message = Messages::SQLClient::ResultsExhausted::decode(stream, socket);
            break;

        case (int)Messages::SQLClient::MessageID::ExecutionError:
            message = Messages::SQLClient::ExecutionError::decode(stream, socket);
            break;

        case (int)Messages::SQLClient::MessageID::Disconnected:
            message = Messages::SQLClient::Disconnected::decode(stream, socket);
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

class SQLClientStub : public IPC::Stub {
public:
    SQLClientStub() { }
    virtual ~SQLClientStub() override { }

    virtual u32 magic() const override { return 531353361; }
    virtual String name() const override { return "SQLClient"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::SQLClient::MessageID::Connected: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLClient::Connected&>(message);
            connected(request.connection_id(), request.connected_to_database());
            return {};

        }

        case (int)Messages::SQLClient::MessageID::ConnectionError: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLClient::ConnectionError&>(message);
            connection_error(request.connection_id(), request.code(), request.message());
            return {};

        }

        case (int)Messages::SQLClient::MessageID::ExecutionSuccess: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLClient::ExecutionSuccess&>(message);
            execution_success(request.statement_id(), request.has_results(), request.created(), request.updated(), request.deleted());
            return {};

        }

        case (int)Messages::SQLClient::MessageID::NextResult: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLClient::NextResult&>(message);
            next_result(request.statement_id(), request.row());
            return {};

        }

        case (int)Messages::SQLClient::MessageID::ResultsExhausted: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLClient::ResultsExhausted&>(message);
            results_exhausted(request.statement_id(), request.total_rows());
            return {};

        }

        case (int)Messages::SQLClient::MessageID::ExecutionError: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLClient::ExecutionError&>(message);
            execution_error(request.statement_id(), request.code(), request.message());
            return {};

        }

        case (int)Messages::SQLClient::MessageID::Disconnected: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLClient::Disconnected&>(message);
            disconnected(request.connection_id());
            return {};

        }

        default:
            return {};
        }
    }

    virtual void connected(
[[maybe_unused]] int connection_id, [[maybe_unused]] String const& connected_to_database) = 0;

    virtual void connection_error(
[[maybe_unused]] int connection_id, [[maybe_unused]] int code, [[maybe_unused]] String const& message) = 0;

    virtual void execution_success(
[[maybe_unused]] int statement_id, [[maybe_unused]] bool has_results, [[maybe_unused]] int created, [[maybe_unused]] int updated, [[maybe_unused]] int deleted) = 0;

    virtual void next_result(
[[maybe_unused]] int statement_id, [[maybe_unused]] Vector<String> const& row) = 0;

    virtual void results_exhausted(
[[maybe_unused]] int statement_id, [[maybe_unused]] int total_rows) = 0;

    virtual void execution_error(
[[maybe_unused]] int statement_id, [[maybe_unused]] int code, [[maybe_unused]] String const& message) = 0;

    virtual void disconnected(
[[maybe_unused]] int connection_id) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

