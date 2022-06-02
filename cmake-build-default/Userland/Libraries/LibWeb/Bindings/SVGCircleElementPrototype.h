
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGCircleElementPrototype : public JS::Object {
    JS_OBJECT(SVGCircleElementPrototype, JS::Object);
public:
    explicit SVGCircleElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGCircleElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(cx_getter);

    JS_DECLARE_NATIVE_FUNCTION(cy_getter);

    JS_DECLARE_NATIVE_FUNCTION(r_getter);

};

} // namespace Web::Bindings
    
