
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLMediaElementConstructor.h>
#include <LibWeb/Bindings/HTMLMediaElementPrototype.h>
#include <LibWeb/Bindings/HTMLMediaElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLMediaElement.h>)
#    include <LibWeb/Crypto/HTMLMediaElement.h>
#elif __has_include(<LibWeb/CSS/HTMLMediaElement.h>)
#    include <LibWeb/CSS/HTMLMediaElement.h>
#elif __has_include(<LibWeb/DOM/HTMLMediaElement.h>)
#    include <LibWeb/DOM/HTMLMediaElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLMediaElement.h>)
#    include <LibWeb/Encoding/HTMLMediaElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLMediaElement.h>)
#    include <LibWeb/Geometry/HTMLMediaElement.h>
#elif __has_include(<LibWeb/HTML/HTMLMediaElement.h>)
#    include <LibWeb/HTML/HTMLMediaElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLMediaElement.h>)
#    include <LibWeb/UIEvents/HTMLMediaElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLMediaElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLMediaElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLMediaElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLMediaElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLMediaElement.h>)
#    include <LibWeb/NavigationTiming/HTMLMediaElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLMediaElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLMediaElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLMediaElement.h>)
#    include <LibWeb/ResizeObserver/HTMLMediaElement.h>
#elif __has_include(<LibWeb/SVG/HTMLMediaElement.h>)
#    include <LibWeb/SVG/HTMLMediaElement.h>
#elif __has_include(<LibWeb/Selection/HTMLMediaElement.h>)
#    include <LibWeb/Selection/HTMLMediaElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLMediaElement.h>)
#    include <LibWeb/WebSockets/HTMLMediaElement.h>
#elif __has_include(<LibWeb/XHR/HTMLMediaElement.h>)
#    include <LibWeb/XHR/HTMLMediaElement.h>
#elif __has_include(<LibWeb/URL/HTMLMediaElement.h>)
#    include <LibWeb/URL/HTMLMediaElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLMediaElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMediaElement.h>

#if __has_include(<LibWeb/Bindings/HTMLMediaElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMediaElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMediaElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMediaElementWrapperFactory.h>
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

HTMLMediaElementConstructor::HTMLMediaElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLMediaElementConstructor::~HTMLMediaElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLMediaElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLMediaElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLMediaElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLMediaElement");

}

void HTMLMediaElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLMediaElementPrototype>("HTMLMediaElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

