
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class TextDecoderPrototype : public JS::Object {
    JS_OBJECT(TextDecoderPrototype, JS::Object);
public:
    explicit TextDecoderPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TextDecoderPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(decode);
        
    JS_DECLARE_NATIVE_FUNCTION(encoding_getter);

    JS_DECLARE_NATIVE_FUNCTION(fatal_getter);

    JS_DECLARE_NATIVE_FUNCTION(ignore_bom_getter);

};

} // namespace Web::Bindings
    
