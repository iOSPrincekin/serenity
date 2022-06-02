
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLSpanElementConstructor.h>
#include <LibWeb/Bindings/HTMLSpanElementPrototype.h>
#include <LibWeb/Bindings/HTMLSpanElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLSpanElement.h>)
#    include <LibWeb/Crypto/HTMLSpanElement.h>
#elif __has_include(<LibWeb/CSS/HTMLSpanElement.h>)
#    include <LibWeb/CSS/HTMLSpanElement.h>
#elif __has_include(<LibWeb/DOM/HTMLSpanElement.h>)
#    include <LibWeb/DOM/HTMLSpanElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLSpanElement.h>)
#    include <LibWeb/Encoding/HTMLSpanElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLSpanElement.h>)
#    include <LibWeb/Geometry/HTMLSpanElement.h>
#elif __has_include(<LibWeb/HTML/HTMLSpanElement.h>)
#    include <LibWeb/HTML/HTMLSpanElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLSpanElement.h>)
#    include <LibWeb/UIEvents/HTMLSpanElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLSpanElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLSpanElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLSpanElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLSpanElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLSpanElement.h>)
#    include <LibWeb/NavigationTiming/HTMLSpanElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLSpanElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLSpanElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLSpanElement.h>)
#    include <LibWeb/ResizeObserver/HTMLSpanElement.h>
#elif __has_include(<LibWeb/SVG/HTMLSpanElement.h>)
#    include <LibWeb/SVG/HTMLSpanElement.h>
#elif __has_include(<LibWeb/Selection/HTMLSpanElement.h>)
#    include <LibWeb/Selection/HTMLSpanElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLSpanElement.h>)
#    include <LibWeb/WebSockets/HTMLSpanElement.h>
#elif __has_include(<LibWeb/XHR/HTMLSpanElement.h>)
#    include <LibWeb/XHR/HTMLSpanElement.h>
#elif __has_include(<LibWeb/URL/HTMLSpanElement.h>)
#    include <LibWeb/URL/HTMLSpanElement.h>
#endif


#include <LibWeb/HTML/HTMLSpanElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLSpanElement.h>

#if __has_include(<LibWeb/Bindings/HTMLSpanElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLSpanElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLSpanElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLSpanElementWrapperFactory.h>
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

HTMLSpanElementConstructor::HTMLSpanElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLSpanElementConstructor::~HTMLSpanElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLSpanElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLSpanElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLSpanElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLSpanElement");

}

void HTMLSpanElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLSpanElementPrototype>("HTMLSpanElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

