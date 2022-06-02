
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLFrameSetElementPrototype : public JS::Object {
    JS_OBJECT(HTMLFrameSetElementPrototype, JS::Object);
public:
    explicit HTMLFrameSetElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFrameSetElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(cols_getter);

    JS_DECLARE_NATIVE_FUNCTION(cols_setter);

    JS_DECLARE_NATIVE_FUNCTION(rows_getter);

    JS_DECLARE_NATIVE_FUNCTION(rows_setter);

};

} // namespace Web::Bindings
    
