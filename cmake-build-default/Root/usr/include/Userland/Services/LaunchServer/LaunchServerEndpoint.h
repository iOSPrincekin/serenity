#pragma once
#include <AK/URL.h>
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

namespace Messages::LaunchServer {

enum class MessageID : i32 {
    OpenUrl = 1,
    OpenUrlResponse = 2,
    GetHandlersForUrl = 3,
    GetHandlersForUrlResponse = 4,
    GetHandlersWithDetailsForUrl = 5,
    GetHandlersWithDetailsForUrlResponse = 6,
    AddAllowedUrl = 7,
    AddAllowedUrlResponse = 8,
    AddAllowedHandlerWithAnyUrl = 9,
    AddAllowedHandlerWithAnyUrlResponse = 10,
    AddAllowedHandlerWithOnlySpecificUrls = 11,
    AddAllowedHandlerWithOnlySpecificUrlsResponse = 12,
    SealAllowlist = 13,
    SealAllowlistResponse = 14,
};

class OpenUrlResponse final : public IPC::Message {
public:

    OpenUrlResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    OpenUrlResponse(OpenUrlResponse const&) = default;
    OpenUrlResponse(OpenUrlResponse&&) = default;
    OpenUrlResponse& operator=(OpenUrlResponse const&) = default;
    OpenUrlResponse(bool response) : m_response(move(response)) {}
    virtual ~OpenUrlResponse() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::OpenUrlResponse; }
    static i32 static_message_id() { return (int)MessageID::OpenUrlResponse; }
    virtual const char* message_name() const override { return "LaunchServer::OpenUrlResponse"; }

    static OwnPtr<OpenUrlResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        bool response = false;
        if (decoder.decode(response).is_error())
            return {};

        return make<OpenUrlResponse>(move(response));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::OpenUrlResponse;

        stream << m_response;

        return buffer;
    }

    const bool& response() const { return m_response; }
    bool take_response() { return move(m_response); }

private:
    bool m_ipc_message_valid { true };

    bool m_response {};

};

class OpenUrl final : public IPC::Message {
public:

   typedef class OpenUrlResponse ResponseType;

    OpenUrl(decltype(nullptr)) : m_ipc_message_valid(false) { }
    OpenUrl(OpenUrl const&) = default;
    OpenUrl(OpenUrl&&) = default;
    OpenUrl& operator=(OpenUrl const&) = default;
    OpenUrl(URL url, String handler_name) : m_url(move(url)), m_handler_name(move(handler_name)) {}
    virtual ~OpenUrl() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::OpenUrl; }
    static i32 static_message_id() { return (int)MessageID::OpenUrl; }
    virtual const char* message_name() const override { return "LaunchServer::OpenUrl"; }

    static OwnPtr<OpenUrl> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        String handler_name = {};
        if (decoder.decode(handler_name).is_error())
            return {};

        return make<OpenUrl>(move(url), move(handler_name));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::OpenUrl;

        stream << m_url;

        stream << m_handler_name;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

    const String& handler_name() const { return m_handler_name; }
    String take_handler_name() { return move(m_handler_name); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

    String m_handler_name {};

};

class GetHandlersForUrlResponse final : public IPC::Message {
public:

    GetHandlersForUrlResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetHandlersForUrlResponse(GetHandlersForUrlResponse const&) = default;
    GetHandlersForUrlResponse(GetHandlersForUrlResponse&&) = default;
    GetHandlersForUrlResponse& operator=(GetHandlersForUrlResponse const&) = default;
    GetHandlersForUrlResponse(Vector<String> handlers) : m_handlers(move(handlers)) {}
    virtual ~GetHandlersForUrlResponse() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::GetHandlersForUrlResponse; }
    static i32 static_message_id() { return (int)MessageID::GetHandlersForUrlResponse; }
    virtual const char* message_name() const override { return "LaunchServer::GetHandlersForUrlResponse"; }

    static OwnPtr<GetHandlersForUrlResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<String> handlers = {};
        if (decoder.decode(handlers).is_error())
            return {};

        return make<GetHandlersForUrlResponse>(move(handlers));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetHandlersForUrlResponse;

        stream << m_handlers;

        return buffer;
    }

    const Vector<String>& handlers() const { return m_handlers; }
    Vector<String> take_handlers() { return move(m_handlers); }

