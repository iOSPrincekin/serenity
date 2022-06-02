
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLSpanElementPrototype : public JS::Object {
    JS_OBJECT(HTMLSpanElementPrototype, JS::Object);
public:
    explicit HTMLSpanElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLSpanElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
