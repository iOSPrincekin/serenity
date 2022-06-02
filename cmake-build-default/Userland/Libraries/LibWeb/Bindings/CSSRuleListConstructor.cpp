
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSRuleListConstructor.h>
#include <LibWeb/Bindings/CSSRuleListPrototype.h>
#include <LibWeb/Bindings/CSSRuleListWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSRuleList.h>)
#    include <LibWeb/Crypto/CSSRuleList.h>
#elif __has_include(<LibWeb/CSS/CSSRuleList.h>)
#    include <LibWeb/CSS/CSSRuleList.h>
#elif __has_include(<LibWeb/DOM/CSSRuleList.h>)
#    include <LibWeb/DOM/CSSRuleList.h>
#elif __has_include(<LibWeb/Encoding/CSSRuleList.h>)
#    include <LibWeb/Encoding/CSSRuleList.h>
#elif __has_include(<LibWeb/Geometry/CSSRuleList.h>)
#    include <LibWeb/Geometry/CSSRuleList.h>
#elif __has_include(<LibWeb/HTML/CSSRuleList.h>)
#    include <LibWeb/HTML/CSSRuleList.h>
#elif __has_include(<LibWeb/UIEvents/CSSRuleList.h>)
#    include <LibWeb/UIEvents/CSSRuleList.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSRuleList.h>)
#    include <LibWeb/HighResolutionTime/CSSRuleList.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSRuleList.h>)
#    include <LibWeb/IntersectionObserver/CSSRuleList.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSRuleList.h>)
#    include <LibWeb/NavigationTiming/CSSRuleList.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSRuleList.h>)
#    include <LibWeb/RequestIdleCallback/CSSRuleList.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSRuleList.h>)
#    include <LibWeb/ResizeObserver/CSSRuleList.h>
#elif __has_include(<LibWeb/SVG/CSSRuleList.h>)
#    include <LibWeb/SVG/CSSRuleList.h>
#elif __has_include(<LibWeb/Selection/CSSRuleList.h>)
#    include <LibWeb/Selection/CSSRuleList.h>
#elif __has_include(<LibWeb/WebSockets/CSSRuleList.h>)
#    include <LibWeb/WebSockets/CSSRuleList.h>
#elif __has_include(<LibWeb/XHR/CSSRuleList.h>)
#    include <LibWeb/XHR/CSSRuleList.h>
#elif __has_include(<LibWeb/URL/CSSRuleList.h>)
#    include <LibWeb/URL/CSSRuleList.h>
#endif


#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSRuleList.h>

#if __has_include(<LibWeb/Bindings/CSSRuleListWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleListWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleListWrapperFactory.h>
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

CSSRuleListConstructor::CSSRuleListConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSRuleListConstructor::~CSSRuleListConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSRuleListConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSRuleList");
}

JS::ThrowCompletionOr<JS::Object*> CSSRuleListConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSRuleList");

}

void CSSRuleListConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSRuleListPrototype>("CSSRuleList"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

