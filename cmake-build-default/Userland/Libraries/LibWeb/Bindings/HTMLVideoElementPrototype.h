
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLVideoElementPrototype : public JS::Object {
    JS_OBJECT(HTMLVideoElementPrototype, JS::Object);
public:
    explicit HTMLVideoElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLVideoElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(poster_getter);

    JS_DECLARE_NATIVE_FUNCTION(poster_setter);

    JS_DECLARE_NATIVE_FUNCTION(plays_inline_getter);

    JS_DECLARE_NATIVE_FUNCTION(plays_inline_setter);

};

} // namespace Web::Bindings
    
