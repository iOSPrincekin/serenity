
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGPathElementPrototype : public JS::Object {
    JS_OBJECT(SVGPathElementPrototype, JS::Object);
public:
    explicit SVGPathElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGPathElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
