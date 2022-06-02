
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class AbortControllerPrototype : public JS::Object {
    JS_OBJECT(AbortControllerPrototype, JS::Object);
public:
    explicit AbortControllerPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~AbortControllerPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(abort);
        
    JS_DECLARE_NATIVE_FUNCTION(signal_getter);

};

} // namespace Web::Bindings
    
