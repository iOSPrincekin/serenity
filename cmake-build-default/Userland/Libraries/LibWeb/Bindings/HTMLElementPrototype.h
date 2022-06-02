
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class HTMLElementPrototype : public JS::Object {
    JS_OBJECT(HTMLElementPrototype, JS::Object);
public:
    explicit HTMLElementPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLElementPrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(click);
        
    JS_DECLARE_NATIVE_FUNCTION(focus);
        
    JS_DECLARE_NATIVE_FUNCTION(title_getter);

    JS_DECLARE_NATIVE_FUNCTION(title_setter);

    JS_DECLARE_NATIVE_FUNCTION(lang_getter);

    JS_DECLARE_NATIVE_FUNCTION(lang_setter);

    JS_DECLARE_NATIVE_FUNCTION(hidden_getter);

    JS_DECLARE_NATIVE_FUNCTION(hidden_setter);

    JS_DECLARE_NATIVE_FUNCTION(content_editable_getter);

    JS_DECLARE_NATIVE_FUNCTION(content_editable_setter);

    JS_DECLARE_NATIVE_FUNCTION(inner_text_getter);

    JS_DECLARE_NATIVE_FUNCTION(inner_text_setter);

    JS_DECLARE_NATIVE_FUNCTION(offset_top_getter);

    JS_DECLARE_NATIVE_FUNCTION(offset_left_getter);

    JS_DECLARE_NATIVE_FUNCTION(offset_width_getter);

    JS_DECLARE_NATIVE_FUNCTION(offset_height_getter);

    JS_DECLARE_NATIVE_FUNCTION(onabort_getter);

    JS_DECLARE_NATIVE_FUNCTION(onabort_setter);

    JS_DECLARE_NATIVE_FUNCTION(onauxclick_getter);

    JS_DECLARE_NATIVE_FUNCTION(onauxclick_setter);

    JS_DECLARE_NATIVE_FUNCTION(onblur_getter);

    JS_DECLARE_NATIVE_FUNCTION(onblur_setter);

    JS_DECLARE_NATIVE_FUNCTION(oncancel_getter);

    JS_DECLARE_NATIVE_FUNCTION(oncancel_setter);

    JS_DECLARE_NATIVE_FUNCTION(oncanplay_getter);

    JS_DECLARE_NATIVE_FUNCTION(oncanplay_setter);

    JS_DECLARE_NATIVE_FUNCTION(oncanplaythrough_getter);

    JS_DECLARE_NATIVE_FUNCTION(oncanplaythrough_setter);

    JS_DECLARE_NATIVE_FUNCTION(onchange_getter);

    JS_DECLARE_NATIVE_FUNCTION(onchange_setter);

    JS_DECLARE_NATIVE_FUNCTION(onclick_getter);

    JS_DECLARE_NATIVE_FUNCTION(onclick_setter);

    JS_DECLARE_NATIVE_FUNCTION(onclose_getter);

    JS_DECLARE_NATIVE_FUNCTION(onclose_setter);

    JS_DECLARE_NATIVE_FUNCTION(oncontextmenu_getter);

    JS_DECLARE_NATIVE_FUNCTION(oncontextmenu_setter);

    JS_DECLARE_NATIVE_FUNCTION(oncuechange_getter);

    JS_DECLARE_NATIVE_FUNCTION(oncuechange_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondblclick_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondblclick_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondrag_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondrag_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondragend_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondragend_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondragenter_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondragenter_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondragleave_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondragleave_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondragover_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondragover_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondragstart_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondragstart_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondrop_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondrop_setter);

    JS_DECLARE_NATIVE_FUNCTION(ondurationchange_getter);

    JS_DECLARE_NATIVE_FUNCTION(ondurationchange_setter);

    JS_DECLARE_NATIVE_FUNCTION(onemptied_getter);

    JS_DECLARE_NATIVE_FUNCTION(onemptied_setter);

    JS_DECLARE_NATIVE_FUNCTION(onended_getter);

    JS_DECLARE_NATIVE_FUNCTION(onended_setter);

    JS_DECLARE_NATIVE_FUNCTION(onerror_getter);

    JS_DECLARE_NATIVE_FUNCTION(onerror_setter);

    JS_DECLARE_NATIVE_FUNCTION(onfocus_getter);

    JS_DECLARE_NATIVE_FUNCTION(onfocus_setter);

    JS_DECLARE_NATIVE_FUNCTION(onformdata_getter);

    JS_DECLARE_NATIVE_FUNCTION(onformdata_setter);

    JS_DECLARE_NATIVE_FUNCTION(oninput_getter);

    JS_DECLARE_NATIVE_FUNCTION(oninput_setter);

    JS_DECLARE_NATIVE_FUNCTION(oninvalid_getter);

    JS_DECLARE_NATIVE_FUNCTION(oninvalid_setter);

    JS_DECLARE_NATIVE_FUNCTION(onkeydown_getter);

    JS_DECLARE_NATIVE_FUNCTION(onkeydown_setter);

    JS_DECLARE_NATIVE_FUNCTION(onkeypress_getter);

    JS_DECLARE_NATIVE_FUNCTION(onkeypress_setter);

    JS_DECLARE_NATIVE_FUNCTION(onkeyup_getter);

    JS_DECLARE_NATIVE_FUNCTION(onkeyup_setter);

    JS_DECLARE_NATIVE_FUNCTION(onload_getter);

    JS_DECLARE_NATIVE_FUNCTION(onload_setter);

    JS_DECLARE_NATIVE_FUNCTION(onloadeddata_getter);

    JS_DECLARE_NATIVE_FUNCTION(onloadeddata_setter);

    JS_DECLARE_NATIVE_FUNCTION(onloadedmetadata_getter);

    JS_DECLARE_NATIVE_FUNCTION(onloadedmetadata_setter);

    JS_DECLARE_NATIVE_FUNCTION(onloadstart_getter);

    JS_DECLARE_NATIVE_FUNCTION(onloadstart_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmousedown_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmousedown_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseenter_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseenter_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseleave_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseleave_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmousemove_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmousemove_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseout_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseout_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseover_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseover_setter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseup_getter);

    JS_DECLARE_NATIVE_FUNCTION(onmouseup_setter);

    JS_DECLARE_NATIVE_FUNCTION(onpause_getter);

    JS_DECLARE_NATIVE_FUNCTION(onpause_setter);

    JS_DECLARE_NATIVE_FUNCTION(onplay_getter);

    JS_DECLARE_NATIVE_FUNCTION(onplay_setter);

    JS_DECLARE_NATIVE_FUNCTION(onplaying_getter);

    JS_DECLARE_NATIVE_FUNCTION(onplaying_setter);

    JS_DECLARE_NATIVE_FUNCTION(onprogress_getter);

    JS_DECLARE_NATIVE_FUNCTION(onprogress_setter);

    JS_DECLARE_NATIVE_FUNCTION(onratechange_getter);

    JS_DECLARE_NATIVE_FUNCTION(onratechange_setter);

    JS_DECLARE_NATIVE_FUNCTION(onreset_getter);

    JS_DECLARE_NATIVE_FUNCTION(onreset_setter);

    JS_DECLARE_NATIVE_FUNCTION(onresize_getter);

    JS_DECLARE_NATIVE_FUNCTION(onresize_setter);

    JS_DECLARE_NATIVE_FUNCTION(onscroll_getter);

    JS_DECLARE_NATIVE_FUNCTION(onscroll_setter);

    JS_DECLARE_NATIVE_FUNCTION(onsecuritypolicyviolation_getter);

    JS_DECLARE_NATIVE_FUNCTION(onsecuritypolicyviolation_setter);

    JS_DECLARE_NATIVE_FUNCTION(onseeked_getter);

    JS_DECLARE_NATIVE_FUNCTION(onseeked_setter);

    JS_DECLARE_NATIVE_FUNCTION(onseeking_getter);

    JS_DECLARE_NATIVE_FUNCTION(onseeking_setter);

    JS_DECLARE_NATIVE_FUNCTION(onselect_getter);

    JS_DECLARE_NATIVE_FUNCTION(onselect_setter);

    JS_DECLARE_NATIVE_FUNCTION(onslotchange_getter);

    JS_DECLARE_NATIVE_FUNCTION(onslotchange_setter);

    JS_DECLARE_NATIVE_FUNCTION(onstalled_getter);

    JS_DECLARE_NATIVE_FUNCTION(onstalled_setter);

    JS_DECLARE_NATIVE_FUNCTION(onsubmit_getter);

    JS_DECLARE_NATIVE_FUNCTION(onsubmit_setter);

    JS_DECLARE_NATIVE_FUNCTION(onsuspend_getter);

    JS_DECLARE_NATIVE_FUNCTION(onsuspend_setter);

    JS_DECLARE_NATIVE_FUNCTION(ontimeupdate_getter);

    JS_DECLARE_NATIVE_FUNCTION(ontimeupdate_setter);

    JS_DECLARE_NATIVE_FUNCTION(ontoggle_getter);

    JS_DECLARE_NATIVE_FUNCTION(ontoggle_setter);

    JS_DECLARE_NATIVE_FUNCTION(onvolumechange_getter);

    JS_DECLARE_NATIVE_FUNCTION(onvolumechange_setter);

    JS_DECLARE_NATIVE_FUNCTION(onwaiting_getter);

    JS_DECLARE_NATIVE_FUNCTION(onwaiting_setter);

    JS_DECLARE_NATIVE_FUNCTION(onwebkitanimationend_getter);

    JS_DECLARE_NATIVE_FUNCTION(onwebkitanimationend_setter);

    JS_DECLARE_NATIVE_FUNCTION(onwebkitanimationiteration_getter);

    JS_DECLARE_NATIVE_FUNCTION(onwebkitanimationiteration_setter);

    JS_DECLARE_NATIVE_FUNCTION(onwebkitanimationstart_getter);

    JS_DECLARE_NATIVE_FUNCTION(onwebkitanimationstart_setter);

    JS_DECLARE_NATIVE_FUNCTION(onwebkittransitionend_getter);

    JS_DECLARE_NATIVE_FUNCTION(onwebkittransitionend_setter);

    JS_DECLARE_NATIVE_FUNCTION(onwheel_getter);

    JS_DECLARE_NATIVE_FUNCTION(onwheel_setter);

    JS_DECLARE_NATIVE_FUNCTION(dataset_getter);

};

} // namespace Web::Bindings
    
