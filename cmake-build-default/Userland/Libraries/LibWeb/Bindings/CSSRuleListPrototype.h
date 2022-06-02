
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSRuleListPrototype : public JS::Object {
    JS_OBJECT(CSSRuleListPrototype, JS::Object);
public:
    explicit CSSRuleListPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSRuleListPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
