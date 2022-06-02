
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CSSRulePrototype.h>
#include <LibWeb/Bindings/CSSRuleWrapper.h>
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

#if __has_include(<LibWeb/Bindings/ObjectPrototype.h>)
#    include <LibWeb/Bindings/ObjectPrototype.h>
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

CSSRulePrototype::CSSRulePrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

CSSRulePrototype::~CSSRulePrototype()
{
}

void CSSRulePrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("cssText", css_text_getter, css_text_setter, default_attributes);

    define_native_accessor("parentRule", parent_rule_getter, nullptr, default_attributes);

    define_native_accessor("parentStyleSheet", parent_style_sheet_getter, nullptr, default_attributes);

    define_native_accessor("type", type_getter, nullptr, default_attributes);

    define_direct_property("STYLE_RULE", JS::Value((i32)1), JS::Attribute::Enumerable);

    define_direct_property("CHARSET_RULE", JS::Value((i32)2), JS::Attribute::Enumerable);

    define_direct_property("IMPORT_RULE", JS::Value((i32)3), JS::Attribute::Enumerable);

    define_direct_property("MEDIA_RULE", JS::Value((i32)4), JS::Attribute::Enumerable);

    define_direct_property("FONT_FACE_RULE", JS::Value((i32)5), JS::Attribute::Enumerable);

    define_direct_property("PAGE_RULE", JS::Value((i32)6), JS::Attribute::Enumerable);

    define_direct_property("MARGIN_RULE", JS::Value((i32)9), JS::Attribute::Enumerable);

    define_direct_property("NAMESPACE_RULE", JS::Value((i32)10), JS::Attribute::Enumerable);

    define_direct_property("SUPPORTS_RULE", JS::Value((i32)12), JS::Attribute::Enumerable);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<CSS::CSSRule*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<CSSRuleWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "CSS::CSSRule");

    return &static_cast<CSSRuleWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(CSSRulePrototype::css_text_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->css_text(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(CSSRulePrototype::css_text_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_css_text(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(CSSRulePrototype::parent_rule_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->parent_rule(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<CSSRule&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(CSSRulePrototype::parent_style_sheet_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->parent_style_sheet(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<CSSStyleSheet&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(CSSRulePrototype::type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->type(); }));

    return JS::Value((i32)retval);

}

} // namespace Web::Bindings

