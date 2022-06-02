
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HistoryPrototype : public JS::Object {
    JS_OBJECT(HistoryPrototype, JS::Object);
public:
    explicit HistoryPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HistoryPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(replace_state);
        
    JS_DECLARE_NATIVE_FUNCTION(push_state);
        
};

} // namespace Web::Bindings
    
