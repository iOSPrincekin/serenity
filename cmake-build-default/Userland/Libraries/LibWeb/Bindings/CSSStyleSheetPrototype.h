
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSStyleSheetPrototype : public JS::Object {
    JS_OBJECT(CSSStyleSheetPrototype, JS::Object);
public:
    explicit CSSStyleSheetPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSStyleSheetPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(insert_rule);
        
    JS_DECLARE_NATIVE_FUNCTION(delete_rule);
        
    JS_DECLARE_NATIVE_FUNCTION(remove_rule);
        
    JS_DECLARE_NATIVE_FUNCTION(css_rules_getter);

};

} // namespace Web::Bindings
    
