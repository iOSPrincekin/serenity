
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class NamedNodeMapPrototype : public JS::Object {
    JS_OBJECT(NamedNodeMapPrototype, JS::Object);
public:
    explicit NamedNodeMapPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~NamedNodeMapPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(remove_named_item);
        
    JS_DECLARE_NATIVE_FUNCTION(get_named_item);
        
    JS_DECLARE_NATIVE_FUNCTION(set_named_item);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
