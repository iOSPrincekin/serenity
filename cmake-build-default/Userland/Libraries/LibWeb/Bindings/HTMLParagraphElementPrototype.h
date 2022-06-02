
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLParagraphElementPrototype : public JS::Object {
    JS_OBJECT(HTMLParagraphElementPrototype, JS::Object);
public:
    explicit HTMLParagraphElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLParagraphElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

};

} // namespace Web::Bindings
    
