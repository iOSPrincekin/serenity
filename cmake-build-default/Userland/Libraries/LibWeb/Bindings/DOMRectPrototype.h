
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DOMRectPrototype : public JS::Object {
    JS_OBJECT(DOMRectPrototype, JS::Object);
public:
    explicit DOMRectPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMRectPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(x_getter);

    JS_DECLARE_NATIVE_FUNCTION(x_setter);

    JS_DECLARE_NATIVE_FUNCTION(y_getter);

    JS_DECLARE_NATIVE_FUNCTION(y_setter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_setter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_setter);

};

} // namespace Web::Bindings
    
