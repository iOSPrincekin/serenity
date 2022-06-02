
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSStyleRulePrototype : public JS::Object {
    JS_OBJECT(CSSStyleRulePrototype, JS::Object);
public:
    explicit CSSStyleRulePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSStyleRulePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(selector_text_getter);

    JS_DECLARE_NATIVE_FUNCTION(selector_text_setter);

    JS_DECLARE_NATIVE_FUNCTION(style_getter);

};

} // namespace Web::Bindings
    
