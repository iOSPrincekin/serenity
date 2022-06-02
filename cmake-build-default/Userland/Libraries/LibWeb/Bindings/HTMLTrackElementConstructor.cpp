
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLTrackElementConstructor.h>
#include <LibWeb/Bindings/HTMLTrackElementPrototype.h>
#include <LibWeb/Bindings/HTMLTrackElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLTrackElement.h>)
#    include <LibWeb/Crypto/HTMLTrackElement.h>
#elif __has_include(<LibWeb/CSS/HTMLTrackElement.h>)
#    include <LibWeb/CSS/HTMLTrackElement.h>
#elif __has_include(<LibWeb/DOM/HTMLTrackElement.h>)
#    include <LibWeb/DOM/HTMLTrackElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLTrackElement.h>)
#    include <LibWeb/Encoding/HTMLTrackElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLTrackElement.h>)
#    include <LibWeb/Geometry/HTMLTrackElement.h>
#elif __has_include(<LibWeb/HTML/HTMLTrackElement.h>)
#    include <LibWeb/HTML/HTMLTrackElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLTrackElement.h>)
#    include <LibWeb/UIEvents/HTMLTrackElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLTrackElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLTrackElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLTrackElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLTrackElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLTrackElement.h>)
#    include <LibWeb/NavigationTiming/HTMLTrackElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLTrackElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLTrackElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLTrackElement.h>)
#    include <LibWeb/ResizeObserver/HTMLTrackElement.h>
#elif __has_include(<LibWeb/SVG/HTMLTrackElement.h>)
#    include <LibWeb/SVG/HTMLTrackElement.h>
#elif __has_include(<LibWeb/Selection/HTMLTrackElement.h>)
#    include <LibWeb/Selection/HTMLTrackElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLTrackElement.h>)
#    include <LibWeb/WebSockets/HTMLTrackElement.h>
#elif __has_include(<LibWeb/XHR/HTMLTrackElement.h>)
#    include <LibWeb/XHR/HTMLTrackElement.h>
#elif __has_include(<LibWeb/URL/HTMLTrackElement.h>)
#    include <LibWeb/URL/HTMLTrackElement.h>
#endif


#include <LibWeb/HTML/HTMLTrackElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLTrackElement.h>

#if __has_include(<LibWeb/Bindings/HTMLTrackElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLTrackElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLTrackElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLTrackElementWrapperFactory.h>
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

HTMLTrackElementConstructor::HTMLTrackElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLTrackElementConstructor::~HTMLTrackElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLTrackElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLTrackElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLTrackElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLTrackElement");

}

void HTMLTrackElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLTrackElementPrototype>("HTMLTrackElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

