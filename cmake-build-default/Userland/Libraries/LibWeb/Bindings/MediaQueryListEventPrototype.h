
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class MediaQueryListEventPrototype : public JS::Object {
    JS_OBJECT(MediaQueryListEventPrototype, JS::Object);
public:
    explicit MediaQueryListEventPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MediaQueryListEventPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(media_getter);

    JS_DECLARE_NATIVE_FUNCTION(matches_getter);

};

} // namespace Web::Bindings
    
