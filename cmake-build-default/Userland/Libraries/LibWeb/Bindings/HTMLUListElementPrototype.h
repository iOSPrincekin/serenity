
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLUListElementPrototype : public JS::Object {
    JS_OBJECT(HTMLUListElementPrototype, JS::Object);
public:
    explicit HTMLUListElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLUListElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(compact_getter);

    JS_DECLARE_NATIVE_FUNCTION(compact_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

};

} // namespace Web::Bindings
    
