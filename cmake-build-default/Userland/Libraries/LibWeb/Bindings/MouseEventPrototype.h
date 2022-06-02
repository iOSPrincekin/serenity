
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class MouseEventPrototype : public JS::Object {
    JS_OBJECT(MouseEventPrototype, JS::Object);
public:
    explicit MouseEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MouseEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(offset_x_getter);

    JS_DECLARE_NATIVE_FUNCTION(offset_y_getter);

    JS_DECLARE_NATIVE_FUNCTION(client_x_getter);

    JS_DECLARE_NATIVE_FUNCTION(client_y_getter);

    JS_DECLARE_NATIVE_FUNCTION(x_getter);

    JS_DECLARE_NATIVE_FUNCTION(y_getter);

    JS_DECLARE_NATIVE_FUNCTION(button_getter);

};

} // namespace Web::Bindings
    
