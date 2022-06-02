
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/WorkerGlobalScopePrototype.h>
#include <LibWeb/Bindings/WorkerGlobalScopeWrapper.h>
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

#include <LibWeb/HTML/WorkerNavigator.h>

#include <LibWeb/HTML/WorkerGlobalScope.h>

#include <LibWeb/HTML/WorkerLocation.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/WorkerGlobalScope.h>

#if __has_include(<LibWeb/Bindings/WorkerGlobalScopeWrapper.h>)
#   include <LibWeb/Bindings/WorkerGlobalScopeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerGlobalScopeWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerGlobalScopeWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/HTML/WorkerLocation.h>

#if __has_include(<LibWeb/Bindings/WorkerLocationWrapper.h>)
#   include <LibWeb/Bindings/WorkerLocationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerLocationWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerLocationWrapperFactory.h>
#endif

#include <LibWeb/HTML/WorkerNavigator.h>

#if __has_include(<LibWeb/Bindings/WorkerNavigatorWrapper.h>)
#   include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerNavigatorWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerNavigatorWrapperFactory.h>
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

WorkerGlobalScopePrototype::WorkerGlobalScopePrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<EventTargetPrototype>("EventTarget"))

{
}

WorkerGlobalScopePrototype::~WorkerGlobalScopePrototype()
{
}

void WorkerGlobalScopePrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("self", self_getter, nullptr, default_attributes);

    define_native_accessor("location", location_getter, nullptr, default_attributes);

    define_native_accessor("navigator", navigator_getter, nullptr, default_attributes);

    define_native_accessor("onerror", onerror_getter, onerror_setter, default_attributes);

    define_native_accessor("onlanguagechange", onlanguagechange_getter, onlanguagechange_setter, default_attributes);

    define_native_accessor("onoffline", onoffline_getter, onoffline_setter, default_attributes);

    define_native_accessor("ononline", ononline_getter, ononline_setter, default_attributes);

    define_native_accessor("onrejectionhandled", onrejectionhandled_getter, onrejectionhandled_setter, default_attributes);

    define_native_accessor("onunhandledrejection", onunhandledrejection_getter, onunhandledrejection_setter, default_attributes);

    define_native_accessor("origin", origin_getter, nullptr, default_attributes);

    define_native_accessor("isSecureContext", is_secure_context_getter, nullptr, default_attributes);

    define_native_accessor("crossOriginIsolated", cross_origin_isolated_getter, nullptr, default_attributes);

    define_native_function("importScripts", import_scripts, 0, default_attributes);

    define_native_function("btoa", btoa, 1, default_attributes);

    define_native_function("atob", atob, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::WorkerGlobalScope*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<WorkerGlobalScopeWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::WorkerGlobalScope");

    return &static_cast<WorkerGlobalScopeWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::self_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->self(); }));

    return wrap(global_object, const_cast<WorkerGlobalScope&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::location_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->location(); }));

    return wrap(global_object, const_cast<WorkerLocation&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::navigator_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->navigator(); }));

    return wrap(global_object, const_cast<WorkerNavigator&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onerror_getter)
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

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onerror_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onerror(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onlanguagechange_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onlanguagechange(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onlanguagechange_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onlanguagechange(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onoffline_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onoffline(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onoffline_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onoffline(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::ononline_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ononline(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::ononline_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_ononline(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onrejectionhandled_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onrejectionhandled(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onrejectionhandled_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onrejectionhandled(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onunhandledrejection_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onunhandledrejection(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::onunhandledrejection_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onunhandledrejection(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::origin_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->origin(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::is_secure_context_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->is_secure_context(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::cross_origin_isolated_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->cross_origin_isolated(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::import_scripts)
{

    auto* impl = TRY(impl_from(vm, global_object));

    Vector<String> urls;
    urls.ensure_capacity(vm.argument_count() - 0);

    for (size_t i = 0; i < vm.argument_count(); ++i) {
        auto to_string_result = TRY(vm.argument(i).to_string(global_object));
        urls.append(move(to_string_result));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->import_scripts(urls); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::btoa)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "btoa");

    auto arg0 = vm.argument(0);

    String data;
    if (arg0.is_null() && false) {
        data = String::empty();
    } else {
        data = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->btoa(data); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(WorkerGlobalScopePrototype::atob)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "atob");

    auto arg0 = vm.argument(0);

    String data;
    if (arg0.is_null() && false) {
        data = String::empty();
    } else {
        data = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->atob(data); }));

    return JS::js_string(vm, retval);

}

} // namespace Web::Bindings

