
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DOMRectListPrototype : public JS::Object {
    JS_OBJECT(DOMRectListPrototype, JS::Object);
public:
    explicit DOMRectListPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMRectListPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
