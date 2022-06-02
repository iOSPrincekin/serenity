
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/MouseEventPrototype.h>
#include <LibWeb/Bindings/MouseEventWrapper.h>
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


#include <LibWeb/UIEvents/MouseEvent.h>

#include <LibWeb/UIEvents/MouseEvent.h>

#if __has_include(<LibWeb/Bindings/MouseEventWrapper.h>)
#   include <LibWeb/Bindings/MouseEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MouseEventWrapperFactory.h>)
#   include <LibWeb/Bindings/MouseEventWrapperFactory.h>
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

MouseEventPrototype::MouseEventPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<UIEventPrototype>("UIEvent"))

{
}

MouseEventPrototype::~MouseEventPrototype()
{
}

void MouseEventPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("offsetX", offset_x_getter, nullptr, default_attributes);

    define_native_accessor("offsetY", offset_y_getter, nullptr, default_attributes);

    define_native_accessor("clientX", client_x_getter, nullptr, default_attributes);

    define_native_accessor("clientY", client_y_getter, nullptr, default_attributes);

    define_native_accessor("x", x_getter, nullptr, default_attributes);

    define_native_accessor("y", y_getter, nullptr, default_attributes);

    define_native_accessor("button", button_getter, nullptr, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<UIEvents::MouseEvent*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<MouseEventWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "UIEvents::MouseEvent");

    return &static_cast<MouseEventWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(MouseEventPrototype::offset_x_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->offset_x(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(MouseEventPrototype::offset_y_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->offset_y(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(MouseEventPrototype::client_x_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->client_x(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(MouseEventPrototype::client_y_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->client_y(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(MouseEventPrototype::x_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->x(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(MouseEventPrototype::y_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->y(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(MouseEventPrototype::button_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->button(); }));

    return JS::Value((i32)retval);

}

} // namespace Web::Bindings

