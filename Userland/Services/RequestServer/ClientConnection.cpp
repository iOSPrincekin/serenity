/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/Badge.h>
#include <RequestServer/ClientConnection.h>
#include <RequestServer/Protocol.h>
#include <RequestServer/Request.h>
#include <RequestServer/RequestClientEndpoint.h>
#include <netdb.h>

namespace RequestServer {

static HashMap<int, RefPtr<ClientConnection>> s_connections;

ClientConnection::ClientConnection(NonnullRefPtr<Core::LocalSocket> socket, int client_id)
    : IPC::ClientConnection<RequestClientEndpoint, RequestServerEndpoint>(*this, move(socket), client_id)
{
    s_connections.set(client_id, *this);
}

ClientConnection::~ClientConnection()
{
}

void ClientConnection::die()
{
    s_connections.remove(client_id());
    if (s_connections.is_empty())
        Core::EventLoop::current().quit(0);
}

Messages::RequestServer::IsSupportedProtocolResponse ClientConnection::is_supported_protocol(String const& protocol)
{
    bool supported = Protocol::find_by_name(protocol.to_lowercase());
    return supported;
}

Messages::RequestServer::StartRequestResponse ClientConnection::start_request(String const& method, URL const& url, IPC::Dictionary const& request_headers, ByteBuffer const& request_body)
{
    if (!url.is_valid()) {
        dbgln("StartRequest: Invalid URL requested: '{}'", url);
        return { -1, Optional<IPC::File> {} };
    }
    auto* protocol = Protocol::find_by_name(url.protocol());
    if (!protocol) {
        dbgln("StartRequest: No protocol handler for URL: '{}'", url);
        return { -1, Optional<IPC::File> {} };
    }
    auto request = protocol->start_request(*this, method, url, request_headers.entries(), request_body);
    if (!request) {
        dbgln("StartRequest: Protocol handler failed to start request: '{}'", url);
        return { -1, Optional<IPC::File> {} };
    }
    auto id = request->id();
    auto fd = request->request_fd();
    m_requests.set(id, move(request));
    return { id, IPC::File(fd, IPC::File::CloseAfterSending) };
}

Messages::RequestServer::StopRequestResponse ClientConnection::stop_request(i32 request_id)
{
    auto* request = const_cast<Request*>(m_requests.get(request_id).value_or(nullptr));
    bool success = false;
    if (request) {
        request->stop();
        m_requests.remove(request_id);
        success = true;
    }
    return success;
}

void ClientConnection::did_receive_headers(Badge<Request>, Request& request)
{
    IPC::Dictionary response_headers;
    for (auto& it : request.response_headers())
        response_headers.add(it.key, it.value);

    async_headers_became_available(request.id(), move(response_headers), request.status_code());
}

void ClientConnection::did_finish_request(Badge<Request>, Request& request, bool success)
{
    VERIFY(request.total_size().has_value());

    async_request_finished(request.id(), success, request.total_size().value());

    m_requests.remove(request.id());
}

void ClientConnection::did_progress_request(Badge<Request>, Request& request)
{
    async_request_progress(request.id(), request.total_size(), request.downloaded_size());
}

void ClientConnection::did_request_certificates(Badge<Request>, Request& request)
{
    async_certificate_requested(request.id());
}

Messages::RequestServer::SetCertificateResponse ClientConnection::set_certificate(i32 request_id, String const& certificate, String const& key)
{
    auto* request = const_cast<Request*>(m_requests.get(request_id).value_or(nullptr));
    bool success = false;
    if (request) {
        request->set_certificate(certificate, key);
        success = true;
    }
    return success;
}

void ClientConnection::ensure_connection(URL const& url, ::RequestServer::CacheLevel const& cache_level)
{
    if (!url.is_valid()) {
        dbgln("EnsureConnection: Invalid URL requested: '{}'", url);
        return;
    }

    if (cache_level == CacheLevel::ResolveOnly) {
        return Core::deferred_invoke([host = url.host()] {
            dbgln("EnsureConnection: DNS-preload for {}", host);
            (void)gethostbyname(host.characters());
        });
    }

    struct {
        URL const& m_url;
        void start(NonnullRefPtr<Core::Socket> socket)
        {
            auto is_tls = is<TLS::TLSv12>(*socket);
            auto* tls_instance = is_tls ? static_cast<TLS::TLSv12*>(socket.ptr()) : nullptr;

            auto is_connected = false;
            if (is_tls && tls_instance->is_established())
                is_connected = true;
            if (!is_tls && socket->is_connected())
                is_connected = true;

            if (is_connected)
                return ConnectionCache::request_did_finish(m_url, socket);

            bool did_connect;
            if (is_tls) {
                tls_instance->set_root_certificates(DefaultRootCACertificates::the().certificates());
                tls_instance->on_tls_connected = [socket, url = m_url, tls_instance] {
                    tls_instance->set_on_tls_ready_to_write([socket, url](auto&) {
                        ConnectionCache::request_did_finish(url, socket);
                    });
                };
                tls_instance->on_tls_error = [socket, url = m_url](auto) {
                    ConnectionCache::request_did_finish(url, socket);
                };
                did_connect = tls_instance->connect(m_url.host(), m_url.port_or_default());
            } else {
                socket->on_connected = [socket, url = m_url]() mutable {
                    ConnectionCache::request_did_finish(url, socket);
                };
                did_connect = socket->connect(m_url.host(), m_url.port_or_default());
            }

            if (!did_connect)
                ConnectionCache::request_did_finish(m_url, socket);
        }
    } job { url };

    dbgln("EnsureConnection: Pre-connect to {}", url);
    auto do_preconnect = [&](auto& cache) {
        ConnectionCache::get_or_create_connection(cache, url, job);
    };

    if (url.scheme() == "http"sv)
        do_preconnect(ConnectionCache::g_tcp_connection_cache);
    else if (url.scheme() == "https"sv)
        do_preconnect(ConnectionCache::g_tls_connection_cache);
    else
        dbgln("EnsureConnection: Invalid URL scheme: '{}'", url.scheme());
}

}
