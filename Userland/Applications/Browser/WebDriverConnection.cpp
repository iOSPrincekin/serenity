/*
 * Copyright (c) 2022, Florent Castelli <florent.castelli@gmail.com>
 * Copyright (c) 2022, Sam Atkins <atkinssj@serenityos.org>
 * Copyright (c) 2022, Tobias Christiansen <tobyase@serenityos.org>
 * Copyright (c) 2022, Tim Flynn <trflynn89@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "WebDriverConnection.h"
#include "BrowserWindow.h"
#include <AK/Vector.h>
#include <LibWeb/Cookie/Cookie.h>
#include <LibWeb/Cookie/ParsedCookie.h>
#include <LibWebView/WebContentClient.h>

namespace Browser {

WebDriverConnection::WebDriverConnection(NonnullOwnPtr<Core::Stream::LocalSocket> socket, NonnullRefPtr<BrowserWindow> browser_window)
    : IPC::ConnectionToServer<WebDriverSessionClientEndpoint, WebDriverSessionServerEndpoint>(*this, move(socket))
    , m_browser_window(move(browser_window))
{
}

void WebDriverConnection::quit()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: quit");
    if (auto browser_window = m_browser_window.strong_ref())
        browser_window->close();
}

Messages::WebDriverSessionClient::GetTitleResponse WebDriverConnection::get_title()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: get_title");
    if (auto browser_window = m_browser_window.strong_ref())
        return { browser_window->active_tab().title() };
    return { "" };
}

void WebDriverConnection::refresh()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: refresh");
    if (auto browser_window = m_browser_window.strong_ref())
        browser_window->active_tab().reload();
}

void WebDriverConnection::back()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: back");
    if (auto browser_window = m_browser_window.strong_ref())
        browser_window->active_tab().go_back();
}

void WebDriverConnection::forward()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: forward");
    if (auto browser_window = m_browser_window.strong_ref())
        browser_window->active_tab().go_forward();
}

Messages::WebDriverSessionClient::SerializeSourceResponse WebDriverConnection::serialize_source()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: serialize_source");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_serialize_source)
            return { tab.webdriver_endpoints().on_serialize_source() };
    }

    return { {} };
}

Messages::WebDriverSessionClient::ExecuteScriptResponse WebDriverConnection::execute_script(String const& body, Vector<String> const& json_arguments, Optional<u64> const& timeout, bool async)
{
    dbgln("WebDriverConnection: execute_script");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_execute_script) {
            auto response = tab.webdriver_endpoints().on_execute_script(body, json_arguments, timeout, async);
            // WebContentServer's and WebDriverSessionClient's ExecuteScriptResponse have an identical
            // structure but are distinct types, so we have to convert here.
            return { response.result_type(), response.json_result() };
        }
    }
    return { {} };
}

Messages::WebDriverSessionClient::GetAllCookiesResponse WebDriverConnection::get_all_cookies()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: get_cookies");
    if (auto browser_window = m_browser_window.strong_ref()) {
        if (browser_window->active_tab().on_get_cookies_entries) {
            return { browser_window->active_tab().on_get_cookies_entries() };
        }
    }
    return { {} };
}

Messages::WebDriverSessionClient::GetNamedCookieResponse WebDriverConnection::get_named_cookie(String const& name)
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: get_named_cookie {}", name);
    if (auto browser_window = m_browser_window.strong_ref()) {
        if (browser_window->active_tab().on_get_cookies_entries) {
            for (auto cookie : browser_window->active_tab().on_get_cookies_entries()) {
                if (cookie.name == name)
                    return { cookie };
            }
            return Optional<Web::Cookie::Cookie> {};
        }
    }
    return { {} };
}

void WebDriverConnection::add_cookie(Web::Cookie::ParsedCookie const& cookie)
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: add_cookie {}", cookie.name);
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.on_set_cookie) {
            // FIXME: The spec doesn't say anything about the source
            //  but can we assume a cookie created through a HTTP-request to the WebDriver
            //  to be (source) from an HTTP-API?
            tab.on_set_cookie(tab.url(), cookie, Web::Cookie::Source::Http);
        }
    }
}

void WebDriverConnection::update_cookie(Web::Cookie::Cookie const& cookie)
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: update_cookie {}", cookie.name);
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.on_update_cookie) {
            tab.on_update_cookie(tab.url(), cookie);
        }
    }
}

void WebDriverConnection::scroll_element_into_view(i32 element_id)
{
    dbgln("WebDriverConnection: scroll_element_into_view {}", element_id);
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_scroll_element_into_view)
            tab.webdriver_endpoints().on_scroll_element_into_view(element_id);
    }
}

Messages::WebDriverSessionClient::IsElementSelectedResponse WebDriverConnection::is_element_selected(i32 element_id)
{
    dbgln("WebDriverConnection: is_element_selected {}", element_id);
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_is_element_selected)
            return { tab.webdriver_endpoints().on_is_element_selected(element_id) };
    }
    return { false };
}

Messages::WebDriverSessionClient::GetElementAttributeResponse WebDriverConnection::get_element_attribute(i32 element_id, String const& name)
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: get_element_attribute");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_get_element_attribute)
            return { tab.webdriver_endpoints().on_get_element_attribute(element_id, name) };
    }
    return { {} };
}

Messages::WebDriverSessionClient::GetElementPropertyResponse WebDriverConnection::get_element_property(i32 element_id, String const& name)
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: get_element_property");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_get_element_property)
            return { tab.webdriver_endpoints().on_get_element_property(element_id, name) };
    }
    return { {} };
}

Messages::WebDriverSessionClient::GetActiveDocumentsTypeResponse WebDriverConnection::get_active_documents_type()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: get_active_documents_type");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_get_active_documents_type)
            return { tab.webdriver_endpoints().on_get_active_documents_type() };
    }
    return { "" };
}

Messages::WebDriverSessionClient::GetComputedValueForElementResponse WebDriverConnection::get_computed_value_for_element(i32 element_id, String const& property_name)
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: get_computed_value_for_element");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_get_computed_value_for_element)
            return { tab.webdriver_endpoints().on_get_computed_value_for_element(element_id, property_name) };
    }
    return { "" };
}

Messages::WebDriverSessionClient::GetElementTextResponse WebDriverConnection::get_element_text(i32 element_id)
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: get_element_text");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_get_element_text)
            return { tab.webdriver_endpoints().on_get_element_text(element_id) };
    }
    return { "" };
}

Messages::WebDriverSessionClient::GetElementTagNameResponse WebDriverConnection::get_element_tag_name(i32 element_id)
{
    dbgln("WebDriverConnection: get_computed_value_for_element");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_get_element_tag_name)
            return { tab.webdriver_endpoints().on_get_element_tag_name(element_id) };
    }
    return { "" };
}

Messages::WebDriverSessionClient::GetElementRectResponse WebDriverConnection::get_element_rect(i32 element_id)
{
    dbgln("WebDriverConnection: get_element_rect {}", element_id);
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_get_element_rect)
            return { tab.webdriver_endpoints().on_get_element_rect(element_id) };
    }
    return { {} };
}

Messages::WebDriverSessionClient::IsElementEnabledResponse WebDriverConnection::is_element_enabled(i32 element_id)
{
    dbgln("WebDriverConnection: is_element_enabled {}", element_id);
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_is_element_enabled)
            return { tab.webdriver_endpoints().on_is_element_enabled(element_id) };
    }
    return { false };
}

Messages::WebDriverSessionClient::TakeScreenshotResponse WebDriverConnection::take_screenshot()
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: take_screenshot");
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.on_take_screenshot)
            return { tab.on_take_screenshot() };
    }

    return { {} };
}

Messages::WebDriverSessionClient::TakeElementScreenshotResponse WebDriverConnection::take_element_screenshot(i32 element_id)
{
    dbgln_if(WEBDRIVER_DEBUG, "WebDriverConnection: take_element_screenshot {}", element_id);
    if (auto browser_window = m_browser_window.strong_ref()) {
        auto& tab = browser_window->active_tab();
        if (tab.webdriver_endpoints().on_take_element_screenshot)
            return { tab.webdriver_endpoints().on_take_element_screenshot(element_id) };
    }

    return { {} };
}

}
