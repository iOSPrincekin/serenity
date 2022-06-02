
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLCollectionPrototype : public JS::Object {
    JS_OBJECT(HTMLCollectionPrototype, JS::Object);
public:
    explicit HTMLCollectionPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLCollectionPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(named_item);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
