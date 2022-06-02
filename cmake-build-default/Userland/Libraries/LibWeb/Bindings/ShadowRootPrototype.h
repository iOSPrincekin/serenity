
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class ShadowRootPrototype : public JS::Object {
    JS_OBJECT(ShadowRootPrototype, JS::Object);
public:
    explicit ShadowRootPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ShadowRootPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(mode_getter);

    JS_DECLARE_NATIVE_FUNCTION(host_getter);

    JS_DECLARE_NATIVE_FUNCTION(inner_html_getter);

    JS_DECLARE_NATIVE_FUNCTION(inner_html_setter);

};

} // namespace Web::Bindings
    
