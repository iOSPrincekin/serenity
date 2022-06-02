
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLOListElementPrototype : public JS::Object {
    JS_OBJECT(HTMLOListElementPrototype, JS::Object);
public:
    explicit HTMLOListElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLOListElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(reversed_getter);

    JS_DECLARE_NATIVE_FUNCTION(reversed_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

    JS_DECLARE_NATIVE_FUNCTION(compact_getter);

    JS_DECLARE_NATIVE_FUNCTION(compact_setter);

};

} // namespace Web::Bindings
    
