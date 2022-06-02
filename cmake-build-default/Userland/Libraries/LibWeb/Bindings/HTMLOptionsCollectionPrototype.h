
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLOptionsCollectionPrototype : public JS::Object {
    JS_OBJECT(HTMLOptionsCollectionPrototype, JS::Object);
public:
    explicit HTMLOptionsCollectionPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLOptionsCollectionPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(add);
        
};

} // namespace Web::Bindings
    
