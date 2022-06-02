
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/EventPrototype.h>
#include <LibWeb/Bindings/EventWrapper.h>
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

EventPrototype::EventPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

EventPrototype::~EventPrototype()
{
}

void EventPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("type", type_getter, nullptr, default_attributes);

    define_native_accessor("target", target_getter, nullptr, default_attributes);

    define_native_accessor("srcTarget", src_target_getter, nullptr, default_attributes);

    define_native_accessor("currentTarget", current_target_getter, nullptr, default_attributes);

    define_native_accessor("eventPhase", event_phase_getter, nullptr, default_attributes);

    define_native_accessor("cancelBubble", cancel_bubble_getter, cancel_bubble_setter, default_attributes);

    define_native_accessor("bubbles", bubbles_getter, nullptr, default_attributes);

    define_native_accessor("cancelable", cancelable_getter, nullptr, default_attributes);

    define_native_accessor("returnValue", return_value_getter, return_value_setter, default_attributes);

    define_native_accessor("defaultPrevented", default_prevented_getter, nullptr, default_attributes);

    define_native_accessor("composed", composed_getter, nullptr, default_attributes);

    define_native_accessor("isTrusted", is_trusted_getter, nullptr, default_attributes);

    define_native_accessor("timeStamp", time_stamp_getter, nullptr, default_attributes);

    define_direct_property("NONE", JS::Value((i32)0), JS::Attribute::Enumerable);

    define_direct_property("CAPTURING_PHASE", JS::Value((i32)1), JS::Attribute::Enumerable);

    define_direct_property("AT_TARGET", JS::Value((i32)2), JS::Attribute::Enumerable);

    define_direct_property("BUBBLING_PHASE", JS::Value((i32)3), JS::Attribute::Enumerable);

    define_native_function("initEvent", init_event, 1, default_attributes);

    define_native_function("stopPropagation", stop_propagation, 0, default_attributes);

    define_native_function("composedPath", composed_path, 0, default_attributes);

    define_native_function("stopImmediatePropagation", stop_immediate_propagation, 0, default_attributes);

    define_native_function("preventDefault", prevent_default, 0, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<DOM::Event*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<EventWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "DOM::Event");

    return &static_cast<EventWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->type(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::target_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->target(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<EventTarget&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::src_target_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->src_target(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<EventTarget&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::current_target_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->current_target(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<EventTarget&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::event_phase_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->event_phase(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::cancel_bubble_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->cancel_bubble(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::cancel_bubble_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_cancel_bubble(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::bubbles_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->bubbles(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::cancelable_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->cancelable(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::return_value_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->return_value(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::return_value_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_return_value(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::default_prevented_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->default_prevented(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::composed_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->composed(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::is_trusted_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->is_trusted(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::time_stamp_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->time_stamp(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::composed_path)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->composed_path(); }));

    auto* new_array0 = MUST(JS::Array::create(global_object, 0));

    for (size_t i0 = 0; i0 < retval.size(); ++i0) {
        auto& element0 = retval.at(i0);

    auto wrapped_element0 = wrap(global_object, const_cast<EventTarget&>(element0));

        auto property_index0 = JS::PropertyKey { i0 };
        MUST(new_array0->create_data_property(property_index0, wrapped_element0));
    }

    return new_array0;

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::stop_propagation)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->stop_propagation(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::stop_immediate_propagation)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->stop_immediate_propagation(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::prevent_default)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->prevent_default(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(EventPrototype::init_event)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "initEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    bool bubbles;

    if (!arg1.is_undefined())

    bubbles = arg1.to_boolean();

    else
        bubbles = false;

    auto arg2 = vm.argument(2);

    bool cancelable;

    if (!arg2.is_undefined())

    cancelable = arg2.to_boolean();

    else
        cancelable = false;

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->init_event(type, bubbles, cancelable); }));

    return JS::js_undefined();

}

} // namespace Web::Bindings

