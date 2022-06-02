
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGRectElementPrototype : public JS::Object {
    JS_OBJECT(SVGRectElementPrototype, JS::Object);
public:
    explicit SVGRectElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGRectElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(x_getter);

    JS_DECLARE_NATIVE_FUNCTION(y_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(rx_getter);

    JS_DECLARE_NATIVE_FUNCTION(ry_getter);

};

} // namespace Web::Bindings
    
