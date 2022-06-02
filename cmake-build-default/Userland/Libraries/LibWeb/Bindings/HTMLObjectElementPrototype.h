
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLObjectElementPrototype : public JS::Object {
    JS_OBJECT(HTMLObjectElementPrototype, JS::Object);
public:
    explicit HTMLObjectElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLObjectElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(get_svg_document);
        
    JS_DECLARE_NATIVE_FUNCTION(data_getter);

    JS_DECLARE_NATIVE_FUNCTION(data_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(use_map_getter);

    JS_DECLARE_NATIVE_FUNCTION(use_map_setter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_setter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_setter);

    JS_DECLARE_NATIVE_FUNCTION(content_document_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

    JS_DECLARE_NATIVE_FUNCTION(archive_getter);

    JS_DECLARE_NATIVE_FUNCTION(archive_setter);

    JS_DECLARE_NATIVE_FUNCTION(code_getter);

    JS_DECLARE_NATIVE_FUNCTION(code_setter);

    JS_DECLARE_NATIVE_FUNCTION(declare_getter);

    JS_DECLARE_NATIVE_FUNCTION(declare_setter);

    JS_DECLARE_NATIVE_FUNCTION(standby_getter);

    JS_DECLARE_NATIVE_FUNCTION(standby_setter);

    JS_DECLARE_NATIVE_FUNCTION(code_type_getter);

    JS_DECLARE_NATIVE_FUNCTION(code_type_setter);

    JS_DECLARE_NATIVE_FUNCTION(border_getter);

    JS_DECLARE_NATIVE_FUNCTION(border_setter);

};

} // namespace Web::Bindings
    
