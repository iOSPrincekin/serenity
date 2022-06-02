
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGPolylineElementPrototype : public JS::Object {
    JS_OBJECT(SVGPolylineElementPrototype, JS::Object);
public:
    explicit SVGPolylineElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGPolylineElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
