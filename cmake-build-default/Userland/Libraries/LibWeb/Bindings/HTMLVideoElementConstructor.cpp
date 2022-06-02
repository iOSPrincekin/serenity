
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLVideoElementConstructor.h>
#include <LibWeb/Bindings/HTMLVideoElementPrototype.h>
#include <LibWeb/Bindings/HTMLVideoElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLVideoElement.h>)
#    include <LibWeb/Crypto/HTMLVideoElement.h>
#elif __has_include(<LibWeb/CSS/HTMLVideoElement.h>)
#    include <LibWeb/CSS/HTMLVideoElement.h>
#elif __has_include(<LibWeb/DOM/HTMLVideoElement.h>)
#    include <LibWeb/DOM/HTMLVideoElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLVideoElement.h>)
#    include <LibWeb/Encoding/HTMLVideoElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLVideoElement.h>)
#    include <LibWeb/Geometry/HTMLVideoElement.h>
#elif __has_include(<LibWeb/HTML/HTMLVideoElement.h>)
#    include <LibWeb/HTML/HTMLVideoElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLVideoElement.h>)
#    include <LibWeb/UIEvents/HTMLVideoElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLVideoElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLVideoElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLVideoElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLVideoElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLVideoElement.h>)
#    include <LibWeb/NavigationTiming/HTMLVideoElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLVideoElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLVideoElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLVideoElement.h>)
#    include <LibWeb/ResizeObserver/HTMLVideoElement.h>
#elif __has_include(<LibWeb/SVG/HTMLVideoElement.h>)
#    include <LibWeb/SVG/HTMLVideoElement.h>
#elif __has_include(<LibWeb/Selection/HTMLVideoElement.h>)
#    include <LibWeb/Selection/HTMLVideoElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLVideoElement.h>)
#    include <LibWeb/WebSockets/HTMLVideoElement.h>
#elif __has_include(<LibWeb/XHR/HTMLVideoElement.h>)
#    include <LibWeb/XHR/HTMLVideoElement.h>
#elif __has_include(<LibWeb/URL/HTMLVideoElement.h>)
#    include <LibWeb/URL/HTMLVideoElement.h>
#endif


#include <LibWeb/HTML/HTMLVideoElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLMediaElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLVideoElement.h>

#if __has_include(<LibWeb/Bindings/HTMLVideoElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLVideoElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLVideoElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLVideoElementWrapperFactory.h>
#endif

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

HTMLVideoElementConstructor::HTMLVideoElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLVideoElementConstructor::~HTMLVideoElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLVideoElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLVideoElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLVideoElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLVideoElement");

}

void HTMLVideoElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLVideoElementPrototype>("HTMLVideoElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

