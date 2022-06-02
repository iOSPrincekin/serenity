
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSSupportsRulePrototype : public JS::Object {
    JS_OBJECT(CSSSupportsRulePrototype, JS::Object);
public:
    explicit CSSSupportsRulePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSSupportsRulePrototype() override;
private:

};

} // namespace Web::Bindings
    
