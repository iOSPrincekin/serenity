
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLOptGroupElementPrototype : public JS::Object {
    JS_OBJECT(HTMLOptGroupElementPrototype, JS::Object);
public:
    explicit HTMLOptGroupElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLOptGroupElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(disabled_getter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_setter);

    JS_DECLARE_NATIVE_FUNCTION(label_getter);

    JS_DECLARE_NATIVE_FUNCTION(label_setter);

};

} // namespace Web::Bindings
    
