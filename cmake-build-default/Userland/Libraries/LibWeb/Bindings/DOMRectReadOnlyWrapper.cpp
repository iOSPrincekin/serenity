
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DOMRectReadOnlyPrototype.h>
#include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapper.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>
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

DOMRectReadOnlyWrapper* DOMRectReadOnlyWrapper::create(JS::GlobalObject& global_object, Geometry::DOMRectReadOnly& impl)
{
    return global_object.heap().allocate<DOMRectReadOnlyWrapper>(global_object, global_object, impl);
}


DOMRectReadOnlyWrapper::DOMRectReadOnlyWrapper(JS::GlobalObject& global_object, Geometry::DOMRectReadOnly& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<DOMRectReadOnlyPrototype>("DOMRectReadOnly"))
    , m_impl(impl)
{
}

void DOMRectReadOnlyWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "DOMRectReadOnly"), JS::Attribute::Configurable);
}

DOMRectReadOnlyWrapper::~DOMRectReadOnlyWrapper()
{
}

DOMRectReadOnlyWrapper* wrap(JS::GlobalObject& global_object, Geometry::DOMRectReadOnly& impl)
{
    return static_cast<DOMRectReadOnlyWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

