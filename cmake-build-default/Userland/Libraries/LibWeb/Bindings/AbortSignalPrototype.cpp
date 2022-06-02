
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/AbortSignalPrototype.h>
#include <LibWeb/Bindings/AbortSignalWrapper.h>
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

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
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

AbortSignalPrototype::AbortSignalPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<EventTargetPrototype>("EventTarget"))

{
}

AbortSignalPrototype::~AbortSignalPrototype()
{
}

void AbortSignalPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("aborted", aborted_getter, nullptr, default_attributes);

    define_native_accessor("reason", reason_getter, nullptr, default_attributes);

    define_native_accessor("onabort", onabort_getter, onabort_setter, default_attributes);

    define_native_function("throwIfAborted", throw_if_aborted, 0, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<DOM::AbortSignal*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<AbortSignalWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "DOM::AbortSignal");

    return &static_cast<AbortSignalWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(AbortSignalPrototype::aborted_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->aborted(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(AbortSignalPrototype::reason_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->reason(); }));

    return retval;

}

JS_DEFINE_NATIVE_FUNCTION(AbortSignalPrototype::onabort_getter)
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

JS_DEFINE_NATIVE_FUNCTION(AbortSignalPrototype::onabort_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onabort(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(AbortSignalPrototype::throw_if_aborted)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->throw_if_aborted(); }));

    return JS::js_undefined();

}

} // namespace Web::Bindings

