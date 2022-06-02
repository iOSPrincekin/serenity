
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/SVGAnimatedLengthPrototype.h>
#include <LibWeb/Bindings/SVGAnimatedLengthWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

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
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;

namespace Web::Bindings {

SVGAnimatedLengthWrapper* SVGAnimatedLengthWrapper::create(JS::GlobalObject& global_object, SVG::SVGAnimatedLength& impl)
{
    return global_object.heap().allocate<SVGAnimatedLengthWrapper>(global_object, global_object, impl);
}


SVGAnimatedLengthWrapper::SVGAnimatedLengthWrapper(JS::GlobalObject& global_object, SVG::SVGAnimatedLength& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<SVGAnimatedLengthPrototype>("SVGAnimatedLength"))
    , m_impl(impl)
{
}

void SVGAnimatedLengthWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "SVGAnimatedLength"), JS::Attribute::Configurable);
}

SVGAnimatedLengthWrapper::~SVGAnimatedLengthWrapper()
{
}

SVGAnimatedLengthWrapper* wrap(JS::GlobalObject& global_object, SVG::SVGAnimatedLength& impl)
{
    return static_cast<SVGAnimatedLengthWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

