
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class MessageChannelPrototype : public JS::Object {
    JS_OBJECT(MessageChannelPrototype, JS::Object);
public:
    explicit MessageChannelPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MessageChannelPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(port1_getter);

    JS_DECLARE_NATIVE_FUNCTION(port2_getter);

};

} // namespace Web::Bindings
    
