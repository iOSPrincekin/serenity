
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLSourceElementConstructor.h>
#include <LibWeb/Bindings/HTMLSourceElementPrototype.h>
#include <LibWeb/Bindings/HTMLSourceElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLSourceElement.h>)
#    include <LibWeb/Crypto/HTMLSourceElement.h>
#elif __has_include(<LibWeb/CSS/HTMLSourceElement.h>)
#    include <LibWeb/CSS/HTMLSourceElement.h>
#elif __has_include(<LibWeb/DOM/HTMLSourceElement.h>)
#    include <LibWeb/DOM/HTMLSourceElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLSourceElement.h>)
#    include <LibWeb/Encoding/HTMLSourceElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLSourceElement.h>)
#    include <LibWeb/Geometry/HTMLSourceElement.h>
#elif __has_include(<LibWeb/HTML/HTMLSourceElement.h>)
#    include <LibWeb/HTML/HTMLSourceElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLSourceElement.h>)
#    include <LibWeb/UIEvents/HTMLSourceElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLSourceElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLSourceElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLSourceElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLSourceElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLSourceElement.h>)
#    include <LibWeb/NavigationTiming/HTMLSourceElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLSourceElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLSourceElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLSourceElement.h>)
#    include <LibWeb/ResizeObserver/HTMLSourceElement.h>
#elif __has_include(<LibWeb/SVG/HTMLSourceElement.h>)
#    include <LibWeb/SVG/HTMLSourceElement.h>
#elif __has_include(<LibWeb/Selection/HTMLSourceElement.h>)
#    include <LibWeb/Selection/HTMLSourceElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLSourceElement.h>)
#    include <LibWeb/WebSockets/HTMLSourceElement.h>
#elif __has_include(<LibWeb/XHR/HTMLSourceElement.h>)
#    include <LibWeb/XHR/HTMLSourceElement.h>
#elif __has_include(<LibWeb/URL/HTMLSourceElement.h>)
#    include <LibWeb/URL/HTMLSourceElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLSourceElement.h>

#include <LibWeb/HTML/HTMLSourceElement.h>

#if __has_include(<LibWeb/Bindings/HTMLSourceElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLSourceElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLSourceElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLSourceElementWrapperFactory.h>
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

HTMLSourceElementConstructor::HTMLSourceElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLSourceElementConstructor::~HTMLSourceElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLSourceElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLSourceElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLSourceElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLSourceElement");

}

void HTMLSourceElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLSourceElementPrototype>("HTMLSourceElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

