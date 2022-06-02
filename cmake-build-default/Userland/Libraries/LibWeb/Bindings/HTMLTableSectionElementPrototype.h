
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTableSectionElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTableSectionElementPrototype, JS::Object);
public:
    explicit HTMLTableSectionElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTableSectionElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(insert_row);
        
    JS_DECLARE_NATIVE_FUNCTION(delete_row);
        
    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

    JS_DECLARE_NATIVE_FUNCTION(ch_getter);

    JS_DECLARE_NATIVE_FUNCTION(ch_setter);

    JS_DECLARE_NATIVE_FUNCTION(ch_off_getter);

    JS_DECLARE_NATIVE_FUNCTION(ch_off_setter);

    JS_DECLARE_NATIVE_FUNCTION(v_align_getter);

    JS_DECLARE_NATIVE_FUNCTION(v_align_setter);

    JS_DECLARE_NATIVE_FUNCTION(rows_getter);

};

} // namespace Web::Bindings
    
