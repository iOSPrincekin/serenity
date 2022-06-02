
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLBRElementPrototype : public JS::Object {
    JS_OBJECT(HTMLBRElementPrototype, JS::Object);
public:
    explicit HTMLBRElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLBRElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(clear_getter);

    JS_DECLARE_NATIVE_FUNCTION(clear_setter);

};

} // namespace Web::Bindings
    
