
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLUnknownElementConstructor.h>
#include <LibWeb/Bindings/HTMLUnknownElementPrototype.h>
#include <LibWeb/Bindings/HTMLUnknownElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLUnknownElement.h>)
#    include <LibWeb/Crypto/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/CSS/HTMLUnknownElement.h>)
#    include <LibWeb/CSS/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/DOM/HTMLUnknownElement.h>)
#    include <LibWeb/DOM/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLUnknownElement.h>)
#    include <LibWeb/Encoding/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLUnknownElement.h>)
#    include <LibWeb/Geometry/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/HTML/HTMLUnknownElement.h>)
#    include <LibWeb/HTML/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLUnknownElement.h>)
#    include <LibWeb/UIEvents/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLUnknownElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLUnknownElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLUnknownElement.h>)
#    include <LibWeb/NavigationTiming/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLUnknownElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLUnknownElement.h>)
#    include <LibWeb/ResizeObserver/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/SVG/HTMLUnknownElement.h>)
#    include <LibWeb/SVG/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/Selection/HTMLUnknownElement.h>)
#    include <LibWeb/Selection/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLUnknownElement.h>)
#    include <LibWeb/WebSockets/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/XHR/HTMLUnknownElement.h>)
#    include <LibWeb/XHR/HTMLUnknownElement.h>
#elif __has_include(<LibWeb/URL/HTMLUnknownElement.h>)
#    include <LibWeb/URL/HTMLUnknownElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLUnknownElement.h>

#include <LibWeb/HTML/HTMLUnknownElement.h>

#if __has_include(<LibWeb/Bindings/HTMLUnknownElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLUnknownElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLUnknownElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLUnknownElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
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

HTMLUnknownElementConstructor::HTMLUnknownElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLUnknownElementConstructor::~HTMLUnknownElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLUnknownElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLUnknownElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLUnknownElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLUnknownElement");

}

void HTMLUnknownElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLUnknownElementPrototype>("HTMLUnknownElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

