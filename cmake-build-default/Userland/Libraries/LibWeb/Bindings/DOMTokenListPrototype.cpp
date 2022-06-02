
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DOMTokenListPrototype.h>
#include <LibWeb/Bindings/DOMTokenListWrapper.h>
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


#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/DOMTokenList.h>

#if __has_include(<LibWeb/Bindings/DOMTokenListWrapper.h>)
#   include <LibWeb/Bindings/DOMTokenListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMTokenListWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMTokenListWrapperFactory.h>
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

DOMTokenListPrototype::DOMTokenListPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

DOMTokenListPrototype::~DOMTokenListPrototype()
{
}

void DOMTokenListPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("length", length_getter, nullptr, default_attributes);

    define_native_accessor("value", value_getter, value_setter, default_attributes);

    define_native_function("remove", remove, 0, default_attributes);

    define_native_function("add", add, 0, default_attributes);

    define_native_function("item", item, 1, default_attributes);

    define_native_function("replace", replace, 2, default_attributes);

    define_native_function("contains", contains, 1, default_attributes);

    define_native_function("toggle", toggle, 1, default_attributes);

    define_native_function("supports", supports, 1, default_attributes);

    define_native_function("toString", to_string, 0, default_attributes);

    define_direct_property(*vm.well_known_symbol_iterator(), global_object.array_prototype()->get_without_side_effects(vm.names.values), JS::Attribute::Configurable | JS::Attribute::Writable);

    define_direct_property(vm.names.entries, global_object.array_prototype()->get_without_side_effects(vm.names.entries), default_attributes);
    define_direct_property(vm.names.keys, global_object.array_prototype()->get_without_side_effects(vm.names.keys), default_attributes);
    define_direct_property(vm.names.values, global_object.array_prototype()->get_without_side_effects(vm.names.values), default_attributes);
    define_direct_property(vm.names.forEach, global_object.array_prototype()->get_without_side_effects(vm.names.forEach), default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<DOM::DOMTokenList*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<DOMTokenListWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "DOM::DOMTokenList");

    return &static_cast<DOMTokenListWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::length_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->length(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::value_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->value(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::value_setter)
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

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::item)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "item");

    auto arg0 = vm.argument(0);

    u32 index;

    index = TRY(arg0.to_u32(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->item(index); }));

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::contains)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "contains");

    auto arg0 = vm.argument(0);

    String token;
    if (arg0.is_null() && false) {
        token = String::empty();
    } else {
        token = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->contains(token); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::add)
{

    auto* impl = TRY(impl_from(vm, global_object));

    Vector<String> tokens;
    tokens.ensure_capacity(vm.argument_count() - 0);

    for (size_t i = 0; i < vm.argument_count(); ++i) {
        auto to_string_result = TRY(vm.argument(i).to_string(global_object));
        tokens.append(move(to_string_result));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->add(tokens); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::remove)
{

    auto* impl = TRY(impl_from(vm, global_object));

    Vector<String> tokens;
    tokens.ensure_capacity(vm.argument_count() - 0);

    for (size_t i = 0; i < vm.argument_count(); ++i) {
        auto to_string_result = TRY(vm.argument(i).to_string(global_object));
        tokens.append(move(to_string_result));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->remove(tokens); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::toggle)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "toggle");

    auto arg0 = vm.argument(0);

    String token;
    if (arg0.is_null() && false) {
        token = String::empty();
    } else {
        token = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    Optional<bool> force;

    if (!arg1.is_undefined())

    force = arg1.to_boolean();

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->toggle(token, force); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::replace)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "replace", "2");

    auto arg0 = vm.argument(0);

    String token;
    if (arg0.is_null() && false) {
        token = String::empty();
    } else {
        token = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String new_token;
    if (arg1.is_null() && false) {
        new_token = String::empty();
    } else {
        new_token = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->replace(token, new_token); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::supports)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "supports");

    auto arg0 = vm.argument(0);

    String token;
    if (arg0.is_null() && false) {
        token = String::empty();
    } else {
        token = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->supports(token); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMTokenListPrototype::to_string)
{
    auto* impl = TRY(impl_from(vm, global_object));


    auto retval = impl->value();


    return JS::js_string(vm, move(retval));
}

} // namespace Web::Bindings

