
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/IdleDeadlinePrototype.h>
#include <LibWeb/Bindings/IdleDeadlineWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/RequestIdleCallback/IdleDeadline.h>

#if __has_include(<LibWeb/Bindings/IdleDeadlineWrapper.h>)
#   include <LibWeb/Bindings/IdleDeadlineWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/IdleDeadlineWrapperFactory.h>)
#   include <LibWeb/Bindings/IdleDeadlineWrapperFactory.h>
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

IdleDeadlineWrapper* IdleDeadlineWrapper::create(JS::GlobalObject& global_object, RequestIdleCallback::IdleDeadline& impl)
{
    return global_object.heap().allocate<IdleDeadlineWrapper>(global_object, global_object, impl);
}


IdleDeadlineWrapper::IdleDeadlineWrapper(JS::GlobalObject& global_object, RequestIdleCallback::IdleDeadline& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<IdleDeadlinePrototype>("IdleDeadline"))
    , m_impl(impl)
{
}

void IdleDeadlineWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "IdleDeadline"), JS::Attribute::Configurable);
}

IdleDeadlineWrapper::~IdleDeadlineWrapper()
{
}

IdleDeadlineWrapper* wrap(JS::GlobalObject& global_object, RequestIdleCallback::IdleDeadline& impl)
{
    return static_cast<IdleDeadlineWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

