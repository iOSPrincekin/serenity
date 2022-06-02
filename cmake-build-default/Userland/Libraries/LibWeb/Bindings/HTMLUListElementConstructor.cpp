
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLUListElementConstructor.h>
#include <LibWeb/Bindings/HTMLUListElementPrototype.h>
#include <LibWeb/Bindings/HTMLUListElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLUListElement.h>)
#    include <LibWeb/Crypto/HTMLUListElement.h>
#elif __has_include(<LibWeb/CSS/HTMLUListElement.h>)
#    include <LibWeb/CSS/HTMLUListElement.h>
#elif __has_include(<LibWeb/DOM/HTMLUListElement.h>)
#    include <LibWeb/DOM/HTMLUListElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLUListElement.h>)
#    include <LibWeb/Encoding/HTMLUListElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLUListElement.h>)
#    include <LibWeb/Geometry/HTMLUListElement.h>
#elif __has_include(<LibWeb/HTML/HTMLUListElement.h>)
#    include <LibWeb/HTML/HTMLUListElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLUListElement.h>)
#    include <LibWeb/UIEvents/HTMLUListElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLUListElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLUListElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLUListElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLUListElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLUListElement.h>)
#    include <LibWeb/NavigationTiming/HTMLUListElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLUListElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLUListElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLUListElement.h>)
#    include <LibWeb/ResizeObserver/HTMLUListElement.h>
#elif __has_include(<LibWeb/SVG/HTMLUListElement.h>)
#    include <LibWeb/SVG/HTMLUListElement.h>
#elif __has_include(<LibWeb/Selection/HTMLUListElement.h>)
#    include <LibWeb/Selection/HTMLUListElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLUListElement.h>)
#    include <LibWeb/WebSockets/HTMLUListElement.h>
#elif __has_include(<LibWeb/XHR/HTMLUListElement.h>)
#    include <LibWeb/XHR/HTMLUListElement.h>
#elif __has_include(<LibWeb/URL/HTMLUListElement.h>)
#    include <LibWeb/URL/HTMLUListElement.h>
#endif


#include <LibWeb/HTML/HTMLUListElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLUListElement.h>

#if __has_include(<LibWeb/Bindings/HTMLUListElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLUListElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLUListElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLUListElementWrapperFactory.h>
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

HTMLUListElementConstructor::HTMLUListElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLUListElementConstructor::~HTMLUListElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLUListElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLUListElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLUListElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLUListElement");

}

void HTMLUListElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLUListElementPrototype>("HTMLUListElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

