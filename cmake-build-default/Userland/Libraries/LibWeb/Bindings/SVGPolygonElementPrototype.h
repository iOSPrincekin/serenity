
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGPolygonElementPrototype : public JS::Object {
    JS_OBJECT(SVGPolygonElementPrototype, JS::Object);
public:
    explicit SVGPolygonElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGPolygonElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
