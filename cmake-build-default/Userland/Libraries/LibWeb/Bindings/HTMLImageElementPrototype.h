
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLImageElementPrototype : public JS::Object {
    JS_OBJECT(HTMLImageElementPrototype, JS::Object);
public:
    explicit HTMLImageElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLImageElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(src_getter);

    JS_DECLARE_NATIVE_FUNCTION(src_setter);

    JS_DECLARE_NATIVE_FUNCTION(alt_getter);

    JS_DECLARE_NATIVE_FUNCTION(alt_setter);

    JS_DECLARE_NATIVE_FUNCTION(srcset_getter);

    JS_DECLARE_NATIVE_FUNCTION(srcset_setter);

    JS_DECLARE_NATIVE_FUNCTION(sizes_getter);

    JS_DECLARE_NATIVE_FUNCTION(sizes_setter);

    JS_DECLARE_NATIVE_FUNCTION(use_map_getter);

    JS_DECLARE_NATIVE_FUNCTION(use_map_setter);

    JS_DECLARE_NATIVE_FUNCTION(is_map_getter);

    JS_DECLARE_NATIVE_FUNCTION(is_map_setter);

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

    JS_DECLARE_NATIVE_FUNCTION(border_getter);

    JS_DECLARE_NATIVE_FUNCTION(border_setter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_setter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_setter);

    JS_DECLARE_NATIVE_FUNCTION(natural_width_getter);

    JS_DECLARE_NATIVE_FUNCTION(natural_height_getter);

};

} // namespace Web::Bindings
    
