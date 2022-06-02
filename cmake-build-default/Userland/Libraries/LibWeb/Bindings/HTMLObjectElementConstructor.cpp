
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLObjectElementConstructor.h>
#include <LibWeb/Bindings/HTMLObjectElementPrototype.h>
#include <LibWeb/Bindings/HTMLObjectElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLObjectElement.h>)
#    include <LibWeb/Crypto/HTMLObjectElement.h>
#elif __has_include(<LibWeb/CSS/HTMLObjectElement.h>)
#    include <LibWeb/CSS/HTMLObjectElement.h>
#elif __has_include(<LibWeb/DOM/HTMLObjectElement.h>)
#    include <LibWeb/DOM/HTMLObjectElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLObjectElement.h>)
#    include <LibWeb/Encoding/HTMLObjectElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLObjectElement.h>)
#    include <LibWeb/Geometry/HTMLObjectElement.h>
#elif __has_include(<LibWeb/HTML/HTMLObjectElement.h>)
#    include <LibWeb/HTML/HTMLObjectElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLObjectElement.h>)
#    include <LibWeb/UIEvents/HTMLObjectElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLObjectElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLObjectElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLObjectElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLObjectElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLObjectElement.h>)
#    include <LibWeb/NavigationTiming/HTMLObjectElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLObjectElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLObjectElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLObjectElement.h>)
#    include <LibWeb/ResizeObserver/HTMLObjectElement.h>
#elif __has_include(<LibWeb/SVG/HTMLObjectElement.h>)
#    include <LibWeb/SVG/HTMLObjectElement.h>
#elif __has_include(<LibWeb/Selection/HTMLObjectElement.h>)
#    include <LibWeb/Selection/HTMLObjectElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLObjectElement.h>)
#    include <LibWeb/WebSockets/HTMLObjectElement.h>
#elif __has_include(<LibWeb/XHR/HTMLObjectElement.h>)
#    include <LibWeb/XHR/HTMLObjectElement.h>
#elif __has_include(<LibWeb/URL/HTMLObjectElement.h>)
#    include <LibWeb/URL/HTMLObjectElement.h>
#endif


#include <LibWeb/HTML/HTMLObjectElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLObjectElement.h>

#if __has_include(<LibWeb/Bindings/HTMLObjectElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLObjectElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLObjectElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLObjectElementWrapperFactory.h>
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

HTMLObjectElementConstructor::HTMLObjectElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLObjectElementConstructor::~HTMLObjectElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLObjectElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLObjectElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLObjectElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLObjectElement");

}

void HTMLObjectElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLObjectElementPrototype>("HTMLObjectElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

