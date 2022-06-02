
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class TextPrototype : public JS::Object {
    JS_OBJECT(TextPrototype, JS::Object);
public:
    explicit TextPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TextPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(split_text);
        
};

} // namespace Web::Bindings
    
