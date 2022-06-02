
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/WebSockets/WebSocket.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class WebSocketWrapper : public EventTargetWrapper {
    JS_OBJECT(WebSocket, EventTargetWrapper);
public:
    static WebSocketWrapper* create(JS::GlobalObject&, WebSockets::WebSocket&);

    WebSocketWrapper(JS::GlobalObject&, WebSockets::WebSocket&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WebSocketWrapper() override;

    WebSockets::WebSocket& impl() { return static_cast<WebSockets::WebSocket&>(EventTargetWrapper::impl()); }
    WebSockets::WebSocket const& impl() const { return static_cast<WebSockets::WebSocket const&>(EventTargetWrapper::impl()); }

private:

};

WebSocketWrapper* wrap(JS::GlobalObject&, WebSockets::WebSocket&);

} // namespace Web::Bindings

