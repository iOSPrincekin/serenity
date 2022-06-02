
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class ProcessingInstructionPrototype : public JS::Object {
    JS_OBJECT(ProcessingInstructionPrototype, JS::Object);
public:
    explicit ProcessingInstructionPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ProcessingInstructionPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(target_getter);

};

} // namespace Web::Bindings
    
