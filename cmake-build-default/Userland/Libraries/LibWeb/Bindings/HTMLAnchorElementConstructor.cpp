
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLAnchorElementConstructor.h>
#include <LibWeb/Bindings/HTMLAnchorElementPrototype.h>
#include <LibWeb/Bindings/HTMLAnchorElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLAnchorElement.h>)
#    include <LibWeb/Crypto/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/CSS/HTMLAnchorElement.h>)
#    include <LibWeb/CSS/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/DOM/HTMLAnchorElement.h>)
#    include <LibWeb/DOM/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLAnchorElement.h>)
#    include <LibWeb/Encoding/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLAnchorElement.h>)
#    include <LibWeb/Geometry/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/HTML/HTMLAnchorElement.h>)
#    include <LibWeb/HTML/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLAnchorElement.h>)
#    include <LibWeb/UIEvents/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLAnchorElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLAnchorElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLAnchorElement.h>)
#    include <LibWeb/NavigationTiming/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLAnchorElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLAnchorElement.h>)
#    include <LibWeb/ResizeObserver/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/SVG/HTMLAnchorElement.h>)
#    include <LibWeb/SVG/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/Selection/HTMLAnchorElement.h>)
#    include <LibWeb/Selection/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLAnchorElement.h>)
#    include <LibWeb/WebSockets/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/XHR/HTMLAnchorElement.h>)
#    include <LibWeb/XHR/HTMLAnchorElement.h>
#elif __has_include(<LibWeb/URL/HTMLAnchorElement.h>)
#    include <LibWeb/URL/HTMLAnchorElement.h>
#endif


#include <LibWeb/HTML/HTMLAnchorElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLAnchorElement.h>

#if __has_include(<LibWeb/Bindings/HTMLAnchorElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLAnchorElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLAnchorElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLAnchorElementWrapperFactory.h>
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

HTMLAnchorElementConstructor::HTMLAnchorElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLAnchorElementConstructor::~HTMLAnchorElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLAnchorElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLAnchorElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLAnchorElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLAnchorElement");

}

void HTMLAnchorElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLAnchorElementPrototype>("HTMLAnchorElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

