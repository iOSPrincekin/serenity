
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/TextMetricsPrototype.h>
#include <LibWeb/Bindings/TextMetricsWrapper.h>
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

#include <LibWeb/HTML/TextMetrics.h>

#if __has_include(<LibWeb/Bindings/TextMetricsWrapper.h>)
#   include <LibWeb/Bindings/TextMetricsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TextMetricsWrapperFactory.h>)
#   include <LibWeb/Bindings/TextMetricsWrapperFactory.h>
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

TextMetricsPrototype::TextMetricsPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

TextMetricsPrototype::~TextMetricsPrototype()
{
}

void TextMetricsPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("width", width_getter, nullptr, default_attributes);

    define_native_accessor("actualBoundingBoxLeft", actual_bounding_box_left_getter, nullptr, default_attributes);

    define_native_accessor("actualBoundingBoxRight", actual_bounding_box_right_getter, nullptr, default_attributes);

    define_native_accessor("fontBoundingBoxAscent", font_bounding_box_ascent_getter, nullptr, default_attributes);

    define_native_accessor("fontBoundingBoxDescent", font_bounding_box_descent_getter, nullptr, default_attributes);

    define_native_accessor("actualBoundingBoxAscent", actual_bounding_box_ascent_getter, nullptr, default_attributes);

    define_native_accessor("actualBoundingBoxDescent", actual_bounding_box_descent_getter, nullptr, default_attributes);

    define_native_accessor("emHeightAscent", em_height_ascent_getter, nullptr, default_attributes);

    define_native_accessor("emHeightDescent", em_height_descent_getter, nullptr, default_attributes);

    define_native_accessor("hangingBaseline", hanging_baseline_getter, nullptr, default_attributes);

    define_native_accessor("alphabeticBaseline", alphabetic_baseline_getter, nullptr, default_attributes);

    define_native_accessor("ideographicBaseline", ideographic_baseline_getter, nullptr, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::TextMetrics*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<TextMetricsWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::TextMetrics");

    return &static_cast<TextMetricsWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->width(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::actual_bounding_box_left_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->actual_bounding_box_left(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::actual_bounding_box_right_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->actual_bounding_box_right(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::font_bounding_box_ascent_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->font_bounding_box_ascent(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::font_bounding_box_descent_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->font_bounding_box_descent(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::actual_bounding_box_ascent_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->actual_bounding_box_ascent(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::actual_bounding_box_descent_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->actual_bounding_box_descent(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::em_height_ascent_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->em_height_ascent(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::em_height_descent_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->em_height_descent(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::hanging_baseline_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->hanging_baseline(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::alphabetic_baseline_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->alphabetic_baseline(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextMetricsPrototype::ideographic_baseline_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ideographic_baseline(); }));

    return JS::Value(retval);

}

} // namespace Web::Bindings

