
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DocumentFragmentPrototype : public JS::Object {
    JS_OBJECT(DocumentFragmentPrototype, JS::Object);
public:
    explicit DocumentFragmentPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DocumentFragmentPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(query_selector);
        
    JS_DECLARE_NATIVE_FUNCTION(prepend);
        
    JS_DECLARE_NATIVE_FUNCTION(append);
        
    JS_DECLARE_NATIVE_FUNCTION(query_selector_all);
        
    JS_DECLARE_NATIVE_FUNCTION(replace_children);
        
    JS_DECLARE_NATIVE_FUNCTION(get_element_by_id);
        
    JS_DECLARE_NATIVE_FUNCTION(first_element_child_getter);

    JS_DECLARE_NATIVE_FUNCTION(last_element_child_getter);

    JS_DECLARE_NATIVE_FUNCTION(child_element_count_getter);

    JS_DECLARE_NATIVE_FUNCTION(children_getter);

};

} // namespace Web::Bindings
    
