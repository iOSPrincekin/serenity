
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class StaticRangePrototype : public JS::Object {
    JS_OBJECT(StaticRangePrototype, JS::Object);
public:
    explicit StaticRangePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~StaticRangePrototype() override;
private:

};

} // namespace Web::Bindings
    
