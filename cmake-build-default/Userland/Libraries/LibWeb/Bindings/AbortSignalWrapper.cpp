
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/AbortSignalPrototype.h>
#include <LibWeb/Bindings/AbortSignalWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
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

AbortSignalWrapper* AbortSignalWrapper::create(JS::GlobalObject& global_object, DOM::AbortSignal& impl)
{
    return global_object.heap().allocate<AbortSignalWrapper>(global_object, global_object, impl);
}


AbortSignalWrapper::AbortSignalWrapper(JS::GlobalObject& global_object, DOM::AbortSignal& impl)
    : EventTargetWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<AbortSignalPrototype>("AbortSignal"));
}

void AbortSignalWrapper::initialize(JS::GlobalObject& global_object)
{
    EventTargetWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "AbortSignal"), JS::Attribute::Configurable);
}

AbortSignalWrapper::~AbortSignalWrapper()
{
}

AbortSignalWrapper* wrap(JS::GlobalObject& global_object, DOM::AbortSignal& impl)
{
    return static_cast<AbortSignalWrapper*>(wrap_impl(global_object, impl));
}

void AbortSignalWrapper::visit_edges(JS::Cell::Visitor& visitor)
{
    EventTargetWrapper::visit_edges(visitor);
    impl().visit_edges(visitor);
}

} // namespace Web::Bindings

