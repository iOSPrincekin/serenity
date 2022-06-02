
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLMarqueeElementPrototype : public JS::Object {
    JS_OBJECT(HTMLMarqueeElementPrototype, JS::Object);
public:
    explicit HTMLMarqueeElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMarqueeElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(behavior_getter);

    JS_DECLARE_NATIVE_FUNCTION(behavior_setter);

    JS_DECLARE_NATIVE_FUNCTION(bg_color_getter);

    JS_DECLARE_NATIVE_FUNCTION(bg_color_setter);

    JS_DECLARE_NATIVE_FUNCTION(direction_getter);

    JS_DECLARE_NATIVE_FUNCTION(direction_setter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_setter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_setter);

};

} // namespace Web::Bindings
    
