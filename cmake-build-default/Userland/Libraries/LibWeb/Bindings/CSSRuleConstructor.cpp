
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSRuleConstructor.h>
#include <LibWeb/Bindings/CSSRulePrototype.h>
#include <LibWeb/Bindings/CSSRuleWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSRule.h>)
#    include <LibWeb/Crypto/CSSRule.h>
#elif __has_include(<LibWeb/CSS/CSSRule.h>)
#    include <LibWeb/CSS/CSSRule.h>
#elif __has_include(<LibWeb/DOM/CSSRule.h>)
#    include <LibWeb/DOM/CSSRule.h>
#elif __has_include(<LibWeb/Encoding/CSSRule.h>)
#    include <LibWeb/Encoding/CSSRule.h>
#elif __has_include(<LibWeb/Geometry/CSSRule.h>)
#    include <LibWeb/Geometry/CSSRule.h>
#elif __has_include(<LibWeb/HTML/CSSRule.h>)
#    include <LibWeb/HTML/CSSRule.h>
#elif __has_include(<LibWeb/UIEvents/CSSRule.h>)
#    include <LibWeb/UIEvents/CSSRule.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSRule.h>)
#    include <LibWeb/HighResolutionTime/CSSRule.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSRule.h>)
#    include <LibWeb/IntersectionObserver/CSSRule.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSRule.h>)
#    include <LibWeb/NavigationTiming/CSSRule.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSRule.h>)
#    include <LibWeb/RequestIdleCallback/CSSRule.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSRule.h>)
#    include <LibWeb/ResizeObserver/CSSRule.h>
#elif __has_include(<LibWeb/SVG/CSSRule.h>)
#    include <LibWeb/SVG/CSSRule.h>
#elif __has_include(<LibWeb/Selection/CSSRule.h>)
#    include <LibWeb/Selection/CSSRule.h>
#elif __has_include(<LibWeb/WebSockets/CSSRule.h>)
#    include <LibWeb/WebSockets/CSSRule.h>
#elif __has_include(<LibWeb/XHR/CSSRule.h>)
#    include <LibWeb/XHR/CSSRule.h>
#elif __has_include(<LibWeb/URL/CSSRule.h>)
#    include <LibWeb/URL/CSSRule.h>
#endif


#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

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

CSSRuleConstructor::CSSRuleConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSRuleConstructor::~CSSRuleConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSRuleConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSRule");
}

JS::ThrowCompletionOr<JS::Object*> CSSRuleConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSRule");

}

void CSSRuleConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSRulePrototype>("CSSRule"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


define_direct_property("STYLE_RULE", JS::Value((i32)1), JS::Attribute::Enumerable);

define_direct_property("CHARSET_RULE", JS::Value((i32)2), JS::Attribute::Enumerable);

define_direct_property("IMPORT_RULE", JS::Value((i32)3), JS::Attribute::Enumerable);

define_direct_property("MEDIA_RULE", JS::Value((i32)4), JS::Attribute::Enumerable);

define_direct_property("FONT_FACE_RULE", JS::Value((i32)5), JS::Attribute::Enumerable);

define_direct_property("PAGE_RULE", JS::Value((i32)6), JS::Attribute::Enumerable);

define_direct_property("MARGIN_RULE", JS::Value((i32)9), JS::Attribute::Enumerable);

define_direct_property("NAMESPACE_RULE", JS::Value((i32)10), JS::Attribute::Enumerable);

define_direct_property("SUPPORTS_RULE", JS::Value((i32)12), JS::Attribute::Enumerable);

}

} // namespace Web::Bindings

