
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DOMStringMapPrototype : public JS::Object {
    JS_OBJECT(DOMStringMapPrototype, JS::Object);
public:
    explicit DOMStringMapPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMStringMapPrototype() override;
private:

};

} // namespace Web::Bindings
    
