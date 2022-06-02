
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SubmitEventPrototype : public JS::Object {
    JS_OBJECT(SubmitEventPrototype, JS::Object);
public:
    explicit SubmitEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SubmitEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(submitter_getter);

};

} // namespace Web::Bindings
    
