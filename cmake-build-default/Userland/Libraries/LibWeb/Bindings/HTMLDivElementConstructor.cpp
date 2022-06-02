
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLDivElementConstructor.h>
#include <LibWeb/Bindings/HTMLDivElementPrototype.h>
#include <LibWeb/Bindings/HTMLDivElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLDivElement.h>)
#    include <LibWeb/Crypto/HTMLDivElement.h>
#elif __has_include(<LibWeb/CSS/HTMLDivElement.h>)
#    include <LibWeb/CSS/HTMLDivElement.h>
#elif __has_include(<LibWeb/DOM/HTMLDivElement.h>)
#    include <LibWeb/DOM/HTMLDivElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLDivElement.h>)
#    include <LibWeb/Encoding/HTMLDivElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLDivElement.h>)
#    include <LibWeb/Geometry/HTMLDivElement.h>
#elif __has_include(<LibWeb/HTML/HTMLDivElement.h>)
#    include <LibWeb/HTML/HTMLDivElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLDivElement.h>)
#    include <LibWeb/UIEvents/HTMLDivElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLDivElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLDivElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLDivElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLDivElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLDivElement.h>)
#    include <LibWeb/NavigationTiming/HTMLDivElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLDivElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLDivElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLDivElement.h>)
#    include <LibWeb/ResizeObserver/HTMLDivElement.h>
#elif __has_include(<LibWeb/SVG/HTMLDivElement.h>)
#    include <LibWeb/SVG/HTMLDivElement.h>
#elif __has_include(<LibWeb/Selection/HTMLDivElement.h>)
#    include <LibWeb/Selection/HTMLDivElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLDivElement.h>)
#    include <LibWeb/WebSockets/HTMLDivElement.h>
#elif __has_include(<LibWeb/XHR/HTMLDivElement.h>)
#    include <LibWeb/XHR/HTMLDivElement.h>
#elif __has_include(<LibWeb/URL/HTMLDivElement.h>)
#    include <LibWeb/URL/HTMLDivElement.h>
#endif


#include <LibWeb/HTML/HTMLDivElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLDivElement.h>

#if __has_include(<LibWeb/Bindings/HTMLDivElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLDivElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLDivElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLDivElementWrapperFactory.h>
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

HTMLDivElementConstructor::HTMLDivElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLDivElementConstructor::~HTMLDivElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLDivElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLDivElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLDivElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLDivElement");

}

void HTMLDivElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLDivElementPrototype>("HTMLDivElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

