
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSMediaRuleConstructor.h>
#include <LibWeb/Bindings/CSSMediaRulePrototype.h>
#include <LibWeb/Bindings/CSSMediaRuleWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSMediaRule.h>)
#    include <LibWeb/Crypto/CSSMediaRule.h>
#elif __has_include(<LibWeb/CSS/CSSMediaRule.h>)
#    include <LibWeb/CSS/CSSMediaRule.h>
#elif __has_include(<LibWeb/DOM/CSSMediaRule.h>)
#    include <LibWeb/DOM/CSSMediaRule.h>
#elif __has_include(<LibWeb/Encoding/CSSMediaRule.h>)
#    include <LibWeb/Encoding/CSSMediaRule.h>
#elif __has_include(<LibWeb/Geometry/CSSMediaRule.h>)
#    include <LibWeb/Geometry/CSSMediaRule.h>
#elif __has_include(<LibWeb/HTML/CSSMediaRule.h>)
#    include <LibWeb/HTML/CSSMediaRule.h>
#elif __has_include(<LibWeb/UIEvents/CSSMediaRule.h>)
#    include <LibWeb/UIEvents/CSSMediaRule.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSMediaRule.h>)
#    include <LibWeb/HighResolutionTime/CSSMediaRule.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSMediaRule.h>)
#    include <LibWeb/IntersectionObserver/CSSMediaRule.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSMediaRule.h>)
#    include <LibWeb/NavigationTiming/CSSMediaRule.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSMediaRule.h>)
#    include <LibWeb/RequestIdleCallback/CSSMediaRule.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSMediaRule.h>)
#    include <LibWeb/ResizeObserver/CSSMediaRule.h>
#elif __has_include(<LibWeb/SVG/CSSMediaRule.h>)
#    include <LibWeb/SVG/CSSMediaRule.h>
#elif __has_include(<LibWeb/Selection/CSSMediaRule.h>)
#    include <LibWeb/Selection/CSSMediaRule.h>
#elif __has_include(<LibWeb/WebSockets/CSSMediaRule.h>)
#    include <LibWeb/WebSockets/CSSMediaRule.h>
#elif __has_include(<LibWeb/XHR/CSSMediaRule.h>)
#    include <LibWeb/XHR/CSSMediaRule.h>
#elif __has_include(<LibWeb/URL/CSSMediaRule.h>)
#    include <LibWeb/URL/CSSMediaRule.h>
#endif


#include <LibWeb/CSS/MediaList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSGroupingRule.h>

#include <LibWeb/CSS/CSSConditionRule.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSMediaRule.h>

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
using namespace Web::UIEvents;
using namespace Web::XHR;

namespace Web::Bindings {

CSSMediaRuleConstructor::CSSMediaRuleConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSMediaRuleConstructor::~CSSMediaRuleConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSMediaRuleConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSMediaRule");
}

JS::ThrowCompletionOr<JS::Object*> CSSMediaRuleConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSMediaRule");

}

void CSSMediaRuleConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSMediaRulePrototype>("CSSMediaRule"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

