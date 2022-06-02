
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTableCellElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTableCellElementPrototype, JS::Object);
public:
    explicit HTMLTableCellElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTableCellElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(col_span_getter);

    JS_DECLARE_NATIVE_FUNCTION(col_span_setter);

    JS_DECLARE_NATIVE_FUNCTION(row_span_getter);

    JS_DECLARE_NATIVE_FUNCTION(row_span_setter);

    JS_DECLARE_NATIVE_FUNCTION(headers_getter);

    JS_DECLARE_NATIVE_FUNCTION(headers_setter);

    JS_DECLARE_NATIVE_FUNCTION(abbr_getter);

    JS_DECLARE_NATIVE_FUNCTION(abbr_setter);

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

    JS_DECLARE_NATIVE_FUNCTION(axis_getter);

    JS_DECLARE_NATIVE_FUNCTION(axis_setter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_setter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_setter);

    JS_DECLARE_NATIVE_FUNCTION(ch_getter);

    JS_DECLARE_NATIVE_FUNCTION(ch_setter);

    JS_DECLARE_NATIVE_FUNCTION(ch_off_getter);

    JS_DECLARE_NATIVE_FUNCTION(ch_off_setter);

    JS_DECLARE_NATIVE_FUNCTION(no_wrap_getter);

    JS_DECLARE_NATIVE_FUNCTION(no_wrap_setter);

    JS_DECLARE_NATIVE_FUNCTION(v_align_getter);

    JS_DECLARE_NATIVE_FUNCTION(v_align_setter);

    JS_DECLARE_NATIVE_FUNCTION(bg_color_getter);

    JS_DECLARE_NATIVE_FUNCTION(bg_color_setter);

};

} // namespace Web::Bindings
    
