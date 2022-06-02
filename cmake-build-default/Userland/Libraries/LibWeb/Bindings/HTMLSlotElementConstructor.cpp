
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLSlotElementConstructor.h>
#include <LibWeb/Bindings/HTMLSlotElementPrototype.h>
#include <LibWeb/Bindings/HTMLSlotElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLSlotElement.h>)
#    include <LibWeb/Crypto/HTMLSlotElement.h>
#elif __has_include(<LibWeb/CSS/HTMLSlotElement.h>)
#    include <LibWeb/CSS/HTMLSlotElement.h>
#elif __has_include(<LibWeb/DOM/HTMLSlotElement.h>)
#    include <LibWeb/DOM/HTMLSlotElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLSlotElement.h>)
#    include <LibWeb/Encoding/HTMLSlotElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLSlotElement.h>)
#    include <LibWeb/Geometry/HTMLSlotElement.h>
#elif __has_include(<LibWeb/HTML/HTMLSlotElement.h>)
#    include <LibWeb/HTML/HTMLSlotElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLSlotElement.h>)
#    include <LibWeb/UIEvents/HTMLSlotElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLSlotElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLSlotElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLSlotElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLSlotElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLSlotElement.h>)
#    include <LibWeb/NavigationTiming/HTMLSlotElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLSlotElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLSlotElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLSlotElement.h>)
#    include <LibWeb/ResizeObserver/HTMLSlotElement.h>
#elif __has_include(<LibWeb/SVG/HTMLSlotElement.h>)
#    include <LibWeb/SVG/HTMLSlotElement.h>
#elif __has_include(<LibWeb/Selection/HTMLSlotElement.h>)
#    include <LibWeb/Selection/HTMLSlotElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLSlotElement.h>)
#    include <LibWeb/WebSockets/HTMLSlotElement.h>
#elif __has_include(<LibWeb/XHR/HTMLSlotElement.h>)
#    include <LibWeb/XHR/HTMLSlotElement.h>
#elif __has_include(<LibWeb/URL/HTMLSlotElement.h>)
#    include <LibWeb/URL/HTMLSlotElement.h>
#endif


#include <LibWeb/HTML/HTMLSlotElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLSlotElement.h>

#if __has_include(<LibWeb/Bindings/HTMLSlotElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLSlotElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLSlotElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLSlotElementWrapperFactory.h>
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

HTMLSlotElementConstructor::HTMLSlotElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLSlotElementConstructor::~HTMLSlotElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLSlotElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLSlotElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLSlotElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLSlotElement");

}

void HTMLSlotElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLSlotElementPrototype>("HTMLSlotElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

