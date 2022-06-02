
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/SVGLengthPrototype.h>
#include <LibWeb/Bindings/SVGLengthWrapper.h>
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


#include <LibWeb/SVG/SVGLength.h>

#include <LibWeb/SVG/SVGLength.h>

#if __has_include(<LibWeb/Bindings/SVGLengthWrapper.h>)
#   include <LibWeb/Bindings/SVGLengthWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGLengthWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGLengthWrapperFactory.h>
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

SVGLengthPrototype::SVGLengthPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

SVGLengthPrototype::~SVGLengthPrototype()
{
}

void SVGLengthPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("unitType", unit_type_getter, nullptr, default_attributes);

    define_native_accessor("value", value_getter, value_setter, default_attributes);

    define_direct_property("SVG_LENGTHTYPE_UNKNOWN", JS::Value((i32)0), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_NUMBER", JS::Value((i32)1), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_PERCENTAGE", JS::Value((i32)2), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_EMS", JS::Value((i32)3), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_EXS", JS::Value((i32)4), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_PX", JS::Value((i32)5), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_CM", JS::Value((i32)6), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_MM", JS::Value((i32)7), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_IN", JS::Value((i32)8), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_PT", JS::Value((i32)9), JS::Attribute::Enumerable);

    define_direct_property("SVG_LENGTHTYPE_PC", JS::Value((i32)10), JS::Attribute::Enumerable);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<SVG::SVGLength*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<SVGLengthWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "SVG::SVGLength");

    return &static_cast<SVGLengthWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(SVGLengthPrototype::unit_type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->unit_type(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(SVGLengthPrototype::value_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->value(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(SVGLengthPrototype::value_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    float cpp_value = TRY(value.to_double(global_object));

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_value(cpp_value); }));

    return JS::js_undefined();
}

} // namespace Web::Bindings

