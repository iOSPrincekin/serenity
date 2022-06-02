
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGEllipseElementPrototype : public JS::Object {
    JS_OBJECT(SVGEllipseElementPrototype, JS::Object);
public:
    explicit SVGEllipseElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGEllipseElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(cx_getter);

    JS_DECLARE_NATIVE_FUNCTION(cy_getter);

    JS_DECLARE_NATIVE_FUNCTION(rx_getter);

    JS_DECLARE_NATIVE_FUNCTION(ry_getter);

};

} // namespace Web::Bindings
    
