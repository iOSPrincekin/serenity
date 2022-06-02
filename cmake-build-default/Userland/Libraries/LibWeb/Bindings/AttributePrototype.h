
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class AttributePrototype : public JS::Object {
    JS_OBJECT(AttributePrototype, JS::Object);
public:
    explicit AttributePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~AttributePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(namespace_uri_getter);

    JS_DECLARE_NATIVE_FUNCTION(prefix_getter);

    JS_DECLARE_NATIVE_FUNCTION(local_name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_setter);

    JS_DECLARE_NATIVE_FUNCTION(owner_element_getter);

    JS_DECLARE_NATIVE_FUNCTION(specified_getter);

};

} // namespace Web::Bindings
    
