
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGSVGElementPrototype : public JS::Object {
    JS_OBJECT(SVGSVGElementPrototype, JS::Object);
public:
    explicit SVGSVGElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGSVGElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
