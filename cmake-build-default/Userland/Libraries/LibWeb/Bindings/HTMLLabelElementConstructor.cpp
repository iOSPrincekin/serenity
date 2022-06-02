
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLLabelElementConstructor.h>
#include <LibWeb/Bindings/HTMLLabelElementPrototype.h>
#include <LibWeb/Bindings/HTMLLabelElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLLabelElement.h>)
#    include <LibWeb/Crypto/HTMLLabelElement.h>
#elif __has_include(<LibWeb/CSS/HTMLLabelElement.h>)
#    include <LibWeb/CSS/HTMLLabelElement.h>
#elif __has_include(<LibWeb/DOM/HTMLLabelElement.h>)
#    include <LibWeb/DOM/HTMLLabelElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLLabelElement.h>)
#    include <LibWeb/Encoding/HTMLLabelElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLLabelElement.h>)
#    include <LibWeb/Geometry/HTMLLabelElement.h>
#elif __has_include(<LibWeb/HTML/HTMLLabelElement.h>)
#    include <LibWeb/HTML/HTMLLabelElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLLabelElement.h>)
#    include <LibWeb/UIEvents/HTMLLabelElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLLabelElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLLabelElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLLabelElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLLabelElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLLabelElement.h>)
#    include <LibWeb/NavigationTiming/HTMLLabelElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLLabelElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLLabelElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLLabelElement.h>)
#    include <LibWeb/ResizeObserver/HTMLLabelElement.h>
#elif __has_include(<LibWeb/SVG/HTMLLabelElement.h>)
#    include <LibWeb/SVG/HTMLLabelElement.h>
#elif __has_include(<LibWeb/Selection/HTMLLabelElement.h>)
#    include <LibWeb/Selection/HTMLLabelElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLLabelElement.h>)
#    include <LibWeb/WebSockets/HTMLLabelElement.h>
#elif __has_include(<LibWeb/XHR/HTMLLabelElement.h>)
#    include <LibWeb/XHR/HTMLLabelElement.h>
#elif __has_include(<LibWeb/URL/HTMLLabelElement.h>)
#    include <LibWeb/URL/HTMLLabelElement.h>
#endif


#include <LibWeb/HTML/HTMLLabelElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLLabelElement.h>

#if __has_include(<LibWeb/Bindings/HTMLLabelElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLLabelElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLLabelElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLLabelElementWrapperFactory.h>
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

HTMLLabelElementConstructor::HTMLLabelElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLLabelElementConstructor::~HTMLLabelElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLLabelElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLLabelElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLLabelElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLLabelElement");

}

void HTMLLabelElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLLabelElementPrototype>("HTMLLabelElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

