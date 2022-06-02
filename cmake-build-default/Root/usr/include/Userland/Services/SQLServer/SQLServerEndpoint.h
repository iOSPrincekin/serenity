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

namespace Messages::SQLServer {

enum class MessageID : i32 {
    Connect = 1,
    ConnectResponse = 2,
    SqlStatement = 3,
    SqlStatementResponse = 4,
    StatementExecute = 5,
    Disconnect = 6,
};

class ConnectResponse final : public IPC::Message {
public:

    ConnectResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    ConnectResponse(ConnectResponse const&) = default;
    ConnectResponse(ConnectResponse&&) = default;
    ConnectResponse& operator=(ConnectResponse const&) = default;
    ConnectResponse(int connection_id) : m_connection_id(move(connection_id)) {}
    virtual ~ConnectResponse() override {}

    virtual u32 endpoint_magic() const override { return 3731107876; }
    virtual i32 message_id() const override { return (int)MessageID::ConnectResponse; }
    static i32 static_message_id() { return (int)MessageID::ConnectResponse; }
    virtual const char* message_name() const override { return "SQLServer::ConnectResponse"; }

    static OwnPtr<ConnectResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        return make<ConnectResponse>(move(connection_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::ConnectResponse;

        stream << m_connection_id;

        return buffer;
    }

    const int& connection_id() const { return m_connection_id; }
    int take_connection_id() { return move(m_connection_id); }

private:
    bool m_ipc_message_valid { true };

    int m_connection_id {};

};

class Connect final : public IPC::Message {
public:

   typedef class ConnectResponse ResponseType;

    Connect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Connect(Connect const&) = default;
    Connect(Connect&&) = default;
    Connect& operator=(Connect const&) = default;
    Connect(String name) : m_name(move(name)) {}
    virtual ~Connect() override {}

    virtual u32 endpoint_magic() const override { return 3731107876; }
    virtual i32 message_id() const override { return (int)MessageID::Connect; }
    static i32 static_message_id() { return (int)MessageID::Connect; }
    virtual const char* message_name() const override { return "SQLServer::Connect"; }

    static OwnPtr<Connect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String name = {};
        if (decoder.decode(name).is_error())
            return {};

        return make<Connect>(move(name));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Connect;

        stream << m_name;

        return buffer;
    }

    const String& name() const { return m_name; }
    String take_name() { return move(m_name); }

private:
    bool m_ipc_message_valid { true };

    String m_name {};

};

class SqlStatementResponse final : public IPC::Message {
public:

    SqlStatementResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SqlStatementResponse(SqlStatementResponse const&) = default;
    SqlStatementResponse(SqlStatementResponse&&) = default;
    SqlStatementResponse& operator=(SqlStatementResponse const&) = default;
    SqlStatementResponse(int statement_id) : m_statement_id(move(statement_id)) {}
    virtual ~SqlStatementResponse() override {}

    virtual u32 endpoint_magic() const override { return 3731107876; }
    virtual i32 message_id() const override { return (int)MessageID::SqlStatementResponse; }
    static i32 static_message_id() { return (int)MessageID::SqlStatementResponse; }
    virtual const char* message_name() const override { return "SQLServer::SqlStatementResponse"; }

    static OwnPtr<SqlStatementResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int statement_id = {};
        if (decoder.decode(statement_id).is_error())
            return {};

        return make<SqlStatementResponse>(move(statement_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SqlStatementResponse;

        stream << m_statement_id;

        return buffer;
    }

    const int& statement_id() const { return m_statement_id; }
    int take_statement_id() { return move(m_statement_id); }

private:
    bool m_ipc_message_valid { true };

    int m_statement_id {};

};

class SqlStatement final : public IPC::Message {
public:

   typedef class SqlStatementResponse ResponseType;

    SqlStatement(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SqlStatement(SqlStatement const&) = default;
    SqlStatement(SqlStatement&&) = default;
    SqlStatement& operator=(SqlStatement const&) = default;
    SqlStatement(int connection_id, String statement) : m_connection_id(move(connection_id)), m_statement(move(statement)) {}
    virtual ~SqlStatement() override {}

    virtual u32 endpoint_magic() const override { return 3731107876; }
    virtual i32 message_id() const override { return (int)MessageID::SqlStatement; }
    static i32 static_message_id() { return (int)MessageID::SqlStatement; }
    virtual const char* message_name() const override { return "SQLServer::SqlStatement"; }

    static OwnPtr<SqlStatement> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        String statement = {};
        if (decoder.decode(statement).is_error())
            return {};

        return make<SqlStatement>(move(connection_id), move(statement));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SqlStatement;

        stream << m_connection_id;

        stream << m_statement;

        return buffer;
    }

    const int& connection_id() const { return m_connection_id; }
    int take_connection_id() { return move(m_connection_id); }

    const String& statement() const { return m_statement; }
    String take_statement() { return move(m_statement); }

private:
    bool m_ipc_message_valid { true };

    int m_connection_id {};

    String m_statement {};

};

class StatementExecute final : public IPC::Message {
public:

    StatementExecute(decltype(nullptr)) : m_ipc_message_valid(false) { }
    StatementExecute(StatementExecute const&) = default;
    StatementExecute(StatementExecute&&) = default;
    StatementExecute& operator=(StatementExecute const&) = default;
    StatementExecute(int statement_id) : m_statement_id(move(statement_id)) {}
    virtual ~StatementExecute() override {}

