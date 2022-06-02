
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLAnchorElementPrototype.h>
#include <LibWeb/Bindings/HTMLAnchorElementWrapper.h>
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


#include <LibWeb/HTML/HTMLAnchorElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLAnchorElement.h>

#if __has_include(<LibWeb/Bindings/HTMLAnchorElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLAnchorElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLAnchorElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLAnchorElementWrapperFactory.h>
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

HTMLAnchorElementPrototype::HTMLAnchorElementPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLElementPrototype>("HTMLElement"))

{
}

HTMLAnchorElementPrototype::~HTMLAnchorElementPrototype()
{
}

void HTMLAnchorElementPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("target", target_getter, target_setter, default_attributes);

    define_native_accessor("download", download_getter, download_setter, default_attributes);

    define_native_accessor("ping", ping_getter, ping_setter, default_attributes);

    define_native_accessor("rel", rel_getter, rel_setter, default_attributes);

    define_native_accessor("hreflang", hreflang_getter, hreflang_setter, default_attributes);

    define_native_accessor("type", type_getter, type_setter, default_attributes);

    define_native_accessor("coords", coords_getter, coords_setter, default_attributes);

    define_native_accessor("charset", charset_getter, charset_setter, default_attributes);

    define_native_accessor("name", name_getter, name_setter, default_attributes);

    define_native_accessor("rev", rev_getter, rev_setter, default_attributes);

    define_native_accessor("shape", shape_getter, shape_setter, default_attributes);

    define_native_accessor("href", href_getter, href_setter, default_attributes);

    define_native_accessor("origin", origin_getter, nullptr, default_attributes);

    define_native_accessor("protocol", protocol_getter, protocol_setter, default_attributes);

    define_native_accessor("username", username_getter, username_setter, default_attributes);

    define_native_accessor("password", password_getter, password_setter, default_attributes);

    define_native_accessor("host", host_getter, host_setter, default_attributes);

    define_native_accessor("hostname", hostname_getter, hostname_setter, default_attributes);

    define_native_accessor("port", port_getter, port_setter, default_attributes);

    define_native_accessor("pathname", pathname_getter, pathname_setter, default_attributes);

    define_native_accessor("search", search_getter, search_setter, default_attributes);

    define_native_accessor("hash", hash_getter, hash_setter, default_attributes);

    define_native_function("toString", to_string, 0, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::HTMLAnchorElement*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<HTMLAnchorElementWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::HTMLAnchorElement");

    return &static_cast<HTMLAnchorElementWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::target_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::target);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::target_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::download_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::download);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::download_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::download, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::ping_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::ping);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::ping_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::ping, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::rel_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::rel);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::rel_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::hreflang_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::hreflang);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::hreflang_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::type);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::type_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::coords_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::coords);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::coords_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::coords, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::charset_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::charset);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::charset_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::name_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::name);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::name_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::name, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::rev_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::rev);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::rev_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::shape_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::shape);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::shape_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::shape, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::href_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->href(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::href_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_href(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::origin_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->origin(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::protocol_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->protocol(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::protocol_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_protocol(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::username_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->username(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::username_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_username(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::password_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->password(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::password_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_password(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::host_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->host(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::host_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_host(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::hostname_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->hostname(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::hostname_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_hostname(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::port_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->port(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::port_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_port(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::pathname_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->pathname(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::pathname_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_pathname(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::search_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->search(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::search_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_search(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::hash_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->hash(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::hash_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_hash(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLAnchorElementPrototype::to_string)
{
    auto* impl = TRY(impl_from(vm, global_object));


    auto retval = impl->href();


    return JS::js_string(vm, move(retval));
}

} // namespace Web::Bindings

