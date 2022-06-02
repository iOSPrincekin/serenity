
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSGroupingRulePrototype : public JS::Object {
    JS_OBJECT(CSSGroupingRulePrototype, JS::Object);
public:
    explicit CSSGroupingRulePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSGroupingRulePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(insert_rule);
        
    JS_DECLARE_NATIVE_FUNCTION(delete_rule);
        
    JS_DECLARE_NATIVE_FUNCTION(css_rules_getter);

};

} // namespace Web::Bindings
    
