
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLDataElementPrototype : public JS::Object {
    JS_OBJECT(HTMLDataElementPrototype, JS::Object);
public:
    explicit HTMLDataElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDataElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(value_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_setter);

};

} // namespace Web::Bindings
    
