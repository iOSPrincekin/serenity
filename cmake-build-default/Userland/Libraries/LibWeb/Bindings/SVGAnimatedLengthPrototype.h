
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGAnimatedLengthPrototype : public JS::Object {
    JS_OBJECT(SVGAnimatedLengthPrototype, JS::Object);
public:
    explicit SVGAnimatedLengthPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGAnimatedLengthPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(base_val_getter);

    JS_DECLARE_NATIVE_FUNCTION(anim_val_getter);

};

} // namespace Web::Bindings
    
