
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class ErrorEventPrototype : public JS::Object {
    JS_OBJECT(ErrorEventPrototype, JS::Object);
public:
    explicit ErrorEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ErrorEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(message_getter);

    JS_DECLARE_NATIVE_FUNCTION(filename_getter);

    JS_DECLARE_NATIVE_FUNCTION(lineno_getter);

    JS_DECLARE_NATIVE_FUNCTION(colno_getter);

    JS_DECLARE_NATIVE_FUNCTION(error_getter);

};

} // namespace Web::Bindings
    
