
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLDataListElementPrototype : public JS::Object {
    JS_OBJECT(HTMLDataListElementPrototype, JS::Object);
public:
    explicit HTMLDataListElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDataListElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
