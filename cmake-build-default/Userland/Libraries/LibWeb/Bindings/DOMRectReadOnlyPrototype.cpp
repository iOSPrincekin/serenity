
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DOMRectReadOnlyPrototype.h>
#include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
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


#include <LibWeb/Geometry/DOMRectReadOnly.h>

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

DOMRectReadOnlyPrototype::DOMRectReadOnlyPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

DOMRectReadOnlyPrototype::~DOMRectReadOnlyPrototype()
{
}

void DOMRectReadOnlyPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("x", x_getter, nullptr, default_attributes);

    define_native_accessor("y", y_getter, nullptr, default_attributes);

    define_native_accessor("width", width_getter, nullptr, default_attributes);

    define_native_accessor("height", height_getter, nullptr, default_attributes);

    define_native_accessor("top", top_getter, nullptr, default_attributes);

    define_native_accessor("right", right_getter, nullptr, default_attributes);

    define_native_accessor("bottom", bottom_getter, nullptr, default_attributes);

    define_native_accessor("left", left_getter, nullptr, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<Geometry::DOMRectReadOnly*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<DOMRectReadOnlyWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Geometry::DOMRectReadOnly");

    return &static_cast<DOMRectReadOnlyWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(DOMRectReadOnlyPrototype::x_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->x(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectReadOnlyPrototype::y_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->y(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectReadOnlyPrototype::width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->width(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectReadOnlyPrototype::height_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->height(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectReadOnlyPrototype::top_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->top(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectReadOnlyPrototype::right_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->right(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectReadOnlyPrototype::bottom_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->bottom(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMRectReadOnlyPrototype::left_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->left(); }));

    return JS::Value(retval);

}

} // namespace Web::Bindings

