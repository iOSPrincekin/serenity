
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSGroupingRuleConstructor.h>
#include <LibWeb/Bindings/CSSGroupingRulePrototype.h>
#include <LibWeb/Bindings/CSSGroupingRuleWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSGroupingRule.h>)
#    include <LibWeb/Crypto/CSSGroupingRule.h>
#elif __has_include(<LibWeb/CSS/CSSGroupingRule.h>)
#    include <LibWeb/CSS/CSSGroupingRule.h>
#elif __has_include(<LibWeb/DOM/CSSGroupingRule.h>)
#    include <LibWeb/DOM/CSSGroupingRule.h>
#elif __has_include(<LibWeb/Encoding/CSSGroupingRule.h>)
#    include <LibWeb/Encoding/CSSGroupingRule.h>
#elif __has_include(<LibWeb/Geometry/CSSGroupingRule.h>)
#    include <LibWeb/Geometry/CSSGroupingRule.h>
#elif __has_include(<LibWeb/HTML/CSSGroupingRule.h>)
#    include <LibWeb/HTML/CSSGroupingRule.h>
#elif __has_include(<LibWeb/UIEvents/CSSGroupingRule.h>)
#    include <LibWeb/UIEvents/CSSGroupingRule.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSGroupingRule.h>)
#    include <LibWeb/HighResolutionTime/CSSGroupingRule.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSGroupingRule.h>)
#    include <LibWeb/IntersectionObserver/CSSGroupingRule.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSGroupingRule.h>)
#    include <LibWeb/NavigationTiming/CSSGroupingRule.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSGroupingRule.h>)
#    include <LibWeb/RequestIdleCallback/CSSGroupingRule.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSGroupingRule.h>)
#    include <LibWeb/ResizeObserver/CSSGroupingRule.h>
#elif __has_include(<LibWeb/SVG/CSSGroupingRule.h>)
#    include <LibWeb/SVG/CSSGroupingRule.h>
#elif __has_include(<LibWeb/Selection/CSSGroupingRule.h>)
#    include <LibWeb/Selection/CSSGroupingRule.h>
#elif __has_include(<LibWeb/WebSockets/CSSGroupingRule.h>)
#    include <LibWeb/WebSockets/CSSGroupingRule.h>
#elif __has_include(<LibWeb/XHR/CSSGroupingRule.h>)
#    include <LibWeb/XHR/CSSGroupingRule.h>
#elif __has_include(<LibWeb/URL/CSSGroupingRule.h>)
#    include <LibWeb/URL/CSSGroupingRule.h>
#endif


#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSGroupingRule.h>

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

CSSGroupingRuleConstructor::CSSGroupingRuleConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSGroupingRuleConstructor::~CSSGroupingRuleConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSGroupingRuleConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSGroupingRule");
}

JS::ThrowCompletionOr<JS::Object*> CSSGroupingRuleConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSGroupingRule");

}

void CSSGroupingRuleConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSGroupingRulePrototype>("CSSGroupingRule"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

