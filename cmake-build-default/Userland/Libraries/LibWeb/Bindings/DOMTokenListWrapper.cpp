
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DOMTokenListPrototype.h>
#include <LibWeb/Bindings/DOMTokenListWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/DOM/DOMTokenList.h>

#if __has_include(<LibWeb/Bindings/DOMTokenListWrapper.h>)
#   include <LibWeb/Bindings/DOMTokenListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMTokenListWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMTokenListWrapperFactory.h>
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

DOMTokenListWrapper* DOMTokenListWrapper::create(JS::GlobalObject& global_object, DOM::DOMTokenList& impl)
{
    return global_object.heap().allocate<DOMTokenListWrapper>(global_object, global_object, impl);
}


DOMTokenListWrapper::DOMTokenListWrapper(JS::GlobalObject& global_object, DOM::DOMTokenList& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<DOMTokenListPrototype>("DOMTokenList"))
    , m_impl(impl)
{
}

void DOMTokenListWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "DOMTokenList"), JS::Attribute::Configurable);
}

DOMTokenListWrapper::~DOMTokenListWrapper()
{
}

DOMTokenListWrapper* wrap(JS::GlobalObject& global_object, DOM::DOMTokenList& impl)
{
    return static_cast<DOMTokenListWrapper*>(wrap_impl(global_object, impl));
}

static JS::Value wrap_for_legacy_platform_object_get_own_property(JS::GlobalObject& global_object, [[maybe_unused]] auto& retval)
{
    [[maybe_unused]] auto& vm = global_object.vm();

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> DOMTokenListWrapper::legacy_platform_object_get_own_property_for_get_own_property_slot(JS::PropertyKey const& property_name) const
{

    [[maybe_unused]] auto& global_object = this->global_object();

    if (property_name.is_number()) {
        // 1. Let index be the result of calling ToUint32(P).
        u32 index = property_name.as_number();

        // 2. If index is a supported property index, then:
        // FIXME: Can this throw?
        if (impl().is_supported_property_index(index)) {

            auto value = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl().item(index); }));

            // 5. Let desc be a newly created Property Descriptor with no fields.
            JS::PropertyDescriptor descriptor;

            // 6. Set desc.[[Value]] to the result of converting value to an ECMAScript value.
            descriptor.value = wrap_for_legacy_platform_object_get_own_property(global_object, value);

            descriptor.writable = false;


            // 8. Set desc.[[Enumerable]] and desc.[[Configurable]] to true.
            descriptor.enumerable = true;
            descriptor.configurable = true;

            // 9. Return desc.
            return descriptor;
        }

        // 3. Set ignoreNamedProps to true.
        // NOTE: To reduce complexity of WrapperGenerator, this just returns early instead of keeping track of another variable.
        return TRY(Object::internal_get_own_property(property_name));
    }

    return TRY(Object::internal_get_own_property(property_name));
}

JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> DOMTokenListWrapper::legacy_platform_object_get_own_property_for_set_slot(JS::PropertyKey const& property_name) const
{

    [[maybe_unused]] auto& global_object = this->global_object();

    if (property_name.is_number()) {
        // 1. Let index be the result of calling ToUint32(P).
        u32 index = property_name.as_number();

        // 2. If index is a supported property index, then:
        // FIXME: Can this throw?
        if (impl().is_supported_property_index(index)) {

            auto value = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl().item(index); }));

            // 5. Let desc be a newly created Property Descriptor with no fields.
            JS::PropertyDescriptor descriptor;

            // 6. Set desc.[[Value]] to the result of converting value to an ECMAScript value.
            descriptor.value = wrap_for_legacy_platform_object_get_own_property(global_object, value);

            descriptor.writable = false;


            // 8. Set desc.[[Enumerable]] and desc.[[Configurable]] to true.
            descriptor.enumerable = true;
            descriptor.configurable = true;

            // 9. Return desc.
            return descriptor;
        }

        // 3. Set ignoreNamedProps to true.
        // NOTE: To reduce complexity of WrapperGenerator, this just returns early instead of keeping track of another variable.
        return TRY(Object::internal_get_own_property(property_name));
    }

    return TRY(Object::internal_get_own_property(property_name));
}

JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> DOMTokenListWrapper::internal_get_own_property(JS::PropertyKey const& property_name) const
{
    // 1. Return LegacyPlatformObjectGetOwnProperty(O, P, false).
    return TRY(legacy_platform_object_get_own_property_for_get_own_property_slot(property_name));
}

JS::ThrowCompletionOr<bool> DOMTokenListWrapper::internal_set(JS::PropertyKey const& property_name, JS::Value value, JS::Value receiver)
{
    [[maybe_unused]] auto& global_object = this->global_object();

    // 2. Let ownDesc be LegacyPlatformObjectGetOwnProperty(O, P, true).
    auto own_descriptor = TRY(legacy_platform_object_get_own_property_for_set_slot(property_name));

    // 3. Perform ? OrdinarySetWithOwnDescriptor(O, P, V, Receiver, ownDesc).
    // NOTE: The spec says "perform" instead of "return", meaning nothing will be returned on this path according to the spec, which isn't possible to do.
    //       Let's treat it as though it says "return" instead of "perform".
    return ordinary_set_with_own_descriptor(property_name, value, receiver, own_descriptor);
}

JS::ThrowCompletionOr<bool> DOMTokenListWrapper::internal_define_own_property(JS::PropertyKey const& property_name, JS::PropertyDescriptor const& property_descriptor)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    if (property_name.is_number()) {
        // 1. If the result of calling IsDataDescriptor(Desc) is false, then return false.
        if (!property_descriptor.is_data_descriptor())
            return false;

        return false;

    }

    // property_descriptor is a const&, thus we need to create a copy here to set [[Configurable]]
    JS::PropertyDescriptor descriptor_copy(property_descriptor);
    descriptor_copy.configurable = true;

    // 4. Return OrdinaryDefineOwnProperty(O, P, Desc).
    return Object::internal_define_own_property(property_name, descriptor_copy);

}

JS::ThrowCompletionOr<bool> DOMTokenListWrapper::internal_delete(JS::PropertyKey const& property_name)
{
    [[maybe_unused]] auto& global_object = this->global_object();

    if (property_name.is_number()) {
        // 1. Let index be the result of calling ToUint32(P).
        u32 index = property_name.as_number();

        // 2. If index is not a supported property index, then return true.
        // FIXME: Can this throw?
        if (!impl().is_supported_property_index(index))
            return true;

        // 3. Return false.
        return false;
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

JS::ThrowCompletionOr<bool> DOMTokenListWrapper::internal_prevent_extensions()
{
    // 1. Return false.
    return false;
}

JS::ThrowCompletionOr<JS::MarkedVector<JS::Value>> DOMTokenListWrapper::internal_own_property_keys() const
{
    auto& vm = this->vm();

    // 1. Let keys be a new empty list of ECMAScript String and Symbol values.
    JS::MarkedVector<JS::Value> keys { heap() };


    for (u64 index = 0; index <= NumericLimits<u32>::max(); ++index) {
        if (impl().is_supported_property_index(index))
            keys.append(js_string(vm, String::number(index)));
        else
            break;
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

