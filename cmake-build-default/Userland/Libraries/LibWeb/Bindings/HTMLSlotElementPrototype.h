
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLSlotElementPrototype : public JS::Object {
    JS_OBJECT(HTMLSlotElementPrototype, JS::Object);
public:
    explicit HTMLSlotElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLSlotElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

};

} // namespace Web::Bindings
    
