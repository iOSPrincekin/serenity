
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLDivElementPrototype : public JS::Object {
    JS_OBJECT(HTMLDivElementPrototype, JS::Object);
public:
    explicit HTMLDivElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDivElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

};

} // namespace Web::Bindings
    
