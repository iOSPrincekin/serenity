
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLOptionElementPrototype.h>
#include <LibWeb/Bindings/HTMLOptionElementWrapper.h>
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


#include <LibWeb/HTML/HTMLOptionElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLOptionElement.h>

#if __has_include(<LibWeb/Bindings/HTMLOptionElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLOptionElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLOptionElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLOptionElementWrapperFactory.h>
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

HTMLOptionElementPrototype::HTMLOptionElementPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLElementPrototype>("HTMLElement"))

{
}

HTMLOptionElementPrototype::~HTMLOptionElementPrototype()
{
}

void HTMLOptionElementPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("disabled", disabled_getter, disabled_setter, default_attributes);

    define_native_accessor("defaultSelected", default_selected_getter, default_selected_setter, default_attributes);

    define_native_accessor("selected", selected_getter, selected_setter, default_attributes);

    define_native_accessor("value", value_getter, value_setter, default_attributes);

    define_native_accessor("text", text_getter, text_setter, default_attributes);

    define_native_accessor("index", index_getter, nullptr, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::HTMLOptionElement*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<HTMLOptionElementWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::HTMLOptionElement");

    return &static_cast<HTMLOptionElementWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::disabled_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->has_attribute(HTML::AttributeNames::disabled);

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::disabled_setter)
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

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::default_selected_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->has_attribute(HTML::AttributeNames::selected);

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::default_selected_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    if (!cpp_value)
        impl->remove_attribute(HTML::AttributeNames::selected);
    else
        impl->set_attribute(HTML::AttributeNames::selected, String::empty());

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::selected_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->selected(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::selected_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_selected(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::value_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->value(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::value_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_value(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::text_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->text(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::text_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_text(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLOptionElementPrototype::index_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->index(); }));

    return JS::Value((i32)retval);

}

} // namespace Web::Bindings

