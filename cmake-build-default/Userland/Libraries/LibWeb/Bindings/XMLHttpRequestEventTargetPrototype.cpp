
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/XMLHttpRequestEventTargetPrototype.h>
#include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>
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

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>)
#   include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapperFactory.h>
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

XMLHttpRequestEventTargetPrototype::XMLHttpRequestEventTargetPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<EventTargetPrototype>("EventTarget"))

{
}

XMLHttpRequestEventTargetPrototype::~XMLHttpRequestEventTargetPrototype()
{
}

void XMLHttpRequestEventTargetPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("onloadstart", onloadstart_getter, onloadstart_setter, default_attributes);

    define_native_accessor("onprogress", onprogress_getter, onprogress_setter, default_attributes);

    define_native_accessor("onabort", onabort_getter, onabort_setter, default_attributes);

    define_native_accessor("onerror", onerror_getter, onerror_setter, default_attributes);

    define_native_accessor("onload", onload_getter, onload_setter, default_attributes);

    define_native_accessor("ontimeout", ontimeout_getter, ontimeout_setter, default_attributes);

    define_native_accessor("onloadend", onloadend_getter, onloadend_setter, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<XHR::XMLHttpRequestEventTarget*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<XMLHttpRequestEventTargetWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "XHR::XMLHttpRequestEventTarget");

    return &static_cast<XMLHttpRequestEventTargetWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onloadstart_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onloadstart(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onloadstart_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onloadstart(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onprogress_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onprogress(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onprogress_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onprogress(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onabort_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onabort(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onabort_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onabort(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onerror_getter)
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

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onerror_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onerror(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onload_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onload(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onload_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onload(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::ontimeout_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ontimeout(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::ontimeout_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_ontimeout(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onloadend_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onloadend(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestEventTargetPrototype::onloadend_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onloadend(cpp_value); }));

    return JS::js_undefined();
}

} // namespace Web::Bindings

