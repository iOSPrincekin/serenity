
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/EventTargetPrototype.h>
#include <LibWeb/Bindings/EventTargetWrapper.h>
#include <LibWeb/Bindings/EventWrapper.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/LocationObject.h>
#include <LibWeb/Bindings/WindowObject.h>
#include <LibWeb/Bindings/WorkerLocationWrapper.h>
#include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#include <LibWeb/Bindings/WorkerWrapper.h>
#include <LibWeb/DOM/Element.h>
#include <LibWeb/DOM/Event.h>
#include <LibWeb/DOM/IDLEventListener.h>
#include <LibWeb/DOM/NodeFilter.h>
#include <LibWeb/DOM/Range.h>
#include <LibWeb/HTML/Scripting/Environments.h>
#include <LibWeb/HTML/Window.h>
#include <LibWeb/Origin.h>

#if __has_include(<LibWeb/Bindings/ObjectPrototype.h>)
#    include <LibWeb/Bindings/ObjectPrototype.h>
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
using namespace Web::Crypto;
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::NavigationTiming;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;
using namespace Web::SVG;
using namespace Web::URL;
using namespace Web::WebSockets;
using namespace Web::XHR;

namespace Web::Bindings {

EventTargetPrototype::EventTargetPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

EventTargetPrototype::~EventTargetPrototype()
{
}

void EventTargetPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_function("removeEventListener", remove_event_listener, 2, default_attributes);

    define_native_function("addEventListener", add_event_listener, 2, default_attributes);

    define_native_function("dispatchEvent", dispatch_event, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<DOM::EventTarget*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (is<WindowObject>(this_object)) {
        return &static_cast<WindowObject*>(this_object)->impl();
    }

    if (!is<EventTargetWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "DOM::EventTarget");

    return &static_cast<EventTargetWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(EventTargetPrototype::add_event_listener)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "addEventListener", "2");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    RefPtr<IDLEventListener> callback;
    if (!arg1.is_nullish()) {
        if (!arg1.is_object())
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObject, arg1.to_string_without_side_effects());

        CallbackType callback_type(JS::make_handle(&arg1.as_object()), HTML::incumbent_settings_object());
        callback = adopt_ref(*new IDLEventListener(move(callback_type)));
    }

    auto arg2 = vm.argument(2);

    auto arg2_to_dictionary = [&global_object, &vm](JS::Value arg2) -> JS::ThrowCompletionOr<AddEventListenerOptions> {

    if (!arg2.is_nullish() && !arg2.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "AddEventListenerOptions");

    AddEventListenerOptions dictionary_union_type {};

    JS::Value once;
    if (arg2.is_nullish()) {
        once = JS::js_undefined();
    } else {
        once = TRY(arg2.as_object().get("once"));
    }

    bool once_value;

    if (!once.is_undefined())

    once_value = once.to_boolean();

    else
        once_value = false;

    dictionary_union_type.once = once_value;

    JS::Value passive;
    if (arg2.is_nullish()) {
        passive = JS::js_undefined();
    } else {
        passive = TRY(arg2.as_object().get("passive"));
    }

    bool passive_value;

    if (!passive.is_undefined())

    passive_value = passive.to_boolean();

    else
        passive_value = false;

    dictionary_union_type.passive = passive_value;

    JS::Value signal;
    if (arg2.is_nullish()) {
        signal = JS::js_undefined();
    } else {
        signal = TRY(arg2.as_object().get("signal"));
    }

    Optional<NonnullRefPtr<AbortSignal>> signal_value;
    if (!signal.is_undefined()) {
        if (!signal.is_object() || !is<AbortSignalWrapper>(signal.as_object()))
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "AbortSignal");

        signal_value = static_cast<AbortSignalWrapper&>(signal.as_object()).impl();
    }

    dictionary_union_type.signal = signal_value;

    JS::Value capture;
    if (arg2.is_nullish()) {
        capture = JS::js_undefined();
    } else {
        capture = TRY(arg2.as_object().get("capture"));
    }

    bool capture_value;

    if (!capture.is_undefined())

    capture_value = capture.to_boolean();

    else
        capture_value = false;

    dictionary_union_type.capture = capture_value;

        return dictionary_union_type;
    };

    auto arg2_to_variant = [&global_object, &vm, &arg2_to_dictionary](JS::Value arg2) -> JS::ThrowCompletionOr<Variant<AddEventListenerOptions, bool>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg2.is_nullish())
            return Variant<AddEventListenerOptions, bool> { TRY(arg2_to_dictionary(arg2)) };

        if (arg2.is_object()) {
            [[maybe_unused]] auto& arg2_object = arg2.as_object();

        return Variant<AddEventListenerOptions, bool> { TRY(arg2_to_dictionary(arg2)) };

        }

        if (arg2.is_boolean())
            return Variant<AddEventListenerOptions, bool> { arg2.as_bool() };

        return Variant<AddEventListenerOptions, bool> { arg2.to_boolean() };

    };

    Variant<AddEventListenerOptions, bool> options = arg2.is_undefined() ? TRY(arg2_to_dictionary(arg2)) : TRY(arg2_to_variant(arg2));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->add_event_listener(type, callback, options); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(EventTargetPrototype::remove_event_listener)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "removeEventListener", "2");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    RefPtr<IDLEventListener> callback;
    if (!arg1.is_nullish()) {
        if (!arg1.is_object())
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObject, arg1.to_string_without_side_effects());

        CallbackType callback_type(JS::make_handle(&arg1.as_object()), HTML::incumbent_settings_object());
        callback = adopt_ref(*new IDLEventListener(move(callback_type)));
    }

    auto arg2 = vm.argument(2);

    auto arg2_to_dictionary = [&global_object, &vm](JS::Value arg2) -> JS::ThrowCompletionOr<EventListenerOptions> {

    if (!arg2.is_nullish() && !arg2.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "EventListenerOptions");

    EventListenerOptions dictionary_union_type {};

    JS::Value capture;
    if (arg2.is_nullish()) {
        capture = JS::js_undefined();
    } else {
        capture = TRY(arg2.as_object().get("capture"));
    }

    bool capture_value;

    if (!capture.is_undefined())

    capture_value = capture.to_boolean();

    else
        capture_value = false;

    dictionary_union_type.capture = capture_value;

        return dictionary_union_type;
    };

    auto arg2_to_variant = [&global_object, &vm, &arg2_to_dictionary](JS::Value arg2) -> JS::ThrowCompletionOr<Variant<EventListenerOptions, bool>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg2.is_nullish())
            return Variant<EventListenerOptions, bool> { TRY(arg2_to_dictionary(arg2)) };

        if (arg2.is_object()) {
            [[maybe_unused]] auto& arg2_object = arg2.as_object();

        return Variant<EventListenerOptions, bool> { TRY(arg2_to_dictionary(arg2)) };

        }

        if (arg2.is_boolean())
            return Variant<EventListenerOptions, bool> { arg2.as_bool() };

        return Variant<EventListenerOptions, bool> { arg2.to_boolean() };

    };

    Variant<EventListenerOptions, bool> options = arg2.is_undefined() ? TRY(arg2_to_dictionary(arg2)) : TRY(arg2_to_variant(arg2));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->remove_event_listener(type, callback, options); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(EventTargetPrototype::dispatch_event)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "dispatchEvent");

    auto arg0 = vm.argument(0);

    if (!arg0.is_object() || !is<EventWrapper>(arg0.as_object()))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Event");

    auto& event = static_cast<EventWrapper&>(arg0.as_object()).impl();

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->dispatch_event_binding(event); }));

    return JS::Value(retval);

}

} // namespace Web::Bindings

