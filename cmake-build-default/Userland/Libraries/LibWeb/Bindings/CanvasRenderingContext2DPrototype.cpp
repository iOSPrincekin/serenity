
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CanvasRenderingContext2DPrototype.h>
#include <LibWeb/Bindings/CanvasRenderingContext2DWrapper.h>
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


#include <LibWeb/HTML/TextMetrics.h>

#include <LibWeb/HTML/CanvasRenderingContext2D.h>

#include <LibWeb/HTML/HTMLCanvasElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/ImageData.h>

#include <LibWeb/HTML/CanvasGradient.h>

#include <LibWeb/HTML/HTMLImageElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/CanvasRenderingContext2D.h>

#if __has_include(<LibWeb/Bindings/CanvasRenderingContext2DWrapper.h>)
#   include <LibWeb/Bindings/CanvasRenderingContext2DWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CanvasRenderingContext2DWrapperFactory.h>)
#   include <LibWeb/Bindings/CanvasRenderingContext2DWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLCanvasElement.h>

#if __has_include(<LibWeb/Bindings/HTMLCanvasElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLCanvasElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLCanvasElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLCanvasElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLImageElement.h>

#if __has_include(<LibWeb/Bindings/HTMLImageElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLImageElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLImageElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLImageElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/ImageData.h>

#if __has_include(<LibWeb/Bindings/ImageDataWrapper.h>)
#   include <LibWeb/Bindings/ImageDataWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ImageDataWrapperFactory.h>)
#   include <LibWeb/Bindings/ImageDataWrapperFactory.h>
#endif

#include <LibWeb/HTML/TextMetrics.h>

#if __has_include(<LibWeb/Bindings/TextMetricsWrapper.h>)
#   include <LibWeb/Bindings/TextMetricsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TextMetricsWrapperFactory.h>)
#   include <LibWeb/Bindings/TextMetricsWrapperFactory.h>
#endif

#include <LibWeb/HTML/CanvasGradient.h>

#if __has_include(<LibWeb/Bindings/CanvasGradientWrapper.h>)
#   include <LibWeb/Bindings/CanvasGradientWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CanvasGradientWrapperFactory.h>)
#   include <LibWeb/Bindings/CanvasGradientWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
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

CanvasRenderingContext2DPrototype::CanvasRenderingContext2DPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

CanvasRenderingContext2DPrototype::~CanvasRenderingContext2DPrototype()
{
}

