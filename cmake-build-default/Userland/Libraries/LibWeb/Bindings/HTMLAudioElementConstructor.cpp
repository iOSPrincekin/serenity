
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLAudioElementConstructor.h>
#include <LibWeb/Bindings/HTMLAudioElementPrototype.h>
#include <LibWeb/Bindings/HTMLAudioElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLAudioElement.h>)
#    include <LibWeb/Crypto/HTMLAudioElement.h>
#elif __has_include(<LibWeb/CSS/HTMLAudioElement.h>)
#    include <LibWeb/CSS/HTMLAudioElement.h>
#elif __has_include(<LibWeb/DOM/HTMLAudioElement.h>)
#    include <LibWeb/DOM/HTMLAudioElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLAudioElement.h>)
#    include <LibWeb/Encoding/HTMLAudioElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLAudioElement.h>)
#    include <LibWeb/Geometry/HTMLAudioElement.h>
#elif __has_include(<LibWeb/HTML/HTMLAudioElement.h>)
#    include <LibWeb/HTML/HTMLAudioElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLAudioElement.h>)
#    include <LibWeb/UIEvents/HTMLAudioElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLAudioElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLAudioElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLAudioElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLAudioElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLAudioElement.h>)
#    include <LibWeb/NavigationTiming/HTMLAudioElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLAudioElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLAudioElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLAudioElement.h>)
#    include <LibWeb/ResizeObserver/HTMLAudioElement.h>
#elif __has_include(<LibWeb/SVG/HTMLAudioElement.h>)
#    include <LibWeb/SVG/HTMLAudioElement.h>
#elif __has_include(<LibWeb/Selection/HTMLAudioElement.h>)
#    include <LibWeb/Selection/HTMLAudioElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLAudioElement.h>)
#    include <LibWeb/WebSockets/HTMLAudioElement.h>
#elif __has_include(<LibWeb/XHR/HTMLAudioElement.h>)
#    include <LibWeb/XHR/HTMLAudioElement.h>
#elif __has_include(<LibWeb/URL/HTMLAudioElement.h>)
#    include <LibWeb/URL/HTMLAudioElement.h>
#endif


#include <LibWeb/HTML/HTMLAudioElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLMediaElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLAudioElement.h>

#if __has_include(<LibWeb/Bindings/HTMLAudioElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLAudioElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLAudioElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLAudioElementWrapperFactory.h>
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

HTMLAudioElementConstructor::HTMLAudioElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLAudioElementConstructor::~HTMLAudioElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLAudioElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLAudioElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLAudioElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLAudioElement");

}

void HTMLAudioElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLAudioElementPrototype>("HTMLAudioElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

