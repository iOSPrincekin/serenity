
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLMenuElementPrototype : public JS::Object {
    JS_OBJECT(HTMLMenuElementPrototype, JS::Object);
public:
    explicit HTMLMenuElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMenuElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(compact_getter);

    JS_DECLARE_NATIVE_FUNCTION(compact_setter);

};

} // namespace Web::Bindings
    
