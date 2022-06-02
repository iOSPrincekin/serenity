
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLProgressElementPrototype : public JS::Object {
    JS_OBJECT(HTMLProgressElementPrototype, JS::Object);
public:
    explicit HTMLProgressElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLProgressElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(value_getter);

    JS_DECLARE_NATIVE_FUNCTION(value_setter);

    JS_DECLARE_NATIVE_FUNCTION(max_getter);

    JS_DECLARE_NATIVE_FUNCTION(max_setter);

    JS_DECLARE_NATIVE_FUNCTION(position_getter);

};

} // namespace Web::Bindings
    
