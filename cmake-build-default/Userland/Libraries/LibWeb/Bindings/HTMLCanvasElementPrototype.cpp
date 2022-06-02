
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLCanvasElementPrototype.h>
#include <LibWeb/Bindings/HTMLCanvasElementWrapper.h>
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

#if __has_include(<LibWeb/Bindings/HTMLElementPrototype.h>)
#    include <LibWeb/Bindings/HTMLElementPrototype.h>
#endif


#include <LibWeb/HTML/TextMetrics.h>

#include <LibWeb/HTML/CanvasRenderingContext2D.h>

#include <LibWeb/HTML/HTMLCanvasElement.h>

#include <LibWeb/HTML/ImageData.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/CanvasGradient.h>

#include <LibWeb/HTML/HTMLImageElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLCanvasElement.h>

#if __has_include(<LibWeb/Bindings/HTMLCanvasElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLCanvasElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLCanvasElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLCanvasElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/CanvasRenderingContext2D.h>

#if __has_include(<LibWeb/Bindings/CanvasRenderingContext2DWrapper.h>)
#   include <LibWeb/Bindings/CanvasRenderingContext2DWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CanvasRenderingContext2DWrapperFactory.h>)
#   include <LibWeb/Bindings/CanvasRenderingContext2DWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
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

HTMLCanvasElementPrototype::HTMLCanvasElementPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLElementPrototype>("HTMLElement"))

{
}

HTMLCanvasElementPrototype::~HTMLCanvasElementPrototype()
{
}

void HTMLCanvasElementPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("width", width_getter, width_setter, default_attributes);

    define_native_accessor("height", height_getter, height_setter, default_attributes);

    define_native_function("toDataURL", to_data_url, 0, default_attributes);

    define_native_function("getContext", get_context, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::HTMLCanvasElement*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<HTMLCanvasElementWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::HTMLCanvasElement");

    return &static_cast<HTMLCanvasElementWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLCanvasElementPrototype::width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->width(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLCanvasElementPrototype::width_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    u32 cpp_value;

    cpp_value = TRY(value.to_u32(global_object));

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_width(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLCanvasElementPrototype::height_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->height(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLCanvasElementPrototype::height_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    u32 cpp_value;

    cpp_value = TRY(value.to_u32(global_object));

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_height(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLCanvasElementPrototype::get_context)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getContext");

    auto arg0 = vm.argument(0);

    String context_id;
    if (arg0.is_null() && false) {
        context_id = String::empty();
    } else {
        context_id = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_context(context_id); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<CanvasRenderingContext2D&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(HTMLCanvasElementPrototype::to_data_url)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    String type;
    if (!arg0.is_undefined()) {
        if (arg0.is_null() && false)
            type = String::empty();
        else
            type = TRY(arg0.to_string(global_object));
    } else {
        type = "image/png";
    }

    auto arg1 = vm.argument(1);

    Optional<double> quality;

    if (!arg1.is_undefined())
        quality = TRY(arg1.to_double(global_object));


    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->to_data_url(type, quality); }));

    return JS::js_string(vm, retval);

}

} // namespace Web::Bindings

