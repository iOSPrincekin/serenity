
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLMediaElementPrototype : public JS::Object {
    JS_OBJECT(HTMLMediaElementPrototype, JS::Object);
public:
    explicit HTMLMediaElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMediaElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(can_play_type);
        
    JS_DECLARE_NATIVE_FUNCTION(src_getter);

    JS_DECLARE_NATIVE_FUNCTION(src_setter);

    JS_DECLARE_NATIVE_FUNCTION(autoplay_getter);

    JS_DECLARE_NATIVE_FUNCTION(autoplay_setter);

    JS_DECLARE_NATIVE_FUNCTION(loop_getter);

    JS_DECLARE_NATIVE_FUNCTION(loop_setter);

    JS_DECLARE_NATIVE_FUNCTION(controls_getter);

    JS_DECLARE_NATIVE_FUNCTION(controls_setter);

};

} // namespace Web::Bindings
    
