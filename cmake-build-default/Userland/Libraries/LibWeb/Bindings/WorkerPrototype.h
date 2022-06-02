
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class WorkerPrototype : public JS::Object {
    JS_OBJECT(WorkerPrototype, JS::Object);
public:
    explicit WorkerPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WorkerPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(terminate);
        
    JS_DECLARE_NATIVE_FUNCTION(post_message);
        
    JS_DECLARE_NATIVE_FUNCTION(onmessage_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmessage_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmessageerror_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmessageerror_setter);

};

} // namespace Web::Bindings
    