private:
    bool m_ipc_message_valid { true };

    Vector<String> m_handlers {};

};

class GetHandlersForUrl final : public IPC::Message {
public:

   typedef class GetHandlersForUrlResponse ResponseType;

    GetHandlersForUrl(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetHandlersForUrl(GetHandlersForUrl const&) = default;
    GetHandlersForUrl(GetHandlersForUrl&&) = default;
    GetHandlersForUrl& operator=(GetHandlersForUrl const&) = default;
    GetHandlersForUrl(URL url) : m_url(move(url)) {}
    virtual ~GetHandlersForUrl() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::GetHandlersForUrl; }
    static i32 static_message_id() { return (int)MessageID::GetHandlersForUrl; }
    virtual const char* message_name() const override { return "LaunchServer::GetHandlersForUrl"; }

    static OwnPtr<GetHandlersForUrl> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        return make<GetHandlersForUrl>(move(url));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetHandlersForUrl;

        stream << m_url;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

};

class GetHandlersWithDetailsForUrlResponse final : public IPC::Message {
public:

    GetHandlersWithDetailsForUrlResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetHandlersWithDetailsForUrlResponse(GetHandlersWithDetailsForUrlResponse const&) = default;
    GetHandlersWithDetailsForUrlResponse(GetHandlersWithDetailsForUrlResponse&&) = default;
    GetHandlersWithDetailsForUrlResponse& operator=(GetHandlersWithDetailsForUrlResponse const&) = default;
    GetHandlersWithDetailsForUrlResponse(Vector<String> handlers_details) : m_handlers_details(move(handlers_details)) {}
    virtual ~GetHandlersWithDetailsForUrlResponse() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::GetHandlersWithDetailsForUrlResponse; }
    static i32 static_message_id() { return (int)MessageID::GetHandlersWithDetailsForUrlResponse; }
    virtual const char* message_name() const override { return "LaunchServer::GetHandlersWithDetailsForUrlResponse"; }

    static OwnPtr<GetHandlersWithDetailsForUrlResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        Vector<String> handlers_details = {};
        if (decoder.decode(handlers_details).is_error())
            return {};

        return make<GetHandlersWithDetailsForUrlResponse>(move(handlers_details));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetHandlersWithDetailsForUrlResponse;

        stream << m_handlers_details;

        return buffer;
    }

    const Vector<String>& handlers_details() const { return m_handlers_details; }
    Vector<String> take_handlers_details() { return move(m_handlers_details); }

private:
    bool m_ipc_message_valid { true };

    Vector<String> m_handlers_details {};

};

class GetHandlersWithDetailsForUrl final : public IPC::Message {
public:

   typedef class GetHandlersWithDetailsForUrlResponse ResponseType;

    GetHandlersWithDetailsForUrl(decltype(nullptr)) : m_ipc_message_valid(false) { }
    GetHandlersWithDetailsForUrl(GetHandlersWithDetailsForUrl const&) = default;
    GetHandlersWithDetailsForUrl(GetHandlersWithDetailsForUrl&&) = default;
    GetHandlersWithDetailsForUrl& operator=(GetHandlersWithDetailsForUrl const&) = default;
    GetHandlersWithDetailsForUrl(URL url) : m_url(move(url)) {}
    virtual ~GetHandlersWithDetailsForUrl() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::GetHandlersWithDetailsForUrl; }
    static i32 static_message_id() { return (int)MessageID::GetHandlersWithDetailsForUrl; }
    virtual const char* message_name() const override { return "LaunchServer::GetHandlersWithDetailsForUrl"; }

    static OwnPtr<GetHandlersWithDetailsForUrl> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        return make<GetHandlersWithDetailsForUrl>(move(url));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::GetHandlersWithDetailsForUrl;

        stream << m_url;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

};

class AddAllowedUrlResponse final : public IPC::Message {
public:

    AddAllowedUrlResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddAllowedUrlResponse(AddAllowedUrlResponse const&) = default;
    AddAllowedUrlResponse(AddAllowedUrlResponse&&) = default;
    AddAllowedUrlResponse& operator=(AddAllowedUrlResponse const&) = default;
    AddAllowedUrlResponse() {}
    virtual ~AddAllowedUrlResponse() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::AddAllowedUrlResponse; }
    static i32 static_message_id() { return (int)MessageID::AddAllowedUrlResponse; }
    virtual const char* message_name() const override { return "LaunchServer::AddAllowedUrlResponse"; }

    static OwnPtr<AddAllowedUrlResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<AddAllowedUrlResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddAllowedUrlResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class AddAllowedUrl final : public IPC::Message {
public:

   typedef class AddAllowedUrlResponse ResponseType;

    AddAllowedUrl(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddAllowedUrl(AddAllowedUrl const&) = default;
    AddAllowedUrl(AddAllowedUrl&&) = default;
    AddAllowedUrl& operator=(AddAllowedUrl const&) = default;
    AddAllowedUrl(URL url) : m_url(move(url)) {}
    virtual ~AddAllowedUrl() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::AddAllowedUrl; }
    static i32 static_message_id() { return (int)MessageID::AddAllowedUrl; }
    virtual const char* message_name() const override { return "LaunchServer::AddAllowedUrl"; }

    static OwnPtr<AddAllowedUrl> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        URL url = {};
        if (decoder.decode(url).is_error())
            return {};

        return make<AddAllowedUrl>(move(url));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddAllowedUrl;

        stream << m_url;

        return buffer;
    }

    const URL& url() const { return m_url; }
    URL take_url() { return move(m_url); }

private:
    bool m_ipc_message_valid { true };

    URL m_url {};

};

class AddAllowedHandlerWithAnyUrlResponse final : public IPC::Message {
public:

    AddAllowedHandlerWithAnyUrlResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddAllowedHandlerWithAnyUrlResponse(AddAllowedHandlerWithAnyUrlResponse const&) = default;
    AddAllowedHandlerWithAnyUrlResponse(AddAllowedHandlerWithAnyUrlResponse&&) = default;
    AddAllowedHandlerWithAnyUrlResponse& operator=(AddAllowedHandlerWithAnyUrlResponse const&) = default;
    AddAllowedHandlerWithAnyUrlResponse() {}
    virtual ~AddAllowedHandlerWithAnyUrlResponse() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::AddAllowedHandlerWithAnyUrlResponse; }
    static i32 static_message_id() { return (int)MessageID::AddAllowedHandlerWithAnyUrlResponse; }
    virtual const char* message_name() const override { return "LaunchServer::AddAllowedHandlerWithAnyUrlResponse"; }

    static OwnPtr<AddAllowedHandlerWithAnyUrlResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<AddAllowedHandlerWithAnyUrlResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddAllowedHandlerWithAnyUrlResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class AddAllowedHandlerWithAnyUrl final : public IPC::Message {
public:

   typedef class AddAllowedHandlerWithAnyUrlResponse ResponseType;

    AddAllowedHandlerWithAnyUrl(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddAllowedHandlerWithAnyUrl(AddAllowedHandlerWithAnyUrl const&) = default;
    AddAllowedHandlerWithAnyUrl(AddAllowedHandlerWithAnyUrl&&) = default;
    AddAllowedHandlerWithAnyUrl& operator=(AddAllowedHandlerWithAnyUrl const&) = default;
    AddAllowedHandlerWithAnyUrl(String handler_name) : m_handler_name(move(handler_name)) {}
    virtual ~AddAllowedHandlerWithAnyUrl() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::AddAllowedHandlerWithAnyUrl; }
    static i32 static_message_id() { return (int)MessageID::AddAllowedHandlerWithAnyUrl; }
    virtual const char* message_name() const override { return "LaunchServer::AddAllowedHandlerWithAnyUrl"; }

    static OwnPtr<AddAllowedHandlerWithAnyUrl> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String handler_name = {};
        if (decoder.decode(handler_name).is_error())
            return {};

        return make<AddAllowedHandlerWithAnyUrl>(move(handler_name));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddAllowedHandlerWithAnyUrl;

        stream << m_handler_name;

        return buffer;
    }

    const String& handler_name() const { return m_handler_name; }
    String take_handler_name() { return move(m_handler_name); }

