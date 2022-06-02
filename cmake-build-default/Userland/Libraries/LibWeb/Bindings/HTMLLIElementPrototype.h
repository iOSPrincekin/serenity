
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLLIElementPrototype : public JS::Object {
    JS_OBJECT(HTMLLIElementPrototype, JS::Object);
public:
    explicit HTMLLIElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLLIElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

};

} // namespace Web::Bindings
    
