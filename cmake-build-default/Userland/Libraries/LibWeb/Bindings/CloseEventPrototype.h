
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CloseEventPrototype : public JS::Object {
    JS_OBJECT(CloseEventPrototype, JS::Object);
public:
    explicit CloseEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CloseEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(was_clean_getter);

    JS_DECLARE_NATIVE_FUNCTION(code_getter);

    JS_DECLARE_NATIVE_FUNCTION(reason_getter);

};

} // namespace Web::Bindings
    
