
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HistoryPrototype.h>
#include <LibWeb/Bindings/HistoryWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/HTML/History.h>

#if __has_include(<LibWeb/Bindings/HistoryWrapper.h>)
#   include <LibWeb/Bindings/HistoryWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HistoryWrapperFactory.h>)
#   include <LibWeb/Bindings/HistoryWrapperFactory.h>
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

HistoryWrapper* HistoryWrapper::create(JS::GlobalObject& global_object, HTML::History& impl)
{
    return global_object.heap().allocate<HistoryWrapper>(global_object, global_object, impl);
}


HistoryWrapper::HistoryWrapper(JS::GlobalObject& global_object, HTML::History& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<HistoryPrototype>("History"))
    , m_impl(impl)
{
}

void HistoryWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "History"), JS::Attribute::Configurable);
}

HistoryWrapper::~HistoryWrapper()
{
}

HistoryWrapper* wrap(JS::GlobalObject& global_object, HTML::History& impl)
{
    return static_cast<HistoryWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

