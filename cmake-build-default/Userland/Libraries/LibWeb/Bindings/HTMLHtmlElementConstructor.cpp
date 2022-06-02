
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLHtmlElementConstructor.h>
#include <LibWeb/Bindings/HTMLHtmlElementPrototype.h>
#include <LibWeb/Bindings/HTMLHtmlElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLHtmlElement.h>)
#    include <LibWeb/Crypto/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/CSS/HTMLHtmlElement.h>)
#    include <LibWeb/CSS/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/DOM/HTMLHtmlElement.h>)
#    include <LibWeb/DOM/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLHtmlElement.h>)
#    include <LibWeb/Encoding/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLHtmlElement.h>)
#    include <LibWeb/Geometry/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/HTML/HTMLHtmlElement.h>)
#    include <LibWeb/HTML/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLHtmlElement.h>)
#    include <LibWeb/UIEvents/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLHtmlElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLHtmlElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLHtmlElement.h>)
#    include <LibWeb/NavigationTiming/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLHtmlElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLHtmlElement.h>)
#    include <LibWeb/ResizeObserver/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/SVG/HTMLHtmlElement.h>)
#    include <LibWeb/SVG/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/Selection/HTMLHtmlElement.h>)
#    include <LibWeb/Selection/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLHtmlElement.h>)
#    include <LibWeb/WebSockets/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/XHR/HTMLHtmlElement.h>)
#    include <LibWeb/XHR/HTMLHtmlElement.h>
#elif __has_include(<LibWeb/URL/HTMLHtmlElement.h>)
#    include <LibWeb/URL/HTMLHtmlElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLHtmlElement.h>

#include <LibWeb/HTML/HTMLHtmlElement.h>

#if __has_include(<LibWeb/Bindings/HTMLHtmlElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLHtmlElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLHtmlElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLHtmlElementWrapperFactory.h>
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

HTMLHtmlElementConstructor::HTMLHtmlElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLHtmlElementConstructor::~HTMLHtmlElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLHtmlElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLHtmlElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLHtmlElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLHtmlElement");

}

void HTMLHtmlElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLHtmlElementPrototype>("HTMLHtmlElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

