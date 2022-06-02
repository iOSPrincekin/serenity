
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CustomEventPrototype : public JS::Object {
    JS_OBJECT(CustomEventPrototype, JS::Object);
public:
    explicit CustomEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CustomEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(init_custom_event);
        
    JS_DECLARE_NATIVE_FUNCTION(detail_getter);

};

} // namespace Web::Bindings
    
