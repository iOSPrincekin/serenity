
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/PerformanceTimingPrototype.h>
#include <LibWeb/Bindings/PerformanceTimingWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapper.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapperFactory.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapperFactory.h>
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

PerformanceTimingWrapper* PerformanceTimingWrapper::create(JS::GlobalObject& global_object, NavigationTiming::PerformanceTiming& impl)
{
    return global_object.heap().allocate<PerformanceTimingWrapper>(global_object, global_object, impl);
}


PerformanceTimingWrapper::PerformanceTimingWrapper(JS::GlobalObject& global_object, NavigationTiming::PerformanceTiming& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<PerformanceTimingPrototype>("PerformanceTiming"))
    , m_impl(impl)
{
}

void PerformanceTimingWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "PerformanceTiming"), JS::Attribute::Configurable);
}

PerformanceTimingWrapper::~PerformanceTimingWrapper()
{
}

PerformanceTimingWrapper* wrap(JS::GlobalObject& global_object, NavigationTiming::PerformanceTiming& impl)
{
    return static_cast<PerformanceTimingWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

