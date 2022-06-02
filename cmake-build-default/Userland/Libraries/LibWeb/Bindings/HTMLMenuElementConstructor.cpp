
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLMenuElementConstructor.h>
#include <LibWeb/Bindings/HTMLMenuElementPrototype.h>
#include <LibWeb/Bindings/HTMLMenuElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLMenuElement.h>)
#    include <LibWeb/Crypto/HTMLMenuElement.h>
#elif __has_include(<LibWeb/CSS/HTMLMenuElement.h>)
#    include <LibWeb/CSS/HTMLMenuElement.h>
#elif __has_include(<LibWeb/DOM/HTMLMenuElement.h>)
#    include <LibWeb/DOM/HTMLMenuElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLMenuElement.h>)
#    include <LibWeb/Encoding/HTMLMenuElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLMenuElement.h>)
#    include <LibWeb/Geometry/HTMLMenuElement.h>
#elif __has_include(<LibWeb/HTML/HTMLMenuElement.h>)
#    include <LibWeb/HTML/HTMLMenuElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLMenuElement.h>)
#    include <LibWeb/UIEvents/HTMLMenuElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLMenuElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLMenuElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLMenuElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLMenuElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLMenuElement.h>)
#    include <LibWeb/NavigationTiming/HTMLMenuElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLMenuElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLMenuElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLMenuElement.h>)
#    include <LibWeb/ResizeObserver/HTMLMenuElement.h>
#elif __has_include(<LibWeb/SVG/HTMLMenuElement.h>)
#    include <LibWeb/SVG/HTMLMenuElement.h>
#elif __has_include(<LibWeb/Selection/HTMLMenuElement.h>)
#    include <LibWeb/Selection/HTMLMenuElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLMenuElement.h>)
#    include <LibWeb/WebSockets/HTMLMenuElement.h>
#elif __has_include(<LibWeb/XHR/HTMLMenuElement.h>)
#    include <LibWeb/XHR/HTMLMenuElement.h>
#elif __has_include(<LibWeb/URL/HTMLMenuElement.h>)
#    include <LibWeb/URL/HTMLMenuElement.h>
#endif


#include <LibWeb/HTML/HTMLMenuElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMenuElement.h>

#if __has_include(<LibWeb/Bindings/HTMLMenuElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMenuElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMenuElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMenuElementWrapperFactory.h>
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

HTMLMenuElementConstructor::HTMLMenuElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLMenuElementConstructor::~HTMLMenuElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLMenuElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLMenuElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLMenuElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLMenuElement");

}

void HTMLMenuElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLMenuElementPrototype>("HTMLMenuElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

