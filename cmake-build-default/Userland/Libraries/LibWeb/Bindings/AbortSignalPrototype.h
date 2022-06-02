
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class AbortSignalPrototype : public JS::Object {
    JS_OBJECT(AbortSignalPrototype, JS::Object);
public:
    explicit AbortSignalPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~AbortSignalPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(throw_if_aborted);
        
    JS_DECLARE_NATIVE_FUNCTION(aborted_getter);

    JS_DECLARE_NATIVE_FUNCTION(reason_getter);

    JS_DECLARE_NATIVE_FUNCTION(onabort_getter);

    JS_DECLARE_NATIVE_FUNCTION(onabort_setter);

};

} // namespace Web::Bindings
    
