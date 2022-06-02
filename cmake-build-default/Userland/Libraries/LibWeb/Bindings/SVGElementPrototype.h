
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class SVGElementPrototype : public JS::Object {
    JS_OBJECT(SVGElementPrototype, JS::Object);
public:
    explicit SVGElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(dataset_getter);

};

} // namespace Web::Bindings
    
