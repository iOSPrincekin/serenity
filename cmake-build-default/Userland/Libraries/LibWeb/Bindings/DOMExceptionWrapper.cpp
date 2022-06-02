
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DOMExceptionPrototype.h>
#include <LibWeb/Bindings/DOMExceptionWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/DOM/DOMException.h>

#if __has_include(<LibWeb/Bindings/DOMExceptionWrapper.h>)
#   include <LibWeb/Bindings/DOMExceptionWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMExceptionWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMExceptionWrapperFactory.h>
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

DOMExceptionWrapper* DOMExceptionWrapper::create(JS::GlobalObject& global_object, DOM::DOMException& impl)
{
    return global_object.heap().allocate<DOMExceptionWrapper>(global_object, global_object, impl);
}


DOMExceptionWrapper::DOMExceptionWrapper(JS::GlobalObject& global_object, DOM::DOMException& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<DOMExceptionPrototype>("DOMException"))
    , m_impl(impl)
{
}

void DOMExceptionWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "DOMException"), JS::Attribute::Configurable);
}

DOMExceptionWrapper::~DOMExceptionWrapper()
{
}

DOMExceptionWrapper* wrap(JS::GlobalObject& global_object, DOM::DOMException& impl)
{
    return static_cast<DOMExceptionWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

