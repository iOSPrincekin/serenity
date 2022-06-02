
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSStyleDeclarationPrototype : public JS::Object {
    JS_OBJECT(CSSStyleDeclarationPrototype, JS::Object);
public:
    explicit CSSStyleDeclarationPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSStyleDeclarationPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(get_property_value);
        
    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(get_property_priority);
        
    JS_DECLARE_NATIVE_FUNCTION(remove_property);
        
    JS_DECLARE_NATIVE_FUNCTION(set_property);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
