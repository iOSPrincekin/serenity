
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLBodyElementPrototype.h>
#include <LibWeb/Bindings/HTMLBodyElementWrapper.h>
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

#if __has_include(<LibWeb/Bindings/HTMLElementPrototype.h>)
#    include <LibWeb/Bindings/HTMLElementPrototype.h>
#endif


#include <LibWeb/HTML/HTMLBodyElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLBodyElement.h>

#if __has_include(<LibWeb/Bindings/HTMLBodyElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLBodyElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLBodyElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLBodyElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
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

HTMLBodyElementPrototype::HTMLBodyElementPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLElementPrototype>("HTMLElement"))

{
}

HTMLBodyElementPrototype::~HTMLBodyElementPrototype()
{
}

void HTMLBodyElementPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("text", text_getter, text_setter, default_attributes);

    define_native_accessor("link", link_getter, link_setter, default_attributes);

    define_native_accessor("vLink", v_link_getter, v_link_setter, default_attributes);

    define_native_accessor("aLink", a_link_getter, a_link_setter, default_attributes);

    define_native_accessor("bgColor", bg_color_getter, bg_color_setter, default_attributes);

    define_native_accessor("background", background_getter, background_setter, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::HTMLBodyElement*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<HTMLBodyElementWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::HTMLBodyElement");

    return &static_cast<HTMLBodyElementWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::text_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::text);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::text_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && true) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::text, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::link_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::link);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::link_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && true) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::link, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::v_link_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::vlink);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::v_link_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && true) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::vlink, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::a_link_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::alink);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::a_link_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && true) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::alink, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::bg_color_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::bgcolor);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::bg_color_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && true) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::bgcolor, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::background_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::background);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLBodyElementPrototype::background_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::background, cpp_value);

    return JS::js_undefined();
}

} // namespace Web::Bindings

