
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class UIEventPrototype : public JS::Object {
    JS_OBJECT(UIEventPrototype, JS::Object);
public:
    explicit UIEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~UIEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(init_ui_event);
        
    JS_DECLARE_NATIVE_FUNCTION(view_getter);

    JS_DECLARE_NATIVE_FUNCTION(detail_getter);

    JS_DECLARE_NATIVE_FUNCTION(which_getter);

};

} // namespace Web::Bindings
    