private:
    bool m_ipc_message_valid { true };

    String m_handler_name {};

};

class AddAllowedHandlerWithOnlySpecificUrlsResponse final : public IPC::Message {
public:

    AddAllowedHandlerWithOnlySpecificUrlsResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddAllowedHandlerWithOnlySpecificUrlsResponse(AddAllowedHandlerWithOnlySpecificUrlsResponse const&) = default;
    AddAllowedHandlerWithOnlySpecificUrlsResponse(AddAllowedHandlerWithOnlySpecificUrlsResponse&&) = default;
    AddAllowedHandlerWithOnlySpecificUrlsResponse& operator=(AddAllowedHandlerWithOnlySpecificUrlsResponse const&) = default;
    AddAllowedHandlerWithOnlySpecificUrlsResponse() {}
    virtual ~AddAllowedHandlerWithOnlySpecificUrlsResponse() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::AddAllowedHandlerWithOnlySpecificUrlsResponse; }
    static i32 static_message_id() { return (int)MessageID::AddAllowedHandlerWithOnlySpecificUrlsResponse; }
    virtual const char* message_name() const override { return "LaunchServer::AddAllowedHandlerWithOnlySpecificUrlsResponse"; }

    static OwnPtr<AddAllowedHandlerWithOnlySpecificUrlsResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<AddAllowedHandlerWithOnlySpecificUrlsResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddAllowedHandlerWithOnlySpecificUrlsResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class AddAllowedHandlerWithOnlySpecificUrls final : public IPC::Message {
public:

   typedef class AddAllowedHandlerWithOnlySpecificUrlsResponse ResponseType;

    AddAllowedHandlerWithOnlySpecificUrls(decltype(nullptr)) : m_ipc_message_valid(false) { }
    AddAllowedHandlerWithOnlySpecificUrls(AddAllowedHandlerWithOnlySpecificUrls const&) = default;
    AddAllowedHandlerWithOnlySpecificUrls(AddAllowedHandlerWithOnlySpecificUrls&&) = default;
    AddAllowedHandlerWithOnlySpecificUrls& operator=(AddAllowedHandlerWithOnlySpecificUrls const&) = default;
    AddAllowedHandlerWithOnlySpecificUrls(String handler_name, Vector<URL> urls) : m_handler_name(move(handler_name)), m_urls(move(urls)) {}
    virtual ~AddAllowedHandlerWithOnlySpecificUrls() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::AddAllowedHandlerWithOnlySpecificUrls; }
    static i32 static_message_id() { return (int)MessageID::AddAllowedHandlerWithOnlySpecificUrls; }
    virtual const char* message_name() const override { return "LaunchServer::AddAllowedHandlerWithOnlySpecificUrls"; }

    static OwnPtr<AddAllowedHandlerWithOnlySpecificUrls> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        String handler_name = {};
        if (decoder.decode(handler_name).is_error())
            return {};

        Vector<URL> urls = {};
        if (decoder.decode(urls).is_error())
            return {};

        return make<AddAllowedHandlerWithOnlySpecificUrls>(move(handler_name), move(urls));
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::AddAllowedHandlerWithOnlySpecificUrls;

        stream << m_handler_name;

        stream << m_urls;

        return buffer;
    }

    const String& handler_name() const { return m_handler_name; }
    String take_handler_name() { return move(m_handler_name); }

    const Vector<URL>& urls() const { return m_urls; }
    Vector<URL> take_urls() { return move(m_urls); }

private:
    bool m_ipc_message_valid { true };

    String m_handler_name {};

    Vector<URL> m_urls {};

};

class SealAllowlistResponse final : public IPC::Message {
public:

