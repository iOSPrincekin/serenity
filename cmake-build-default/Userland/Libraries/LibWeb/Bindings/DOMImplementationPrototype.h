
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DOMImplementationPrototype : public JS::Object {
    JS_OBJECT(DOMImplementationPrototype, JS::Object);
public:
    explicit DOMImplementationPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMImplementationPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(create_document_type);
        
    JS_DECLARE_NATIVE_FUNCTION(create_document);
        
    JS_DECLARE_NATIVE_FUNCTION(has_feature);
        
    JS_DECLARE_NATIVE_FUNCTION(create_html_document);
        
};

} // namespace Web::Bindings
    
