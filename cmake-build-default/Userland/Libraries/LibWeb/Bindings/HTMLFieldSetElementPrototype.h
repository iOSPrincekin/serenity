
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLFieldSetElementPrototype : public JS::Object {
    JS_OBJECT(HTMLFieldSetElementPrototype, JS::Object);
public:
    explicit HTMLFieldSetElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFieldSetElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

};

} // namespace Web::Bindings
    
