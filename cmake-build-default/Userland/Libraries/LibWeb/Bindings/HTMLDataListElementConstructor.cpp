
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLDataListElementConstructor.h>
#include <LibWeb/Bindings/HTMLDataListElementPrototype.h>
#include <LibWeb/Bindings/HTMLDataListElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLDataListElement.h>)
#    include <LibWeb/Crypto/HTMLDataListElement.h>
#elif __has_include(<LibWeb/CSS/HTMLDataListElement.h>)
#    include <LibWeb/CSS/HTMLDataListElement.h>
#elif __has_include(<LibWeb/DOM/HTMLDataListElement.h>)
#    include <LibWeb/DOM/HTMLDataListElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLDataListElement.h>)
#    include <LibWeb/Encoding/HTMLDataListElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLDataListElement.h>)
#    include <LibWeb/Geometry/HTMLDataListElement.h>
#elif __has_include(<LibWeb/HTML/HTMLDataListElement.h>)
#    include <LibWeb/HTML/HTMLDataListElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLDataListElement.h>)
#    include <LibWeb/UIEvents/HTMLDataListElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLDataListElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLDataListElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLDataListElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLDataListElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLDataListElement.h>)
#    include <LibWeb/NavigationTiming/HTMLDataListElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLDataListElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLDataListElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLDataListElement.h>)
#    include <LibWeb/ResizeObserver/HTMLDataListElement.h>
#elif __has_include(<LibWeb/SVG/HTMLDataListElement.h>)
#    include <LibWeb/SVG/HTMLDataListElement.h>
#elif __has_include(<LibWeb/Selection/HTMLDataListElement.h>)
#    include <LibWeb/Selection/HTMLDataListElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLDataListElement.h>)
#    include <LibWeb/WebSockets/HTMLDataListElement.h>
#elif __has_include(<LibWeb/XHR/HTMLDataListElement.h>)
#    include <LibWeb/XHR/HTMLDataListElement.h>
#elif __has_include(<LibWeb/URL/HTMLDataListElement.h>)
#    include <LibWeb/URL/HTMLDataListElement.h>
#endif


#include <LibWeb/HTML/HTMLDataListElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLDataListElement.h>

#if __has_include(<LibWeb/Bindings/HTMLDataListElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLDataListElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLDataListElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLDataListElementWrapperFactory.h>
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

HTMLDataListElementConstructor::HTMLDataListElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLDataListElementConstructor::~HTMLDataListElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLDataListElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLDataListElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLDataListElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLDataListElement");

}

void HTMLDataListElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLDataListElementPrototype>("HTMLDataListElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

