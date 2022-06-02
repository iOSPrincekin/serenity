
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLElementConstructor.h>
#include <LibWeb/Bindings/HTMLElementPrototype.h>
#include <LibWeb/Bindings/HTMLElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLElement.h>)
#    include <LibWeb/Crypto/HTMLElement.h>
#elif __has_include(<LibWeb/CSS/HTMLElement.h>)
#    include <LibWeb/CSS/HTMLElement.h>
#elif __has_include(<LibWeb/DOM/HTMLElement.h>)
#    include <LibWeb/DOM/HTMLElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLElement.h>)
#    include <LibWeb/Encoding/HTMLElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLElement.h>)
#    include <LibWeb/Geometry/HTMLElement.h>
#elif __has_include(<LibWeb/HTML/HTMLElement.h>)
#    include <LibWeb/HTML/HTMLElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLElement.h>)
#    include <LibWeb/UIEvents/HTMLElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLElement.h>)
#    include <LibWeb/NavigationTiming/HTMLElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLElement.h>)
#    include <LibWeb/ResizeObserver/HTMLElement.h>
#elif __has_include(<LibWeb/SVG/HTMLElement.h>)
#    include <LibWeb/SVG/HTMLElement.h>
#elif __has_include(<LibWeb/Selection/HTMLElement.h>)
#    include <LibWeb/Selection/HTMLElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLElement.h>)
#    include <LibWeb/WebSockets/HTMLElement.h>
#elif __has_include(<LibWeb/XHR/HTMLElement.h>)
#    include <LibWeb/XHR/HTMLElement.h>
#elif __has_include(<LibWeb/URL/HTMLElement.h>)
#    include <LibWeb/URL/HTMLElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

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

HTMLElementConstructor::HTMLElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLElementConstructor::~HTMLElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLElement");

}

void HTMLElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLElementPrototype>("HTMLElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

