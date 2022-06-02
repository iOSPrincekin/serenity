
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DOMTokenListPrototype : public JS::Object {
    JS_OBJECT(DOMTokenListPrototype, JS::Object);
public:
    explicit DOMTokenListPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMTokenListPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(remove);
        
    JS_DECLARE_NATIVE_FUNCTION(add);
        
    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(replace);
        
    JS_DECLARE_NATIVE_FUNCTION(contains);
        
    JS_DECLARE_NATIVE_FUNCTION(toggle);
        
    JS_DECLARE_NATIVE_FUNCTION(supports);
        
    JS_DECLARE_NATIVE_FUNCTION(to_string);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_setter);

};

} // namespace Web::Bindings
    
