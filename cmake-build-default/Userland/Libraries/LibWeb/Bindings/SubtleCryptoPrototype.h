
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SubtleCryptoPrototype : public JS::Object {
    JS_OBJECT(SubtleCryptoPrototype, JS::Object);
public:
    explicit SubtleCryptoPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SubtleCryptoPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(digest);
        
};

} // namespace Web::Bindings
    
