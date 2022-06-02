
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGGeometryElementPrototype : public JS::Object {
    JS_OBJECT(SVGGeometryElementPrototype, JS::Object);
public:
    explicit SVGGeometryElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGGeometryElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
