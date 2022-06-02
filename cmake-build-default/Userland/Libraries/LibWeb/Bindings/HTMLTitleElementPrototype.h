
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLTitleElementPrototype : public JS::Object {
    JS_OBJECT(HTMLTitleElementPrototype, JS::Object);
public:
    explicit HTMLTitleElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTitleElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
