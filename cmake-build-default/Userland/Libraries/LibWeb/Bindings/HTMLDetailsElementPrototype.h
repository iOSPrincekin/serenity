
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLDetailsElementPrototype : public JS::Object {
    JS_OBJECT(HTMLDetailsElementPrototype, JS::Object);
public:
    explicit HTMLDetailsElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDetailsElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(open_getter);

    JS_DECLARE_NATIVE_FUNCTION(open_setter);

};

} // namespace Web::Bindings
    
