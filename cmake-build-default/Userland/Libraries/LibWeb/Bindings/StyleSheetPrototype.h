
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class StyleSheetPrototype : public JS::Object {
    JS_OBJECT(StyleSheetPrototype, JS::Object);
public:
    explicit StyleSheetPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~StyleSheetPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(owner_node_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

    JS_DECLARE_NATIVE_FUNCTION(href_getter);

    JS_DECLARE_NATIVE_FUNCTION(parent_style_sheet_getter);

    JS_DECLARE_NATIVE_FUNCTION(title_getter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_getter);

    JS_DECLARE_NATIVE_FUNCTION(disabled_setter);

};

} // namespace Web::Bindings
    
