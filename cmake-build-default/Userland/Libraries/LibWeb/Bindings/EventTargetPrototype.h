
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class EventTargetPrototype : public JS::Object {
    JS_OBJECT(EventTargetPrototype, JS::Object);
public:
    explicit EventTargetPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~EventTargetPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(remove_event_listener);
        
    JS_DECLARE_NATIVE_FUNCTION(add_event_listener);
        
    JS_DECLARE_NATIVE_FUNCTION(dispatch_event);
        
};

} // namespace Web::Bindings
    
