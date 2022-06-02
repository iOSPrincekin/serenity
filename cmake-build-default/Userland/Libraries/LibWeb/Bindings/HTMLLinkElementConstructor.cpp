
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLLinkElementConstructor.h>
#include <LibWeb/Bindings/HTMLLinkElementPrototype.h>
#include <LibWeb/Bindings/HTMLLinkElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLLinkElement.h>)
#    include <LibWeb/Crypto/HTMLLinkElement.h>
#elif __has_include(<LibWeb/CSS/HTMLLinkElement.h>)
#    include <LibWeb/CSS/HTMLLinkElement.h>
#elif __has_include(<LibWeb/DOM/HTMLLinkElement.h>)
#    include <LibWeb/DOM/HTMLLinkElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLLinkElement.h>)
#    include <LibWeb/Encoding/HTMLLinkElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLLinkElement.h>)
#    include <LibWeb/Geometry/HTMLLinkElement.h>
#elif __has_include(<LibWeb/HTML/HTMLLinkElement.h>)
#    include <LibWeb/HTML/HTMLLinkElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLLinkElement.h>)
#    include <LibWeb/UIEvents/HTMLLinkElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLLinkElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLLinkElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLLinkElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLLinkElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLLinkElement.h>)
#    include <LibWeb/NavigationTiming/HTMLLinkElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLLinkElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLLinkElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLLinkElement.h>)
#    include <LibWeb/ResizeObserver/HTMLLinkElement.h>
#elif __has_include(<LibWeb/SVG/HTMLLinkElement.h>)
#    include <LibWeb/SVG/HTMLLinkElement.h>
#elif __has_include(<LibWeb/Selection/HTMLLinkElement.h>)
#    include <LibWeb/Selection/HTMLLinkElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLLinkElement.h>)
#    include <LibWeb/WebSockets/HTMLLinkElement.h>
#elif __has_include(<LibWeb/XHR/HTMLLinkElement.h>)
#    include <LibWeb/XHR/HTMLLinkElement.h>
#elif __has_include(<LibWeb/URL/HTMLLinkElement.h>)
#    include <LibWeb/URL/HTMLLinkElement.h>
#endif


#include <LibWeb/HTML/HTMLLinkElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLLinkElement.h>

#if __has_include(<LibWeb/Bindings/HTMLLinkElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLLinkElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLLinkElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLLinkElementWrapperFactory.h>
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

HTMLLinkElementConstructor::HTMLLinkElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLLinkElementConstructor::~HTMLLinkElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLLinkElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLLinkElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLLinkElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLLinkElement");

}

void HTMLLinkElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLLinkElementPrototype>("HTMLLinkElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

