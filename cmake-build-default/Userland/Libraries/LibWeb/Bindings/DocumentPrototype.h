
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class DocumentPrototype : public JS::Object {
    JS_OBJECT(DocumentPrototype, JS::Object);
public:
    explicit DocumentPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DocumentPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(get_elements_by_tag_name_ns);
        
    JS_DECLARE_NATIVE_FUNCTION(get_elements_by_class_name);
        
    JS_DECLARE_NATIVE_FUNCTION(create_tree_walker);
        
    JS_DECLARE_NATIVE_FUNCTION(import_node);
        
    JS_DECLARE_NATIVE_FUNCTION(create_node_iterator);
        
    JS_DECLARE_NATIVE_FUNCTION(replace_children);
        
    JS_DECLARE_NATIVE_FUNCTION(prepend);
        
    JS_DECLARE_NATIVE_FUNCTION(has_focus);
        
    JS_DECLARE_NATIVE_FUNCTION(append);
        
    JS_DECLARE_NATIVE_FUNCTION(create_comment);
        
    JS_DECLARE_NATIVE_FUNCTION(open);
        
    JS_DECLARE_NATIVE_FUNCTION(write);
        
    JS_DECLARE_NATIVE_FUNCTION(query_selector_all);
        
    JS_DECLARE_NATIVE_FUNCTION(create_element_ns);
        
    JS_DECLARE_NATIVE_FUNCTION(close);
        
    JS_DECLARE_NATIVE_FUNCTION(get_elements_by_name);
        
    JS_DECLARE_NATIVE_FUNCTION(adopt_node);
        
    JS_DECLARE_NATIVE_FUNCTION(create_document_fragment);
        
    JS_DECLARE_NATIVE_FUNCTION(get_element_by_id);
        
    JS_DECLARE_NATIVE_FUNCTION(query_selector);
        
    JS_DECLARE_NATIVE_FUNCTION(create_element);
        
    JS_DECLARE_NATIVE_FUNCTION(get_elements_by_tag_name);
        
    JS_DECLARE_NATIVE_FUNCTION(create_range);
        
    JS_DECLARE_NATIVE_FUNCTION(writeln);
        
    JS_DECLARE_NATIVE_FUNCTION(create_event);
        
    JS_DECLARE_NATIVE_FUNCTION(create_text_node);
        
    JS_DECLARE_NATIVE_FUNCTION(location_getter);

    JS_DECLARE_NATIVE_FUNCTION(implementation_getter);

    JS_DECLARE_NATIVE_FUNCTION(url_getter);

    JS_DECLARE_NATIVE_FUNCTION(document_uri_getter);

    JS_DECLARE_NATIVE_FUNCTION(character_set_getter);

    JS_DECLARE_NATIVE_FUNCTION(charset_getter);

    JS_DECLARE_NATIVE_FUNCTION(input_encoding_getter);

    JS_DECLARE_NATIVE_FUNCTION(content_type_getter);

    JS_DECLARE_NATIVE_FUNCTION(default_view_getter);

    JS_DECLARE_NATIVE_FUNCTION(cookie_getter);

    JS_DECLARE_NATIVE_FUNCTION(cookie_setter);

    JS_DECLARE_NATIVE_FUNCTION(referrer_getter);

    JS_DECLARE_NATIVE_FUNCTION(active_element_getter);

    JS_DECLARE_NATIVE_FUNCTION(applets_getter);

    JS_DECLARE_NATIVE_FUNCTION(anchors_getter);

    JS_DECLARE_NATIVE_FUNCTION(images_getter);

    JS_DECLARE_NATIVE_FUNCTION(embeds_getter);

    JS_DECLARE_NATIVE_FUNCTION(plugins_getter);

    JS_DECLARE_NATIVE_FUNCTION(links_getter);

    JS_DECLARE_NATIVE_FUNCTION(forms_getter);

    JS_DECLARE_NATIVE_FUNCTION(scripts_getter);

    JS_DECLARE_NATIVE_FUNCTION(style_sheets_getter);

    JS_DECLARE_NATIVE_FUNCTION(compat_mode_getter);

    JS_DECLARE_NATIVE_FUNCTION(doctype_getter);

    JS_DECLARE_NATIVE_FUNCTION(document_element_getter);

    JS_DECLARE_NATIVE_FUNCTION(body_getter);

    JS_DECLARE_NATIVE_FUNCTION(body_setter);

    JS_DECLARE_NATIVE_FUNCTION(head_getter);

    JS_DECLARE_NATIVE_FUNCTION(current_script_getter);

    JS_DECLARE_NATIVE_FUNCTION(ready_state_getter);

    JS_DECLARE_NATIVE_FUNCTION(title_getter);

    JS_DECLARE_NATIVE_FUNCTION(title_setter);

    JS_DECLARE_NATIVE_FUNCTION(first_element_child_getter);

    JS_DECLARE_NATIVE_FUNCTION(last_element_child_getter);

    JS_DECLARE_NATIVE_FUNCTION(child_element_count_getter);

    JS_DECLARE_NATIVE_FUNCTION(children_getter);

    JS_DECLARE_NATIVE_FUNCTION(hidden_getter);

    JS_DECLARE_NATIVE_FUNCTION(visibility_state_getter);

};

} // namespace Web::Bindings
    
