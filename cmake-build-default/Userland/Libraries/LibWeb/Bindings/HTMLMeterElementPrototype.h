
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLMeterElementPrototype : public JS::Object {
    JS_OBJECT(HTMLMeterElementPrototype, JS::Object);
public:
    explicit HTMLMeterElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMeterElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
