
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/KeyboardEventPrototype.h>
#include <LibWeb/Bindings/KeyboardEventWrapper.h>
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

#if __has_include(<LibWeb/Bindings/UIEventPrototype.h>)
#    include <LibWeb/Bindings/UIEventPrototype.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/UIEvents/UIEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/UIEvents/KeyboardEvent.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/UIEvents/KeyboardEvent.h>

#if __has_include(<LibWeb/Bindings/KeyboardEventWrapper.h>)
#   include <LibWeb/Bindings/KeyboardEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/KeyboardEventWrapperFactory.h>)
#   include <LibWeb/Bindings/KeyboardEventWrapperFactory.h>
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

KeyboardEventPrototype::KeyboardEventPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<UIEventPrototype>("UIEvent"))

{
}

KeyboardEventPrototype::~KeyboardEventPrototype()
{
}

void KeyboardEventPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("key", key_getter, nullptr, default_attributes);

    define_native_accessor("code", code_getter, nullptr, default_attributes);

    define_native_accessor("location", location_getter, nullptr, default_attributes);

    define_native_accessor("ctrlKey", ctrl_key_getter, nullptr, default_attributes);

    define_native_accessor("shiftKey", shift_key_getter, nullptr, default_attributes);

    define_native_accessor("altKey", alt_key_getter, nullptr, default_attributes);

    define_native_accessor("metaKey", meta_key_getter, nullptr, default_attributes);

    define_native_accessor("repeat", repeat_getter, nullptr, default_attributes);

    define_native_accessor("isComposing", is_composing_getter, nullptr, default_attributes);

    define_native_accessor("charCode", char_code_getter, nullptr, default_attributes);

    define_native_accessor("keyCode", key_code_getter, nullptr, default_attributes);

    define_direct_property("DOM_KEY_LOCATION_STANDARD", JS::Value((i32)0x00), JS::Attribute::Enumerable);

    define_direct_property("DOM_KEY_LOCATION_LEFT", JS::Value((i32)0x01), JS::Attribute::Enumerable);

    define_direct_property("DOM_KEY_LOCATION_RIGHT", JS::Value((i32)0x02), JS::Attribute::Enumerable);

    define_direct_property("DOM_KEY_LOCATION_NUMPAD", JS::Value((i32)0x03), JS::Attribute::Enumerable);

    define_native_function("getModifierState", get_modifier_state, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<UIEvents::KeyboardEvent*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<KeyboardEventWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "UIEvents::KeyboardEvent");

    return &static_cast<KeyboardEventWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::key_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->key(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::code_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->code(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::location_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->location(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::ctrl_key_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ctrl_key(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::shift_key_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->shift_key(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::alt_key_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->alt_key(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::meta_key_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->meta_key(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::repeat_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->repeat(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::is_composing_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->is_composing(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::char_code_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->char_code(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::key_code_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->key_code(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(KeyboardEventPrototype::get_modifier_state)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getModifierState");

    auto arg0 = vm.argument(0);

    String key_arg;
    if (arg0.is_null() && false) {
        key_arg = String::empty();
    } else {
        key_arg = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_modifier_state(key_arg); }));

    return JS::Value(retval);

}

} // namespace Web::Bindings

