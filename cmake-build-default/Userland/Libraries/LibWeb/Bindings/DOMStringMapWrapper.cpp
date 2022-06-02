
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DOMStringMapPrototype.h>
#include <LibWeb/Bindings/DOMStringMapWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
#endif

// FIXME: This is a total hack until we can figure out the namespace for a given type somehow.
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;

namespace Web::Bindings {

DOMStringMapWrapper* DOMStringMapWrapper::create(JS::GlobalObject& global_object, HTML::DOMStringMap& impl)
{
    return global_object.heap().allocate<DOMStringMapWrapper>(global_object, global_object, impl);
}


DOMStringMapWrapper::DOMStringMapWrapper(JS::GlobalObject& global_object, HTML::DOMStringMap& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<DOMStringMapPrototype>("DOMStringMap"))
    , m_impl(impl)
{
}

void DOMStringMapWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "DOMStringMap"), JS::Attribute::Configurable);
}

DOMStringMapWrapper::~DOMStringMapWrapper()
{
}

DOMStringMapWrapper* wrap(JS::GlobalObject& global_object, HTML::DOMStringMap& impl)
{
    return static_cast<DOMStringMapWrapper*>(wrap_impl(global_object, impl));
}

static JS::Value wrap_for_legacy_platform_object_get_own_property(JS::GlobalObject& global_object, [[maybe_unused]] auto& retval)
{
    [[maybe_unused]] auto& vm = global_object.vm();

    return JS::js_string(vm, retval);

}

JS::ThrowCompletionOr<bool> DOMStringMapWrapper::is_named_property_exposed_on_object(JS::PropertyKey const& property_key) const
{
    [[maybe_unused]] auto& vm = this->vm();

    // The spec doesn't say anything about the type of the property name here.
    // Numbers can be converted to a string, which is fine and what other engines do.
    // However, since a symbol cannot be converted to a string, it cannot be a supported property name. Return early if it's a symbol.
    if (property_key.is_symbol())
        return false;

    // 1. If P is not a supported property name of O, then return false.
    // NOTE: This is in it's own variable to enforce the type.
    // FIXME: Can this throw?
    Vector<String> supported_property_names = impl().supported_property_names();
    auto property_key_string = property_key.to_string();
    if (!supported_property_names.contains_slow(property_key_string))
        return false;

    // 2. If O has an own property named P, then return false.
    // NOTE: This has to be done manually instead of using Object::has_own_property, as that would use the overridden internal_get_own_property.
    auto own_property_named_p = MUST(Object::internal_get_own_property(property_key));

    if (own_property_named_p.has_value())
        return false;

    // 3. If O implements an interface that has the [LegacyOverrideBuiltIns] extended attribute, then return true.
    return true;
}

JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> DOMStringMapWrapper::legacy_platform_object_get_own_property_for_get_own_property_slot(JS::PropertyKey const& property_name) const
{

    [[maybe_unused]] auto& global_object = this->global_object();

    // 1. If the result of running the named property visibility algorithm with property name P and object O is true, then:
    if (TRY(is_named_property_exposed_on_object(property_name))) {
        // FIXME: It's unfortunate that this is done twice, once in is_named_property_exposed_on_object and here.
        auto property_name_string = property_name.to_string();

        auto value = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl().determine_value_of_named_property(property_name_string); }));

        // 5. Let desc be a newly created Property Descriptor with no fields.
        JS::PropertyDescriptor descriptor;

        // 6. Set desc.[[Value]] to the result of converting value to an ECMAScript value.
        descriptor.value = wrap_for_legacy_platform_object_get_own_property(global_object, value);

        descriptor.writable = true;

        descriptor.enumerable = true;

        // 9. Set desc.[[Configurable]] to true.
        descriptor.configurable = true;

        // 10. Return desc.
        return descriptor;
    }

    return TRY(Object::internal_get_own_property(property_name));
}

JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> DOMStringMapWrapper::legacy_platform_object_get_own_property_for_set_slot(JS::PropertyKey const& property_name) const
{

    [[maybe_unused]] auto& global_object = this->global_object();

    return TRY(Object::internal_get_own_property(property_name));
}

static JS::ThrowCompletionOr<void> invoke_named_property_setter(JS::GlobalObject& global_object, HTML::DOMStringMap& impl, String const& property_name, JS::Value value)
{
    // 1. Let creating be true if P is not a supported property name, and false otherwise.
    // NOTE: This is in it's own variable to enforce the type.
    // FIXME: Can this throw?
    Vector<String> supported_property_names = impl.supported_property_names();
    [[maybe_unused]] bool creating = !supported_property_names.contains_slow(property_name);

    String converted_value;
    if (value.is_null() && false) {
        converted_value = String::empty();
    } else {
        converted_value = TRY(value.to_string(global_object));
    }

    if (creating) {
        // 5.1. If creating is true, then perform the steps listed in the interface description to set the value of a new named property with P as the name and value as the value.
        TRY(throw_dom_exception_if_needed(global_object, [&] { impl.set_value_of_new_named_property(property_name, converted_value); }));
    } else {
        // 5.2 Otherwise, creating is false. Perform the steps listed in the interface description to set the value of an existing named property with P as the name and value as the value.
        TRY(throw_dom_exception_if_needed(global_object, [&] { impl.set_value_of_existing_named_property(property_name, converted_value); }));
    }

    return {};
}

JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> DOMStringMapWrapper::internal_get_own_property(JS::PropertyKey const& property_name) const
{
    // 1. Return LegacyPlatformObjectGetOwnProperty(O, P, false).
    return TRY(legacy_platform_object_get_own_property_for_get_own_property_slot(property_name));
}

JS::ThrowCompletionOr<bool> DOMStringMapWrapper::internal_set(JS::PropertyKey const& property_name, JS::Value value, JS::Value receiver)
{
    [[maybe_unused]] auto& global_object = this->global_object();

    // 1. If O and Receiver are the same object, then:
    if (JS::same_value(this, receiver)) {

        if (property_name.is_string()) {
            // 1. Invoke the named property setter on O with P and V.
            TRY(invoke_named_property_setter(global_object, impl(), property_name.as_string(), value));

            // 2. Return true.
            return true;
        }

    }

    // 2. Let ownDesc be LegacyPlatformObjectGetOwnProperty(O, P, true).
    auto own_descriptor = TRY(legacy_platform_object_get_own_property_for_set_slot(property_name));

    // 3. Perform ? OrdinarySetWithOwnDescriptor(O, P, V, Receiver, ownDesc).
    // NOTE: The spec says "perform" instead of "return", meaning nothing will be returned on this path according to the spec, which isn't possible to do.
    //       Let's treat it as though it says "return" instead of "perform".
    return ordinary_set_with_own_descriptor(property_name, value, receiver, own_descriptor);
}

JS::ThrowCompletionOr<bool> DOMStringMapWrapper::internal_define_own_property(JS::PropertyKey const& property_name, JS::PropertyDescriptor const& property_descriptor)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    if (property_name.is_string()) {
        auto& property_name_as_string = property_name.as_string();

        // 1. Let creating be true if P is not a supported property name, and false otherwise.
        // NOTE: This is in it's own variable to enforce the type.
        // FIXME: Can this throw?
        Vector<String> supported_property_names = impl().supported_property_names();
        [[maybe_unused]] bool creating = !supported_property_names.contains_slow(property_name_as_string);

        {

            // 1. If the result of calling IsDataDescriptor(Desc) is false, then return false.
            if (!property_descriptor.is_data_descriptor())
                return false;

            // 2. Invoke the named property setter on O with P and Desc.[[Value]].
            TRY(invoke_named_property_setter(global_object, impl(), property_name_as_string, *property_descriptor.value));

            // 3. Return true.
            return true;

        }

    }

    // property_descriptor is a const&, thus we need to create a copy here to set [[Configurable]]
    JS::PropertyDescriptor descriptor_copy(property_descriptor);
    descriptor_copy.configurable = true;

    // 4. Return OrdinaryDefineOwnProperty(O, P, Desc).
    return Object::internal_define_own_property(property_name, descriptor_copy);

}

JS::ThrowCompletionOr<bool> DOMStringMapWrapper::internal_delete(JS::PropertyKey const& property_name)
{
    [[maybe_unused]] auto& global_object = this->global_object();

    if (TRY(is_named_property_exposed_on_object(property_name))) {

        // FIXME: It's unfortunate that this is done twice, once in is_named_property_exposed_on_object and here.
        auto property_name_string = property_name.to_string();

        // 1. Perform the steps listed in the interface description to delete an existing named property with P as the name.
        bool succeeded = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl().delete_existing_named_property(property_name_string); }));

        // 2. If the steps indicated that the deletion failed, then return false.
        if (!succeeded)
            return false;

        // 5. Return true.
        return true;

    }

    // 3. If O has an own property with name P, then:
    auto own_property_named_p_descriptor = TRY(Object::internal_get_own_property(property_name));

    if (own_property_named_p_descriptor.has_value()) {
        // 1. If the property is not configurable, then return false.
        // 2. Otherwise, remove the property from O.
        if (*own_property_named_p_descriptor->configurable)
            storage_delete(property_name);
        else
            return false;
    }

    // 4. Return true.
    return true;
}

JS::ThrowCompletionOr<bool> DOMStringMapWrapper::internal_prevent_extensions()
{
    // 1. Return false.
    return false;
}

JS::ThrowCompletionOr<JS::MarkedVector<JS::Value>> DOMStringMapWrapper::internal_own_property_keys() const
{
    auto& vm = this->vm();

    // 1. Let keys be a new empty list of ECMAScript String and Symbol values.
    JS::MarkedVector<JS::Value> keys { heap() };


    for (auto& named_property : impl().supported_property_names()) {
        if (TRY(is_named_property_exposed_on_object(named_property)))
            keys.append(js_string(vm, named_property));
    }

    // 4. For each P of O’s own property keys that is a String, in ascending chronological order of property creation, append P to keys.
    for (auto& it : shape().property_table_ordered()) {
        if (it.key.is_string())
            keys.append(it.key.to_value(vm));
    }

    // 5. For each P of O’s own property keys that is a Symbol, in ascending chronological order of property creation, append P to keys.
    for (auto& it : shape().property_table_ordered()) {
        if (it.key.is_symbol())
            keys.append(it.key.to_value(vm));
    }

    // FIXME: 6. Assert: keys has no duplicate items.

    // 7. Return keys.
    return { move(keys) };
}

} // namespace Web::Bindings

