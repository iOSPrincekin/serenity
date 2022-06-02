
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSStyleRuleConstructor.h>
#include <LibWeb/Bindings/CSSStyleRulePrototype.h>
#include <LibWeb/Bindings/CSSStyleRuleWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSStyleRule.h>)
#    include <LibWeb/Crypto/CSSStyleRule.h>
#elif __has_include(<LibWeb/CSS/CSSStyleRule.h>)
#    include <LibWeb/CSS/CSSStyleRule.h>
#elif __has_include(<LibWeb/DOM/CSSStyleRule.h>)
#    include <LibWeb/DOM/CSSStyleRule.h>
#elif __has_include(<LibWeb/Encoding/CSSStyleRule.h>)
#    include <LibWeb/Encoding/CSSStyleRule.h>
#elif __has_include(<LibWeb/Geometry/CSSStyleRule.h>)
#    include <LibWeb/Geometry/CSSStyleRule.h>
#elif __has_include(<LibWeb/HTML/CSSStyleRule.h>)
#    include <LibWeb/HTML/CSSStyleRule.h>
#elif __has_include(<LibWeb/UIEvents/CSSStyleRule.h>)
#    include <LibWeb/UIEvents/CSSStyleRule.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSStyleRule.h>)
#    include <LibWeb/HighResolutionTime/CSSStyleRule.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSStyleRule.h>)
#    include <LibWeb/IntersectionObserver/CSSStyleRule.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSStyleRule.h>)
#    include <LibWeb/NavigationTiming/CSSStyleRule.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSStyleRule.h>)
#    include <LibWeb/RequestIdleCallback/CSSStyleRule.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSStyleRule.h>)
#    include <LibWeb/ResizeObserver/CSSStyleRule.h>
#elif __has_include(<LibWeb/SVG/CSSStyleRule.h>)
#    include <LibWeb/SVG/CSSStyleRule.h>
#elif __has_include(<LibWeb/Selection/CSSStyleRule.h>)
#    include <LibWeb/Selection/CSSStyleRule.h>
#elif __has_include(<LibWeb/WebSockets/CSSStyleRule.h>)
#    include <LibWeb/WebSockets/CSSStyleRule.h>
#elif __has_include(<LibWeb/XHR/CSSStyleRule.h>)
#    include <LibWeb/XHR/CSSStyleRule.h>
#elif __has_include(<LibWeb/URL/CSSStyleRule.h>)
#    include <LibWeb/URL/CSSStyleRule.h>
#endif


#include <LibWeb/CSS/CSSStyleRule.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleRule.h>

#if __has_include(<LibWeb/Bindings/CSSStyleRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleRuleWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSRule.h>

#if __has_include(<LibWeb/Bindings/CSSRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSStyleSheet.h>

#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>
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
using namespace Web::UIEvents;
using namespace Web::XHR;

namespace Web::Bindings {

CSSStyleRuleConstructor::CSSStyleRuleConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSStyleRuleConstructor::~CSSStyleRuleConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSStyleRuleConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSStyleRule");
}

JS::ThrowCompletionOr<JS::Object*> CSSStyleRuleConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSStyleRule");

}

void CSSStyleRuleConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSStyleRulePrototype>("CSSStyleRule"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

