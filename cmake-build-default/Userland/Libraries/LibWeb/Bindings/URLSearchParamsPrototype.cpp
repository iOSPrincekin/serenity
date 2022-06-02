
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/URLSearchParamsPrototype.h>
#include <LibWeb/Bindings/URLSearchParamsWrapper.h>
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


#include <LibWeb/URL/URLSearchParams.h>

#include <LibWeb/URL/URLSearchParams.h>

//#if __has_include(<LibWeb/URL/URLSearchParamsIterator.h>)
#   include <LibWeb/URL/URLSearchParamsIterator.h>
//#endif
#if __has_include(<LibWeb/URL/URLSearchParamsIteratorFactory.h>)
#   include <LibWeb/URL/URLSearchParamsIteratorFactory.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsIteratorWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsIteratorWrapperFactory.h>
#endif

#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapperFactory.h>
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

URLSearchParamsPrototype::URLSearchParamsPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

URLSearchParamsPrototype::~URLSearchParamsPrototype()
{
}

void URLSearchParamsPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_function("has", has, 1, default_attributes);

    define_native_function("append", append, 2, default_attributes);

    define_native_function("getAll", get_all, 1, default_attributes);

    define_native_function("sort", sort, 0, default_attributes);

    define_native_function("get", get, 1, default_attributes);

    define_native_function("delete", delete_, 1, default_attributes);

    define_native_function("set", set, 2, default_attributes);

    define_native_function("toString", to_string, 0, default_attributes);

    define_native_function(vm.names.entries, entries, 0, default_attributes);
    define_native_function(vm.names.forEach, for_each, 1, default_attributes);
    define_native_function(vm.names.keys, keys, 0, default_attributes);
    define_native_function(vm.names.values, values, 0, default_attributes);

    define_direct_property(*vm.well_known_symbol_iterator(), get_without_side_effects(vm.names.entries), JS::Attribute::Configurable | JS::Attribute::Writable);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<URL::URLSearchParams*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<URLSearchParamsWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "URL::URLSearchParams");

    return &static_cast<URLSearchParamsWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::append)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "append", "2");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String value;
    if (arg1.is_null() && false) {
        value = String::empty();
    } else {
        value = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->append(name, value); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::delete_)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "delete");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->delete_(name); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::get)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "get");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get(name); }));

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::get_all)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getAll");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_all(name); }));

    auto* new_array0 = MUST(JS::Array::create(global_object, 0));

    for (size_t i0 = 0; i0 < retval.size(); ++i0) {
        auto& element0 = retval.at(i0);

    auto wrapped_element0 = JS::js_string(vm, element0);

        auto property_index0 = JS::PropertyKey { i0 };
        MUST(new_array0->create_data_property(property_index0, wrapped_element0));
    }

    return new_array0;

}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::has)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "has");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->has(name); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::set)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "set", "2");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String value;
    if (arg1.is_null() && false) {
        value = String::empty();
    } else {
        value = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set(name, value); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::sort)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->sort(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::to_string)
{
    auto* impl = TRY(impl_from(vm, global_object));


    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->to_string(); }));


    return JS::js_string(vm, move(retval));
}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::entries)
{
    auto* impl = TRY(impl_from(vm, global_object));

    return wrap(global_object, URLSearchParamsIterator::create(*impl, Object::PropertyKind::KeyAndValue));
}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::for_each)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto callback = vm.argument(0);
    if (!callback.is_function())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAFunction, callback.to_string_without_side_effects());

    auto this_value = vm.this_value(global_object);
    TRY(impl->for_each([&](auto key, auto value) -> JS::ThrowCompletionOr<void> {

    JS::Value wrapped_key;

    wrapped_key =  JS::js_string(vm, key);

    JS::Value wrapped_value;

    wrapped_value =  JS::js_string(vm, value);

        TRY(call(global_object, callback.as_function(), vm.argument(1), wrapped_value, wrapped_key, this_value));
        return {};
    }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::keys)
{
    auto* impl = TRY(impl_from(vm, global_object));

    return wrap(global_object, URLSearchParamsIterator::create(*impl, Object::PropertyKind::Key));
}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsPrototype::values)
{
    auto* impl = TRY(impl_from(vm, global_object));

    return wrap(global_object, URLSearchParamsIterator::create(*impl, Object::PropertyKind::Value));
}

} // namespace Web::Bindings

