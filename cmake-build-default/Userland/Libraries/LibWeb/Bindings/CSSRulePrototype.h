
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSRulePrototype : public JS::Object {
    JS_OBJECT(CSSRulePrototype, JS::Object);
public:
    explicit CSSRulePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSRulePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(css_text_getter);

    JS_DECLARE_NATIVE_FUNCTION(css_text_setter);

    JS_DECLARE_NATIVE_FUNCTION(parent_rule_getter);

    JS_DECLARE_NATIVE_FUNCTION(parent_style_sheet_getter);

    JS_DECLARE_NATIVE_FUNCTION(type_getter);

};

} // namespace Web::Bindings
    
