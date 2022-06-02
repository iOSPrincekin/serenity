
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CharacterDataPrototype : public JS::Object {
    JS_OBJECT(CharacterDataPrototype, JS::Object);
public:
    explicit CharacterDataPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CharacterDataPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(remove);
        
    JS_DECLARE_NATIVE_FUNCTION(substring_data);
        
    JS_DECLARE_NATIVE_FUNCTION(after);
        
    JS_DECLARE_NATIVE_FUNCTION(replace_data);
        
    JS_DECLARE_NATIVE_FUNCTION(replace_with);
        
    JS_DECLARE_NATIVE_FUNCTION(before);
        
    JS_DECLARE_NATIVE_FUNCTION(data_getter);

    JS_DECLARE_NATIVE_FUNCTION(data_setter);

    JS_DECLARE_NATIVE_FUNCTION(length_getter);

    JS_DECLARE_NATIVE_FUNCTION(next_element_sibling_getter);

    JS_DECLARE_NATIVE_FUNCTION(previous_element_sibling_getter);

};

} // namespace Web::Bindings
    
