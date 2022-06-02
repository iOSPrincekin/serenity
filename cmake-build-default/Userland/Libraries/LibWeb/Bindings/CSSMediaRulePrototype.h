
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSMediaRulePrototype : public JS::Object {
    JS_OBJECT(CSSMediaRulePrototype, JS::Object);
public:
    explicit CSSMediaRulePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSMediaRulePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(media_getter);

};

} // namespace Web::Bindings
    
