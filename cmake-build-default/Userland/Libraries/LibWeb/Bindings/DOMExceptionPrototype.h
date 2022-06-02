
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DOMExceptionPrototype : public JS::Object {
    JS_OBJECT(DOMExceptionPrototype, JS::Object);
public:
    explicit DOMExceptionPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMExceptionPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(message_getter);

    JS_DECLARE_NATIVE_FUNCTION(code_getter);

};

} // namespace Web::Bindings
    
