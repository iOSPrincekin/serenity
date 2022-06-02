
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/AbstractRangePrototype.h>
#include <LibWeb/Bindings/AbstractRangeWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/DOM/AbstractRange.h>

#if __has_include(<LibWeb/Bindings/AbstractRangeWrapper.h>)
#   include <LibWeb/Bindings/AbstractRangeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbstractRangeWrapperFactory.h>)
#   include <LibWeb/Bindings/AbstractRangeWrapperFactory.h>
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

AbstractRangeWrapper* AbstractRangeWrapper::create(JS::GlobalObject& global_object, DOM::AbstractRange& impl)
{
    return global_object.heap().allocate<AbstractRangeWrapper>(global_object, global_object, impl);
}


AbstractRangeWrapper::AbstractRangeWrapper(JS::GlobalObject& global_object, DOM::AbstractRange& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<AbstractRangePrototype>("AbstractRange"))
    , m_impl(impl)
{
}

void AbstractRangeWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "AbstractRange"), JS::Attribute::Configurable);
}

AbstractRangeWrapper::~AbstractRangeWrapper()
{
}

AbstractRangeWrapper* wrap(JS::GlobalObject& global_object, DOM::AbstractRange& impl)
{
    return static_cast<AbstractRangeWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

