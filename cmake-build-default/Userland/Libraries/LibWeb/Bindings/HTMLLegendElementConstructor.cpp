
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLLegendElementConstructor.h>
#include <LibWeb/Bindings/HTMLLegendElementPrototype.h>
#include <LibWeb/Bindings/HTMLLegendElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLLegendElement.h>)
#    include <LibWeb/Crypto/HTMLLegendElement.h>
#elif __has_include(<LibWeb/CSS/HTMLLegendElement.h>)
#    include <LibWeb/CSS/HTMLLegendElement.h>
#elif __has_include(<LibWeb/DOM/HTMLLegendElement.h>)
#    include <LibWeb/DOM/HTMLLegendElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLLegendElement.h>)
#    include <LibWeb/Encoding/HTMLLegendElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLLegendElement.h>)
#    include <LibWeb/Geometry/HTMLLegendElement.h>
#elif __has_include(<LibWeb/HTML/HTMLLegendElement.h>)
#    include <LibWeb/HTML/HTMLLegendElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLLegendElement.h>)
#    include <LibWeb/UIEvents/HTMLLegendElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLLegendElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLLegendElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLLegendElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLLegendElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLLegendElement.h>)
#    include <LibWeb/NavigationTiming/HTMLLegendElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLLegendElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLLegendElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLLegendElement.h>)
#    include <LibWeb/ResizeObserver/HTMLLegendElement.h>
#elif __has_include(<LibWeb/SVG/HTMLLegendElement.h>)
#    include <LibWeb/SVG/HTMLLegendElement.h>
#elif __has_include(<LibWeb/Selection/HTMLLegendElement.h>)
#    include <LibWeb/Selection/HTMLLegendElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLLegendElement.h>)
#    include <LibWeb/WebSockets/HTMLLegendElement.h>
#elif __has_include(<LibWeb/XHR/HTMLLegendElement.h>)
#    include <LibWeb/XHR/HTMLLegendElement.h>
#elif __has_include(<LibWeb/URL/HTMLLegendElement.h>)
#    include <LibWeb/URL/HTMLLegendElement.h>
#endif


#include <LibWeb/HTML/HTMLLegendElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLLegendElement.h>

#if __has_include(<LibWeb/Bindings/HTMLLegendElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLLegendElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLLegendElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLLegendElementWrapperFactory.h>
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

HTMLLegendElementConstructor::HTMLLegendElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLLegendElementConstructor::~HTMLLegendElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLLegendElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLLegendElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLLegendElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLLegendElement");

}

void HTMLLegendElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLLegendElementPrototype>("HTMLLegendElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

