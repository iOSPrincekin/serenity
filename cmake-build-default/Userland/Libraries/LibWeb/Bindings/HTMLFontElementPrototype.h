
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLFontElementPrototype : public JS::Object {
    JS_OBJECT(HTMLFontElementPrototype, JS::Object);
public:
    explicit HTMLFontElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFontElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(color_getter);

    JS_DECLARE_NATIVE_FUNCTION(color_setter);

    JS_DECLARE_NATIVE_FUNCTION(face_getter);

    JS_DECLARE_NATIVE_FUNCTION(face_setter);

    JS_DECLARE_NATIVE_FUNCTION(size_getter);

    JS_DECLARE_NATIVE_FUNCTION(size_setter);

};

} // namespace Web::Bindings
    
