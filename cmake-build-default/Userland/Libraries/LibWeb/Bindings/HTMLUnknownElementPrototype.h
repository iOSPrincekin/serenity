
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLUnknownElementPrototype : public JS::Object {
    JS_OBJECT(HTMLUnknownElementPrototype, JS::Object);
public:
    explicit HTMLUnknownElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLUnknownElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
