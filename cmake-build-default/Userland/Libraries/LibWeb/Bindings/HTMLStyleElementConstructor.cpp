
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLStyleElementConstructor.h>
#include <LibWeb/Bindings/HTMLStyleElementPrototype.h>
#include <LibWeb/Bindings/HTMLStyleElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLStyleElement.h>)
#    include <LibWeb/Crypto/HTMLStyleElement.h>
#elif __has_include(<LibWeb/CSS/HTMLStyleElement.h>)
#    include <LibWeb/CSS/HTMLStyleElement.h>
#elif __has_include(<LibWeb/DOM/HTMLStyleElement.h>)
#    include <LibWeb/DOM/HTMLStyleElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLStyleElement.h>)
#    include <LibWeb/Encoding/HTMLStyleElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLStyleElement.h>)
#    include <LibWeb/Geometry/HTMLStyleElement.h>
#elif __has_include(<LibWeb/HTML/HTMLStyleElement.h>)
#    include <LibWeb/HTML/HTMLStyleElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLStyleElement.h>)
#    include <LibWeb/UIEvents/HTMLStyleElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLStyleElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLStyleElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLStyleElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLStyleElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLStyleElement.h>)
#    include <LibWeb/NavigationTiming/HTMLStyleElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLStyleElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLStyleElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLStyleElement.h>)
#    include <LibWeb/ResizeObserver/HTMLStyleElement.h>
#elif __has_include(<LibWeb/SVG/HTMLStyleElement.h>)
#    include <LibWeb/SVG/HTMLStyleElement.h>
#elif __has_include(<LibWeb/Selection/HTMLStyleElement.h>)
#    include <LibWeb/Selection/HTMLStyleElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLStyleElement.h>)
#    include <LibWeb/WebSockets/HTMLStyleElement.h>
#elif __has_include(<LibWeb/XHR/HTMLStyleElement.h>)
#    include <LibWeb/XHR/HTMLStyleElement.h>
#elif __has_include(<LibWeb/URL/HTMLStyleElement.h>)
#    include <LibWeb/URL/HTMLStyleElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLStyleElement.h>

#include <LibWeb/HTML/HTMLStyleElement.h>

#if __has_include(<LibWeb/Bindings/HTMLStyleElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLStyleElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLStyleElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLStyleElementWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSStyleSheet.h>

#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
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

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
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

HTMLStyleElementConstructor::HTMLStyleElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLStyleElementConstructor::~HTMLStyleElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLStyleElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLStyleElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLStyleElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLStyleElement");

}

void HTMLStyleElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLStyleElementPrototype>("HTMLStyleElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

