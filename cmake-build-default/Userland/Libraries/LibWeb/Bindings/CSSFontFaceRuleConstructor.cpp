
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSFontFaceRuleConstructor.h>
#include <LibWeb/Bindings/CSSFontFaceRulePrototype.h>
#include <LibWeb/Bindings/CSSFontFaceRuleWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSFontFaceRule.h>)
#    include <LibWeb/Crypto/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/CSS/CSSFontFaceRule.h>)
#    include <LibWeb/CSS/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/DOM/CSSFontFaceRule.h>)
#    include <LibWeb/DOM/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/Encoding/CSSFontFaceRule.h>)
#    include <LibWeb/Encoding/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/Geometry/CSSFontFaceRule.h>)
#    include <LibWeb/Geometry/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/HTML/CSSFontFaceRule.h>)
#    include <LibWeb/HTML/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/UIEvents/CSSFontFaceRule.h>)
#    include <LibWeb/UIEvents/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSFontFaceRule.h>)
#    include <LibWeb/HighResolutionTime/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSFontFaceRule.h>)
#    include <LibWeb/IntersectionObserver/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSFontFaceRule.h>)
#    include <LibWeb/NavigationTiming/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSFontFaceRule.h>)
#    include <LibWeb/RequestIdleCallback/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSFontFaceRule.h>)
#    include <LibWeb/ResizeObserver/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/SVG/CSSFontFaceRule.h>)
#    include <LibWeb/SVG/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/Selection/CSSFontFaceRule.h>)
#    include <LibWeb/Selection/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/WebSockets/CSSFontFaceRule.h>)
#    include <LibWeb/WebSockets/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/XHR/CSSFontFaceRule.h>)
#    include <LibWeb/XHR/CSSFontFaceRule.h>
#elif __has_include(<LibWeb/URL/CSSFontFaceRule.h>)
#    include <LibWeb/URL/CSSFontFaceRule.h>
#endif


#include <LibWeb/CSS/CSSFontFaceRule.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSFontFaceRule.h>

#if __has_include(<LibWeb/Bindings/CSSFontFaceRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSFontFaceRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSFontFaceRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSFontFaceRuleWrapperFactory.h>
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

CSSFontFaceRuleConstructor::CSSFontFaceRuleConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSFontFaceRuleConstructor::~CSSFontFaceRuleConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSFontFaceRuleConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSFontFaceRule");
}

JS::ThrowCompletionOr<JS::Object*> CSSFontFaceRuleConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSFontFaceRule");

}

void CSSFontFaceRuleConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSFontFaceRulePrototype>("CSSFontFaceRule"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

