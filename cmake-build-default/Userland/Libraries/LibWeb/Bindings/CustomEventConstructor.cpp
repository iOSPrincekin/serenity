
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CustomEventConstructor.h>
#include <LibWeb/Bindings/CustomEventPrototype.h>
#include <LibWeb/Bindings/CustomEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CustomEvent.h>)
#    include <LibWeb/Crypto/CustomEvent.h>
#elif __has_include(<LibWeb/CSS/CustomEvent.h>)
#    include <LibWeb/CSS/CustomEvent.h>
#elif __has_include(<LibWeb/DOM/CustomEvent.h>)
#    include <LibWeb/DOM/CustomEvent.h>
#elif __has_include(<LibWeb/Encoding/CustomEvent.h>)
#    include <LibWeb/Encoding/CustomEvent.h>
#elif __has_include(<LibWeb/Geometry/CustomEvent.h>)
#    include <LibWeb/Geometry/CustomEvent.h>
#elif __has_include(<LibWeb/HTML/CustomEvent.h>)
#    include <LibWeb/HTML/CustomEvent.h>
#elif __has_include(<LibWeb/UIEvents/CustomEvent.h>)
#    include <LibWeb/UIEvents/CustomEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/CustomEvent.h>)
#    include <LibWeb/HighResolutionTime/CustomEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/CustomEvent.h>)
#    include <LibWeb/IntersectionObserver/CustomEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/CustomEvent.h>)
#    include <LibWeb/NavigationTiming/CustomEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CustomEvent.h>)
#    include <LibWeb/RequestIdleCallback/CustomEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/CustomEvent.h>)
#    include <LibWeb/ResizeObserver/CustomEvent.h>
#elif __has_include(<LibWeb/SVG/CustomEvent.h>)
#    include <LibWeb/SVG/CustomEvent.h>
#elif __has_include(<LibWeb/Selection/CustomEvent.h>)
#    include <LibWeb/Selection/CustomEvent.h>
#elif __has_include(<LibWeb/WebSockets/CustomEvent.h>)
#    include <LibWeb/WebSockets/CustomEvent.h>
#elif __has_include(<LibWeb/XHR/CustomEvent.h>)
#    include <LibWeb/XHR/CustomEvent.h>
#elif __has_include(<LibWeb/URL/CustomEvent.h>)
#    include <LibWeb/URL/CustomEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/CustomEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/CustomEvent.h>

#if __has_include(<LibWeb/Bindings/CustomEventWrapper.h>)
#   include <LibWeb/Bindings/CustomEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CustomEventWrapperFactory.h>)
#   include <LibWeb/Bindings/CustomEventWrapperFactory.h>
#endif

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

CustomEventConstructor::CustomEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CustomEventConstructor::~CustomEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CustomEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CustomEvent");
}

JS::ThrowCompletionOr<JS::Object*> CustomEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "CustomEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "CustomEventInit");

    CustomEventInit event_init_dict {};

    JS::Value detail;
    if (arg1.is_nullish()) {
        detail = JS::js_undefined();
    } else {
        detail = TRY(arg1.as_object().get("detail"));
    }

    JS::Value detail_value = JS::js_undefined();
    if (!detail.is_undefined())
        detail_value = detail;

    else
        detail_value = JS::js_null();

    event_init_dict.detail = detail_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return DOM::CustomEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void CustomEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CustomEventPrototype>("CustomEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

