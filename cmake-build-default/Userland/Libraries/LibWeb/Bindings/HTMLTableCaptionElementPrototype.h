
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTableCaptionElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTableCaptionElementPrototype, JS::Object);
public:
    explicit HTMLTableCaptionElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTableCaptionElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(align_getter);

    JS_DECLARE_NATIVE_FUNCTION(align_setter);

};

} // namespace Web::Bindings
    
