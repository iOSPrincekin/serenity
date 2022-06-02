
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLLabelElementPrototype : public JS::Object {
    JS_OBJECT(HTMLLabelElementPrototype, JS::Object);
public:
    explicit HTMLLabelElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLLabelElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(html_for_getter);

    JS_DECLARE_NATIVE_FUNCTION(html_for_setter);

};

} // namespace Web::Bindings
    
