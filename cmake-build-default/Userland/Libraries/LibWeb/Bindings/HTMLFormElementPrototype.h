
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLFormElementPrototype : public JS::Object {
    JS_OBJECT(HTMLFormElementPrototype, JS::Object);
public:
    explicit HTMLFormElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFormElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(submit);
        
    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(rel_getter);

    JS_DECLARE_NATIVE_FUNCTION(rel_setter);

    JS_DECLARE_NATIVE_FUNCTION(accept_charset_getter);

    JS_DECLARE_NATIVE_FUNCTION(accept_charset_setter);

    JS_DECLARE_NATIVE_FUNCTION(no_validate_getter);

    JS_DECLARE_NATIVE_FUNCTION(no_validate_setter);

    JS_DECLARE_NATIVE_FUNCTION(elements_getter);

    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
