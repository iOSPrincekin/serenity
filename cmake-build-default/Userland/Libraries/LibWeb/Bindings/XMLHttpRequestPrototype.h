
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class XMLHttpRequestPrototype : public JS::Object {
    JS_OBJECT(XMLHttpRequestPrototype, JS::Object);
public:
    explicit XMLHttpRequestPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~XMLHttpRequestPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(send);
        
    JS_DECLARE_NATIVE_FUNCTION(get_all_response_headers);
        
    JS_DECLARE_NATIVE_FUNCTION(set_request_header);
        
    JS_DECLARE_NATIVE_FUNCTION(get_response_header);
        
    JS_DECLARE_NATIVE_FUNCTION(open);
        
    JS_DECLARE_NATIVE_FUNCTION(open0);

    JS_DECLARE_NATIVE_FUNCTION(open1);

    JS_DECLARE_NATIVE_FUNCTION(override_mime_type);
        
    JS_DECLARE_NATIVE_FUNCTION(ready_state_getter);

    JS_DECLARE_NATIVE_FUNCTION(status_getter);

    JS_DECLARE_NATIVE_FUNCTION(response_text_getter);

    JS_DECLARE_NATIVE_FUNCTION(response_getter);

    JS_DECLARE_NATIVE_FUNCTION(response_type_getter);

    JS_DECLARE_NATIVE_FUNCTION(response_type_setter);

    JS_DECLARE_NATIVE_FUNCTION(onreadystatechange_getter);

    JS_DECLARE_NATIVE_FUNCTION(onreadystatechange_setter);

};

} // namespace Web::Bindings
    
