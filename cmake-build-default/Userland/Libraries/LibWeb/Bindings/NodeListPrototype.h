
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class NodeListPrototype : public JS::Object {
    JS_OBJECT(NodeListPrototype, JS::Object);
public:
    explicit NodeListPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~NodeListPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(item);
        
    JS_DECLARE_NATIVE_FUNCTION(length_getter);

};

} // namespace Web::Bindings
    