    SealAllowlistResponse(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SealAllowlistResponse(SealAllowlistResponse const&) = default;
    SealAllowlistResponse(SealAllowlistResponse&&) = default;
    SealAllowlistResponse& operator=(SealAllowlistResponse const&) = default;
    SealAllowlistResponse() {}
    virtual ~SealAllowlistResponse() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::SealAllowlistResponse; }
    static i32 static_message_id() { return (int)MessageID::SealAllowlistResponse; }
    virtual const char* message_name() const override { return "LaunchServer::SealAllowlistResponse"; }

    static OwnPtr<SealAllowlistResponse> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SealAllowlistResponse>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SealAllowlistResponse;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

class SealAllowlist final : public IPC::Message {
public:

   typedef class SealAllowlistResponse ResponseType;

    SealAllowlist(decltype(nullptr)) : m_ipc_message_valid(false) { }
    SealAllowlist(SealAllowlist const&) = default;
    SealAllowlist(SealAllowlist&&) = default;
    SealAllowlist& operator=(SealAllowlist const&) = default;
    SealAllowlist() {}
    virtual ~SealAllowlist() override {}

    virtual u32 endpoint_magic() const override { return 1140813104; }
    virtual i32 message_id() const override { return (int)MessageID::SealAllowlist; }
    static i32 static_message_id() { return (int)MessageID::SealAllowlist; }
    virtual const char* message_name() const override { return "LaunchServer::SealAllowlist"; }

    static OwnPtr<SealAllowlist> decode(InputMemoryStream& stream, Core::Stream::LocalSocket& socket)
    {
        IPC::Decoder decoder { stream, socket };

        return make<SealAllowlist>();
    }

    virtual bool valid() const override { return m_ipc_message_valid; }

    virtual IPC::MessageBuffer encode() const override
    {
        VERIFY(valid());

        IPC::MessageBuffer buffer;
        IPC::Encoder stream(buffer);
        stream << endpoint_magic();
        stream << (int)MessageID::SealAllowlist;

        return buffer;
    }

private:
    bool m_ipc_message_valid { true };

};

} // namespace Messages::LaunchServer

template<typename LocalEndpoint, typename PeerEndpoint>
class LaunchServerProxy {
public:
    // Used to disambiguate the constructor call.
    struct Tag { };

    LaunchServerProxy(IPC::Connection<LocalEndpoint, PeerEndpoint>& connection, Tag)
        : m_connection(connection)
    { }

    bool open_url(
URL url, String handler_name) {
        return m_connection.template send_sync<Messages::LaunchServer::OpenUrl>(move(url), move(handler_name))->take_response();
    }

