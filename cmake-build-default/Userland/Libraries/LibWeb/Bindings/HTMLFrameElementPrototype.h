
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLFrameElementPrototype : public JS::Object {
    JS_OBJECT(HTMLFrameElementPrototype, JS::Object);
public:
    explicit HTMLFrameElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFrameElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(scrolling_getter);

    JS_DECLARE_NATIVE_FUNCTION(scrolling_setter);

    JS_DECLARE_NATIVE_FUNCTION(src_getter);

    JS_DECLARE_NATIVE_FUNCTION(src_setter);

    JS_DECLARE_NATIVE_FUNCTION(frame_border_getter);

    JS_DECLARE_NATIVE_FUNCTION(frame_border_setter);

    JS_DECLARE_NATIVE_FUNCTION(long_desc_getter);

    JS_DECLARE_NATIVE_FUNCTION(long_desc_setter);

};

} // namespace Web::Bindings
    
