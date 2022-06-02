
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLDListElementConstructor.h>
#include <LibWeb/Bindings/HTMLDListElementPrototype.h>
#include <LibWeb/Bindings/HTMLDListElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLDListElement.h>)
#    include <LibWeb/Crypto/HTMLDListElement.h>
#elif __has_include(<LibWeb/CSS/HTMLDListElement.h>)
#    include <LibWeb/CSS/HTMLDListElement.h>
#elif __has_include(<LibWeb/DOM/HTMLDListElement.h>)
#    include <LibWeb/DOM/HTMLDListElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLDListElement.h>)
#    include <LibWeb/Encoding/HTMLDListElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLDListElement.h>)
#    include <LibWeb/Geometry/HTMLDListElement.h>
#elif __has_include(<LibWeb/HTML/HTMLDListElement.h>)
#    include <LibWeb/HTML/HTMLDListElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLDListElement.h>)
#    include <LibWeb/UIEvents/HTMLDListElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLDListElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLDListElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLDListElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLDListElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLDListElement.h>)
#    include <LibWeb/NavigationTiming/HTMLDListElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLDListElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLDListElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLDListElement.h>)
#    include <LibWeb/ResizeObserver/HTMLDListElement.h>
#elif __has_include(<LibWeb/SVG/HTMLDListElement.h>)
#    include <LibWeb/SVG/HTMLDListElement.h>
#elif __has_include(<LibWeb/Selection/HTMLDListElement.h>)
#    include <LibWeb/Selection/HTMLDListElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLDListElement.h>)
#    include <LibWeb/WebSockets/HTMLDListElement.h>
#elif __has_include(<LibWeb/XHR/HTMLDListElement.h>)
#    include <LibWeb/XHR/HTMLDListElement.h>
#elif __has_include(<LibWeb/URL/HTMLDListElement.h>)
#    include <LibWeb/URL/HTMLDListElement.h>
#endif


#include <LibWeb/HTML/HTMLDListElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLDListElement.h>

#if __has_include(<LibWeb/Bindings/HTMLDListElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLDListElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLDListElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLDListElementWrapperFactory.h>
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

HTMLDListElementConstructor::HTMLDListElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLDListElementConstructor::~HTMLDListElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLDListElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLDListElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLDListElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLDListElement");

}

void HTMLDListElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLDListElementPrototype>("HTMLDListElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

