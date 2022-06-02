
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class PageTransitionEventPrototype : public JS::Object {
    JS_OBJECT(PageTransitionEventPrototype, JS::Object);
public:
    explicit PageTransitionEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~PageTransitionEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(persisted_getter);

};

} // namespace Web::Bindings
    
