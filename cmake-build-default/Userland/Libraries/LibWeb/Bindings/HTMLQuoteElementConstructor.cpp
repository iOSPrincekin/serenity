
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLQuoteElementConstructor.h>
#include <LibWeb/Bindings/HTMLQuoteElementPrototype.h>
#include <LibWeb/Bindings/HTMLQuoteElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLQuoteElement.h>)
#    include <LibWeb/Crypto/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/CSS/HTMLQuoteElement.h>)
#    include <LibWeb/CSS/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/DOM/HTMLQuoteElement.h>)
#    include <LibWeb/DOM/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLQuoteElement.h>)
#    include <LibWeb/Encoding/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLQuoteElement.h>)
#    include <LibWeb/Geometry/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/HTML/HTMLQuoteElement.h>)
#    include <LibWeb/HTML/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLQuoteElement.h>)
#    include <LibWeb/UIEvents/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLQuoteElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLQuoteElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLQuoteElement.h>)
#    include <LibWeb/NavigationTiming/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLQuoteElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLQuoteElement.h>)
#    include <LibWeb/ResizeObserver/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/SVG/HTMLQuoteElement.h>)
#    include <LibWeb/SVG/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/Selection/HTMLQuoteElement.h>)
#    include <LibWeb/Selection/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLQuoteElement.h>)
#    include <LibWeb/WebSockets/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/XHR/HTMLQuoteElement.h>)
#    include <LibWeb/XHR/HTMLQuoteElement.h>
#elif __has_include(<LibWeb/URL/HTMLQuoteElement.h>)
#    include <LibWeb/URL/HTMLQuoteElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLQuoteElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLQuoteElement.h>

#if __has_include(<LibWeb/Bindings/HTMLQuoteElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLQuoteElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLQuoteElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLQuoteElementWrapperFactory.h>
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

HTMLQuoteElementConstructor::HTMLQuoteElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLQuoteElementConstructor::~HTMLQuoteElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLQuoteElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLQuoteElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLQuoteElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLQuoteElement");

}

void HTMLQuoteElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLQuoteElementPrototype>("HTMLQuoteElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

