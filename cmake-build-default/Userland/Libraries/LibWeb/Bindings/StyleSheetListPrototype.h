
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class StyleSheetListPrototype : public JS::Object {
    JS_OBJECT(StyleSheetListPrototype, JS::Object);
public:
    explicit StyleSheetListPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~StyleSheetListPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
