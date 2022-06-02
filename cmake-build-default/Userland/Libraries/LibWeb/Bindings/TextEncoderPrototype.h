
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class TextEncoderPrototype : public JS::Object {
    JS_OBJECT(TextEncoderPrototype, JS::Object);
public:
    explicit TextEncoderPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TextEncoderPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(encode);
        
    JS_DECLARE_NATIVE_FUNCTION(encoding_getter);

};

} // namespace Web::Bindings
    
