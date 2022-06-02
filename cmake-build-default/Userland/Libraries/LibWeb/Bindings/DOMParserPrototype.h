
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DOMParserPrototype : public JS::Object {
    JS_OBJECT(DOMParserPrototype, JS::Object);
public:
    explicit DOMParserPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMParserPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(parse_from_string);
        
};

} // namespace Web::Bindings
    
