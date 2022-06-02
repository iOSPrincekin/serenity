
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLMapElementPrototype : public JS::Object {
    JS_OBJECT(HTMLMapElementPrototype, JS::Object);
public:
    explicit HTMLMapElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMapElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(name_setter);

};

} // namespace Web::Bindings
    
