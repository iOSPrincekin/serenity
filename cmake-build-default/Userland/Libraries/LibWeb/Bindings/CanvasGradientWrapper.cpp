
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CanvasGradientPrototype.h>
#include <LibWeb/Bindings/CanvasGradientWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/HTML/CanvasGradient.h>

#if __has_include(<LibWeb/Bindings/CanvasGradientWrapper.h>)
#   include <LibWeb/Bindings/CanvasGradientWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CanvasGradientWrapperFactory.h>)
#   include <LibWeb/Bindings/CanvasGradientWrapperFactory.h>
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

CanvasGradientWrapper* CanvasGradientWrapper::create(JS::GlobalObject& global_object, HTML::CanvasGradient& impl)
{
    return global_object.heap().allocate<CanvasGradientWrapper>(global_object, global_object, impl);
}


CanvasGradientWrapper::CanvasGradientWrapper(JS::GlobalObject& global_object, HTML::CanvasGradient& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<CanvasGradientPrototype>("CanvasGradient"))
    , m_impl(impl)
{
}

void CanvasGradientWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "CanvasGradient"), JS::Attribute::Configurable);
}

CanvasGradientWrapper::~CanvasGradientWrapper()
{
}

CanvasGradientWrapper* wrap(JS::GlobalObject& global_object, HTML::CanvasGradient& impl)
{
    return static_cast<CanvasGradientWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

