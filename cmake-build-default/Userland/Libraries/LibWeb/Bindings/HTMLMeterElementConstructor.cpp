
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLMeterElementConstructor.h>
#include <LibWeb/Bindings/HTMLMeterElementPrototype.h>
#include <LibWeb/Bindings/HTMLMeterElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLMeterElement.h>)
#    include <LibWeb/Crypto/HTMLMeterElement.h>
#elif __has_include(<LibWeb/CSS/HTMLMeterElement.h>)
#    include <LibWeb/CSS/HTMLMeterElement.h>
#elif __has_include(<LibWeb/DOM/HTMLMeterElement.h>)
#    include <LibWeb/DOM/HTMLMeterElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLMeterElement.h>)
#    include <LibWeb/Encoding/HTMLMeterElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLMeterElement.h>)
#    include <LibWeb/Geometry/HTMLMeterElement.h>
#elif __has_include(<LibWeb/HTML/HTMLMeterElement.h>)
#    include <LibWeb/HTML/HTMLMeterElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLMeterElement.h>)
#    include <LibWeb/UIEvents/HTMLMeterElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLMeterElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLMeterElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLMeterElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLMeterElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLMeterElement.h>)
#    include <LibWeb/NavigationTiming/HTMLMeterElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLMeterElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLMeterElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLMeterElement.h>)
#    include <LibWeb/ResizeObserver/HTMLMeterElement.h>
#elif __has_include(<LibWeb/SVG/HTMLMeterElement.h>)
#    include <LibWeb/SVG/HTMLMeterElement.h>
#elif __has_include(<LibWeb/Selection/HTMLMeterElement.h>)
#    include <LibWeb/Selection/HTMLMeterElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLMeterElement.h>)
#    include <LibWeb/WebSockets/HTMLMeterElement.h>
#elif __has_include(<LibWeb/XHR/HTMLMeterElement.h>)
#    include <LibWeb/XHR/HTMLMeterElement.h>
#elif __has_include(<LibWeb/URL/HTMLMeterElement.h>)
#    include <LibWeb/URL/HTMLMeterElement.h>
#endif


#include <LibWeb/HTML/HTMLMeterElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMeterElement.h>

#if __has_include(<LibWeb/Bindings/HTMLMeterElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMeterElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMeterElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMeterElementWrapperFactory.h>
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

HTMLMeterElementConstructor::HTMLMeterElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLMeterElementConstructor::~HTMLMeterElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLMeterElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLMeterElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLMeterElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLMeterElement");

}

void HTMLMeterElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLMeterElementPrototype>("HTMLMeterElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

