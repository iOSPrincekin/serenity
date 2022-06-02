
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLCanvasElementPrototype : public JS::Object {
    JS_OBJECT(HTMLCanvasElementPrototype, JS::Object);
public:
    explicit HTMLCanvasElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLCanvasElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(to_data_url);
        
    JS_DECLARE_NATIVE_FUNCTION(get_context);
        
    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(width_setter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_setter);

};

} // namespace Web::Bindings
    
