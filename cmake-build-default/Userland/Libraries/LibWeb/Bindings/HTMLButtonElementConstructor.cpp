
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLButtonElementConstructor.h>
#include <LibWeb/Bindings/HTMLButtonElementPrototype.h>
#include <LibWeb/Bindings/HTMLButtonElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLButtonElement.h>)
#    include <LibWeb/Crypto/HTMLButtonElement.h>
#elif __has_include(<LibWeb/CSS/HTMLButtonElement.h>)
#    include <LibWeb/CSS/HTMLButtonElement.h>
#elif __has_include(<LibWeb/DOM/HTMLButtonElement.h>)
#    include <LibWeb/DOM/HTMLButtonElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLButtonElement.h>)
#    include <LibWeb/Encoding/HTMLButtonElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLButtonElement.h>)
#    include <LibWeb/Geometry/HTMLButtonElement.h>
#elif __has_include(<LibWeb/HTML/HTMLButtonElement.h>)
#    include <LibWeb/HTML/HTMLButtonElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLButtonElement.h>)
#    include <LibWeb/UIEvents/HTMLButtonElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLButtonElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLButtonElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLButtonElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLButtonElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLButtonElement.h>)
#    include <LibWeb/NavigationTiming/HTMLButtonElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLButtonElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLButtonElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLButtonElement.h>)
#    include <LibWeb/ResizeObserver/HTMLButtonElement.h>
#elif __has_include(<LibWeb/SVG/HTMLButtonElement.h>)
#    include <LibWeb/SVG/HTMLButtonElement.h>
#elif __has_include(<LibWeb/Selection/HTMLButtonElement.h>)
#    include <LibWeb/Selection/HTMLButtonElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLButtonElement.h>)
#    include <LibWeb/WebSockets/HTMLButtonElement.h>
#elif __has_include(<LibWeb/XHR/HTMLButtonElement.h>)
#    include <LibWeb/XHR/HTMLButtonElement.h>
#elif __has_include(<LibWeb/URL/HTMLButtonElement.h>)
#    include <LibWeb/URL/HTMLButtonElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLButtonElement.h>

#include <LibWeb/HTML/HTMLButtonElement.h>

#if __has_include(<LibWeb/Bindings/HTMLButtonElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLButtonElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLButtonElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLButtonElementWrapperFactory.h>
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

HTMLButtonElementConstructor::HTMLButtonElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLButtonElementConstructor::~HTMLButtonElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLButtonElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLButtonElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLButtonElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLButtonElement");

}

void HTMLButtonElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLButtonElementPrototype>("HTMLButtonElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

