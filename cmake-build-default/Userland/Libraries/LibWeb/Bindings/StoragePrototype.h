
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class StoragePrototype : public JS::Object {
    JS_OBJECT(StoragePrototype, JS::Object);
public:
    explicit StoragePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~StoragePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(get_item);
        
    JS_DECLARE_NATIVE_FUNCTION(set_item);
        
    JS_DECLARE_NATIVE_FUNCTION(clear);
        
    JS_DECLARE_NATIVE_FUNCTION(remove_item);
        
    JS_DECLARE_NATIVE_FUNCTION(key);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
