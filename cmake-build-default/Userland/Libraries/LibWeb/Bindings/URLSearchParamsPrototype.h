
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class URLSearchParamsPrototype : public JS::Object {
    JS_OBJECT(URLSearchParamsPrototype, JS::Object);
public:
    explicit URLSearchParamsPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~URLSearchParamsPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(has);
        
    JS_DECLARE_NATIVE_FUNCTION(append);
        
    JS_DECLARE_NATIVE_FUNCTION(get_all);
        
    JS_DECLARE_NATIVE_FUNCTION(sort);
        
    JS_DECLARE_NATIVE_FUNCTION(get);
        
    JS_DECLARE_NATIVE_FUNCTION(delete_);
        
    JS_DECLARE_NATIVE_FUNCTION(set);
        
    JS_DECLARE_NATIVE_FUNCTION(to_string);
        
    JS_DECLARE_NATIVE_FUNCTION(entries);
    JS_DECLARE_NATIVE_FUNCTION(for_each);
    JS_DECLARE_NATIVE_FUNCTION(keys);
    JS_DECLARE_NATIVE_FUNCTION(values);
        
};

} // namespace Web::Bindings
    
