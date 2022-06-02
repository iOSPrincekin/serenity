
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/ScreenPrototype.h>
#include <LibWeb/Bindings/ScreenWrapper.h>
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


#include <LibWeb/CSS/Screen.h>

#include <LibWeb/CSS/Screen.h>

#if __has_include(<LibWeb/Bindings/ScreenWrapper.h>)
#   include <LibWeb/Bindings/ScreenWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ScreenWrapperFactory.h>)
#   include <LibWeb/Bindings/ScreenWrapperFactory.h>
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

ScreenPrototype::ScreenPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

ScreenPrototype::~ScreenPrototype()
{
}

void ScreenPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("availWidth", avail_width_getter, nullptr, default_attributes);

    define_native_accessor("availHeight", avail_height_getter, nullptr, default_attributes);

    define_native_accessor("width", width_getter, nullptr, default_attributes);

    define_native_accessor("height", height_getter, nullptr, default_attributes);

    define_native_accessor("colorDepth", color_depth_getter, nullptr, default_attributes);

    define_native_accessor("pixelDepth", pixel_depth_getter, nullptr, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<CSS::Screen*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<ScreenWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "CSS::Screen");

    return &static_cast<ScreenWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(ScreenPrototype::avail_width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->avail_width(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ScreenPrototype::avail_height_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->avail_height(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ScreenPrototype::width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->width(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ScreenPrototype::height_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->height(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ScreenPrototype::color_depth_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->color_depth(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ScreenPrototype::pixel_depth_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->pixel_depth(); }));

    return JS::Value((u32)retval);

}

} // namespace Web::Bindings

