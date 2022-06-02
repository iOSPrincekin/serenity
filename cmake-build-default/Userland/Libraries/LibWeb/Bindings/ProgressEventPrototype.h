
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class ProgressEventPrototype : public JS::Object {
    JS_OBJECT(ProgressEventPrototype, JS::Object);
public:
    explicit ProgressEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ProgressEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(length_computable_getter);

    JS_DECLARE_NATIVE_FUNCTION(loaded_getter);

    JS_DECLARE_NATIVE_FUNCTION(total_getter);

};

} // namespace Web::Bindings
    
