
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTimeElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTimeElementPrototype, JS::Object);
public:
    explicit HTMLTimeElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTimeElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(date_time_getter);

    JS_DECLARE_NATIVE_FUNCTION(date_time_setter);

};

} // namespace Web::Bindings
    
