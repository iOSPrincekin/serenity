
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class KeyboardEventPrototype : public JS::Object {
    JS_OBJECT(KeyboardEventPrototype, JS::Object);
public:
    explicit KeyboardEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~KeyboardEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(get_modifier_state);
        
    JS_DECLARE_NATIVE_FUNCTION(key_getter);

    JS_DECLARE_NATIVE_FUNCTION(code_getter);

    JS_DECLARE_NATIVE_FUNCTION(location_getter);

    JS_DECLARE_NATIVE_FUNCTION(ctrl_key_getter);

    JS_DECLARE_NATIVE_FUNCTION(shift_key_getter);

    JS_DECLARE_NATIVE_FUNCTION(alt_key_getter);

    JS_DECLARE_NATIVE_FUNCTION(meta_key_getter);

    JS_DECLARE_NATIVE_FUNCTION(repeat_getter);

    JS_DECLARE_NATIVE_FUNCTION(is_composing_getter);

    JS_DECLARE_NATIVE_FUNCTION(char_code_getter);

    JS_DECLARE_NATIVE_FUNCTION(key_code_getter);

};

} // namespace Web::Bindings
    
