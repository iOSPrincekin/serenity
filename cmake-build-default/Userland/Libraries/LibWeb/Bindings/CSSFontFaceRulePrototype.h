
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSFontFaceRulePrototype : public JS::Object {
    JS_OBJECT(CSSFontFaceRulePrototype, JS::Object);
public:
    explicit CSSFontFaceRulePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSFontFaceRulePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(style_getter);

};

} // namespace Web::Bindings
    
