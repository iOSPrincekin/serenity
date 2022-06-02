
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/WebSocketConstructor.h>
#include <LibWeb/Bindings/WebSocketPrototype.h>
#include <LibWeb/Bindings/WebSocketWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/WebSocket.h>)
#    include <LibWeb/Crypto/WebSocket.h>
#elif __has_include(<LibWeb/CSS/WebSocket.h>)
#    include <LibWeb/CSS/WebSocket.h>
#elif __has_include(<LibWeb/DOM/WebSocket.h>)
#    include <LibWeb/DOM/WebSocket.h>
#elif __has_include(<LibWeb/Encoding/WebSocket.h>)
#    include <LibWeb/Encoding/WebSocket.h>
#elif __has_include(<LibWeb/Geometry/WebSocket.h>)
#    include <LibWeb/Geometry/WebSocket.h>
#elif __has_include(<LibWeb/HTML/WebSocket.h>)
#    include <LibWeb/HTML/WebSocket.h>
#elif __has_include(<LibWeb/UIEvents/WebSocket.h>)
#    include <LibWeb/UIEvents/WebSocket.h>
#elif __has_include(<LibWeb/HighResolutionTime/WebSocket.h>)
#    include <LibWeb/HighResolutionTime/WebSocket.h>
#elif __has_include(<LibWeb/IntersectionObserver/WebSocket.h>)
#    include <LibWeb/IntersectionObserver/WebSocket.h>
#elif __has_include(<LibWeb/NavigationTiming/WebSocket.h>)
#    include <LibWeb/NavigationTiming/WebSocket.h>
#elif __has_include(<LibWeb/RequestIdleCallback/WebSocket.h>)
#    include <LibWeb/RequestIdleCallback/WebSocket.h>
#elif __has_include(<LibWeb/ResizeObserver/WebSocket.h>)
#    include <LibWeb/ResizeObserver/WebSocket.h>
#elif __has_include(<LibWeb/SVG/WebSocket.h>)
#    include <LibWeb/SVG/WebSocket.h>
#elif __has_include(<LibWeb/Selection/WebSocket.h>)
#    include <LibWeb/Selection/WebSocket.h>
#elif __has_include(<LibWeb/WebSockets/WebSocket.h>)
#    include <LibWeb/WebSockets/WebSocket.h>
#elif __has_include(<LibWeb/XHR/WebSocket.h>)
#    include <LibWeb/XHR/WebSocket.h>
#elif __has_include(<LibWeb/URL/WebSocket.h>)
#    include <LibWeb/URL/WebSocket.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/WebSockets/WebSocket.h>

#include <LibWeb/DOM/AbortSignal.h>

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
using namespace Web::UIEvents;
using namespace Web::XHR;

namespace Web::Bindings {

WebSocketConstructor::WebSocketConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

WebSocketConstructor::~WebSocketConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> WebSocketConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "WebSocket");
}

JS::ThrowCompletionOr<JS::Object*> WebSocketConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "WebSocket");

    auto arg0 = vm.argument(0);

    String url;
    if (arg0.is_null() && false) {
        url = String::empty();
    } else {
        url = TRY(arg0.to_string(global_object));
    }

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return WebSockets::WebSocket::create_with_global_object(window, url); }));

    return wrap(global_object, *impl);

}

void WebSocketConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<WebSocketPrototype>("WebSocket"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


define_direct_property("CONNECTING", JS::Value((i32)0), JS::Attribute::Enumerable);

define_direct_property("OPEN", JS::Value((i32)1), JS::Attribute::Enumerable);

define_direct_property("CLOSING", JS::Value((i32)2), JS::Attribute::Enumerable);

define_direct_property("CLOSED", JS::Value((i32)3), JS::Attribute::Enumerable);

}

} // namespace Web::Bindings

