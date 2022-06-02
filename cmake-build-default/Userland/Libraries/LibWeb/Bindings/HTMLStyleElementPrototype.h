
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLStyleElementPrototype : public JS::Object {
    JS_OBJECT(HTMLStyleElementPrototype, JS::Object);
public:
    explicit HTMLStyleElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLStyleElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(media_getter);

    JS_DECLARE_NATIVE_FUNCTION(media_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

    JS_DECLARE_NATIVE_FUNCTION(sheet_getter);

};

} // namespace Web::Bindings
    
