
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGLengthPrototype : public JS::Object {
    JS_OBJECT(SVGLengthPrototype, JS::Object);
public:
    explicit SVGLengthPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGLengthPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(unit_type_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_setter);

};

} // namespace Web::Bindings
    
