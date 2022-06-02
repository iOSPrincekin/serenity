
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class MediaListPrototype : public JS::Object {
    JS_OBJECT(MediaListPrototype, JS::Object);
public:
    explicit MediaListPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MediaListPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(delete_medium);
        
    JS_DECLARE_NATIVE_FUNCTION(append_medium);
        
    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(to_string);
        
    JS_DECLARE_NATIVE_FUNCTION(media_text_getter);

    JS_DECLARE_NATIVE_FUNCTION(media_text_setter);

    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
