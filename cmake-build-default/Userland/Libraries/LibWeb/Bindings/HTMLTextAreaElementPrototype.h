
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTextAreaElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTextAreaElementPrototype, JS::Object);
public:
    explicit HTMLTextAreaElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTextAreaElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(placeholder_getter);

    JS_DECLARE_NATIVE_FUNCTION(placeholder_setter);

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

    JS_DECLARE_NATIVE_FUNCTION(wrap_getter);

    JS_DECLARE_NATIVE_FUNCTION(wrap_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_getter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_setter);

    JS_DECLARE_NATIVE_FUNCTION(read_only_getter);

    JS_DECLARE_NATIVE_FUNCTION(read_only_setter);

    JS_DECLARE_NATIVE_FUNCTION(required_getter);

    JS_DECLARE_NATIVE_FUNCTION(required_setter);

};

} // namespace Web::Bindings
    
