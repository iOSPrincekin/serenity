
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLHeadElementPrototype : public JS::Object {
    JS_OBJECT(HTMLHeadElementPrototype, JS::Object);
public:
    explicit HTMLHeadElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLHeadElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
