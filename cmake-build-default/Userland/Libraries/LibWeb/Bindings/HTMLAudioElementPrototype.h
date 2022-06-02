
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLAudioElementPrototype : public JS::Object {
    JS_OBJECT(HTMLAudioElementPrototype, JS::Object);
public:
    explicit HTMLAudioElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLAudioElementPrototype() override;
private:

};

} // namespace Web::Bindings
    
