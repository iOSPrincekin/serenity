
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSStyleSheetConstructor.h>
#include <LibWeb/Bindings/CSSStyleSheetPrototype.h>
#include <LibWeb/Bindings/CSSStyleSheetWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSStyleSheet.h>)
#    include <LibWeb/Crypto/CSSStyleSheet.h>
#elif __has_include(<LibWeb/CSS/CSSStyleSheet.h>)
#    include <LibWeb/CSS/CSSStyleSheet.h>
#elif __has_include(<LibWeb/DOM/CSSStyleSheet.h>)
#    include <LibWeb/DOM/CSSStyleSheet.h>
#elif __has_include(<LibWeb/Encoding/CSSStyleSheet.h>)
#    include <LibWeb/Encoding/CSSStyleSheet.h>
#elif __has_include(<LibWeb/Geometry/CSSStyleSheet.h>)
#    include <LibWeb/Geometry/CSSStyleSheet.h>
#elif __has_include(<LibWeb/HTML/CSSStyleSheet.h>)
#    include <LibWeb/HTML/CSSStyleSheet.h>
#elif __has_include(<LibWeb/UIEvents/CSSStyleSheet.h>)
#    include <LibWeb/UIEvents/CSSStyleSheet.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSStyleSheet.h>)
#    include <LibWeb/HighResolutionTime/CSSStyleSheet.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSStyleSheet.h>)
#    include <LibWeb/IntersectionObserver/CSSStyleSheet.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSStyleSheet.h>)
#    include <LibWeb/NavigationTiming/CSSStyleSheet.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSStyleSheet.h>)
#    include <LibWeb/RequestIdleCallback/CSSStyleSheet.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSStyleSheet.h>)
#    include <LibWeb/ResizeObserver/CSSStyleSheet.h>
#elif __has_include(<LibWeb/SVG/CSSStyleSheet.h>)
#    include <LibWeb/SVG/CSSStyleSheet.h>
#elif __has_include(<LibWeb/Selection/CSSStyleSheet.h>)
#    include <LibWeb/Selection/CSSStyleSheet.h>
#elif __has_include(<LibWeb/WebSockets/CSSStyleSheet.h>)
#    include <LibWeb/WebSockets/CSSStyleSheet.h>
#elif __has_include(<LibWeb/XHR/CSSStyleSheet.h>)
#    include <LibWeb/XHR/CSSStyleSheet.h>
#elif __has_include(<LibWeb/URL/CSSStyleSheet.h>)
#    include <LibWeb/URL/CSSStyleSheet.h>
#endif


#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

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
using namespace Web::UIEvents;
using namespace Web::XHR;

namespace Web::Bindings {

CSSStyleSheetConstructor::CSSStyleSheetConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSStyleSheetConstructor::~CSSStyleSheetConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSStyleSheetConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSStyleSheet");
}

JS::ThrowCompletionOr<JS::Object*> CSSStyleSheetConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSStyleSheet");

}

void CSSStyleSheetConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSStyleSheetPrototype>("CSSStyleSheet"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

