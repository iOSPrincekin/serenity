
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CSSStyleDeclarationPrototype.h>
#include <LibWeb/Bindings/CSSStyleDeclarationWrapper.h>
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


#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>
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

CSSStyleDeclarationPrototype::CSSStyleDeclarationPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

CSSStyleDeclarationPrototype::~CSSStyleDeclarationPrototype()
{
}

void CSSStyleDeclarationPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("length", length_getter, nullptr, default_attributes);

    define_native_function("getPropertyValue", get_property_value, 1, default_attributes);

    define_native_function("item", item, 1, default_attributes);

    define_native_function("getPropertyPriority", get_property_priority, 1, default_attributes);

    define_native_function("removeProperty", remove_property, 1, default_attributes);

    define_native_function("setProperty", set_property, 2, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<CSS::CSSStyleDeclaration*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<CSSStyleDeclarationWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "CSS::CSSStyleDeclaration");

    return &static_cast<CSSStyleDeclarationWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(CSSStyleDeclarationPrototype::length_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->length(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(CSSStyleDeclarationPrototype::item)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "item");

    auto arg0 = vm.argument(0);

    u32 index;

    index = TRY(arg0.to_u32(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->item(index); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(CSSStyleDeclarationPrototype::get_property_value)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getPropertyValue");

    auto arg0 = vm.argument(0);

    String property;
    if (arg0.is_null() && false) {
        property = String::empty();
    } else {
        property = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_property_value(property); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(CSSStyleDeclarationPrototype::get_property_priority)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getPropertyPriority");

    auto arg0 = vm.argument(0);

    String property;
    if (arg0.is_null() && false) {
        property = String::empty();
    } else {
        property = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_property_priority(property); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(CSSStyleDeclarationPrototype::set_property)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "setProperty", "2");

    auto arg0 = vm.argument(0);

    String property;
    if (arg0.is_null() && false) {
        property = String::empty();
    } else {
        property = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String value;
    if (arg1.is_null() && true) {
        value = String::empty();
    } else {
        value = TRY(arg1.to_string(global_object));
    }

    auto arg2 = vm.argument(2);

    String priority;
    if (!arg2.is_undefined()) {
        if (arg2.is_null() && true)
            priority = String::empty();
        else
            priority = TRY(arg2.to_string(global_object));
    } else {
        priority = "";
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_property(property, value, priority); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(CSSStyleDeclarationPrototype::remove_property)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "removeProperty");

    auto arg0 = vm.argument(0);

    String property;
    if (arg0.is_null() && false) {
        property = String::empty();
    } else {
        property = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->remove_property(property); }));

    return JS::js_string(vm, retval);

}

} // namespace Web::Bindings

