
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLSourceElementPrototype : public JS::Object {
    JS_OBJECT(HTMLSourceElementPrototype, JS::Object);
public:
    explicit HTMLSourceElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLSourceElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(src_getter);

    JS_DECLARE_NATIVE_FUNCTION(src_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

    JS_DECLARE_NATIVE_FUNCTION(srcset_getter);

    JS_DECLARE_NATIVE_FUNCTION(srcset_setter);

    JS_DECLARE_NATIVE_FUNCTION(sizes_getter);

    JS_DECLARE_NATIVE_FUNCTION(sizes_setter);

    JS_DECLARE_NATIVE_FUNCTION(media_getter);

    JS_DECLARE_NATIVE_FUNCTION(media_setter);

};

} // namespace Web::Bindings
    
