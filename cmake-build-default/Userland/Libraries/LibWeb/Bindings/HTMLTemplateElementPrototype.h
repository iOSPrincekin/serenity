
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTemplateElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTemplateElementPrototype, JS::Object);
public:
    explicit HTMLTemplateElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTemplateElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(content_getter);

};

} // namespace Web::Bindings
    
