
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class ImageDataPrototype : public JS::Object {
    JS_OBJECT(ImageDataPrototype, JS::Object);
public:
    explicit ImageDataPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ImageDataPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(width_getter);

    JS_DECLARE_NATIVE_FUNCTION(height_getter);

    JS_DECLARE_NATIVE_FUNCTION(data_getter);

};

} // namespace Web::Bindings
    
