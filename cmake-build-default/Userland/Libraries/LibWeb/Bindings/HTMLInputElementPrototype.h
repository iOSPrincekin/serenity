
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLInputElementPrototype : public JS::Object {
    JS_OBJECT(HTMLInputElementPrototype, JS::Object);
public:
    explicit HTMLInputElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLInputElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(form_getter);

    JS_DECLARE_NATIVE_FUNCTION(accept_getter);

    JS_DECLARE_NATIVE_FUNCTION(accept_setter);

    JS_DECLARE_NATIVE_FUNCTION(alt_getter);

    JS_DECLARE_NATIVE_FUNCTION(alt_setter);

    JS_DECLARE_NATIVE_FUNCTION(max_getter);

    JS_DECLARE_NATIVE_FUNCTION(max_setter);

    JS_DECLARE_NATIVE_FUNCTION(min_getter);

    JS_DECLARE_NATIVE_FUNCTION(min_setter);

    JS_DECLARE_NATIVE_FUNCTION(pattern_getter);

    JS_DECLARE_NATIVE_FUNCTION(pattern_setter);

    JS_DECLARE_NATIVE_FUNCTION(placeholder_getter);

    JS_DECLARE_NATIVE_FUNCTION(placeholder_setter);

    JS_DECLARE_NATIVE_FUNCTION(src_getter);

    JS_DECLARE_NATIVE_FUNCTION(src_setter);

    JS_DECLARE_NATIVE_FUNCTION(step_getter);

    JS_DECLARE_NATIVE_FUNCTION(step_setter);

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(dir_name_getter);

    JS_DECLARE_NATIVE_FUNCTION(dir_name_setter);

    JS_DECLARE_NATIVE_FUNCTION(default_value_getter);

    JS_DECLARE_NATIVE_FUNCTION(default_value_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

    JS_DECLARE_NATIVE_FUNCTION(value_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_setter);

    JS_DECLARE_NATIVE_FUNCTION(checked_getter);

    JS_DECLARE_NATIVE_FUNCTION(checked_setter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_getter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_setter);

    JS_DECLARE_NATIVE_FUNCTION(default_checked_getter);

    JS_DECLARE_NATIVE_FUNCTION(default_checked_setter);

    JS_DECLARE_NATIVE_FUNCTION(form_no_validate_getter);

    JS_DECLARE_NATIVE_FUNCTION(form_no_validate_setter);

    JS_DECLARE_NATIVE_FUNCTION(form_target_getter);

    JS_DECLARE_NATIVE_FUNCTION(form_target_setter);

    JS_DECLARE_NATIVE_FUNCTION(multiple_getter);

    JS_DECLARE_NATIVE_FUNCTION(multiple_setter);

    JS_DECLARE_NATIVE_FUNCTION(read_only_getter);

    JS_DECLARE_NATIVE_FUNCTION(read_only_setter);

    JS_DECLARE_NATIVE_FUNCTION(required_getter);

    JS_DECLARE_NATIVE_FUNCTION(required_setter);

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

    JS_DECLARE_NATIVE_FUNCTION(use_map_getter);

    JS_DECLARE_NATIVE_FUNCTION(use_map_setter);

};

} // namespace Web::Bindings
    
