
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/FocusEventConstructor.h>
#include <LibWeb/Bindings/FocusEventPrototype.h>
#include <LibWeb/Bindings/FocusEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/FocusEvent.h>)
#    include <LibWeb/Crypto/FocusEvent.h>
#elif __has_include(<LibWeb/CSS/FocusEvent.h>)
#    include <LibWeb/CSS/FocusEvent.h>
#elif __has_include(<LibWeb/DOM/FocusEvent.h>)
#    include <LibWeb/DOM/FocusEvent.h>
#elif __has_include(<LibWeb/Encoding/FocusEvent.h>)
#    include <LibWeb/Encoding/FocusEvent.h>
#elif __has_include(<LibWeb/Geometry/FocusEvent.h>)
#    include <LibWeb/Geometry/FocusEvent.h>
#elif __has_include(<LibWeb/HTML/FocusEvent.h>)
#    include <LibWeb/HTML/FocusEvent.h>
#elif __has_include(<LibWeb/UIEvents/FocusEvent.h>)
#    include <LibWeb/UIEvents/FocusEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/FocusEvent.h>)
#    include <LibWeb/HighResolutionTime/FocusEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/FocusEvent.h>)
#    include <LibWeb/IntersectionObserver/FocusEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/FocusEvent.h>)
#    include <LibWeb/NavigationTiming/FocusEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/FocusEvent.h>)
#    include <LibWeb/RequestIdleCallback/FocusEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/FocusEvent.h>)
#    include <LibWeb/ResizeObserver/FocusEvent.h>
#elif __has_include(<LibWeb/SVG/FocusEvent.h>)
#    include <LibWeb/SVG/FocusEvent.h>
#elif __has_include(<LibWeb/Selection/FocusEvent.h>)
#    include <LibWeb/Selection/FocusEvent.h>
#elif __has_include(<LibWeb/WebSockets/FocusEvent.h>)
#    include <LibWeb/WebSockets/FocusEvent.h>
#elif __has_include(<LibWeb/XHR/FocusEvent.h>)
#    include <LibWeb/XHR/FocusEvent.h>
#elif __has_include(<LibWeb/URL/FocusEvent.h>)
#    include <LibWeb/URL/FocusEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/UIEvents/UIEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/UIEvents/FocusEvent.h>

#include <LibWeb/UIEvents/FocusEvent.h>

#if __has_include(<LibWeb/Bindings/FocusEventWrapper.h>)
#   include <LibWeb/Bindings/FocusEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/FocusEventWrapperFactory.h>)
#   include <LibWeb/Bindings/FocusEventWrapperFactory.h>
#endif

#include <LibWeb/UIEvents/UIEvent.h>

#if __has_include(<LibWeb/Bindings/UIEventWrapper.h>)
#   include <LibWeb/Bindings/UIEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/UIEventWrapperFactory.h>)
#   include <LibWeb/Bindings/UIEventWrapperFactory.h>
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

FocusEventConstructor::FocusEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

FocusEventConstructor::~FocusEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> FocusEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "FocusEvent");
}

JS::ThrowCompletionOr<JS::Object*> FocusEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "FocusEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "FocusEventInit");

    FocusEventInit event_init_dict {};

    JS::Value related_target;
    if (arg1.is_nullish()) {
        related_target = JS::js_undefined();
    } else {
        related_target = TRY(arg1.as_object().get("relatedTarget"));
    }

    EventTarget* related_target_value = nullptr;
    if (!related_target.is_nullish()) {
        if (!related_target.is_object() || !is<EventTargetWrapper>(related_target.as_object()))
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "EventTarget");

        related_target_value = &static_cast<EventTargetWrapper&>(related_target.as_object()).impl();
    }

    event_init_dict.related_target = related_target_value;

    JS::Value detail;
    if (arg1.is_nullish()) {
        detail = JS::js_undefined();
    } else {
        detail = TRY(arg1.as_object().get("detail"));
    }

    i32 detail_value;

    if (!detail.is_undefined())

    detail_value = TRY(detail.to_i32(global_object));

    else
        detail_value = 0L;

    event_init_dict.detail = detail_value;

    JS::Value view;
    if (arg1.is_nullish()) {
        view = JS::js_undefined();
    } else {
        view = TRY(arg1.as_object().get("view"));
    }

    Window* view_value = nullptr;
    if (!view.is_nullish()) {
        if (!view.is_object() || !is<WindowObject>(view.as_object()))
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Window");

        view_value = &static_cast<WindowObject&>(view.as_object()).impl();
    }

    event_init_dict.view = view_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return UIEvents::FocusEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void FocusEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<FocusEventPrototype>("FocusEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

