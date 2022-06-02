
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class MessagePortPrototype : public JS::Object {
    JS_OBJECT(MessagePortPrototype, JS::Object);
public:
    explicit MessagePortPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MessagePortPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(close);
        
    JS_DECLARE_NATIVE_FUNCTION(post_message);
        
    JS_DECLARE_NATIVE_FUNCTION(start);
        
    JS_DECLARE_NATIVE_FUNCTION(onmessage_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmessage_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmessageerror_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmessageerror_setter);

};

} // namespace Web::Bindings
    
