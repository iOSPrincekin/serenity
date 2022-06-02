
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLIFrameElementPrototype : public JS::Object {
    JS_OBJECT(HTMLIFrameElementPrototype, JS::Object);
public:
    explicit HTMLIFrameElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLIFrameElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(get_svg_document);
        
    JS_DECLARE_NATIVE_FUNCTION(src_getter);

    JS_DECLARE_NATIVE_FUNCTION(src_setter);

    JS_DECLARE_NATIVE_FUNCTION(srcdoc_getter);

    JS_DECLARE_NATIVE_FUNCTION(srcdoc_setter);

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(allow_getter);

    JS_DECLARE_NATIVE_FUNCTION(allow_setter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_setter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_setter);

    JS_DECLARE_NATIVE_FUNCTION(allow_fullscreen_getter);

    JS_DECLARE_NATIVE_FUNCTION(allow_fullscreen_setter);

    JS_DECLARE_NATIVE_FUNCTION(content_document_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

    JS_DECLARE_NATIVE_FUNCTION(scrolling_getter);

    JS_DECLARE_NATIVE_FUNCTION(scrolling_setter);

    JS_DECLARE_NATIVE_FUNCTION(frame_border_getter);

    JS_DECLARE_NATIVE_FUNCTION(frame_border_setter);

    JS_DECLARE_NATIVE_FUNCTION(margin_height_getter);

    JS_DECLARE_NATIVE_FUNCTION(margin_height_setter);

    JS_DECLARE_NATIVE_FUNCTION(margin_width_getter);

    JS_DECLARE_NATIVE_FUNCTION(margin_width_setter);

};

} // namespace Web::Bindings
    
