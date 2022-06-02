
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLButtonElementPrototype : public JS::Object {
    JS_OBJECT(HTMLButtonElementPrototype, JS::Object);
public:
    explicit HTMLButtonElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLButtonElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(form_no_validate_getter);

    JS_DECLARE_NATIVE_FUNCTION(form_no_validate_setter);

    JS_DECLARE_NATIVE_FUNCTION(form_target_getter);

    JS_DECLARE_NATIVE_FUNCTION(form_target_setter);

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(value_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

};

} // namespace Web::Bindings
    
