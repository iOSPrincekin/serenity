
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/SVGAnimatedLengthPrototype.h>
#include <LibWeb/Bindings/SVGAnimatedLengthWrapper.h>
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

#include <LibWeb/SVG/SVGAnimatedLength.h>

#include <LibWeb/SVG/SVGAnimatedLength.h>

#if __has_include(<LibWeb/Bindings/SVGAnimatedLengthWrapper.h>)
#   include <LibWeb/Bindings/SVGAnimatedLengthWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGAnimatedLengthWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGAnimatedLengthWrapperFactory.h>
#endif

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

SVGAnimatedLengthPrototype::SVGAnimatedLengthPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

SVGAnimatedLengthPrototype::~SVGAnimatedLengthPrototype()
{
}

void SVGAnimatedLengthPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("baseVal", base_val_getter, nullptr, default_attributes);

    define_native_accessor("animVal", anim_val_getter, nullptr, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<SVG::SVGAnimatedLength*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<SVGAnimatedLengthWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "SVG::SVGAnimatedLength");

    return &static_cast<SVGAnimatedLengthWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(SVGAnimatedLengthPrototype::base_val_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->base_val(); }));

    return wrap(global_object, const_cast<SVGLength&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(SVGAnimatedLengthPrototype::anim_val_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->anim_val(); }));

    return wrap(global_object, const_cast<SVGLength&>(*retval));

}

} // namespace Web::Bindings

