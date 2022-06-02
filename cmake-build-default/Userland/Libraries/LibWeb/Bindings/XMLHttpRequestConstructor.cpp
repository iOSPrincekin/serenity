
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/XMLHttpRequestConstructor.h>
#include <LibWeb/Bindings/XMLHttpRequestPrototype.h>
#include <LibWeb/Bindings/XMLHttpRequestWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/XMLHttpRequest.h>)
#    include <LibWeb/Crypto/XMLHttpRequest.h>
#elif __has_include(<LibWeb/CSS/XMLHttpRequest.h>)
#    include <LibWeb/CSS/XMLHttpRequest.h>
#elif __has_include(<LibWeb/DOM/XMLHttpRequest.h>)
#    include <LibWeb/DOM/XMLHttpRequest.h>
#elif __has_include(<LibWeb/Encoding/XMLHttpRequest.h>)
#    include <LibWeb/Encoding/XMLHttpRequest.h>
#elif __has_include(<LibWeb/Geometry/XMLHttpRequest.h>)
#    include <LibWeb/Geometry/XMLHttpRequest.h>
#elif __has_include(<LibWeb/HTML/XMLHttpRequest.h>)
#    include <LibWeb/HTML/XMLHttpRequest.h>
#elif __has_include(<LibWeb/UIEvents/XMLHttpRequest.h>)
#    include <LibWeb/UIEvents/XMLHttpRequest.h>
#elif __has_include(<LibWeb/HighResolutionTime/XMLHttpRequest.h>)
#    include <LibWeb/HighResolutionTime/XMLHttpRequest.h>
#elif __has_include(<LibWeb/IntersectionObserver/XMLHttpRequest.h>)
#    include <LibWeb/IntersectionObserver/XMLHttpRequest.h>
#elif __has_include(<LibWeb/NavigationTiming/XMLHttpRequest.h>)
#    include <LibWeb/NavigationTiming/XMLHttpRequest.h>
#elif __has_include(<LibWeb/RequestIdleCallback/XMLHttpRequest.h>)
#    include <LibWeb/RequestIdleCallback/XMLHttpRequest.h>
#elif __has_include(<LibWeb/ResizeObserver/XMLHttpRequest.h>)
#    include <LibWeb/ResizeObserver/XMLHttpRequest.h>
#elif __has_include(<LibWeb/SVG/XMLHttpRequest.h>)
#    include <LibWeb/SVG/XMLHttpRequest.h>
#elif __has_include(<LibWeb/Selection/XMLHttpRequest.h>)
#    include <LibWeb/Selection/XMLHttpRequest.h>
#elif __has_include(<LibWeb/WebSockets/XMLHttpRequest.h>)
#    include <LibWeb/WebSockets/XMLHttpRequest.h>
#elif __has_include(<LibWeb/XHR/XMLHttpRequest.h>)
#    include <LibWeb/XHR/XMLHttpRequest.h>
#elif __has_include(<LibWeb/URL/XMLHttpRequest.h>)
#    include <LibWeb/URL/XMLHttpRequest.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/XHR/XMLHttpRequest.h>

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/XHR/XMLHttpRequest.h>

#if __has_include(<LibWeb/Bindings/XMLHttpRequestWrapper.h>)
#   include <LibWeb/Bindings/XMLHttpRequestWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/XMLHttpRequestWrapperFactory.h>)
#   include <LibWeb/Bindings/XMLHttpRequestWrapperFactory.h>
#endif

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>)
#   include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapperFactory.h>
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

XMLHttpRequestConstructor::XMLHttpRequestConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

XMLHttpRequestConstructor::~XMLHttpRequestConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> XMLHttpRequestConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "XMLHttpRequest");
}

JS::ThrowCompletionOr<JS::Object*> XMLHttpRequestConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return XHR::XMLHttpRequest::create_with_global_object(window); }));

    return wrap(global_object, *impl);

}

void XMLHttpRequestConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<XMLHttpRequestPrototype>("XMLHttpRequest"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


define_direct_property("UNSENT", JS::Value((i32)0), JS::Attribute::Enumerable);

define_direct_property("OPENED", JS::Value((i32)1), JS::Attribute::Enumerable);

define_direct_property("HEADERS_RECEIVED", JS::Value((i32)2), JS::Attribute::Enumerable);

define_direct_property("LOADING", JS::Value((i32)3), JS::Attribute::Enumerable);

define_direct_property("DONE", JS::Value((i32)4), JS::Attribute::Enumerable);

}

} // namespace Web::Bindings

