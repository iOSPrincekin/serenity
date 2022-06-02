
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGDefsElementPrototype : public JS::Object {
    JS_OBJECT(SVGDefsElementPrototype, JS::Object);
public:
    explicit SVGDefsElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGDefsElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
