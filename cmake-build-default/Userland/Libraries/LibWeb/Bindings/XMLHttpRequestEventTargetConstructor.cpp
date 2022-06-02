
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/XMLHttpRequestEventTargetConstructor.h>
#include <LibWeb/Bindings/XMLHttpRequestEventTargetPrototype.h>
#include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/Crypto/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/CSS/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/CSS/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/DOM/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/DOM/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/Encoding/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/Encoding/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/Geometry/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/Geometry/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/HTML/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/HTML/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/UIEvents/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/UIEvents/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/HighResolutionTime/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/HighResolutionTime/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/IntersectionObserver/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/IntersectionObserver/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/NavigationTiming/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/NavigationTiming/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/RequestIdleCallback/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/RequestIdleCallback/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/ResizeObserver/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/ResizeObserver/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/SVG/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/SVG/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/Selection/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/Selection/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/WebSockets/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/WebSockets/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/XHR/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/XHR/XMLHttpRequestEventTarget.h>
#elif __has_include(<LibWeb/URL/XMLHttpRequestEventTarget.h>)
#    include <LibWeb/URL/XMLHttpRequestEventTarget.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

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

XMLHttpRequestEventTargetConstructor::XMLHttpRequestEventTargetConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

XMLHttpRequestEventTargetConstructor::~XMLHttpRequestEventTargetConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> XMLHttpRequestEventTargetConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "XMLHttpRequestEventTarget");
}

JS::ThrowCompletionOr<JS::Object*> XMLHttpRequestEventTargetConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "XMLHttpRequestEventTarget");

}

void XMLHttpRequestEventTargetConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<XMLHttpRequestEventTargetPrototype>("XMLHttpRequestEventTarget"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

