
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class IntersectionObserverPrototype : public JS::Object {
    JS_OBJECT(IntersectionObserverPrototype, JS::Object);
public:
    explicit IntersectionObserverPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~IntersectionObserverPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(observe);
        
    JS_DECLARE_NATIVE_FUNCTION(unobserve);
        
    JS_DECLARE_NATIVE_FUNCTION(disconnect);
        
};

} // namespace Web::Bindings
    
