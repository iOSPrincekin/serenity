
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLHeadingElementPrototype : public JS::Object {
    JS_OBJECT(HTMLHeadingElementPrototype, JS::Object);
public:
    explicit HTMLHeadingElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLHeadingElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

};

} // namespace Web::Bindings
    
