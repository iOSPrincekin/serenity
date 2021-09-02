/*
 * Copyright (c) 2021, Tim Flynn <trflynn89@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/TypeCasts.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/Intl/Locale.h>
#include <LibJS/Runtime/Intl/LocalePrototype.h>

namespace JS::Intl {

static Locale* typed_this(GlobalObject& global_object)
{
    auto& vm = global_object.vm();

    auto* this_object = vm.this_value(global_object).to_object(global_object);
    if (!this_object)
        return nullptr;

    if (!is<Locale>(this_object)) {
        vm.throw_exception<TypeError>(global_object, ErrorType::NotA, "Intl.Locale");
        return nullptr;
    }

    return static_cast<Locale*>(this_object);
}

// 14.3 Properties of the Intl.Locale Prototype Object, https://tc39.es/ecma402/#sec-properties-of-intl-locale-prototype-object
LocalePrototype::LocalePrototype(GlobalObject& global_object)
    : Object(*global_object.object_prototype())
{
}

void LocalePrototype::initialize(GlobalObject& global_object)
{
    Object::initialize(global_object);

    auto& vm = this->vm();

    u8 attr = Attribute::Writable | Attribute::Configurable;
    define_native_function(vm.names.toString, to_string, 0, attr);

    // 14.3.2 Intl.Locale.prototype[ @@toStringTag ], https://tc39.es/ecma402/#sec-Intl.Locale.prototype-@@tostringtag
    define_direct_property(*vm.well_known_symbol_to_string_tag(), js_string(vm, "Intl.Locale"), Attribute::Configurable);
}

// 14.3.5 Intl.Locale.prototype.toString ( ), https://tc39.es/ecma402/#sec-Intl.Locale.prototype.toString
JS_DEFINE_NATIVE_FUNCTION(LocalePrototype::to_string)
{
    // 1. Let loc be the this value.
    // 2. Perform ? RequireInternalSlot(loc, [[InitializedLocale]]).
    auto* locale_object = typed_this(global_object);
    if (!locale_object)
        return {};

    // 3. Return loc.[[Locale]].
    return js_string(vm, locale_object->locale());
}

}
