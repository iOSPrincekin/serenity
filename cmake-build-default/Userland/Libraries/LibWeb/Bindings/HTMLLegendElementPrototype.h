
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLLegendElementPrototype : public JS::Object {
    JS_OBJECT(HTMLLegendElementPrototype, JS::Object);
public:
    explicit HTMLLegendElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLLegendElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

};

} // namespace Web::Bindings
    
