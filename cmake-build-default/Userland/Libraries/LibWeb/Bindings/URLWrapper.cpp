
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/URLPrototype.h>
#include <LibWeb/Bindings/URLWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/URL/URL.h>

#if __has_include(<LibWeb/Bindings/URLWrapper.h>)
#   include <LibWeb/Bindings/URLWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLWrapperFactory.h>)
#   include <LibWeb/Bindings/URLWrapperFactory.h>
#endif

#include <LibWeb/URL/URLSearchParams.h>

#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapperFactory.h>
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

URLWrapper* URLWrapper::create(JS::GlobalObject& global_object, URL::URL& impl)
{
    return global_object.heap().allocate<URLWrapper>(global_object, global_object, impl);
}


URLWrapper::URLWrapper(JS::GlobalObject& global_object, URL::URL& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<URLPrototype>("URL"))
    , m_impl(impl)
{
}

void URLWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "URL"), JS::Attribute::Configurable);
}

URLWrapper::~URLWrapper()
{
}

URLWrapper* wrap(JS::GlobalObject& global_object, URL::URL& impl)
{
    return static_cast<URLWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

