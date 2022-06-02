
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGClipPathElementPrototype : public JS::Object {
    JS_OBJECT(SVGClipPathElementPrototype, JS::Object);
public:
    explicit SVGClipPathElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGClipPathElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
