
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DOMRectPrototype.h>
#include <LibWeb/Bindings/DOMRectWrapper.h>
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

#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyPrototype.h>)
#    include <LibWeb/Bindings/DOMRectReadOnlyPrototype.h>
#endif


#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/Geometry/DOMRect.h>

#if __has_include(<LibWeb/Bindings/DOMRectWrapper.h>)
#   include <LibWeb/Bindings/DOMRectWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectWrapperFactory.h>
#endif

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapper.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>
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

DOMRectPrototype::DOMRectPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<DOMRectReadOnlyPrototype>("DOMRectReadOnly"))

{
}

DOMRectPrototype::~DOMRectPrototype()
{
}

void DOMRectPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("x", x_getter, x_setter, default_attributes);

    define_native_accessor("y", y_getter, y_setter, default_attributes);

    define_native_accessor("width", width_getter, width_setter, default_attributes);

    define_native_accessor("height", height_getter, height_setter, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<Geometry::DOMRect*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<DOMRectWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Geometry::DOMRect");

    return &static_cast<DOMRectWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(DOMRectPrototype::x_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->x(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectPrototype::x_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    double cpp_value = TRY(value.to_double(global_object));

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_x(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(DOMRectPrototype::y_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->y(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectPrototype::y_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    double cpp_value = TRY(value.to_double(global_object));

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_y(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(DOMRectPrototype::width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->width(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectPrototype::width_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    double cpp_value = TRY(value.to_double(global_object));

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_width(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(DOMRectPrototype::height_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->height(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectPrototype::height_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    double cpp_value = TRY(value.to_double(global_object));

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_height(cpp_value); }));

    return JS::js_undefined();
}

} // namespace Web::Bindings

