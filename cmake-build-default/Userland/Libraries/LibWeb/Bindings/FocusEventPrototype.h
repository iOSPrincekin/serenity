
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class FocusEventPrototype : public JS::Object {
    JS_OBJECT(FocusEventPrototype, JS::Object);
public:
    explicit FocusEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~FocusEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(related_target_getter);

};

} // namespace Web::Bindings
    
