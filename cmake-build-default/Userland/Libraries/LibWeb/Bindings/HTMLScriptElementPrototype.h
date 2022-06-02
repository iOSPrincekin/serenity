
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLScriptElementPrototype : public JS::Object {
    JS_OBJECT(HTMLScriptElementPrototype, JS::Object);
public:
    explicit HTMLScriptElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLScriptElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(src_getter);

    JS_DECLARE_NATIVE_FUNCTION(src_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

    JS_DECLARE_NATIVE_FUNCTION(no_module_getter);

    JS_DECLARE_NATIVE_FUNCTION(no_module_setter);

    JS_DECLARE_NATIVE_FUNCTION(defer_getter);

    JS_DECLARE_NATIVE_FUNCTION(defer_setter);

    JS_DECLARE_NATIVE_FUNCTION(integrity_getter);

    JS_DECLARE_NATIVE_FUNCTION(integrity_setter);

    JS_DECLARE_NATIVE_FUNCTION(charset_getter);

    JS_DECLARE_NATIVE_FUNCTION(charset_setter);

    JS_DECLARE_NATIVE_FUNCTION(event_getter);

    JS_DECLARE_NATIVE_FUNCTION(event_setter);

    JS_DECLARE_NATIVE_FUNCTION(html_for_getter);

    JS_DECLARE_NATIVE_FUNCTION(html_for_setter);

};

} // namespace Web::Bindings
    
