
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class XMLHttpRequestEventTargetPrototype : public JS::Object {
    JS_OBJECT(XMLHttpRequestEventTargetPrototype, JS::Object);
public:
    explicit XMLHttpRequestEventTargetPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~XMLHttpRequestEventTargetPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(onloadstart_getter);

    JS_DECLARE_NATIVE_FUNCTION(onloadstart_setter);

    JS_DECLARE_NATIVE_FUNCTION(onprogress_getter);

    JS_DECLARE_NATIVE_FUNCTION(onprogress_setter);

    JS_DECLARE_NATIVE_FUNCTION(onabort_getter);

    JS_DECLARE_NATIVE_FUNCTION(onabort_setter);

    JS_DECLARE_NATIVE_FUNCTION(onerror_getter);

    JS_DECLARE_NATIVE_FUNCTION(onerror_setter);

    JS_DECLARE_NATIVE_FUNCTION(onload_getter);

    JS_DECLARE_NATIVE_FUNCTION(onload_setter);

    JS_DECLARE_NATIVE_FUNCTION(ontimeout_getter);

    JS_DECLARE_NATIVE_FUNCTION(ontimeout_setter);

    JS_DECLARE_NATIVE_FUNCTION(onloadend_getter);

    JS_DECLARE_NATIVE_FUNCTION(onloadend_setter);

};

} // namespace Web::Bindings
    
