
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLOptionElementConstructor.h>
#include <LibWeb/Bindings/HTMLOptionElementPrototype.h>
#include <LibWeb/Bindings/HTMLOptionElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLOptionElement.h>)
#    include <LibWeb/Crypto/HTMLOptionElement.h>
#elif __has_include(<LibWeb/CSS/HTMLOptionElement.h>)
#    include <LibWeb/CSS/HTMLOptionElement.h>
#elif __has_include(<LibWeb/DOM/HTMLOptionElement.h>)
#    include <LibWeb/DOM/HTMLOptionElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLOptionElement.h>)
#    include <LibWeb/Encoding/HTMLOptionElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLOptionElement.h>)
#    include <LibWeb/Geometry/HTMLOptionElement.h>
#elif __has_include(<LibWeb/HTML/HTMLOptionElement.h>)
#    include <LibWeb/HTML/HTMLOptionElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLOptionElement.h>)
#    include <LibWeb/UIEvents/HTMLOptionElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLOptionElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLOptionElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLOptionElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLOptionElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLOptionElement.h>)
#    include <LibWeb/NavigationTiming/HTMLOptionElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLOptionElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLOptionElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLOptionElement.h>)
#    include <LibWeb/ResizeObserver/HTMLOptionElement.h>
#elif __has_include(<LibWeb/SVG/HTMLOptionElement.h>)
#    include <LibWeb/SVG/HTMLOptionElement.h>
#elif __has_include(<LibWeb/Selection/HTMLOptionElement.h>)
#    include <LibWeb/Selection/HTMLOptionElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLOptionElement.h>)
#    include <LibWeb/WebSockets/HTMLOptionElement.h>
#elif __has_include(<LibWeb/XHR/HTMLOptionElement.h>)
#    include <LibWeb/XHR/HTMLOptionElement.h>
#elif __has_include(<LibWeb/URL/HTMLOptionElement.h>)
#    include <LibWeb/URL/HTMLOptionElement.h>
#endif


#include <LibWeb/HTML/HTMLOptionElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLOptionElement.h>

#if __has_include(<LibWeb/Bindings/HTMLOptionElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLOptionElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLOptionElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLOptionElementWrapperFactory.h>
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

HTMLOptionElementConstructor::HTMLOptionElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLOptionElementConstructor::~HTMLOptionElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLOptionElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLOptionElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLOptionElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLOptionElement");

}

void HTMLOptionElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLOptionElementPrototype>("HTMLOptionElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

