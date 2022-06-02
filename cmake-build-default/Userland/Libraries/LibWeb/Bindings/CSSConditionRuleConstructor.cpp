
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSConditionRuleConstructor.h>
#include <LibWeb/Bindings/CSSConditionRulePrototype.h>
#include <LibWeb/Bindings/CSSConditionRuleWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSConditionRule.h>)
#    include <LibWeb/Crypto/CSSConditionRule.h>
#elif __has_include(<LibWeb/CSS/CSSConditionRule.h>)
#    include <LibWeb/CSS/CSSConditionRule.h>
#elif __has_include(<LibWeb/DOM/CSSConditionRule.h>)
#    include <LibWeb/DOM/CSSConditionRule.h>
#elif __has_include(<LibWeb/Encoding/CSSConditionRule.h>)
#    include <LibWeb/Encoding/CSSConditionRule.h>
#elif __has_include(<LibWeb/Geometry/CSSConditionRule.h>)
#    include <LibWeb/Geometry/CSSConditionRule.h>
#elif __has_include(<LibWeb/HTML/CSSConditionRule.h>)
#    include <LibWeb/HTML/CSSConditionRule.h>
#elif __has_include(<LibWeb/UIEvents/CSSConditionRule.h>)
#    include <LibWeb/UIEvents/CSSConditionRule.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSConditionRule.h>)
#    include <LibWeb/HighResolutionTime/CSSConditionRule.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSConditionRule.h>)
#    include <LibWeb/IntersectionObserver/CSSConditionRule.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSConditionRule.h>)
#    include <LibWeb/NavigationTiming/CSSConditionRule.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSConditionRule.h>)
#    include <LibWeb/RequestIdleCallback/CSSConditionRule.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSConditionRule.h>)
#    include <LibWeb/ResizeObserver/CSSConditionRule.h>
#elif __has_include(<LibWeb/SVG/CSSConditionRule.h>)
#    include <LibWeb/SVG/CSSConditionRule.h>
#elif __has_include(<LibWeb/Selection/CSSConditionRule.h>)
#    include <LibWeb/Selection/CSSConditionRule.h>
#elif __has_include(<LibWeb/WebSockets/CSSConditionRule.h>)
#    include <LibWeb/WebSockets/CSSConditionRule.h>
#elif __has_include(<LibWeb/XHR/CSSConditionRule.h>)
#    include <LibWeb/XHR/CSSConditionRule.h>
#elif __has_include(<LibWeb/URL/CSSConditionRule.h>)
#    include <LibWeb/URL/CSSConditionRule.h>
#endif


#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSGroupingRule.h>

#include <LibWeb/CSS/CSSConditionRule.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSConditionRule.h>

#if __has_include(<LibWeb/Bindings/CSSConditionRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSConditionRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSConditionRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSConditionRuleWrapperFactory.h>
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
using namespace Web::UIEvents;
using namespace Web::XHR;

namespace Web::Bindings {

CSSConditionRuleConstructor::CSSConditionRuleConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSConditionRuleConstructor::~CSSConditionRuleConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSConditionRuleConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSConditionRule");
}

JS::ThrowCompletionOr<JS::Object*> CSSConditionRuleConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSConditionRule");

}

void CSSConditionRuleConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSConditionRulePrototype>("CSSConditionRule"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

