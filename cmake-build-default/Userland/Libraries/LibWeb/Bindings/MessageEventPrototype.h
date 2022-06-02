
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class MessageEventPrototype : public JS::Object {
    JS_OBJECT(MessageEventPrototype, JS::Object);
public:
    explicit MessageEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MessageEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(data_getter);

    JS_DECLARE_NATIVE_FUNCTION(origin_getter);

    JS_DECLARE_NATIVE_FUNCTION(last_event_id_getter);

};

} // namespace Web::Bindings
    
