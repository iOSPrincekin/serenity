
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CSSMediaRulePrototype.h>
#include <LibWeb/Bindings/CSSMediaRuleWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/CSS/CSSMediaRule.h>

#if __has_include(<LibWeb/Bindings/CSSMediaRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSMediaRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSMediaRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSMediaRuleWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSConditionRule.h>

#if __has_include(<LibWeb/Bindings/CSSConditionRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSConditionRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSConditionRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSConditionRuleWrapperFactory.h>
#endif

#include <LibWeb/CSS/MediaList.h>

#if __has_include(<LibWeb/Bindings/MediaListWrapper.h>)
#   include <LibWeb/Bindings/MediaListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MediaListWrapperFactory.h>)
#   include <LibWeb/Bindings/MediaListWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSGroupingRule.h>

#if __has_include(<LibWeb/Bindings/CSSGroupingRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSGroupingRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSGroupingRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSGroupingRuleWrapperFactory.h>
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

#include <LibWeb/CSS/CSSStyleSheet.h>

#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>
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

CSSMediaRuleWrapper* CSSMediaRuleWrapper::create(JS::GlobalObject& global_object, CSS::CSSMediaRule& impl)
{
    return global_object.heap().allocate<CSSMediaRuleWrapper>(global_object, global_object, impl);
}


CSSMediaRuleWrapper::CSSMediaRuleWrapper(JS::GlobalObject& global_object, CSS::CSSMediaRule& impl)
    : CSSConditionRuleWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<CSSMediaRulePrototype>("CSSMediaRule"));
}

void CSSMediaRuleWrapper::initialize(JS::GlobalObject& global_object)
{
    CSSConditionRuleWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "CSSMediaRule"), JS::Attribute::Configurable);
}

CSSMediaRuleWrapper::~CSSMediaRuleWrapper()
{
}

} // namespace Web::Bindings

