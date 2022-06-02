
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLParamElementPrototype : public JS::Object {
    JS_OBJECT(HTMLParamElementPrototype, JS::Object);
public:
    explicit HTMLParamElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLParamElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(value_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

    JS_DECLARE_NATIVE_FUNCTION(value_type_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_type_setter);

};

} // namespace Web::Bindings
    
