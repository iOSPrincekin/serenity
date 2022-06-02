
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/WebSocketPrototype.h>
#include <LibWeb/Bindings/WebSocketWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/WebSockets/WebSocket.h>

#if __has_include(<LibWeb/Bindings/WebSocketWrapper.h>)
#   include <LibWeb/Bindings/WebSocketWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WebSocketWrapperFactory.h>)
#   include <LibWeb/Bindings/WebSocketWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
#endif

// FIXME: This is a total hack until we can figure out the namespace for a given type somehow.
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;

namespace Web::Bindings {

WebSocketWrapper* WebSocketWrapper::create(JS::GlobalObject& global_object, WebSockets::WebSocket& impl)
{
    return global_object.heap().allocate<WebSocketWrapper>(global_object, global_object, impl);
}


WebSocketWrapper::WebSocketWrapper(JS::GlobalObject& global_object, WebSockets::WebSocket& impl)
    : EventTargetWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<WebSocketPrototype>("WebSocket"));
}

void WebSocketWrapper::initialize(JS::GlobalObject& global_object)
{
    EventTargetWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "WebSocket"), JS::Attribute::Configurable);
}

WebSocketWrapper::~WebSocketWrapper()
{
}

WebSocketWrapper* wrap(JS::GlobalObject& global_object, WebSockets::WebSocket& impl)
{
    return static_cast<WebSocketWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

