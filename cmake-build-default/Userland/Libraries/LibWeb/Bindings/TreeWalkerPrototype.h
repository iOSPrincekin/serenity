
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class TreeWalkerPrototype : public JS::Object {
    JS_OBJECT(TreeWalkerPrototype, JS::Object);
public:
    explicit TreeWalkerPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TreeWalkerPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(previous_node);
        
    JS_DECLARE_NATIVE_FUNCTION(previous_sibling);
        
    JS_DECLARE_NATIVE_FUNCTION(next_sibling);
        
    JS_DECLARE_NATIVE_FUNCTION(parent_node);
        
    JS_DECLARE_NATIVE_FUNCTION(last_child);
        
    JS_DECLARE_NATIVE_FUNCTION(next_node);
        
    JS_DECLARE_NATIVE_FUNCTION(first_child);
        
    JS_DECLARE_NATIVE_FUNCTION(root_getter);

    JS_DECLARE_NATIVE_FUNCTION(what_to_show_getter);

    JS_DECLARE_NATIVE_FUNCTION(filter_getter);

    JS_DECLARE_NATIVE_FUNCTION(current_node_getter);

    JS_DECLARE_NATIVE_FUNCTION(current_node_setter);

};

} // namespace Web::Bindings
    
