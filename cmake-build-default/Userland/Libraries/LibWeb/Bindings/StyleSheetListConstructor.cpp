
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/StyleSheetListConstructor.h>
#include <LibWeb/Bindings/StyleSheetListPrototype.h>
#include <LibWeb/Bindings/StyleSheetListWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/StyleSheetList.h>)
#    include <LibWeb/Crypto/StyleSheetList.h>
#elif __has_include(<LibWeb/CSS/StyleSheetList.h>)
#    include <LibWeb/CSS/StyleSheetList.h>
#elif __has_include(<LibWeb/DOM/StyleSheetList.h>)
#    include <LibWeb/DOM/StyleSheetList.h>
#elif __has_include(<LibWeb/Encoding/StyleSheetList.h>)
#    include <LibWeb/Encoding/StyleSheetList.h>
#elif __has_include(<LibWeb/Geometry/StyleSheetList.h>)
#    include <LibWeb/Geometry/StyleSheetList.h>
#elif __has_include(<LibWeb/HTML/StyleSheetList.h>)
#    include <LibWeb/HTML/StyleSheetList.h>
#elif __has_include(<LibWeb/UIEvents/StyleSheetList.h>)
#    include <LibWeb/UIEvents/StyleSheetList.h>
#elif __has_include(<LibWeb/HighResolutionTime/StyleSheetList.h>)
#    include <LibWeb/HighResolutionTime/StyleSheetList.h>
#elif __has_include(<LibWeb/IntersectionObserver/StyleSheetList.h>)
#    include <LibWeb/IntersectionObserver/StyleSheetList.h>
#elif __has_include(<LibWeb/NavigationTiming/StyleSheetList.h>)
#    include <LibWeb/NavigationTiming/StyleSheetList.h>
#elif __has_include(<LibWeb/RequestIdleCallback/StyleSheetList.h>)
#    include <LibWeb/RequestIdleCallback/StyleSheetList.h>
#elif __has_include(<LibWeb/ResizeObserver/StyleSheetList.h>)
#    include <LibWeb/ResizeObserver/StyleSheetList.h>
#elif __has_include(<LibWeb/SVG/StyleSheetList.h>)
#    include <LibWeb/SVG/StyleSheetList.h>
#elif __has_include(<LibWeb/Selection/StyleSheetList.h>)
#    include <LibWeb/Selection/StyleSheetList.h>
#elif __has_include(<LibWeb/WebSockets/StyleSheetList.h>)
#    include <LibWeb/WebSockets/StyleSheetList.h>
#elif __has_include(<LibWeb/XHR/StyleSheetList.h>)
#    include <LibWeb/XHR/StyleSheetList.h>
#elif __has_include(<LibWeb/URL/StyleSheetList.h>)
#    include <LibWeb/URL/StyleSheetList.h>
#endif


#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/StyleSheetList.h>

#if __has_include(<LibWeb/Bindings/StyleSheetListWrapper.h>)
#   include <LibWeb/Bindings/StyleSheetListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/StyleSheetListWrapperFactory.h>)
#   include <LibWeb/Bindings/StyleSheetListWrapperFactory.h>
#endif

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

StyleSheetListConstructor::StyleSheetListConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

StyleSheetListConstructor::~StyleSheetListConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> StyleSheetListConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "StyleSheetList");
}

JS::ThrowCompletionOr<JS::Object*> StyleSheetListConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "StyleSheetList");

}

void StyleSheetListConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<StyleSheetListPrototype>("StyleSheetList"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

