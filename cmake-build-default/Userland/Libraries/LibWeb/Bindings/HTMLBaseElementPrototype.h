
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLBaseElementPrototype : public JS::Object {
    JS_OBJECT(HTMLBaseElementPrototype, JS::Object);
public:
    explicit HTMLBaseElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLBaseElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(target_getter);

    JS_DECLARE_NATIVE_FUNCTION(target_setter);

};

} // namespace Web::Bindings
    
