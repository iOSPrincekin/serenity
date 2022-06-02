
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSSupportsRuleConstructor.h>
#include <LibWeb/Bindings/CSSSupportsRulePrototype.h>
#include <LibWeb/Bindings/CSSSupportsRuleWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSSupportsRule.h>)
#    include <LibWeb/Crypto/CSSSupportsRule.h>
#elif __has_include(<LibWeb/CSS/CSSSupportsRule.h>)
#    include <LibWeb/CSS/CSSSupportsRule.h>
#elif __has_include(<LibWeb/DOM/CSSSupportsRule.h>)
#    include <LibWeb/DOM/CSSSupportsRule.h>
#elif __has_include(<LibWeb/Encoding/CSSSupportsRule.h>)
#    include <LibWeb/Encoding/CSSSupportsRule.h>
#elif __has_include(<LibWeb/Geometry/CSSSupportsRule.h>)
#    include <LibWeb/Geometry/CSSSupportsRule.h>
#elif __has_include(<LibWeb/HTML/CSSSupportsRule.h>)
#    include <LibWeb/HTML/CSSSupportsRule.h>
#elif __has_include(<LibWeb/UIEvents/CSSSupportsRule.h>)
#    include <LibWeb/UIEvents/CSSSupportsRule.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSSupportsRule.h>)
#    include <LibWeb/HighResolutionTime/CSSSupportsRule.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSSupportsRule.h>)
#    include <LibWeb/IntersectionObserver/CSSSupportsRule.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSSupportsRule.h>)
#    include <LibWeb/NavigationTiming/CSSSupportsRule.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSSupportsRule.h>)
#    include <LibWeb/RequestIdleCallback/CSSSupportsRule.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSSupportsRule.h>)
#    include <LibWeb/ResizeObserver/CSSSupportsRule.h>
#elif __has_include(<LibWeb/SVG/CSSSupportsRule.h>)
#    include <LibWeb/SVG/CSSSupportsRule.h>
#elif __has_include(<LibWeb/Selection/CSSSupportsRule.h>)
#    include <LibWeb/Selection/CSSSupportsRule.h>
#elif __has_include(<LibWeb/WebSockets/CSSSupportsRule.h>)
#    include <LibWeb/WebSockets/CSSSupportsRule.h>
#elif __has_include(<LibWeb/XHR/CSSSupportsRule.h>)
#    include <LibWeb/XHR/CSSSupportsRule.h>
#elif __has_include(<LibWeb/URL/CSSSupportsRule.h>)
#    include <LibWeb/URL/CSSSupportsRule.h>
#endif


#include <LibWeb/CSS/CSSSupportsRule.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSGroupingRule.h>

#include <LibWeb/CSS/CSSConditionRule.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSSupportsRule.h>

#if __has_include(<LibWeb/Bindings/CSSSupportsRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSSupportsRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSSupportsRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSSupportsRuleWrapperFactory.h>
#endif

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

CSSSupportsRuleConstructor::CSSSupportsRuleConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSSupportsRuleConstructor::~CSSSupportsRuleConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSSupportsRuleConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSSupportsRule");
}

JS::ThrowCompletionOr<JS::Object*> CSSSupportsRuleConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSSupportsRule");

}

void CSSSupportsRuleConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSSupportsRulePrototype>("CSSSupportsRule"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

