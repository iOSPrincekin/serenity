
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class ResizeObserverPrototype : public JS::Object {
    JS_OBJECT(ResizeObserverPrototype, JS::Object);
public:
    explicit ResizeObserverPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ResizeObserverPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(observe);
        
    JS_DECLARE_NATIVE_FUNCTION(unobserve);
        
    JS_DECLARE_NATIVE_FUNCTION(disconnect);
        
};

} // namespace Web::Bindings
    
