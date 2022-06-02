
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CanvasGradientPrototype : public JS::Object {
    JS_OBJECT(CanvasGradientPrototype, JS::Object);
public:
    explicit CanvasGradientPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CanvasGradientPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(add_color_stop);
        
};

} // namespace Web::Bindings
    
