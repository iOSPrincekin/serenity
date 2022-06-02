
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CSSFontFaceRulePrototype.h>
#include <LibWeb/Bindings/CSSFontFaceRuleWrapper.h>
#include <LibWeb/Bindings/EventWrapper.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/LocationObject.h>
#include <LibWeb/Bindings/WindowObject.h>
#include <LibWeb/Bindings/WorkerLocationWrapper.h>
#include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#include <LibWeb/Bindings/WorkerWrapper.h>
#include <LibWeb/DOM/Element.h>
#include <LibWeb/DOM/Event.h>
#include <LibWeb/DOM/IDLEventListener.h>
#include <LibWeb/DOM/NodeFilter.h>
#include <LibWeb/DOM/Range.h>
#include <LibWeb/HTML/Scripting/Environments.h>
#include <LibWeb/HTML/Window.h>
#include <LibWeb/Origin.h>

#if __has_include(<LibWeb/Bindings/CSSRulePrototype.h>)
#    include <LibWeb/Bindings/CSSRulePrototype.h>
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
using namespace Web::Crypto;
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::NavigationTiming;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;
using namespace Web::SVG;
using namespace Web::URL;
using namespace Web::WebSockets;
using namespace Web::XHR;

namespace Web::Bindings {

CSSFontFaceRulePrototype::CSSFontFaceRulePrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<CSSRulePrototype>("CSSRule"))

{
}

CSSFontFaceRulePrototype::~CSSFontFaceRulePrototype()
{
}

void CSSFontFaceRulePrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("style", style_getter, nullptr, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<CSS::CSSFontFaceRule*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<CSSFontFaceRuleWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "CSS::CSSFontFaceRule");

    return &static_cast<CSSFontFaceRuleWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(CSSFontFaceRulePrototype::style_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->style(); }));

    return wrap(global_object, const_cast<CSSStyleDeclaration&>(*retval));

}

} // namespace Web::Bindings

