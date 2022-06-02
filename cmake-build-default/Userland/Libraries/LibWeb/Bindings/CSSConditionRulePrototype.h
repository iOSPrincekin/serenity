
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSConditionRulePrototype : public JS::Object {
    JS_OBJECT(CSSConditionRulePrototype, JS::Object);
public:
    explicit CSSConditionRulePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSConditionRulePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(condition_text_getter);

    JS_DECLARE_NATIVE_FUNCTION(condition_text_setter);

};

} // namespace Web::Bindings
    
