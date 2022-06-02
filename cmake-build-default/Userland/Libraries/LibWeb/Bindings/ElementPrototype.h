
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class ElementPrototype : public JS::Object {
    JS_OBJECT(ElementPrototype, JS::Object);
public:
    explicit ElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(get_elements_by_tag_name_ns);
        
    JS_DECLARE_NATIVE_FUNCTION(get_elements_by_class_name);
        
    JS_DECLARE_NATIVE_FUNCTION(webkit_matches_selector);
        
    JS_DECLARE_NATIVE_FUNCTION(get_attribute_names);
        
    JS_DECLARE_NATIVE_FUNCTION(matches);
        
    JS_DECLARE_NATIVE_FUNCTION(get_client_rects);
        
    JS_DECLARE_NATIVE_FUNCTION(replace_children);
        
    JS_DECLARE_NATIVE_FUNCTION(set_attribute);
        
    JS_DECLARE_NATIVE_FUNCTION(replace_with);
        
    JS_DECLARE_NATIVE_FUNCTION(prepend);
        
    JS_DECLARE_NATIVE_FUNCTION(append);
        
    JS_DECLARE_NATIVE_FUNCTION(query_selector);
        
    JS_DECLARE_NATIVE_FUNCTION(get_bounding_client_rect);
        
    JS_DECLARE_NATIVE_FUNCTION(after);
        
    JS_DECLARE_NATIVE_FUNCTION(query_selector_all);
        
    JS_DECLARE_NATIVE_FUNCTION(has_attribute);
        
    JS_DECLARE_NATIVE_FUNCTION(before);
        
    JS_DECLARE_NATIVE_FUNCTION(remove);
        
    JS_DECLARE_NATIVE_FUNCTION(has_attributes);
        
    JS_DECLARE_NATIVE_FUNCTION(toggle_attribute);
        
    JS_DECLARE_NATIVE_FUNCTION(closest);
        
    JS_DECLARE_NATIVE_FUNCTION(remove_attribute);
        
    JS_DECLARE_NATIVE_FUNCTION(get_elements_by_tag_name);
        
    JS_DECLARE_NATIVE_FUNCTION(set_attribute_ns);
        
    JS_DECLARE_NATIVE_FUNCTION(get_attribute);
        
    JS_DECLARE_NATIVE_FUNCTION(namespace_uri_getter);

    JS_DECLARE_NATIVE_FUNCTION(prefix_getter);

    JS_DECLARE_NATIVE_FUNCTION(local_name_getter);

    JS_DECLARE_NATIVE_FUNCTION(tag_name_getter);

    JS_DECLARE_NATIVE_FUNCTION(attributes_getter);

    JS_DECLARE_NATIVE_FUNCTION(inner_html_getter);

    JS_DECLARE_NATIVE_FUNCTION(inner_html_setter);

    JS_DECLARE_NATIVE_FUNCTION(id_getter);

    JS_DECLARE_NATIVE_FUNCTION(id_setter);

    JS_DECLARE_NATIVE_FUNCTION(class_name_getter);

    JS_DECLARE_NATIVE_FUNCTION(class_name_setter);

    JS_DECLARE_NATIVE_FUNCTION(class_list_getter);

    JS_DECLARE_NATIVE_FUNCTION(next_element_sibling_getter);

    JS_DECLARE_NATIVE_FUNCTION(previous_element_sibling_getter);

    JS_DECLARE_NATIVE_FUNCTION(style_getter);

    JS_DECLARE_NATIVE_FUNCTION(first_element_child_getter);

    JS_DECLARE_NATIVE_FUNCTION(last_element_child_getter);

    JS_DECLARE_NATIVE_FUNCTION(child_element_count_getter);

    JS_DECLARE_NATIVE_FUNCTION(children_getter);

    JS_DECLARE_NATIVE_FUNCTION(client_top_getter);

    JS_DECLARE_NATIVE_FUNCTION(client_left_getter);

    JS_DECLARE_NATIVE_FUNCTION(client_width_getter);

    JS_DECLARE_NATIVE_FUNCTION(client_height_getter);

};

} // namespace Web::Bindings
    
