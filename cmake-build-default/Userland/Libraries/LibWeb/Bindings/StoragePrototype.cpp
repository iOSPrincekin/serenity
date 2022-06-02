
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/StoragePrototype.h>
#include <LibWeb/Bindings/StorageWrapper.h>
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


#include <LibWeb/HTML/Storage.h>

#include <LibWeb/HTML/Storage.h>

#if __has_include(<LibWeb/Bindings/StorageWrapper.h>)
#   include <LibWeb/Bindings/StorageWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/StorageWrapperFactory.h>)
#   include <LibWeb/Bindings/StorageWrapperFactory.h>
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

StoragePrototype::StoragePrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

StoragePrototype::~StoragePrototype()
{
}

void StoragePrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("length", length_getter, nullptr, default_attributes);

    define_native_function("getItem", get_item, 1, default_attributes);

    define_native_function("setItem", set_item, 2, default_attributes);

    define_native_function("clear", clear, 0, default_attributes);

    define_native_function("removeItem", remove_item, 1, default_attributes);

    define_native_function("key", key, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::Storage*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<StorageWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::Storage");

    return &static_cast<StorageWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(StoragePrototype::length_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->length(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(StoragePrototype::key)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "key");

    auto arg0 = vm.argument(0);

    u32 index;

    index = TRY(arg0.to_u32(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->key(index); }));

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS_DEFINE_NATIVE_FUNCTION(StoragePrototype::get_item)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getItem");

    auto arg0 = vm.argument(0);

    String key;
    if (arg0.is_null() && false) {
        key = String::empty();
    } else {
        key = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_item(key); }));

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS_DEFINE_NATIVE_FUNCTION(StoragePrototype::set_item)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "setItem", "2");

    auto arg0 = vm.argument(0);

    String key;
    if (arg0.is_null() && false) {
        key = String::empty();
    } else {
        key = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String value;
    if (arg1.is_null() && false) {
        value = String::empty();
    } else {
        value = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_item(key, value); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(StoragePrototype::remove_item)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "removeItem");

    auto arg0 = vm.argument(0);

    String key;
    if (arg0.is_null() && false) {
        key = String::empty();
    } else {
        key = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->remove_item(key); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(StoragePrototype::clear)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->clear(); }));

    return JS::js_undefined();

}

} // namespace Web::Bindings

