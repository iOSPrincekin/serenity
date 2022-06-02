
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLQuoteElementPrototype : public JS::Object {
    JS_OBJECT(HTMLQuoteElementPrototype, JS::Object);
public:
    explicit HTMLQuoteElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLQuoteElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(cite_getter);

    JS_DECLARE_NATIVE_FUNCTION(cite_setter);

};

} // namespace Web::Bindings
    
