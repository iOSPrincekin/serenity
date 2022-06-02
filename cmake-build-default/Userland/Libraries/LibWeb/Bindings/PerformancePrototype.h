
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class PerformancePrototype : public JS::Object {
    JS_OBJECT(PerformancePrototype, JS::Object);
public:
    explicit PerformancePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~PerformancePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(now);
        
    JS_DECLARE_NATIVE_FUNCTION(time_origin_getter);

    JS_DECLARE_NATIVE_FUNCTION(timing_getter);

};

} // namespace Web::Bindings
    
