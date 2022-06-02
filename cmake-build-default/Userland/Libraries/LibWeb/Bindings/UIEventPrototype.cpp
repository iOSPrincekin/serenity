
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/UIEventPrototype.h>
#include <LibWeb/Bindings/UIEventWrapper.h>
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

#if __has_include(<LibWeb/Bindings/EventPrototype.h>)
#    include <LibWeb/Bindings/EventPrototype.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/UIEvents/UIEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

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

UIEventPrototype::UIEventPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<EventPrototype>("Event"))

{
}

UIEventPrototype::~UIEventPrototype()
{
}

void UIEventPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("view", view_getter, nullptr, default_attributes);

    define_native_accessor("detail", detail_getter, nullptr, default_attributes);

    define_native_accessor("which", which_getter, nullptr, default_attributes);

    define_native_function("initUIEvent", init_ui_event, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<UIEvents::UIEvent*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<UIEventWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "UIEvents::UIEvent");

    return &static_cast<UIEventWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(UIEventPrototype::view_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->view(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Window&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(UIEventPrototype::detail_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->detail(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(UIEventPrototype::which_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->which(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(UIEventPrototype::init_ui_event)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "initUIEvent");

    auto arg0 = vm.argument(0);

    String type_arg;
    if (arg0.is_null() && false) {
        type_arg = String::empty();
    } else {
        type_arg = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    bool bubbles_arg;

    if (!arg1.is_undefined())

    bubbles_arg = arg1.to_boolean();

    else
        bubbles_arg = false;

    auto arg2 = vm.argument(2);

    bool cancelable_arg;

    if (!arg2.is_undefined())

    cancelable_arg = arg2.to_boolean();

    else
        cancelable_arg = false;

    auto arg3 = vm.argument(3);

    Window* view_arg = nullptr;
    if (!arg3.is_nullish()) {
        if (!arg3.is_object() || !is<WindowObject>(arg3.as_object()))
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Window");

        view_arg = &static_cast<WindowObject&>(arg3.as_object()).impl();
    }

    auto arg4 = vm.argument(4);

    i32 detail_arg;

    if (!arg4.is_undefined())

    detail_arg = TRY(arg4.to_i32(global_object));

    else
        detail_arg = 0L;

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->init_ui_event(type_arg, bubbles_arg, cancelable_arg, view_arg, detail_arg); }));

    return JS::js_undefined();

}

} // namespace Web::Bindings

