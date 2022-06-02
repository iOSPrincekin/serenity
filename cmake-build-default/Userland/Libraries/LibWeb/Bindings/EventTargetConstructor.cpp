
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/EventTargetConstructor.h>
#include <LibWeb/Bindings/EventTargetPrototype.h>
#include <LibWeb/Bindings/EventTargetWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/EventTarget.h>)
#    include <LibWeb/Crypto/EventTarget.h>
#elif __has_include(<LibWeb/CSS/EventTarget.h>)
#    include <LibWeb/CSS/EventTarget.h>
#elif __has_include(<LibWeb/DOM/EventTarget.h>)
#    include <LibWeb/DOM/EventTarget.h>
#elif __has_include(<LibWeb/Encoding/EventTarget.h>)
#    include <LibWeb/Encoding/EventTarget.h>
#elif __has_include(<LibWeb/Geometry/EventTarget.h>)
#    include <LibWeb/Geometry/EventTarget.h>
#elif __has_include(<LibWeb/HTML/EventTarget.h>)
#    include <LibWeb/HTML/EventTarget.h>
#elif __has_include(<LibWeb/UIEvents/EventTarget.h>)
#    include <LibWeb/UIEvents/EventTarget.h>
#elif __has_include(<LibWeb/HighResolutionTime/EventTarget.h>)
#    include <LibWeb/HighResolutionTime/EventTarget.h>
#elif __has_include(<LibWeb/IntersectionObserver/EventTarget.h>)
#    include <LibWeb/IntersectionObserver/EventTarget.h>
#elif __has_include(<LibWeb/NavigationTiming/EventTarget.h>)
#    include <LibWeb/NavigationTiming/EventTarget.h>
#elif __has_include(<LibWeb/RequestIdleCallback/EventTarget.h>)
#    include <LibWeb/RequestIdleCallback/EventTarget.h>
#elif __has_include(<LibWeb/ResizeObserver/EventTarget.h>)
#    include <LibWeb/ResizeObserver/EventTarget.h>
#elif __has_include(<LibWeb/SVG/EventTarget.h>)
#    include <LibWeb/SVG/EventTarget.h>
#elif __has_include(<LibWeb/Selection/EventTarget.h>)
#    include <LibWeb/Selection/EventTarget.h>
#elif __has_include(<LibWeb/WebSockets/EventTarget.h>)
#    include <LibWeb/WebSockets/EventTarget.h>
#elif __has_include(<LibWeb/XHR/EventTarget.h>)
#    include <LibWeb/XHR/EventTarget.h>
#elif __has_include(<LibWeb/URL/EventTarget.h>)
#    include <LibWeb/URL/EventTarget.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
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

EventTargetConstructor::EventTargetConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

EventTargetConstructor::~EventTargetConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> EventTargetConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "EventTarget");
}

JS::ThrowCompletionOr<JS::Object*> EventTargetConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "EventTarget");

}

void EventTargetConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<EventTargetPrototype>("EventTarget"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

