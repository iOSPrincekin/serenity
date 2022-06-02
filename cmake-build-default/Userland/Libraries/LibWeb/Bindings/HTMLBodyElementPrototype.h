
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLBodyElementPrototype : public JS::Object {
    JS_OBJECT(HTMLBodyElementPrototype, JS::Object);
public:
    explicit HTMLBodyElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLBodyElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(text_getter);

    JS_DECLARE_NATIVE_FUNCTION(text_setter);

    JS_DECLARE_NATIVE_FUNCTION(link_getter);

    JS_DECLARE_NATIVE_FUNCTION(link_setter);

    JS_DECLARE_NATIVE_FUNCTION(v_link_getter);

    JS_DECLARE_NATIVE_FUNCTION(v_link_setter);

    JS_DECLARE_NATIVE_FUNCTION(a_link_getter);

    JS_DECLARE_NATIVE_FUNCTION(a_link_setter);

    JS_DECLARE_NATIVE_FUNCTION(bg_color_getter);

    JS_DECLARE_NATIVE_FUNCTION(bg_color_setter);

    JS_DECLARE_NATIVE_FUNCTION(background_getter);

    JS_DECLARE_NATIVE_FUNCTION(background_setter);

};

} // namespace Web::Bindings
    
