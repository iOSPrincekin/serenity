
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLOutputElementPrototype : public JS::Object {
    JS_OBJECT(HTMLOutputElementPrototype, JS::Object);
public:
    explicit HTMLOutputElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLOutputElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

};

} // namespace Web::Bindings
    
