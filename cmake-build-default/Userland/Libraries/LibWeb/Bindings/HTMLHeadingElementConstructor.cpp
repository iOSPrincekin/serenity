
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLHeadingElementConstructor.h>
#include <LibWeb/Bindings/HTMLHeadingElementPrototype.h>
#include <LibWeb/Bindings/HTMLHeadingElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLHeadingElement.h>)
#    include <LibWeb/Crypto/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/CSS/HTMLHeadingElement.h>)
#    include <LibWeb/CSS/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/DOM/HTMLHeadingElement.h>)
#    include <LibWeb/DOM/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLHeadingElement.h>)
#    include <LibWeb/Encoding/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLHeadingElement.h>)
#    include <LibWeb/Geometry/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/HTML/HTMLHeadingElement.h>)
#    include <LibWeb/HTML/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLHeadingElement.h>)
#    include <LibWeb/UIEvents/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLHeadingElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLHeadingElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLHeadingElement.h>)
#    include <LibWeb/NavigationTiming/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLHeadingElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLHeadingElement.h>)
#    include <LibWeb/ResizeObserver/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/SVG/HTMLHeadingElement.h>)
#    include <LibWeb/SVG/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/Selection/HTMLHeadingElement.h>)
#    include <LibWeb/Selection/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLHeadingElement.h>)
#    include <LibWeb/WebSockets/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/XHR/HTMLHeadingElement.h>)
#    include <LibWeb/XHR/HTMLHeadingElement.h>
#elif __has_include(<LibWeb/URL/HTMLHeadingElement.h>)
#    include <LibWeb/URL/HTMLHeadingElement.h>
#endif


#include <LibWeb/HTML/HTMLHeadingElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLHeadingElement.h>

#if __has_include(<LibWeb/Bindings/HTMLHeadingElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLHeadingElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLHeadingElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLHeadingElementWrapperFactory.h>
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

HTMLHeadingElementConstructor::HTMLHeadingElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLHeadingElementConstructor::~HTMLHeadingElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLHeadingElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLHeadingElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLHeadingElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLHeadingElement");

}

void HTMLHeadingElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLHeadingElementPrototype>("HTMLHeadingElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

