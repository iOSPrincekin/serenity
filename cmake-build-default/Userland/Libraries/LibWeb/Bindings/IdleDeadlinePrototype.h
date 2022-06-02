
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class IdleDeadlinePrototype : public JS::Object {
    JS_OBJECT(IdleDeadlinePrototype, JS::Object);
public:
    explicit IdleDeadlinePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~IdleDeadlinePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(time_remaining);
        
    JS_DECLARE_NATIVE_FUNCTION(did_timeout_getter);

};

} // namespace Web::Bindings
    
