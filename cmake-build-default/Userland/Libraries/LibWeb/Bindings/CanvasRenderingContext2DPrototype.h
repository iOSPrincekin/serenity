
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CanvasRenderingContext2DPrototype : public JS::Object {
    JS_OBJECT(CanvasRenderingContext2DPrototype, JS::Object);
public:
    explicit CanvasRenderingContext2DPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CanvasRenderingContext2DPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(create_conic_gradient);
        
    JS_DECLARE_NATIVE_FUNCTION(arc);
        
    JS_DECLARE_NATIVE_FUNCTION(fill_rect);
        
    JS_DECLARE_NATIVE_FUNCTION(create_radial_gradient);
        
    JS_DECLARE_NATIVE_FUNCTION(clear_rect);
        
    JS_DECLARE_NATIVE_FUNCTION(is_context_lost);
        
    JS_DECLARE_NATIVE_FUNCTION(put_image_data);
        
    JS_DECLARE_NATIVE_FUNCTION(close_path);
        
    JS_DECLARE_NATIVE_FUNCTION(quadratic_curve_to);
        
    JS_DECLARE_NATIVE_FUNCTION(save);
        
    JS_DECLARE_NATIVE_FUNCTION(restore);
        
    JS_DECLARE_NATIVE_FUNCTION(fill);
        
    JS_DECLARE_NATIVE_FUNCTION(clip);
        
    JS_DECLARE_NATIVE_FUNCTION(bezier_curve_to);
        
    JS_DECLARE_NATIVE_FUNCTION(rect);
        
    JS_DECLARE_NATIVE_FUNCTION(create_linear_gradient);
        
    JS_DECLARE_NATIVE_FUNCTION(set_transform);
        
    JS_DECLARE_NATIVE_FUNCTION(scale);
        
    JS_DECLARE_NATIVE_FUNCTION(measure_text);
        
    JS_DECLARE_NATIVE_FUNCTION(ellipse);
        
    JS_DECLARE_NATIVE_FUNCTION(reset_transform);
        
    JS_DECLARE_NATIVE_FUNCTION(create_image_data);
        
    JS_DECLARE_NATIVE_FUNCTION(stroke_text);
        
    JS_DECLARE_NATIVE_FUNCTION(translate);
        
    JS_DECLARE_NATIVE_FUNCTION(stroke);
        
    JS_DECLARE_NATIVE_FUNCTION(line_to);
        
    JS_DECLARE_NATIVE_FUNCTION(rotate);
        
    JS_DECLARE_NATIVE_FUNCTION(begin_path);
        
    JS_DECLARE_NATIVE_FUNCTION(transform);
        
    JS_DECLARE_NATIVE_FUNCTION(draw_image);
        
    JS_DECLARE_NATIVE_FUNCTION(draw_image0);

    JS_DECLARE_NATIVE_FUNCTION(draw_image1);

    JS_DECLARE_NATIVE_FUNCTION(draw_image2);

    JS_DECLARE_NATIVE_FUNCTION(get_image_data);
        
    JS_DECLARE_NATIVE_FUNCTION(fill_text);
        
    JS_DECLARE_NATIVE_FUNCTION(move_to);
        
    JS_DECLARE_NATIVE_FUNCTION(stroke_rect);
        
    JS_DECLARE_NATIVE_FUNCTION(reset);
        
    JS_DECLARE_NATIVE_FUNCTION(fill_style_getter);

    JS_DECLARE_NATIVE_FUNCTION(fill_style_setter);

    JS_DECLARE_NATIVE_FUNCTION(stroke_style_getter);

    JS_DECLARE_NATIVE_FUNCTION(stroke_style_setter);

    JS_DECLARE_NATIVE_FUNCTION(line_width_getter);

    JS_DECLARE_NATIVE_FUNCTION(line_width_setter);

    JS_DECLARE_NATIVE_FUNCTION(canvas_getter);

};

} // namespace Web::Bindings
    
