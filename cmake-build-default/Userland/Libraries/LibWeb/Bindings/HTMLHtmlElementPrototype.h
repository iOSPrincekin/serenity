
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLHtmlElementPrototype : public JS::Object {
    JS_OBJECT(HTMLHtmlElementPrototype, JS::Object);
public:
    explicit HTMLHtmlElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLHtmlElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(version_getter);

    JS_DECLARE_NATIVE_FUNCTION(version_setter);

};

} // namespace Web::Bindings
    
