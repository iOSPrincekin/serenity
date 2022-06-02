
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/URLSearchParamsIteratorPrototype.h>
#include <LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>
#include <LibWeb/Bindings/IDLAbstractOperations.h>
#include <LibWeb/Bindings/WindowObject.h>


#include <LibWeb/URL/URLSearchParams.h>

#include <LibWeb/URL/URLSearchParams.h>

//#if __has_include(<LibWeb/URL/URLSearchParamsIterator.h>)
#   include <LibWeb/URL/URLSearchParamsIterator.h>
//#endif
#if __has_include(<LibWeb/URL/URLSearchParamsIteratorFactory.h>)
#   include <LibWeb/URL/URLSearchParamsIteratorFactory.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsIteratorWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsIteratorWrapperFactory.h>
#endif

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

URLSearchParamsIteratorWrapper* URLSearchParamsIteratorWrapper::create(JS::GlobalObject& global_object, URL::URLSearchParamsIterator& impl)
{
    return global_object.heap().allocate<URLSearchParamsIteratorWrapper>(global_object, global_object, impl);
}

URLSearchParamsIteratorWrapper::URLSearchParamsIteratorWrapper(JS::GlobalObject& global_object, URL::URLSearchParamsIterator& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<URLSearchParamsIteratorPrototype>("URLSearchParamsIterator"))
    , m_impl(impl)
{
}

void URLSearchParamsIteratorWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);
}

URLSearchParamsIteratorWrapper::~URLSearchParamsIteratorWrapper()
{
}

void URLSearchParamsIteratorWrapper::visit_edges(Cell::Visitor& visitor)
{
    Wrapper::visit_edges(visitor);
    impl().visit_edges(visitor);
}

URLSearchParamsIteratorWrapper* wrap(JS::GlobalObject& global_object, URL::URLSearchParamsIterator& impl)
{
    return static_cast<URLSearchParamsIteratorWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

