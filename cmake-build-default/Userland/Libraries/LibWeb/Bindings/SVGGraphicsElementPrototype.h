
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGGraphicsElementPrototype : public JS::Object {
    JS_OBJECT(SVGGraphicsElementPrototype, JS::Object);
public:
    explicit SVGGraphicsElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGGraphicsElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
