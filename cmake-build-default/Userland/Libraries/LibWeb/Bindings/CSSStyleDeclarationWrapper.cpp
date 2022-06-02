
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CSSStyleDeclarationPrototype.h>
#include <LibWeb/Bindings/CSSStyleDeclarationWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>
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

CSSStyleDeclarationWrapper* CSSStyleDeclarationWrapper::create(JS::GlobalObject& global_object, CSS::CSSStyleDeclaration& impl)
{
    return global_object.heap().allocate<CSSStyleDeclarationWrapper>(global_object, global_object, impl);
}


CSSStyleDeclarationWrapper::CSSStyleDeclarationWrapper(JS::GlobalObject& global_object, CSS::CSSStyleDeclaration& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<CSSStyleDeclarationPrototype>("CSSStyleDeclaration"))
    , m_impl(impl)
{
}

void CSSStyleDeclarationWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "CSSStyleDeclaration"), JS::Attribute::Configurable);
}

CSSStyleDeclarationWrapper::~CSSStyleDeclarationWrapper()
{
}

CSSStyleDeclarationWrapper* wrap(JS::GlobalObject& global_object, CSS::CSSStyleDeclaration& impl)
{
    return static_cast<CSSStyleDeclarationWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

