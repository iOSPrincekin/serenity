
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DOMRectReadOnlyPrototype : public JS::Object {
    JS_OBJECT(DOMRectReadOnlyPrototype, JS::Object);
public:
    explicit DOMRectReadOnlyPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMRectReadOnlyPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(x_getter);

    JS_DECLARE_NATIVE_FUNCTION(y_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(top_getter);

    JS_DECLARE_NATIVE_FUNCTION(right_getter);

    JS_DECLARE_NATIVE_FUNCTION(bottom_getter);

    JS_DECLARE_NATIVE_FUNCTION(left_getter);

};

} // namespace Web::Bindings
    
