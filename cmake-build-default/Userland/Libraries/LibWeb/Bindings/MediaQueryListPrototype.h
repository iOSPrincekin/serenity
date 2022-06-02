
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class MediaQueryListPrototype : public JS::Object {
    JS_OBJECT(MediaQueryListPrototype, JS::Object);
public:
    explicit MediaQueryListPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MediaQueryListPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(remove_listener);
        
    JS_DECLARE_NATIVE_FUNCTION(add_listener);
        
    JS_DECLARE_NATIVE_FUNCTION(media_getter);

    JS_DECLARE_NATIVE_FUNCTION(matches_getter);

    JS_DECLARE_NATIVE_FUNCTION(onchange_getter);

    JS_DECLARE_NATIVE_FUNCTION(onchange_setter);

};

} // namespace Web::Bindings
    
