
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLDialogElementPrototype : public JS::Object {
    JS_OBJECT(HTMLDialogElementPrototype, JS::Object);
public:
    explicit HTMLDialogElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDialogElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(open_getter);

    JS_DECLARE_NATIVE_FUNCTION(open_setter);

};

} // namespace Web::Bindings
    
