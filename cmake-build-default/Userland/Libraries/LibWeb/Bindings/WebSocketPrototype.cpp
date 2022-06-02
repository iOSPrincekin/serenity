
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/WebSocketPrototype.h>
#include <LibWeb/Bindings/WebSocketWrapper.h>
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

#if __has_include(<LibWeb/Bindings/EventTargetPrototype.h>)
#    include <LibWeb/Bindings/EventTargetPrototype.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/WebSockets/WebSocket.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/WebSockets/WebSocket.h>

#if __has_include(<LibWeb/Bindings/WebSocketWrapper.h>)
#   include <LibWeb/Bindings/WebSocketWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WebSocketWrapperFactory.h>)
#   include <LibWeb/Bindings/WebSocketWrapperFactory.h>
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

WebSocketPrototype::WebSocketPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<EventTargetPrototype>("EventTarget"))

{
}

WebSocketPrototype::~WebSocketPrototype()
{
}

void WebSocketPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("url", url_getter, nullptr, default_attributes);

    define_native_accessor("readyState", ready_state_getter, nullptr, default_attributes);

    define_native_accessor("onopen", onopen_getter, onopen_setter, default_attributes);

    define_native_accessor("onerror", onerror_getter, onerror_setter, default_attributes);

    define_native_accessor("onclose", onclose_getter, onclose_setter, default_attributes);

    define_native_accessor("extensions", extensions_getter, nullptr, default_attributes);

    define_native_accessor("protocol", protocol_getter, nullptr, default_attributes);

    define_native_accessor("onmessage", onmessage_getter, onmessage_setter, default_attributes);

    define_native_accessor("binaryType", binary_type_getter, binary_type_setter, default_attributes);

    define_direct_property("CONNECTING", JS::Value((i32)0), JS::Attribute::Enumerable);

    define_direct_property("OPEN", JS::Value((i32)1), JS::Attribute::Enumerable);

    define_direct_property("CLOSING", JS::Value((i32)2), JS::Attribute::Enumerable);

    define_direct_property("CLOSED", JS::Value((i32)3), JS::Attribute::Enumerable);

    define_native_function("close", close, 0, default_attributes);

    define_native_function("send", send, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<WebSockets::WebSocket*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<WebSocketWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "WebSockets::WebSocket");

    return &static_cast<WebSocketWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::url_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->url(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::ready_state_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ready_state(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::onopen_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onopen(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::onopen_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onopen(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::onerror_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onerror(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::onerror_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onerror(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::onclose_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onclose(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::onclose_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onclose(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::extensions_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->extensions(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::protocol_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->protocol(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::onmessage_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onmessage(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::onmessage_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onmessage(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::binary_type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->binary_type(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::binary_type_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_binary_type(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::close)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    Optional<u16> code;

    if (!arg0.is_undefined())

    code = TRY(arg0.to_u16(global_object));

    auto arg1 = vm.argument(1);

    String reason;
    if (!arg1.is_undefined()) {
        if (arg1.is_null() && false)
            reason = String::empty();
        else
            reason = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->close(code, reason); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(WebSocketPrototype::send)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "send");

    auto arg0 = vm.argument(0);

    String data;
    if (arg0.is_null() && false) {
        data = String::empty();
    } else {
        data = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->send(data); }));

    return JS::js_undefined();

}

} // namespace Web::Bindings

