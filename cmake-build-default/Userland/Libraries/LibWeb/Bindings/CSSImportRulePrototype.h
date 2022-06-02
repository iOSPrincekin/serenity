
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CSSImportRulePrototype : public JS::Object {
    JS_OBJECT(CSSImportRulePrototype, JS::Object);
public:
    explicit CSSImportRulePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSImportRulePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(href_getter);

    JS_DECLARE_NATIVE_FUNCTION(style_sheet_getter);

};

} // namespace Web::Bindings
    
