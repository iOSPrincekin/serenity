/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/Object.h>

namespace JS {

class StringObject : public Object {
    JS_OBJECT(StringObject, Object);

public:
    static StringObject* create(GlobalObject&, PrimitiveString&, Object& prototype);

    StringObject(PrimitiveString&, Object& prototype);
    virtual void initialize(GlobalObject&) override;
    virtual ~StringObject() override;

    const PrimitiveString& primitive_string() const { return m_string; }
    virtual Value value_of() const override
    {
        return Value(&m_string);
    }

private:
    virtual Optional<PropertyDescriptor> internal_get_own_property(PropertyName const&) const override;
    virtual bool internal_define_own_property(PropertyName const&, PropertyDescriptor const&) override;
    virtual MarkedValueList internal_own_property_keys() const override;

    virtual bool is_string_object() const final { return true; }
    virtual void visit_edges(Visitor&) override;

    PrimitiveString& m_string;
};

template<>
inline bool Object::fast_is<StringObject>() const { return is_string_object(); }

}
