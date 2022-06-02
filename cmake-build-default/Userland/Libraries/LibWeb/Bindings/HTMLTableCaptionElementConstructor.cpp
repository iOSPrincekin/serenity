
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLTableCaptionElementConstructor.h>
#include <LibWeb/Bindings/HTMLTableCaptionElementPrototype.h>
#include <LibWeb/Bindings/HTMLTableCaptionElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLTableCaptionElement.h>)
#    include <LibWeb/Crypto/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/CSS/HTMLTableCaptionElement.h>)
#    include <LibWeb/CSS/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/DOM/HTMLTableCaptionElement.h>)
#    include <LibWeb/DOM/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLTableCaptionElement.h>)
#    include <LibWeb/Encoding/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLTableCaptionElement.h>)
#    include <LibWeb/Geometry/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/HTML/HTMLTableCaptionElement.h>)
#    include <LibWeb/HTML/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLTableCaptionElement.h>)
#    include <LibWeb/UIEvents/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLTableCaptionElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLTableCaptionElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLTableCaptionElement.h>)
#    include <LibWeb/NavigationTiming/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLTableCaptionElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLTableCaptionElement.h>)
#    include <LibWeb/ResizeObserver/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/SVG/HTMLTableCaptionElement.h>)
#    include <LibWeb/SVG/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/Selection/HTMLTableCaptionElement.h>)
#    include <LibWeb/Selection/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLTableCaptionElement.h>)
#    include <LibWeb/WebSockets/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/XHR/HTMLTableCaptionElement.h>)
#    include <LibWeb/XHR/HTMLTableCaptionElement.h>
#elif __has_include(<LibWeb/URL/HTMLTableCaptionElement.h>)
#    include <LibWeb/URL/HTMLTableCaptionElement.h>
#endif


#include <LibWeb/HTML/HTMLTableCaptionElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLTableCaptionElement.h>

#if __has_include(<LibWeb/Bindings/HTMLTableCaptionElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLTableCaptionElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLTableCaptionElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLTableCaptionElementWrapperFactory.h>
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

HTMLTableCaptionElementConstructor::HTMLTableCaptionElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLTableCaptionElementConstructor::~HTMLTableCaptionElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLTableCaptionElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLTableCaptionElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLTableCaptionElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLTableCaptionElement");

}

void HTMLTableCaptionElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLTableCaptionElementPrototype>("HTMLTableCaptionElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

