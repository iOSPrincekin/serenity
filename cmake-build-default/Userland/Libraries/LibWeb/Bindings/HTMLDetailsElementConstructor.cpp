
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLDetailsElementConstructor.h>
#include <LibWeb/Bindings/HTMLDetailsElementPrototype.h>
#include <LibWeb/Bindings/HTMLDetailsElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLDetailsElement.h>)
#    include <LibWeb/Crypto/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/CSS/HTMLDetailsElement.h>)
#    include <LibWeb/CSS/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/DOM/HTMLDetailsElement.h>)
#    include <LibWeb/DOM/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLDetailsElement.h>)
#    include <LibWeb/Encoding/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLDetailsElement.h>)
#    include <LibWeb/Geometry/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/HTML/HTMLDetailsElement.h>)
#    include <LibWeb/HTML/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLDetailsElement.h>)
#    include <LibWeb/UIEvents/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLDetailsElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLDetailsElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLDetailsElement.h>)
#    include <LibWeb/NavigationTiming/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLDetailsElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLDetailsElement.h>)
#    include <LibWeb/ResizeObserver/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/SVG/HTMLDetailsElement.h>)
#    include <LibWeb/SVG/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/Selection/HTMLDetailsElement.h>)
#    include <LibWeb/Selection/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLDetailsElement.h>)
#    include <LibWeb/WebSockets/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/XHR/HTMLDetailsElement.h>)
#    include <LibWeb/XHR/HTMLDetailsElement.h>
#elif __has_include(<LibWeb/URL/HTMLDetailsElement.h>)
#    include <LibWeb/URL/HTMLDetailsElement.h>
#endif


#include <LibWeb/HTML/HTMLDetailsElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLDetailsElement.h>

#if __has_include(<LibWeb/Bindings/HTMLDetailsElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLDetailsElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLDetailsElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLDetailsElementWrapperFactory.h>
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

HTMLDetailsElementConstructor::HTMLDetailsElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLDetailsElementConstructor::~HTMLDetailsElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLDetailsElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLDetailsElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLDetailsElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLDetailsElement");

}

void HTMLDetailsElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLDetailsElementPrototype>("HTMLDetailsElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

