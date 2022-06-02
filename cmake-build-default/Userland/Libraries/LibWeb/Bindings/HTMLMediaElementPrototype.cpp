
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLMediaElementPrototype.h>
#include <LibWeb/Bindings/HTMLMediaElementWrapper.h>
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


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLMediaElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMediaElement.h>

#if __has_include(<LibWeb/Bindings/HTMLMediaElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMediaElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMediaElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMediaElementWrapperFactory.h>
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

HTMLMediaElementPrototype::HTMLMediaElementPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLElementPrototype>("HTMLElement"))

{
}

HTMLMediaElementPrototype::~HTMLMediaElementPrototype()
{
}

void HTMLMediaElementPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("src", src_getter, src_setter, default_attributes);

    define_native_accessor("autoplay", autoplay_getter, autoplay_setter, default_attributes);

    define_native_accessor("loop", loop_getter, loop_setter, default_attributes);

    define_native_accessor("controls", controls_getter, controls_setter, default_attributes);

    define_native_function("canPlayType", can_play_type, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::HTMLMediaElement*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<HTMLMediaElementWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::HTMLMediaElement");

    return &static_cast<HTMLMediaElementWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::src_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::src);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::src_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::src, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::autoplay_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->has_attribute(HTML::AttributeNames::autoplay);

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::autoplay_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    if (!cpp_value)
        impl->remove_attribute(HTML::AttributeNames::autoplay);
    else
        impl->set_attribute(HTML::AttributeNames::autoplay, String::empty());

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::loop_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->has_attribute(HTML::AttributeNames::loop);

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::loop_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    if (!cpp_value)
        impl->remove_attribute(HTML::AttributeNames::loop);
    else
        impl->set_attribute(HTML::AttributeNames::loop, String::empty());

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::controls_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->has_attribute(HTML::AttributeNames::controls);

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::controls_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    bool cpp_value;

    cpp_value = value.to_boolean();

    if (!cpp_value)
        impl->remove_attribute(HTML::AttributeNames::controls);
    else
        impl->set_attribute(HTML::AttributeNames::controls, String::empty());

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(HTMLMediaElementPrototype::can_play_type)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "canPlayType");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->can_play_type(type); }));

    return JS::js_string(global_object.heap(), Bindings::idl_enum_to_string(retval));

}

} // namespace Web::Bindings

