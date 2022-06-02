
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLPictureElementPrototype : public JS::Object {
    JS_OBJECT(HTMLPictureElementPrototype, JS::Object);
public:
    explicit HTMLPictureElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLPictureElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
