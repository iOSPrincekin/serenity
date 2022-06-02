
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLLinkElementPrototype : public JS::Object {
    JS_OBJECT(HTMLLinkElementPrototype, JS::Object);
public:
    explicit HTMLLinkElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLLinkElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(href_getter);

    JS_DECLARE_NATIVE_FUNCTION(href_setter);

    JS_DECLARE_NATIVE_FUNCTION(hreflang_getter);

    JS_DECLARE_NATIVE_FUNCTION(hreflang_setter);

    JS_DECLARE_NATIVE_FUNCTION(integrity_getter);

    JS_DECLARE_NATIVE_FUNCTION(integrity_setter);

    JS_DECLARE_NATIVE_FUNCTION(media_getter);

    JS_DECLARE_NATIVE_FUNCTION(media_setter);

    JS_DECLARE_NATIVE_FUNCTION(rel_getter);

    JS_DECLARE_NATIVE_FUNCTION(rel_setter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_setter);

    JS_DECLARE_NATIVE_FUNCTION(image_srcset_getter);

    JS_DECLARE_NATIVE_FUNCTION(image_srcset_setter);

    JS_DECLARE_NATIVE_FUNCTION(image_sizes_getter);

    JS_DECLARE_NATIVE_FUNCTION(image_sizes_setter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_getter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_setter);

    JS_DECLARE_NATIVE_FUNCTION(charset_getter);

    JS_DECLARE_NATIVE_FUNCTION(charset_setter);

    JS_DECLARE_NATIVE_FUNCTION(rev_getter);

    JS_DECLARE_NATIVE_FUNCTION(rev_setter);

    JS_DECLARE_NATIVE_FUNCTION(target_getter);

    JS_DECLARE_NATIVE_FUNCTION(target_setter);

};

} // namespace Web::Bindings
    
