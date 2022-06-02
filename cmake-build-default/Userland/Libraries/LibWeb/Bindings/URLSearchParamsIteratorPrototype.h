
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class URLSearchParamsIteratorPrototype : public JS::Object {
    JS_OBJECT(URLSearchParamsIteratorPrototype, JS::Object);
public:
    explicit URLSearchParamsIteratorPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~URLSearchParamsIteratorPrototype() override;

private:
    JS_DECLARE_NATIVE_FUNCTION(next);
};

} // namespace Web::Bindings
    