void CanvasRenderingContext2DPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("fillStyle", fill_style_getter, fill_style_setter, default_attributes);

    define_native_accessor("strokeStyle", stroke_style_getter, stroke_style_setter, default_attributes);

    define_native_accessor("lineWidth", line_width_getter, line_width_setter, default_attributes);

    define_native_accessor("canvas", canvas_getter, nullptr, default_attributes);

    define_native_function("createConicGradient", create_conic_gradient, 3, default_attributes);

    define_native_function("arc", arc, 5, default_attributes);

    define_native_function("fillRect", fill_rect, 4, default_attributes);

    define_native_function("createRadialGradient", create_radial_gradient, 6, default_attributes);

    define_native_function("clearRect", clear_rect, 4, default_attributes);

    define_native_function("isContextLost", is_context_lost, 0, default_attributes);

    define_native_function("putImageData", put_image_data, 3, default_attributes);

    define_native_function("closePath", close_path, 0, default_attributes);

    define_native_function("quadraticCurveTo", quadratic_curve_to, 4, default_attributes);

    define_native_function("save", save, 0, default_attributes);

    define_native_function("restore", restore, 0, default_attributes);

    define_native_function("fill", fill, 0, default_attributes);

    define_native_function("clip", clip, 0, default_attributes);

    define_native_function("bezierCurveTo", bezier_curve_to, 6, default_attributes);

    define_native_function("rect", rect, 4, default_attributes);

    define_native_function("createLinearGradient", create_linear_gradient, 4, default_attributes);

    define_native_function("setTransform", set_transform, 6, default_attributes);

    define_native_function("scale", scale, 2, default_attributes);

    define_native_function("measureText", measure_text, 1, default_attributes);

    define_native_function("ellipse", ellipse, 7, default_attributes);

    define_native_function("resetTransform", reset_transform, 0, default_attributes);

    define_native_function("createImageData", create_image_data, 2, default_attributes);

    define_native_function("strokeText", stroke_text, 3, default_attributes);

    define_native_function("translate", translate, 2, default_attributes);

    define_native_function("stroke", stroke, 0, default_attributes);

    define_native_function("lineTo", line_to, 2, default_attributes);

    define_native_function("rotate", rotate, 1, default_attributes);

    define_native_function("beginPath", begin_path, 0, default_attributes);

    define_native_function("transform", transform, 6, default_attributes);

    define_native_function("drawImage", draw_image, 3, default_attributes);

    define_native_function("getImageData", get_image_data, 4, default_attributes);

    define_native_function("fillText", fill_text, 3, default_attributes);

    define_native_function("moveTo", move_to, 2, default_attributes);

    define_native_function("strokeRect", stroke_rect, 4, default_attributes);

    define_native_function("reset", reset, 0, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::CanvasRenderingContext2D*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<CanvasRenderingContext2DWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::CanvasRenderingContext2D");

    return &static_cast<CanvasRenderingContext2DWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::fill_style_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->fill_style(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::fill_style_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_fill_style(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::stroke_style_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->stroke_style(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::stroke_style_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_stroke_style(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::line_width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->line_width(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::line_width_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    double cpp_value = TRY(value.to_double(global_object));

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_line_width(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::canvas_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->canvas(); }));

    return wrap(global_object, const_cast<HTMLCanvasElement&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::fill_rect)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 4)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "fillRect", "4");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double w = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double h = TRY(arg3.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->fill_rect(x, y, w, h); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::stroke_rect)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 4)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "strokeRect", "4");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double w = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double h = TRY(arg3.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->stroke_rect(x, y, w, h); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::clear_rect)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 4)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "clearRect", "4");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double w = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double h = TRY(arg3.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->clear_rect(x, y, w, h); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::scale)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "scale", "2");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->scale(x, y); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::translate)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "translate", "2");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->translate(x, y); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::rotate)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "rotate");

    auto arg0 = vm.argument(0);

    double radians = TRY(arg0.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->rotate(radians); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::begin_path)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->begin_path(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::close_path)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->close_path(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::fill)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    String fill_rule;
    if (!arg0.is_undefined()) {
        if (arg0.is_null() && false)
            fill_rule = String::empty();
        else
            fill_rule = TRY(arg0.to_string(global_object));
    } else {
        fill_rule = "nonzero";
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->fill(fill_rule); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::stroke)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->stroke(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::move_to)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "moveTo", "2");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->move_to(x, y); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::line_to)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "lineTo", "2");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->line_to(x, y); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::quadratic_curve_to)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 4)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "quadraticCurveTo", "4");

    auto arg0 = vm.argument(0);

    double cpx = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double cpy = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double x = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double y = TRY(arg3.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->quadratic_curve_to(cpx, cpy, x, y); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::bezier_curve_to)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 6)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "bezierCurveTo", "6");

    auto arg0 = vm.argument(0);

    double cp1x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double cp1y = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double cp2x = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double cp2y = TRY(arg3.to_double(global_object));

    auto arg4 = vm.argument(4);

    double x = TRY(arg4.to_double(global_object));

    auto arg5 = vm.argument(5);

    double y = TRY(arg5.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->bezier_curve_to(cp1x, cp1y, cp2x, cp2y, x, y); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::arc)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 5)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "arc", "5");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double radius = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double start_angle = TRY(arg3.to_double(global_object));

    auto arg4 = vm.argument(4);

    double end_angle = TRY(arg4.to_double(global_object));

    auto arg5 = vm.argument(5);

    bool counterclockwise;

    if (!arg5.is_undefined())

    counterclockwise = arg5.to_boolean();

    else
        counterclockwise = false;

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->arc(x, y, radius, start_angle, end_angle, counterclockwise); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::ellipse)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 7)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "ellipse", "7");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double radius_x = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double radius_y = TRY(arg3.to_double(global_object));

    auto arg4 = vm.argument(4);

    double rotation = TRY(arg4.to_double(global_object));

    auto arg5 = vm.argument(5);

    double start_angle = TRY(arg5.to_double(global_object));

    auto arg6 = vm.argument(6);

    double end_angle = TRY(arg6.to_double(global_object));

    auto arg7 = vm.argument(7);

    bool counterclockwise;

    if (!arg7.is_undefined())

    counterclockwise = arg7.to_boolean();

    else
        counterclockwise = false;

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ellipse(x, y, radius_x, radius_y, rotation, start_angle, end_angle, counterclockwise); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::rect)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 4)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "rect", "4");

    auto arg0 = vm.argument(0);

    double x = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double width = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double height = TRY(arg3.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->rect(x, y, width, height); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::fill_text)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 3)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "fillText", "3");

    auto arg0 = vm.argument(0);

    String text;
    if (arg0.is_null() && false) {
        text = String::empty();
    } else {
        text = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    double x = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double y = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    Optional<double> max_width;

    if (!arg3.is_undefined())
        max_width = TRY(arg3.to_double(global_object));


    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->fill_text(text, x, y, max_width); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::stroke_text)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 3)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "strokeText", "3");

    auto arg0 = vm.argument(0);

    String text;
    if (arg0.is_null() && false) {
        text = String::empty();
    } else {
        text = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    double x = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double y = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    Optional<double> max_width;

    if (!arg3.is_undefined())
        max_width = TRY(arg3.to_double(global_object));


    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->stroke_text(text, x, y, max_width); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::draw_image0)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    auto arg0_to_variant = [&global_object, &vm](JS::Value arg0) -> JS::ThrowCompletionOr<Variant<NonnullRefPtr<HTMLImageElement>, NonnullRefPtr<HTMLCanvasElement>>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg0.is_object()) {
            [[maybe_unused]] auto& arg0_object = arg0.as_object();

            if (is<Wrapper>(arg0_object)) {

                if (is<HTMLImageElementWrapper>(arg0_object))
                    return NonnullRefPtr<HTMLImageElement> { static_cast<HTMLImageElementWrapper&>(arg0_object).impl() };

                if (is<HTMLCanvasElementWrapper>(arg0_object))
                    return NonnullRefPtr<HTMLCanvasElement> { static_cast<HTMLCanvasElementWrapper&>(arg0_object).impl() };

            }

        }

        return vm.throw_completion<JS::TypeError>(global_object, "No union types matched");

    };

    Variant<NonnullRefPtr<HTMLImageElement>, NonnullRefPtr<HTMLCanvasElement>> image = TRY(arg0_to_variant(arg0));

    auto arg1 = vm.argument(1);

    double dx = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double dy = TRY(arg2.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->draw_image(image, dx, dy); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::draw_image1)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    auto arg0_to_variant = [&global_object, &vm](JS::Value arg0) -> JS::ThrowCompletionOr<Variant<NonnullRefPtr<HTMLImageElement>, NonnullRefPtr<HTMLCanvasElement>>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg0.is_object()) {
            [[maybe_unused]] auto& arg0_object = arg0.as_object();

            if (is<Wrapper>(arg0_object)) {

                if (is<HTMLImageElementWrapper>(arg0_object))
                    return NonnullRefPtr<HTMLImageElement> { static_cast<HTMLImageElementWrapper&>(arg0_object).impl() };

                if (is<HTMLCanvasElementWrapper>(arg0_object))
                    return NonnullRefPtr<HTMLCanvasElement> { static_cast<HTMLCanvasElementWrapper&>(arg0_object).impl() };

            }

        }

        return vm.throw_completion<JS::TypeError>(global_object, "No union types matched");

    };

    Variant<NonnullRefPtr<HTMLImageElement>, NonnullRefPtr<HTMLCanvasElement>> image = TRY(arg0_to_variant(arg0));

    auto arg1 = vm.argument(1);

    double dx = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double dy = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double dw = TRY(arg3.to_double(global_object));

    auto arg4 = vm.argument(4);

    double dh = TRY(arg4.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->draw_image(image, dx, dy, dw, dh); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::draw_image2)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    auto arg0_to_variant = [&global_object, &vm](JS::Value arg0) -> JS::ThrowCompletionOr<Variant<NonnullRefPtr<HTMLImageElement>, NonnullRefPtr<HTMLCanvasElement>>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg0.is_object()) {
            [[maybe_unused]] auto& arg0_object = arg0.as_object();

            if (is<Wrapper>(arg0_object)) {

                if (is<HTMLImageElementWrapper>(arg0_object))
                    return NonnullRefPtr<HTMLImageElement> { static_cast<HTMLImageElementWrapper&>(arg0_object).impl() };

                if (is<HTMLCanvasElementWrapper>(arg0_object))
                    return NonnullRefPtr<HTMLCanvasElement> { static_cast<HTMLCanvasElementWrapper&>(arg0_object).impl() };

            }

        }

        return vm.throw_completion<JS::TypeError>(global_object, "No union types matched");

    };

    Variant<NonnullRefPtr<HTMLImageElement>, NonnullRefPtr<HTMLCanvasElement>> image = TRY(arg0_to_variant(arg0));

    auto arg1 = vm.argument(1);

    double sx = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double sy = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double sw = TRY(arg3.to_double(global_object));

    auto arg4 = vm.argument(4);

    double sh = TRY(arg4.to_double(global_object));

    auto arg5 = vm.argument(5);

    double dx = TRY(arg5.to_double(global_object));

    auto arg6 = vm.argument(6);

    double dy = TRY(arg6.to_double(global_object));

    auto arg7 = vm.argument(7);

    double dw = TRY(arg7.to_double(global_object));

    auto arg8 = vm.argument(8);

    double dh = TRY(arg8.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->draw_image(image, sx, sy, sw, sh, dx, dy, dw, dh); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::create_image_data)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "createImageData", "2");

    auto arg0 = vm.argument(0);

    i32 sw;

    sw = TRY(arg0.to_i32(global_object));

    auto arg1 = vm.argument(1);

    i32 sh;

    sh = TRY(arg1.to_i32(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_image_data(sw, sh); }));

    return wrap(global_object, const_cast<ImageData&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::get_image_data)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 4)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "getImageData", "4");

    auto arg0 = vm.argument(0);

    i32 sx;

    sx = TRY(arg0.to_i32(global_object));

    auto arg1 = vm.argument(1);

    i32 sy;

    sy = TRY(arg1.to_i32(global_object));

    auto arg2 = vm.argument(2);

    i32 sw;

    sw = TRY(arg2.to_i32(global_object));

    auto arg3 = vm.argument(3);

    i32 sh;

    sh = TRY(arg3.to_i32(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_image_data(sx, sy, sw, sh); }));

    return wrap(global_object, const_cast<ImageData&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::put_image_data)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 3)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "putImageData", "3");

    auto arg0 = vm.argument(0);

    if (!arg0.is_object() || !is<ImageDataWrapper>(arg0.as_object()))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "ImageData");

    auto& imagedata = static_cast<ImageDataWrapper&>(arg0.as_object()).impl();

    auto arg1 = vm.argument(1);

    double dx = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double dy = TRY(arg2.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->put_image_data(imagedata, dx, dy); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::save)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->save(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::restore)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->restore(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::reset)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->reset(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::is_context_lost)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->is_context_lost(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::measure_text)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "measureText");

    auto arg0 = vm.argument(0);

    String text;
    if (arg0.is_null() && false) {
        text = String::empty();
    } else {
        text = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->measure_text(text); }));

    return wrap(global_object, const_cast<TextMetrics&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::create_radial_gradient)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 6)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "createRadialGradient", "6");

    auto arg0 = vm.argument(0);

    double x0 = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y0 = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double r0 = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double x1 = TRY(arg3.to_double(global_object));

    auto arg4 = vm.argument(4);

    double y1 = TRY(arg4.to_double(global_object));

    auto arg5 = vm.argument(5);

    double r1 = TRY(arg5.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_radial_gradient(x0, y0, r0, x1, y1, r1); }));

    return wrap(global_object, const_cast<CanvasGradient&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::create_linear_gradient)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 4)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "createLinearGradient", "4");

    auto arg0 = vm.argument(0);

    double x0 = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double y0 = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double x1 = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double y1 = TRY(arg3.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_linear_gradient(x0, y0, x1, y1); }));

    return wrap(global_object, const_cast<CanvasGradient&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::create_conic_gradient)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 3)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "createConicGradient", "3");

    auto arg0 = vm.argument(0);

    double start_angle = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double x = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double y = TRY(arg2.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_conic_gradient(start_angle, x, y); }));

    return wrap(global_object, const_cast<CanvasGradient&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::transform)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 6)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "transform", "6");

    auto arg0 = vm.argument(0);

    double a = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double b = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double c = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double d = TRY(arg3.to_double(global_object));

    auto arg4 = vm.argument(4);

    double e = TRY(arg4.to_double(global_object));

    auto arg5 = vm.argument(5);

    double f = TRY(arg5.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->transform(a, b, c, d, e, f); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::set_transform)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 6)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "setTransform", "6");

    auto arg0 = vm.argument(0);

    double a = TRY(arg0.to_double(global_object));

    auto arg1 = vm.argument(1);

    double b = TRY(arg1.to_double(global_object));

    auto arg2 = vm.argument(2);

    double c = TRY(arg2.to_double(global_object));

    auto arg3 = vm.argument(3);

    double d = TRY(arg3.to_double(global_object));

    auto arg4 = vm.argument(4);

    double e = TRY(arg4.to_double(global_object));

    auto arg5 = vm.argument(5);

    double f = TRY(arg5.to_double(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_transform(a, b, c, d, e, f); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::reset_transform)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->reset_transform(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::clip)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->clip(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CanvasRenderingContext2DPrototype::draw_image)
{

    if (vm.argument_count() < 3)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "drawImage", "3");

    [[maybe_unused]] auto arg0 = vm.argument(0);

    [[maybe_unused]] auto arg1 = vm.argument(1);

    [[maybe_unused]] auto arg2 = vm.argument(2);

    if (vm.argument_count() == 3) {

    if (((arg0.is_object())))
        return draw_image0(vm, global_object);

    }

    [[maybe_unused]] auto arg3 = vm.argument(3);

    [[maybe_unused]] auto arg4 = vm.argument(4);

    if (vm.argument_count() == 5) {

    if (((arg0.is_object())))
        return draw_image1(vm, global_object);

    }

    [[maybe_unused]] auto arg5 = vm.argument(5);

    [[maybe_unused]] auto arg6 = vm.argument(6);

    [[maybe_unused]] auto arg7 = vm.argument(7);

    [[maybe_unused]] auto arg8 = vm.argument(8);

    if (((arg0.is_object())))
        return draw_image2(vm, global_object);

    return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::OverloadResolutionFailed);
}

} // namespace Web::Bindings