    void async_open_url(
URL url, String handler_name) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LaunchServer::OpenUrl { move(url), move(handler_name) });

    }

    IPC::IPCErrorOr<bool> try_open_url(
URL url, String handler_name) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LaunchServer::OpenUrl>(move(url), move(handler_name));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Vector<String> get_handlers_for_url(
URL url) {
        return m_connection.template send_sync<Messages::LaunchServer::GetHandlersForUrl>(move(url))->take_handlers();
    }

    void async_get_handlers_for_url(
URL url) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LaunchServer::GetHandlersForUrl { move(url) });

    }

    IPC::IPCErrorOr<Vector<String>> try_get_handlers_for_url(
URL url) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LaunchServer::GetHandlersForUrl>(move(url));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    Vector<String> get_handlers_with_details_for_url(
URL url) {
        return m_connection.template send_sync<Messages::LaunchServer::GetHandlersWithDetailsForUrl>(move(url))->take_handlers_details();
    }

    void async_get_handlers_with_details_for_url(
URL url) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LaunchServer::GetHandlersWithDetailsForUrl { move(url) });

    }

    IPC::IPCErrorOr<Vector<String>> try_get_handlers_with_details_for_url(
URL url) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LaunchServer::GetHandlersWithDetailsForUrl>(move(url));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return move(*result);

    }

    void add_allowed_url(
URL url) {
        (void) m_connection.template send_sync<Messages::LaunchServer::AddAllowedUrl>(move(url));
    }

    void async_add_allowed_url(
URL url) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LaunchServer::AddAllowedUrl { move(url) });

    }

    IPC::IPCErrorOr<void> try_add_allowed_url(
URL url) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LaunchServer::AddAllowedUrl>(move(url));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void add_allowed_handler_with_any_url(
String handler_name) {
        (void) m_connection.template send_sync<Messages::LaunchServer::AddAllowedHandlerWithAnyUrl>(move(handler_name));
    }

    void async_add_allowed_handler_with_any_url(
String handler_name) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LaunchServer::AddAllowedHandlerWithAnyUrl { move(handler_name) });

    }

    IPC::IPCErrorOr<void> try_add_allowed_handler_with_any_url(
String handler_name) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LaunchServer::AddAllowedHandlerWithAnyUrl>(move(handler_name));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void add_allowed_handler_with_only_specific_urls(
String handler_name, Vector<URL> urls) {
        (void) m_connection.template send_sync<Messages::LaunchServer::AddAllowedHandlerWithOnlySpecificUrls>(move(handler_name), move(urls));
    }

    void async_add_allowed_handler_with_only_specific_urls(
String handler_name, Vector<URL> urls) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LaunchServer::AddAllowedHandlerWithOnlySpecificUrls { move(handler_name), move(urls) });

    }

    IPC::IPCErrorOr<void> try_add_allowed_handler_with_only_specific_urls(
String handler_name, Vector<URL> urls) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LaunchServer::AddAllowedHandlerWithOnlySpecificUrls>(move(handler_name), move(urls));
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

    void seal_allowlist(
) {
        (void) m_connection.template send_sync<Messages::LaunchServer::SealAllowlist>();
    }

    void async_seal_allowlist(
) {
        // FIXME: Handle post_message failures.
        (void) m_connection.post_message(Messages::LaunchServer::SealAllowlist {  });

    }

    IPC::IPCErrorOr<void> try_seal_allowlist(
) {
        auto result = m_connection.template send_sync_but_allow_failure<Messages::LaunchServer::SealAllowlist>();
        if (!result)
            return IPC::ErrorCode::PeerDisconnected;
        return { };

    }

private:
    IPC::Connection<LocalEndpoint, PeerEndpoint>& m_connection;
};

template<typename LocalEndpoint, typename PeerEndpoint>
class LaunchServerProxy;
class LaunchServerStub;

class LaunchServerEndpoint {
public:
    template<typename LocalEndpoint>
    using Proxy = LaunchServerProxy<LocalEndpoint, LaunchServerEndpoint>;
    using Stub = LaunchServerStub;

    static u32 static_magic() { return 1140813104; }

