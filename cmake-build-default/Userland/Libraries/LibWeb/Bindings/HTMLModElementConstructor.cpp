
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLModElementConstructor.h>
#include <LibWeb/Bindings/HTMLModElementPrototype.h>
#include <LibWeb/Bindings/HTMLModElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLModElement.h>)
#    include <LibWeb/Crypto/HTMLModElement.h>
#elif __has_include(<LibWeb/CSS/HTMLModElement.h>)
#    include <LibWeb/CSS/HTMLModElement.h>
#elif __has_include(<LibWeb/DOM/HTMLModElement.h>)
#    include <LibWeb/DOM/HTMLModElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLModElement.h>)
#    include <LibWeb/Encoding/HTMLModElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLModElement.h>)
#    include <LibWeb/Geometry/HTMLModElement.h>
#elif __has_include(<LibWeb/HTML/HTMLModElement.h>)
#    include <LibWeb/HTML/HTMLModElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLModElement.h>)
#    include <LibWeb/UIEvents/HTMLModElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLModElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLModElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLModElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLModElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLModElement.h>)
#    include <LibWeb/NavigationTiming/HTMLModElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLModElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLModElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLModElement.h>)
#    include <LibWeb/ResizeObserver/HTMLModElement.h>
#elif __has_include(<LibWeb/SVG/HTMLModElement.h>)
#    include <LibWeb/SVG/HTMLModElement.h>
#elif __has_include(<LibWeb/Selection/HTMLModElement.h>)
#    include <LibWeb/Selection/HTMLModElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLModElement.h>)
#    include <LibWeb/WebSockets/HTMLModElement.h>
#elif __has_include(<LibWeb/XHR/HTMLModElement.h>)
#    include <LibWeb/XHR/HTMLModElement.h>
#elif __has_include(<LibWeb/URL/HTMLModElement.h>)
#    include <LibWeb/URL/HTMLModElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLModElement.h>

#include <LibWeb/HTML/HTMLModElement.h>

#if __has_include(<LibWeb/Bindings/HTMLModElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLModElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLModElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLModElementWrapperFactory.h>
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

HTMLModElementConstructor::HTMLModElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLModElementConstructor::~HTMLModElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLModElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLModElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLModElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLModElement");

}

void HTMLModElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLModElementPrototype>("HTMLModElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

