
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DocumentTypePrototype : public JS::Object {
    JS_OBJECT(DocumentTypePrototype, JS::Object);
public:
    explicit DocumentTypePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DocumentTypePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(after);
        
    JS_DECLARE_NATIVE_FUNCTION(remove);
        
    JS_DECLARE_NATIVE_FUNCTION(replace_with);
        
    JS_DECLARE_NATIVE_FUNCTION(before);
        
    JS_DECLARE_NATIVE_FUNCTION(name_getter);

    JS_DECLARE_NATIVE_FUNCTION(public_id_getter);

    JS_DECLARE_NATIVE_FUNCTION(system_id_getter);

};

} // namespace Web::Bindings
    
