
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class AbstractRangePrototype : public JS::Object {
    JS_OBJECT(AbstractRangePrototype, JS::Object);
public:
    explicit AbstractRangePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~AbstractRangePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(start_container_getter);

    JS_DECLARE_NATIVE_FUNCTION(start_offset_getter);

    JS_DECLARE_NATIVE_FUNCTION(end_container_getter);

    JS_DECLARE_NATIVE_FUNCTION(end_offset_getter);

    JS_DECLARE_NATIVE_FUNCTION(collapsed_getter);

};

} // namespace Web::Bindings
    
