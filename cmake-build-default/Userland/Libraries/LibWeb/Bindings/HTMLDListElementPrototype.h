
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLDListElementPrototype : public JS::Object {
    JS_OBJECT(HTMLDListElementPrototype, JS::Object);
public:
    explicit HTMLDListElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDListElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(compact_getter);

    JS_DECLARE_NATIVE_FUNCTION(compact_setter);

};

} // namespace Web::Bindings
    
