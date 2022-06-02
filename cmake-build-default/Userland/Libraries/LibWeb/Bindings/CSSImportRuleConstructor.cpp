
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSImportRuleConstructor.h>
#include <LibWeb/Bindings/CSSImportRulePrototype.h>
#include <LibWeb/Bindings/CSSImportRuleWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSImportRule.h>)
#    include <LibWeb/Crypto/CSSImportRule.h>
#elif __has_include(<LibWeb/CSS/CSSImportRule.h>)
#    include <LibWeb/CSS/CSSImportRule.h>
#elif __has_include(<LibWeb/DOM/CSSImportRule.h>)
#    include <LibWeb/DOM/CSSImportRule.h>
#elif __has_include(<LibWeb/Encoding/CSSImportRule.h>)
#    include <LibWeb/Encoding/CSSImportRule.h>
#elif __has_include(<LibWeb/Geometry/CSSImportRule.h>)
#    include <LibWeb/Geometry/CSSImportRule.h>
#elif __has_include(<LibWeb/HTML/CSSImportRule.h>)
#    include <LibWeb/HTML/CSSImportRule.h>
#elif __has_include(<LibWeb/UIEvents/CSSImportRule.h>)
#    include <LibWeb/UIEvents/CSSImportRule.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSImportRule.h>)
#    include <LibWeb/HighResolutionTime/CSSImportRule.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSImportRule.h>)
#    include <LibWeb/IntersectionObserver/CSSImportRule.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSImportRule.h>)
#    include <LibWeb/NavigationTiming/CSSImportRule.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSImportRule.h>)
#    include <LibWeb/RequestIdleCallback/CSSImportRule.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSImportRule.h>)
#    include <LibWeb/ResizeObserver/CSSImportRule.h>
#elif __has_include(<LibWeb/SVG/CSSImportRule.h>)
#    include <LibWeb/SVG/CSSImportRule.h>
#elif __has_include(<LibWeb/Selection/CSSImportRule.h>)
#    include <LibWeb/Selection/CSSImportRule.h>
#elif __has_include(<LibWeb/WebSockets/CSSImportRule.h>)
#    include <LibWeb/WebSockets/CSSImportRule.h>
#elif __has_include(<LibWeb/XHR/CSSImportRule.h>)
#    include <LibWeb/XHR/CSSImportRule.h>
#elif __has_include(<LibWeb/URL/CSSImportRule.h>)
#    include <LibWeb/URL/CSSImportRule.h>
#endif


#include <LibWeb/CSS/MediaList.h>

#include <LibWeb/CSS/CSSImportRule.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSImportRule.h>

#if __has_include(<LibWeb/Bindings/CSSImportRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSImportRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSImportRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSImportRuleWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSRule.h>

#if __has_include(<LibWeb/Bindings/CSSRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSStyleSheet.h>

#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>
#endif

#include <LibWeb/CSS/MediaList.h>

#if __has_include(<LibWeb/Bindings/MediaListWrapper.h>)
#   include <LibWeb/Bindings/MediaListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MediaListWrapperFactory.h>)
#   include <LibWeb/Bindings/MediaListWrapperFactory.h>
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

CSSImportRuleConstructor::CSSImportRuleConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSImportRuleConstructor::~CSSImportRuleConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSImportRuleConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSImportRule");
}

JS::ThrowCompletionOr<JS::Object*> CSSImportRuleConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSImportRule");

}

void CSSImportRuleConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSImportRulePrototype>("CSSImportRule"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

