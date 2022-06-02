
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTableRowElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTableRowElementPrototype, JS::Object);
public:
    explicit HTMLTableRowElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTableRowElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

    JS_DECLARE_NATIVE_FUNCTION(ch_getter);

    JS_DECLARE_NATIVE_FUNCTION(ch_setter);

    JS_DECLARE_NATIVE_FUNCTION(ch_off_getter);

    JS_DECLARE_NATIVE_FUNCTION(ch_off_setter);

    JS_DECLARE_NATIVE_FUNCTION(v_align_getter);

    JS_DECLARE_NATIVE_FUNCTION(v_align_setter);

    JS_DECLARE_NATIVE_FUNCTION(bg_color_getter);

    JS_DECLARE_NATIVE_FUNCTION(bg_color_setter);

    JS_DECLARE_NATIVE_FUNCTION(row_index_getter);

    JS_DECLARE_NATIVE_FUNCTION(section_row_index_getter);

    JS_DECLARE_NATIVE_FUNCTION(cells_getter);

};

} // namespace Web::Bindings
    
