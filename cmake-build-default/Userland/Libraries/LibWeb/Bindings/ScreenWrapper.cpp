
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/ScreenPrototype.h>
#include <LibWeb/Bindings/ScreenWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/CSS/Screen.h>

#if __has_include(<LibWeb/Bindings/ScreenWrapper.h>)
#   include <LibWeb/Bindings/ScreenWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ScreenWrapperFactory.h>)
#   include <LibWeb/Bindings/ScreenWrapperFactory.h>
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

ScreenWrapper* ScreenWrapper::create(JS::GlobalObject& global_object, CSS::Screen& impl)
{
    return global_object.heap().allocate<ScreenWrapper>(global_object, global_object, impl);
}


ScreenWrapper::ScreenWrapper(JS::GlobalObject& global_object, CSS::Screen& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<ScreenPrototype>("Screen"))
    , m_impl(impl)
{
}

void ScreenWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "Screen"), JS::Attribute::Configurable);
}

ScreenWrapper::~ScreenWrapper()
{
}

ScreenWrapper* wrap(JS::GlobalObject& global_object, CSS::Screen& impl)
{
    return static_cast<ScreenWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

