
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLPreElementPrototype : public JS::Object {
    JS_OBJECT(HTMLPreElementPrototype, JS::Object);
public:
    explicit HTMLPreElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLPreElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
