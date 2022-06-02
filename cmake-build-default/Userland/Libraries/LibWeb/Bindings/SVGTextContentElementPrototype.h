
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGTextContentElementPrototype : public JS::Object {
    JS_OBJECT(SVGTextContentElementPrototype, JS::Object);
public:
    explicit SVGTextContentElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGTextContentElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(get_number_of_chars);
        
};

} // namespace Web::Bindings
    
