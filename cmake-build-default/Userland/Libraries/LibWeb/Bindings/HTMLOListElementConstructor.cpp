
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLOListElementConstructor.h>
#include <LibWeb/Bindings/HTMLOListElementPrototype.h>
#include <LibWeb/Bindings/HTMLOListElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLOListElement.h>)
#    include <LibWeb/Crypto/HTMLOListElement.h>
#elif __has_include(<LibWeb/CSS/HTMLOListElement.h>)
#    include <LibWeb/CSS/HTMLOListElement.h>
#elif __has_include(<LibWeb/DOM/HTMLOListElement.h>)
#    include <LibWeb/DOM/HTMLOListElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLOListElement.h>)
#    include <LibWeb/Encoding/HTMLOListElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLOListElement.h>)
#    include <LibWeb/Geometry/HTMLOListElement.h>
#elif __has_include(<LibWeb/HTML/HTMLOListElement.h>)
#    include <LibWeb/HTML/HTMLOListElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLOListElement.h>)
#    include <LibWeb/UIEvents/HTMLOListElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLOListElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLOListElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLOListElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLOListElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLOListElement.h>)
#    include <LibWeb/NavigationTiming/HTMLOListElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLOListElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLOListElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLOListElement.h>)
#    include <LibWeb/ResizeObserver/HTMLOListElement.h>
#elif __has_include(<LibWeb/SVG/HTMLOListElement.h>)
#    include <LibWeb/SVG/HTMLOListElement.h>
#elif __has_include(<LibWeb/Selection/HTMLOListElement.h>)
#    include <LibWeb/Selection/HTMLOListElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLOListElement.h>)
#    include <LibWeb/WebSockets/HTMLOListElement.h>
#elif __has_include(<LibWeb/XHR/HTMLOListElement.h>)
#    include <LibWeb/XHR/HTMLOListElement.h>
#elif __has_include(<LibWeb/URL/HTMLOListElement.h>)
#    include <LibWeb/URL/HTMLOListElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLOListElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLOListElement.h>

#if __has_include(<LibWeb/Bindings/HTMLOListElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLOListElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLOListElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLOListElementWrapperFactory.h>
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

HTMLOListElementConstructor::HTMLOListElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLOListElementConstructor::~HTMLOListElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLOListElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLOListElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLOListElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLOListElement");

}

void HTMLOListElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLOListElementPrototype>("HTMLOListElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

