
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/EventConstructor.h>
#include <LibWeb/Bindings/EventPrototype.h>
#include <LibWeb/Bindings/EventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/Event.h>)
#    include <LibWeb/Crypto/Event.h>
#elif __has_include(<LibWeb/CSS/Event.h>)
#    include <LibWeb/CSS/Event.h>
#elif __has_include(<LibWeb/DOM/Event.h>)
#    include <LibWeb/DOM/Event.h>
#elif __has_include(<LibWeb/Encoding/Event.h>)
#    include <LibWeb/Encoding/Event.h>
#elif __has_include(<LibWeb/Geometry/Event.h>)
#    include <LibWeb/Geometry/Event.h>
#elif __has_include(<LibWeb/HTML/Event.h>)
#    include <LibWeb/HTML/Event.h>
#elif __has_include(<LibWeb/UIEvents/Event.h>)
#    include <LibWeb/UIEvents/Event.h>
#elif __has_include(<LibWeb/HighResolutionTime/Event.h>)
#    include <LibWeb/HighResolutionTime/Event.h>
#elif __has_include(<LibWeb/IntersectionObserver/Event.h>)
#    include <LibWeb/IntersectionObserver/Event.h>
#elif __has_include(<LibWeb/NavigationTiming/Event.h>)
#    include <LibWeb/NavigationTiming/Event.h>
#elif __has_include(<LibWeb/RequestIdleCallback/Event.h>)
#    include <LibWeb/RequestIdleCallback/Event.h>
#elif __has_include(<LibWeb/ResizeObserver/Event.h>)
#    include <LibWeb/ResizeObserver/Event.h>
#elif __has_include(<LibWeb/SVG/Event.h>)
#    include <LibWeb/SVG/Event.h>
#elif __has_include(<LibWeb/Selection/Event.h>)
#    include <LibWeb/Selection/Event.h>
#elif __has_include(<LibWeb/WebSockets/Event.h>)
#    include <LibWeb/WebSockets/Event.h>
#elif __has_include(<LibWeb/XHR/Event.h>)
#    include <LibWeb/XHR/Event.h>
#elif __has_include(<LibWeb/URL/Event.h>)
#    include <LibWeb/URL/Event.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/Event.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

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

EventConstructor::EventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

EventConstructor::~EventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> EventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "Event");
}

JS::ThrowCompletionOr<JS::Object*> EventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "Event");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "EventInit");

    EventInit event_init_dict {};

    JS::Value bubbles;
    if (arg1.is_nullish()) {
        bubbles = JS::js_undefined();
    } else {
        bubbles = TRY(arg1.as_object().get("bubbles"));
    }

    bool bubbles_value;

    if (!bubbles.is_undefined())

    bubbles_value = bubbles.to_boolean();

    else
        bubbles_value = false;

    event_init_dict.bubbles = bubbles_value;

    JS::Value cancelable;
    if (arg1.is_nullish()) {
        cancelable = JS::js_undefined();
    } else {
        cancelable = TRY(arg1.as_object().get("cancelable"));
    }

    bool cancelable_value;

    if (!cancelable.is_undefined())

    cancelable_value = cancelable.to_boolean();

    else
        cancelable_value = false;

    event_init_dict.cancelable = cancelable_value;

    JS::Value composed;
    if (arg1.is_nullish()) {
        composed = JS::js_undefined();
    } else {
        composed = TRY(arg1.as_object().get("composed"));
    }

    bool composed_value;

    if (!composed.is_undefined())

    composed_value = composed.to_boolean();

    else
        composed_value = false;

    event_init_dict.composed = composed_value;

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return DOM::Event::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void EventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<EventPrototype>("Event"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


define_direct_property("NONE", JS::Value((i32)0), JS::Attribute::Enumerable);

define_direct_property("CAPTURING_PHASE", JS::Value((i32)1), JS::Attribute::Enumerable);

define_direct_property("AT_TARGET", JS::Value((i32)2), JS::Attribute::Enumerable);

define_direct_property("BUBBLING_PHASE", JS::Value((i32)3), JS::Attribute::Enumerable);

}

} // namespace Web::Bindings

