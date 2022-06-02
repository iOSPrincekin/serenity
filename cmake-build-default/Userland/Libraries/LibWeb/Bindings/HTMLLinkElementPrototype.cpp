
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLLinkElementPrototype.h>
#include <LibWeb/Bindings/HTMLLinkElementWrapper.h>
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


#include <LibWeb/HTML/HTMLLinkElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLLinkElement.h>

#if __has_include(<LibWeb/Bindings/HTMLLinkElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLLinkElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLLinkElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLLinkElementWrapperFactory.h>
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

HTMLLinkElementPrototype::HTMLLinkElementPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLElementPrototype>("HTMLElement"))

{
}

HTMLLinkElementPrototype::~HTMLLinkElementPrototype()
{
}

void HTMLLinkElementPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("href", href_getter, href_setter, default_attributes);

    define_native_accessor("hreflang", hreflang_getter, hreflang_setter, default_attributes);

    define_native_accessor("integrity", integrity_getter, integrity_setter, default_attributes);

    define_native_accessor("media", media_getter, media_setter, default_attributes);

    define_native_accessor("rel", rel_getter, rel_setter, default_attributes);

    define_native_accessor("type", type_getter, type_setter, default_attributes);

    define_native_accessor("imageSrcset", image_srcset_getter, image_srcset_setter, default_attributes);

    define_native_accessor("imageSizes", image_sizes_getter, image_sizes_setter, default_attributes);

    define_native_accessor("disabled", disabled_getter, disabled_setter, default_attributes);

    define_native_accessor("charset", charset_getter, charset_setter, default_attributes);

    define_native_accessor("rev", rev_getter, rev_setter, default_attributes);

    define_native_accessor("target", target_getter, target_setter, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::HTMLLinkElement*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<HTMLLinkElementWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::HTMLLinkElement");

    return &static_cast<HTMLLinkElementWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::href_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::href);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::href_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::href, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::hreflang_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::hreflang);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::hreflang_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::hreflang, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::integrity_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::integrity);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::integrity_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::integrity, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::media_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::media);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::media_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::media, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::rel_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::rel);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::rel_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::rel, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::type);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::type_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::type, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::image_srcset_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::imagesrcset);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::image_srcset_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::imagesrcset, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::image_sizes_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::imagesizes);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::image_sizes_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::imagesizes, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::disabled_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->has_attribute(HTML::AttributeNames::disabled);

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::disabled_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    if (!cpp_value)
        impl->remove_attribute(HTML::AttributeNames::disabled);
    else
        impl->set_attribute(HTML::AttributeNames::disabled, String::empty());

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::charset_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::charset);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::charset_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::charset, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::rev_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::rev);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::rev_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::rev, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::target_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::target);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLLinkElementPrototype::target_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::target, cpp_value);

    return JS::js_undefined();
}

} // namespace Web::Bindings

