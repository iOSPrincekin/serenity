
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class ScreenPrototype : public JS::Object {
    JS_OBJECT(ScreenPrototype, JS::Object);
public:
    explicit ScreenPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ScreenPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(avail_width_getter);

    JS_DECLARE_NATIVE_FUNCTION(avail_height_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(color_depth_getter);

    JS_DECLARE_NATIVE_FUNCTION(pixel_depth_getter);

};

} // namespace Web::Bindings
    