    virtual u32 endpoint_magic() const override { return 3731107876; }
    virtual i32 message_id() const override { return (int)MessageID::StatementExecute; }
    static i32 static_message_id() { return (int)MessageID::StatementExecute; }
    virtual const char* message_name() const override { return "SQLServer::StatementExecute"; }

    static OwnPtr<StatementExecute> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int statement_id = {};
        if (decoder.decode(statement_id).is_error())
            return {};

        return make<StatementExecute>(move(statement_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::StatementExecute;

        stream << m_statement_id;

        return buffer;
    }

    const int& statement_id() const { return m_statement_id; }
    int take_statement_id() { return move(m_statement_id); }

private:
    bool m_ipc_message_valid { true };

    int m_statement_id {};

};

class Disconnect final : public IPC::Message {
public:

    Disconnect(decltype(nullptr)) : m_ipc_message_valid(false) { }
    Disconnect(Disconnect const&) = default;
    Disconnect(Disconnect&&) = default;
    Disconnect& operator=(Disconnect const&) = default;
    Disconnect(int connection_id) : m_connection_id(move(connection_id)) {}
    virtual ~Disconnect() override {}

    virtual u32 endpoint_magic() const override { return 3731107876; }
    virtual i32 message_id() const override { return (int)MessageID::Disconnect; }
    static i32 static_message_id() { return (int)MessageID::Disconnect; }
    virtual const char* message_name() const override { return "SQLServer::Disconnect"; }

    static OwnPtr<Disconnect> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        int connection_id = {};
        if (decoder.decode(connection_id).is_error())
            return {};

        return make<Disconnect>(move(connection_id));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::Disconnect;

        stream << m_connection_id;

        return buffer;
    }

    const int& connection_id() const { return m_connection_id; }
    int take_connection_id() { return move(m_connection_id); }

private:
    bool m_ipc_message_valid { true };

    int m_connection_id {};

};

} // namespace Messages::SQLServer

template<typename LocalEndpoint, typename PeerEndpoint>
class SQLServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    SQLServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    int connect(
String name) {
        return m_connection.template send_sync<Messages::SQLServer::Connect>(move(name))->take_connection_id();
    }

    void async_connect(
String name) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLServer::Connect { move(name) });

    }

    IPC::IPCErrorOr<int> try_connect(
String name) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::SQLServer::Connect>(move(name));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    int sql_statement(
int connection_id, String statement) {
        return m_connection.template send_sync<Messages::SQLServer::SqlStatement>(connection_id, move(statement))->take_statement_id();
    }

    void async_sql_statement(
int connection_id, String statement) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLServer::SqlStatement { connection_id, move(statement) });

    }

    IPC::IPCErrorOr<int> try_sql_statement(
int connection_id, String statement) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::SQLServer::SqlStatement>(connection_id, move(statement));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void async_statement_execute(
int statement_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLServer::StatementExecute { statement_id });

    }

    void async_disconnect(
int connection_id) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::SQLServer::Disconnect { connection_id });

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class SQLServerProxy;
class SQLServerStub;

class SQLServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = SQLServerProxy<LocalEndpoint, SQLServerEndpoint>;
    using Stub = SQLServerStub;

    static u32 static_magic() { return 3731107876; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 3731107876) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::SQLServer::MessageID::Connect:
            message = Messages::SQLServer::Connect::decode(stream, socket);
            break;

        case (int)Messages::SQLServer::MessageID::ConnectResponse:
            message = Messages::SQLServer::ConnectResponse::decode(stream, socket);
            break;

        case (int)Messages::SQLServer::MessageID::SqlStatement:
            message = Messages::SQLServer::SqlStatement::decode(stream, socket);
            break;

        case (int)Messages::SQLServer::MessageID::SqlStatementResponse:
            message = Messages::SQLServer::SqlStatementResponse::decode(stream, socket);
            break;

        case (int)Messages::SQLServer::MessageID::StatementExecute:
            message = Messages::SQLServer::StatementExecute::decode(stream, socket);
            break;

        case (int)Messages::SQLServer::MessageID::Disconnect:
            message = Messages::SQLServer::Disconnect::decode(stream, socket);
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

class SQLServerStub : public IPC::Stub {
public:
    SQLServerStub() { }
    virtual ~SQLServerStub() override { }

    virtual u32 magic() const override { return 3731107876; }
    virtual String name() const override { return "SQLServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::SQLServer::MessageID::Connect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLServer::Connect&>(message);
            auto response = connect(request.name());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::SQLServer::MessageID::SqlStatement: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLServer::SqlStatement&>(message);
            auto response = sql_statement(request.connection_id(), request.statement());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::SQLServer::MessageID::StatementExecute: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLServer::StatementExecute&>(message);
            statement_execute(request.statement_id());
            return {};

        }

        case (int)Messages::SQLServer::MessageID::Disconnect: {

            [[maybe_unused]] auto& request = static_cast<const Messages::SQLServer::Disconnect&>(message);
            disconnect(request.connection_id());
            return {};

        }

        default:
            return {};
        }
    }

    virtual Messages::SQLServer::ConnectResponse connect(
[[maybe_unused]] String const& name) = 0;

    virtual Messages::SQLServer::SqlStatementResponse sql_statement(
[[maybe_unused]] int connection_id, [[maybe_unused]] String const& statement) = 0;

    virtual void statement_execute(
[[maybe_unused]] int statement_id) = 0;

    virtual void disconnect(
[[maybe_unused]] int connection_id) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

