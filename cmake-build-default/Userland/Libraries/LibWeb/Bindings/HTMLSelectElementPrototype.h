
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLSelectElementPrototype : public JS::Object {
    JS_OBJECT(HTMLSelectElementPrototype, JS::Object);
public:
    explicit HTMLSelectElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLSelectElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(add);
        
    JS_DECLARE_NATIVE_FUNCTION(disabled_getter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_setter);

    JS_DECLARE_NATIVE_FUNCTION(multiple_getter);

    JS_DECLARE_NATIVE_FUNCTION(multiple_setter);

    JS_DECLARE_NATIVE_FUNCTION(required_getter);

    JS_DECLARE_NATIVE_FUNCTION(required_setter);

    JS_DECLARE_NATIVE_FUNCTION(options_getter);

    JS_DECLARE_NATIVE_FUNCTION(selected_index_getter);

    JS_DECLARE_NATIVE_FUNCTION(selected_index_setter);

};

} // namespace Web::Bindings
    
