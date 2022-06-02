
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLObjectElementPrototype.h>
#include <LibWeb/Bindings/HTMLObjectElementWrapper.h>
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


#include <LibWeb/HTML/HTMLObjectElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLObjectElement.h>

#if __has_include(<LibWeb/Bindings/HTMLObjectElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLObjectElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLObjectElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLObjectElementWrapperFactory.h>
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

HTMLObjectElementPrototype::HTMLObjectElementPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLElementPrototype>("HTMLElement"))

{
}

HTMLObjectElementPrototype::~HTMLObjectElementPrototype()
{
}

void HTMLObjectElementPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("data", data_getter, data_setter, default_attributes);

    define_native_accessor("type", type_getter, type_setter, default_attributes);

    define_native_accessor("name", name_getter, name_setter, default_attributes);

    define_native_accessor("useMap", use_map_getter, use_map_setter, default_attributes);

    define_native_accessor("width", width_getter, width_setter, default_attributes);

    define_native_accessor("height", height_getter, height_setter, default_attributes);

    define_native_accessor("contentDocument", content_document_getter, nullptr, default_attributes);

    define_native_accessor("align", align_getter, align_setter, default_attributes);

    define_native_accessor("archive", archive_getter, archive_setter, default_attributes);

    define_native_accessor("code", code_getter, code_setter, default_attributes);

    define_native_accessor("declare", declare_getter, declare_setter, default_attributes);

    define_native_accessor("standby", standby_getter, standby_setter, default_attributes);

    define_native_accessor("codeType", code_type_getter, code_type_setter, default_attributes);

    define_native_accessor("border", border_getter, border_setter, default_attributes);

    define_native_function("getSVGDocument", get_svg_document, 0, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::HTMLObjectElement*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<HTMLObjectElementWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::HTMLObjectElement");

    return &static_cast<HTMLObjectElementWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::data_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->data(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::data_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_data(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::type);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::type_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::name_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::name);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::name_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::use_map_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::usemap);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::use_map_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::usemap, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::width);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::width_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::width, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::height_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::height);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::height_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::height, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::content_document_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->content_document(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Document&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::align_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::align);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::align_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::align, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::archive_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::archive);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::archive_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::archive, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::code_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::code);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::code_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::code, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::declare_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->has_attribute(HTML::AttributeNames::declare);

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::declare_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    if (!cpp_value)
        impl->remove_attribute(HTML::AttributeNames::declare);
    else
        impl->set_attribute(HTML::AttributeNames::declare, String::empty());

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::standby_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::standby);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::standby_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::standby, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::code_type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::codetype);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::code_type_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::codetype, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::border_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::border);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::border_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && true) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::border, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLObjectElementPrototype::get_svg_document)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_svg_document(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Document&>(*retval));

    }

}

} // namespace Web::Bindings

