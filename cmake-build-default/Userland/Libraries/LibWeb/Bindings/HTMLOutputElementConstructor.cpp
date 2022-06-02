
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLOutputElementConstructor.h>
#include <LibWeb/Bindings/HTMLOutputElementPrototype.h>
#include <LibWeb/Bindings/HTMLOutputElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLOutputElement.h>)
#    include <LibWeb/Crypto/HTMLOutputElement.h>
#elif __has_include(<LibWeb/CSS/HTMLOutputElement.h>)
#    include <LibWeb/CSS/HTMLOutputElement.h>
#elif __has_include(<LibWeb/DOM/HTMLOutputElement.h>)
#    include <LibWeb/DOM/HTMLOutputElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLOutputElement.h>)
#    include <LibWeb/Encoding/HTMLOutputElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLOutputElement.h>)
#    include <LibWeb/Geometry/HTMLOutputElement.h>
#elif __has_include(<LibWeb/HTML/HTMLOutputElement.h>)
#    include <LibWeb/HTML/HTMLOutputElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLOutputElement.h>)
#    include <LibWeb/UIEvents/HTMLOutputElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLOutputElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLOutputElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLOutputElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLOutputElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLOutputElement.h>)
#    include <LibWeb/NavigationTiming/HTMLOutputElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLOutputElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLOutputElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLOutputElement.h>)
#    include <LibWeb/ResizeObserver/HTMLOutputElement.h>
#elif __has_include(<LibWeb/SVG/HTMLOutputElement.h>)
#    include <LibWeb/SVG/HTMLOutputElement.h>
#elif __has_include(<LibWeb/Selection/HTMLOutputElement.h>)
#    include <LibWeb/Selection/HTMLOutputElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLOutputElement.h>)
#    include <LibWeb/WebSockets/HTMLOutputElement.h>
#elif __has_include(<LibWeb/XHR/HTMLOutputElement.h>)
#    include <LibWeb/XHR/HTMLOutputElement.h>
#elif __has_include(<LibWeb/URL/HTMLOutputElement.h>)
#    include <LibWeb/URL/HTMLOutputElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLOutputElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLOutputElement.h>

#if __has_include(<LibWeb/Bindings/HTMLOutputElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLOutputElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLOutputElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLOutputElementWrapperFactory.h>
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

HTMLOutputElementConstructor::HTMLOutputElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLOutputElementConstructor::~HTMLOutputElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLOutputElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLOutputElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLOutputElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLOutputElement");

}

void HTMLOutputElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLOutputElementPrototype>("HTMLOutputElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

