
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class PromiseRejectionEventPrototype : public JS::Object {
    JS_OBJECT(PromiseRejectionEventPrototype, JS::Object);
public:
    explicit PromiseRejectionEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~PromiseRejectionEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(promise_getter);

    JS_DECLARE_NATIVE_FUNCTION(reason_getter);

};

} // namespace Web::Bindings
    
