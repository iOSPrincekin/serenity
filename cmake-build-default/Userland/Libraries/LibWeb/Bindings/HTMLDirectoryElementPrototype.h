
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLDirectoryElementPrototype : public JS::Object {
    JS_OBJECT(HTMLDirectoryElementPrototype, JS::Object);
public:
    explicit HTMLDirectoryElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDirectoryElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(compact_getter);

    JS_DECLARE_NATIVE_FUNCTION(compact_setter);

};

} // namespace Web::Bindings
    