    static OwnPtr<IPC::Message> decode_message(ReadonlyBytes buffer, [[maybe_unused]] Core::Stream::LocalSocket& socket)
    {
        InputMemoryStream stream { buffer };
        u32 message_endpoint_magic = 0;
        stream >> message_endpoint_magic;
        if (stream.handle_any_error()) {

            return {};
        }

        if (message_endpoint_magic != 1140813104) {

            return {};
        }

        i32 message_id = 0;
        stream >> message_id;
        if (stream.handle_any_error()) {

            return {};
        }

        OwnPtr<IPC::Message> message;
        switch (message_id) {

        case (int)Messages::LaunchServer::MessageID::OpenUrl:
            message = Messages::LaunchServer::OpenUrl::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::OpenUrlResponse:
            message = Messages::LaunchServer::OpenUrlResponse::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::GetHandlersForUrl:
            message = Messages::LaunchServer::GetHandlersForUrl::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::GetHandlersForUrlResponse:
            message = Messages::LaunchServer::GetHandlersForUrlResponse::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::GetHandlersWithDetailsForUrl:
            message = Messages::LaunchServer::GetHandlersWithDetailsForUrl::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::GetHandlersWithDetailsForUrlResponse:
            message = Messages::LaunchServer::GetHandlersWithDetailsForUrlResponse::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::AddAllowedUrl:
            message = Messages::LaunchServer::AddAllowedUrl::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::AddAllowedUrlResponse:
            message = Messages::LaunchServer::AddAllowedUrlResponse::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::AddAllowedHandlerWithAnyUrl:
            message = Messages::LaunchServer::AddAllowedHandlerWithAnyUrl::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::AddAllowedHandlerWithAnyUrlResponse:
            message = Messages::LaunchServer::AddAllowedHandlerWithAnyUrlResponse::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::AddAllowedHandlerWithOnlySpecificUrls:
            message = Messages::LaunchServer::AddAllowedHandlerWithOnlySpecificUrls::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::AddAllowedHandlerWithOnlySpecificUrlsResponse:
            message = Messages::LaunchServer::AddAllowedHandlerWithOnlySpecificUrlsResponse::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::SealAllowlist:
            message = Messages::LaunchServer::SealAllowlist::decode(stream, socket);
            break;

        case (int)Messages::LaunchServer::MessageID::SealAllowlistResponse:
            message = Messages::LaunchServer::SealAllowlistResponse::decode(stream, socket);
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

class LaunchServerStub : public IPC::Stub {
public:
    LaunchServerStub() { }
    virtual ~LaunchServerStub() override { }

    virtual u32 magic() const override { return 1140813104; }
    virtual String name() const override { return "LaunchServer"; }

    virtual OwnPtr<IPC::MessageBuffer> handle(const IPC::Message& message) override
    {
        switch (message.message_id()) {

        case (int)Messages::LaunchServer::MessageID::OpenUrl: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LaunchServer::OpenUrl&>(message);
            auto response = open_url(request.url(), request.handler_name());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::LaunchServer::MessageID::GetHandlersForUrl: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LaunchServer::GetHandlersForUrl&>(message);
            auto response = get_handlers_for_url(request.url());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::LaunchServer::MessageID::GetHandlersWithDetailsForUrl: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LaunchServer::GetHandlersWithDetailsForUrl&>(message);
            auto response = get_handlers_with_details_for_url(request.url());
            if (!response.valid())
                return {};
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::LaunchServer::MessageID::AddAllowedUrl: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LaunchServer::AddAllowedUrl&>(message);
            add_allowed_url(request.url());
            auto response = Messages::LaunchServer::AddAllowedUrlResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::LaunchServer::MessageID::AddAllowedHandlerWithAnyUrl: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LaunchServer::AddAllowedHandlerWithAnyUrl&>(message);
            add_allowed_handler_with_any_url(request.handler_name());
            auto response = Messages::LaunchServer::AddAllowedHandlerWithAnyUrlResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::LaunchServer::MessageID::AddAllowedHandlerWithOnlySpecificUrls: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LaunchServer::AddAllowedHandlerWithOnlySpecificUrls&>(message);
            add_allowed_handler_with_only_specific_urls(request.handler_name(), request.urls());
            auto response = Messages::LaunchServer::AddAllowedHandlerWithOnlySpecificUrlsResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        case (int)Messages::LaunchServer::MessageID::SealAllowlist: {

            [[maybe_unused]] auto& request = static_cast<const Messages::LaunchServer::SealAllowlist&>(message);
            seal_allowlist();
            auto response = Messages::LaunchServer::SealAllowlistResponse { };
            return make<IPC::MessageBuffer>(response.encode());

        }

        default:
            return {};
        }
    }

    virtual Messages::LaunchServer::OpenUrlResponse open_url(
[[maybe_unused]] URL const& url, [[maybe_unused]] String const& handler_name) = 0;

    virtual Messages::LaunchServer::GetHandlersForUrlResponse get_handlers_for_url(
[[maybe_unused]] URL const& url) = 0;

    virtual Messages::LaunchServer::GetHandlersWithDetailsForUrlResponse get_handlers_with_details_for_url(
[[maybe_unused]] URL const& url) = 0;

    virtual void add_allowed_url(
[[maybe_unused]] URL const& url) = 0;

    virtual void add_allowed_handler_with_any_url(
[[maybe_unused]] String const& handler_name) = 0;

    virtual void add_allowed_handler_with_only_specific_urls(
[[maybe_unused]] String const& handler_name, [[maybe_unused]] Vector<URL> const& urls) = 0;

    virtual void seal_allowlist(
) = 0;

private:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

