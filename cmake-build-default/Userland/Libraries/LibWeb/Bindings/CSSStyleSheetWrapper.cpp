
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CSSStyleSheetPrototype.h>
#include <LibWeb/Bindings/CSSStyleSheetWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSRule.h>

#if __has_include(<LibWeb/Bindings/CSSRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSRuleList.h>

#if __has_include(<LibWeb/Bindings/CSSRuleListWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleListWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleListWrapperFactory.h>
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

CSSStyleSheetWrapper* CSSStyleSheetWrapper::create(JS::GlobalObject& global_object, CSS::CSSStyleSheet& impl)
{
    return global_object.heap().allocate<CSSStyleSheetWrapper>(global_object, global_object, impl);
}


CSSStyleSheetWrapper::CSSStyleSheetWrapper(JS::GlobalObject& global_object, CSS::CSSStyleSheet& impl)
    : StyleSheetWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<CSSStyleSheetPrototype>("CSSStyleSheet"));
}

void CSSStyleSheetWrapper::initialize(JS::GlobalObject& global_object)
{
    StyleSheetWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "CSSStyleSheet"), JS::Attribute::Configurable);
}

CSSStyleSheetWrapper::~CSSStyleSheetWrapper()
{
}

CSSStyleSheetWrapper* wrap(JS::GlobalObject& global_object, CSS::CSSStyleSheet& impl)
{
    return static_cast<CSSStyleSheetWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

