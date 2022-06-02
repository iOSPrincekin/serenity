
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTrackElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTrackElementPrototype, JS::Object);
public:
    explicit HTMLTrackElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTrackElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(src_getter);

    JS_DECLARE_NATIVE_FUNCTION(src_setter);

    JS_DECLARE_NATIVE_FUNCTION(srclang_getter);

    JS_DECLARE_NATIVE_FUNCTION(srclang_setter);

    JS_DECLARE_NATIVE_FUNCTION(label_getter);

    JS_DECLARE_NATIVE_FUNCTION(label_setter);

    JS_DECLARE_NATIVE_FUNCTION(default_getter);

    JS_DECLARE_NATIVE_FUNCTION(default_setter);

};

} // namespace Web::Bindings
    
