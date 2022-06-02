
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/AbortControllerPrototype.h>
#include <LibWeb/Bindings/AbortControllerWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/DOM/AbortController.h>

#if __has_include(<LibWeb/Bindings/AbortControllerWrapper.h>)
#   include <LibWeb/Bindings/AbortControllerWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortControllerWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortControllerWrapperFactory.h>
#endif

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

AbortControllerWrapper* AbortControllerWrapper::create(JS::GlobalObject& global_object, DOM::AbortController& impl)
{
    return global_object.heap().allocate<AbortControllerWrapper>(global_object, global_object, impl);
}


AbortControllerWrapper::AbortControllerWrapper(JS::GlobalObject& global_object, DOM::AbortController& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<AbortControllerPrototype>("AbortController"))
    , m_impl(impl)
{
}

void AbortControllerWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "AbortController"), JS::Attribute::Configurable);
}

AbortControllerWrapper::~AbortControllerWrapper()
{
}

AbortControllerWrapper* wrap(JS::GlobalObject& global_object, DOM::AbortController& impl)
{
    return static_cast<AbortControllerWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

