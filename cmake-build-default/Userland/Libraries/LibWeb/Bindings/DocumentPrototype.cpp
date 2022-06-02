
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DocumentPrototype.h>
#include <LibWeb/Bindings/DocumentWrapper.h>
#include <LibWeb/Bindings/EventWrapper.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/LocationObject.h>
#include <LibWeb/Bindings/WindowObject.h>
#include <LibWeb/Bindings/WorkerLocationWrapper.h>
#include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#include <LibWeb/Bindings/WorkerWrapper.h>
#include <LibWeb/DOM/Element.h>
#include <LibWeb/DOM/Event.h>
#include <LibWeb/DOM/IDLEventListener.h>
#include <LibWeb/DOM/NodeFilter.h>
#include <LibWeb/DOM/Range.h>
#include <LibWeb/HTML/Scripting/Environments.h>
#include <LibWeb/HTML/Window.h>
#include <LibWeb/Origin.h>

#if __has_include(<LibWeb/Bindings/NodePrototype.h>)
#    include <LibWeb/Bindings/NodePrototype.h>
#endif


#include <LibWeb/Geometry/DOMRectList.h>

#include <LibWeb/DOM/Element.h>

#include <LibWeb/HTML/HTMLScriptElement.h>

#include <LibWeb/DOM/Comment.h>

#include <LibWeb/DOM/Document.h>

#include <LibWeb/HTML/HTMLHeadElement.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/DOM/DOMImplementation.h>

#include <LibWeb/DOM/NodeList.h>

#include <LibWeb/DOM/DocumentType.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/DOM/CharacterData.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/DocumentFragment.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/Text.h>

#include <LibWeb/DOM/NodeFilter.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/DOM/NamedNodeMap.h>

#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/TreeWalker.h>

#include <LibWeb/DOM/HTMLCollection.h>

#include <LibWeb/DOM/Node.h>

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/DOM/Document.h>

#if __has_include(<LibWeb/Bindings/DocumentWrapper.h>)
#   include <LibWeb/Bindings/DocumentWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DocumentWrapperFactory.h>)
#   include <LibWeb/Bindings/DocumentWrapperFactory.h>
#endif

#include <LibWeb/CSS/StyleSheetList.h>

#if __has_include(<LibWeb/Bindings/StyleSheetListWrapper.h>)
#   include <LibWeb/Bindings/StyleSheetListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/StyleSheetListWrapperFactory.h>)
#   include <LibWeb/Bindings/StyleSheetListWrapperFactory.h>
#endif

#include <LibWeb/DOM/Comment.h>

#if __has_include(<LibWeb/Bindings/CommentWrapper.h>)
#   include <LibWeb/Bindings/CommentWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CommentWrapperFactory.h>)
#   include <LibWeb/Bindings/CommentWrapperFactory.h>
#endif

#include <LibWeb/DOM/DOMImplementation.h>

#if __has_include(<LibWeb/Bindings/DOMImplementationWrapper.h>)
#   include <LibWeb/Bindings/DOMImplementationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMImplementationWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMImplementationWrapperFactory.h>
#endif

#include <LibWeb/DOM/DocumentFragment.h>

#if __has_include(<LibWeb/Bindings/DocumentFragmentWrapper.h>)
#   include <LibWeb/Bindings/DocumentFragmentWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DocumentFragmentWrapperFactory.h>)
#   include <LibWeb/Bindings/DocumentFragmentWrapperFactory.h>
#endif

#include <LibWeb/DOM/DocumentType.h>

#if __has_include(<LibWeb/Bindings/DocumentTypeWrapper.h>)
#   include <LibWeb/Bindings/DocumentTypeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DocumentTypeWrapperFactory.h>)
#   include <LibWeb/Bindings/DocumentTypeWrapperFactory.h>
#endif

#include <LibWeb/DOM/Element.h>

#if __has_include(<LibWeb/Bindings/ElementWrapper.h>)
#   include <LibWeb/Bindings/ElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ElementWrapperFactory.h>)
#   include <LibWeb/Bindings/ElementWrapperFactory.h>
#endif

#include <LibWeb/DOM/Event.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

#include <LibWeb/DOM/HTMLCollection.h>

#if __has_include(<LibWeb/Bindings/HTMLCollectionWrapper.h>)
#   include <LibWeb/Bindings/HTMLCollectionWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLCollectionWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLCollectionWrapperFactory.h>
#endif

#include <LibWeb/DOM/Node.h>

#if __has_include(<LibWeb/Bindings/NodeWrapper.h>)
#   include <LibWeb/Bindings/NodeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/NodeWrapperFactory.h>)
#   include <LibWeb/Bindings/NodeWrapperFactory.h>
#endif

#include <LibWeb/DOM/NodeFilter.h>

#if __has_include(<LibWeb/Bindings/NodeFilterWrapper.h>)
#   include <LibWeb/Bindings/NodeFilterWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/NodeFilterWrapperFactory.h>)
#   include <LibWeb/Bindings/NodeFilterWrapperFactory.h>
#endif

#include <LibWeb/DOM/NodeIterator.h>

#if __has_include(<LibWeb/Bindings/NodeIteratorWrapper.h>)
#   include <LibWeb/Bindings/NodeIteratorWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/NodeIteratorWrapperFactory.h>)
#   include <LibWeb/Bindings/NodeIteratorWrapperFactory.h>
#endif

#include <LibWeb/DOM/NodeList.h>

#if __has_include(<LibWeb/Bindings/NodeListWrapper.h>)
#   include <LibWeb/Bindings/NodeListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/NodeListWrapperFactory.h>)
#   include <LibWeb/Bindings/NodeListWrapperFactory.h>
#endif

#include <LibWeb/DOM/Range.h>

#if __has_include(<LibWeb/Bindings/RangeWrapper.h>)
#   include <LibWeb/Bindings/RangeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/RangeWrapperFactory.h>)
#   include <LibWeb/Bindings/RangeWrapperFactory.h>
#endif

#include <LibWeb/DOM/Text.h>

#if __has_include(<LibWeb/Bindings/TextWrapper.h>)
#   include <LibWeb/Bindings/TextWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TextWrapperFactory.h>)
#   include <LibWeb/Bindings/TextWrapperFactory.h>
#endif

#include <LibWeb/DOM/TreeWalker.h>

#if __has_include(<LibWeb/Bindings/TreeWalkerWrapper.h>)
#   include <LibWeb/Bindings/TreeWalkerWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TreeWalkerWrapperFactory.h>)
#   include <LibWeb/Bindings/TreeWalkerWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLHeadElement.h>

#if __has_include(<LibWeb/Bindings/HTMLHeadElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLHeadElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLHeadElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLHeadElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLScriptElement.h>

#if __has_include(<LibWeb/Bindings/HTMLScriptElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLScriptElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLScriptElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLScriptElementWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSStyleSheet.h>

#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleSheetWrapperFactory.h>
#endif

#include <LibWeb/DOM/CharacterData.h>

#if __has_include(<LibWeb/Bindings/CharacterDataWrapper.h>)
#   include <LibWeb/Bindings/CharacterDataWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CharacterDataWrapperFactory.h>)
#   include <LibWeb/Bindings/CharacterDataWrapperFactory.h>
#endif

#include <LibWeb/DOM/DOMTokenList.h>

#if __has_include(<LibWeb/Bindings/DOMTokenListWrapper.h>)
#   include <LibWeb/Bindings/DOMTokenListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMTokenListWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMTokenListWrapperFactory.h>
#endif

#include <LibWeb/DOM/NamedNodeMap.h>

#if __has_include(<LibWeb/Bindings/NamedNodeMapWrapper.h>)
#   include <LibWeb/Bindings/NamedNodeMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/NamedNodeMapWrapperFactory.h>)
#   include <LibWeb/Bindings/NamedNodeMapWrapperFactory.h>
#endif

#include <LibWeb/Geometry/DOMRect.h>

#if __has_include(<LibWeb/Bindings/DOMRectWrapper.h>)
#   include <LibWeb/Bindings/DOMRectWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectWrapperFactory.h>
#endif

#include <LibWeb/Geometry/DOMRectList.h>

#if __has_include(<LibWeb/Bindings/DOMRectListWrapper.h>)
#   include <LibWeb/Bindings/DOMRectListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectListWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectListWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbstractRange.h>

#if __has_include(<LibWeb/Bindings/AbstractRangeWrapper.h>)
#   include <LibWeb/Bindings/AbstractRangeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbstractRangeWrapperFactory.h>)
#   include <LibWeb/Bindings/AbstractRangeWrapperFactory.h>
#endif

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSRule.h>

#if __has_include(<LibWeb/Bindings/CSSRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#endif

#include <LibWeb/CSS/CSSRuleList.h>

#if __has_include(<LibWeb/Bindings/CSSRuleListWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleListWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleListWrapperFactory.h>
#endif

#include <LibWeb/DOM/Attribute.h>

#if __has_include(<LibWeb/Bindings/AttributeWrapper.h>)
#   include <LibWeb/Bindings/AttributeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AttributeWrapperFactory.h>)
#   include <LibWeb/Bindings/AttributeWrapperFactory.h>
#endif

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapper.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
#endif


// FIXME: This is a total hack until we can figure out the namespace for a given type somehow.
using namespace Web::Crypto;
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::NavigationTiming;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;
using namespace Web::SVG;
using namespace Web::URL;
using namespace Web::WebSockets;
using namespace Web::XHR;

namespace Web::Bindings {

DocumentPrototype::DocumentPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<NodePrototype>("Node"))

{
}

DocumentPrototype::~DocumentPrototype()
{
}

void DocumentPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    auto* unscopable_object = JS::Object::create(global_object, nullptr);

    define_native_accessor("location", location_getter, nullptr, default_attributes);

    define_native_accessor("implementation", implementation_getter, nullptr, default_attributes);

    define_native_accessor("URL", url_getter, nullptr, default_attributes);

    define_native_accessor("documentURI", document_uri_getter, nullptr, default_attributes);

    define_native_accessor("characterSet", character_set_getter, nullptr, default_attributes);

    define_native_accessor("charset", charset_getter, nullptr, default_attributes);

    define_native_accessor("inputEncoding", input_encoding_getter, nullptr, default_attributes);

    define_native_accessor("contentType", content_type_getter, nullptr, default_attributes);

    define_native_accessor("defaultView", default_view_getter, nullptr, default_attributes);

    define_native_accessor("cookie", cookie_getter, cookie_setter, default_attributes);

    define_native_accessor("referrer", referrer_getter, nullptr, default_attributes);

    define_native_accessor("activeElement", active_element_getter, nullptr, default_attributes);

    define_native_accessor("applets", applets_getter, nullptr, default_attributes);

    define_native_accessor("anchors", anchors_getter, nullptr, default_attributes);

    define_native_accessor("images", images_getter, nullptr, default_attributes);

    define_native_accessor("embeds", embeds_getter, nullptr, default_attributes);

    define_native_accessor("plugins", plugins_getter, nullptr, default_attributes);

    define_native_accessor("links", links_getter, nullptr, default_attributes);

    define_native_accessor("forms", forms_getter, nullptr, default_attributes);

    define_native_accessor("scripts", scripts_getter, nullptr, default_attributes);

    define_native_accessor("styleSheets", style_sheets_getter, nullptr, default_attributes);

    define_native_accessor("compatMode", compat_mode_getter, nullptr, default_attributes);

    define_native_accessor("doctype", doctype_getter, nullptr, default_attributes);

    define_native_accessor("documentElement", document_element_getter, nullptr, default_attributes);

    define_native_accessor("body", body_getter, body_setter, default_attributes);

    define_native_accessor("head", head_getter, nullptr, default_attributes);

    define_native_accessor("currentScript", current_script_getter, nullptr, default_attributes);

    define_native_accessor("readyState", ready_state_getter, nullptr, default_attributes);

    define_native_accessor("title", title_getter, title_setter, default_attributes);

    define_native_accessor("firstElementChild", first_element_child_getter, nullptr, default_attributes);

    define_native_accessor("lastElementChild", last_element_child_getter, nullptr, default_attributes);

    define_native_accessor("childElementCount", child_element_count_getter, nullptr, default_attributes);

    define_native_accessor("children", children_getter, nullptr, default_attributes);

    define_native_accessor("hidden", hidden_getter, nullptr, default_attributes);

    define_native_accessor("visibilityState", visibility_state_getter, nullptr, default_attributes);

    define_native_function("getElementsByTagNameNS", get_elements_by_tag_name_ns, 2, default_attributes);

    define_native_function("getElementsByClassName", get_elements_by_class_name, 1, default_attributes);

    define_native_function("createTreeWalker", create_tree_walker, 1, default_attributes);

    define_native_function("importNode", import_node, 1, default_attributes);

    define_native_function("createNodeIterator", create_node_iterator, 1, default_attributes);

    MUST(unscopable_object->create_data_property("replaceChildren", JS::Value(true)));

    define_native_function("replaceChildren", replace_children, 0, default_attributes);

    MUST(unscopable_object->create_data_property("prepend", JS::Value(true)));

    define_native_function("prepend", prepend, 0, default_attributes);

    define_native_function("hasFocus", has_focus, 0, default_attributes);

    MUST(unscopable_object->create_data_property("append", JS::Value(true)));

    define_native_function("append", append, 0, default_attributes);

    define_native_function("createComment", create_comment, 1, default_attributes);

    define_native_function("open", open, 0, default_attributes);

    define_native_function("write", write, 0, default_attributes);

    define_native_function("querySelectorAll", query_selector_all, 1, default_attributes);

    define_native_function("createElementNS", create_element_ns, 2, default_attributes);

    define_native_function("close", close, 0, default_attributes);

    define_native_function("getElementsByName", get_elements_by_name, 1, default_attributes);

    define_native_function("adoptNode", adopt_node, 1, default_attributes);

    define_native_function("createDocumentFragment", create_document_fragment, 0, default_attributes);

    define_native_function("getElementById", get_element_by_id, 1, default_attributes);

    define_native_function("querySelector", query_selector, 1, default_attributes);

    define_native_function("createElement", create_element, 1, default_attributes);

    define_native_function("getElementsByTagName", get_elements_by_tag_name, 1, default_attributes);

    define_native_function("createRange", create_range, 0, default_attributes);

    define_native_function("writeln", writeln, 0, default_attributes);

    define_native_function("createEvent", create_event, 1, default_attributes);

    define_native_function("createTextNode", create_text_node, 1, default_attributes);

    define_direct_property(*vm.well_known_symbol_unscopables(), unscopable_object, JS::Attribute::Configurable);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<DOM::Document*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<DocumentWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "DOM::Document");

    return &static_cast<DocumentWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::location_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->location(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return retval;

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::implementation_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->implementation(); }));

    return wrap(global_object, const_cast<DOMImplementation&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::url_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->url_string(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::document_uri_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->document_uri(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::character_set_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->character_set(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::charset_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->charset(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::input_encoding_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->input_encoding(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::content_type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->content_type(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::default_view_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->default_view(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Window&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::cookie_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->cookie(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::cookie_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_cookie(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::referrer_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->referrer(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::active_element_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->active_element(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::applets_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->applets(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::anchors_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->anchors(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::images_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->images(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::embeds_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->embeds(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::plugins_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->plugins(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::links_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->links(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::forms_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->forms(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::scripts_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->scripts(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::style_sheets_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->style_sheets_for_bindings(); }));

    return wrap(global_object, const_cast<StyleSheetList&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::compat_mode_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->compat_mode(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::doctype_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->doctype(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<DocumentType&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::document_element_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->document_element(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::body_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->body(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<HTMLElement&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::body_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    HTMLElement* cpp_value = nullptr;
    if (!value.is_nullish()) {
        if (!value.is_object() || !is<HTMLElementWrapper>(value.as_object()))
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTMLElement");

        cpp_value = &static_cast<HTMLElementWrapper&>(value.as_object()).impl();
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_body(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::head_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->head(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<HTMLHeadElement&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::current_script_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->current_script(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<HTMLScriptElement&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::ready_state_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ready_state(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::title_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->title(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::title_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_title(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::first_element_child_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->first_element_child(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::last_element_child_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->last_element_child(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::child_element_count_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->child_element_count(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::children_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->children(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::hidden_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->hidden(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::visibility_state_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->visibility_state(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::has_focus)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->has_focus(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::open)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    String unused1;
    if (!arg0.is_undefined()) {
        if (arg0.is_null() && false)
            unused1 = String::empty();
        else
            unused1 = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String unused2;
    if (!arg1.is_undefined()) {
        if (arg1.is_null() && false)
            unused2 = String::empty();
        else
            unused2 = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->open(unused1, unused2); }));

    return wrap(global_object, const_cast<Document&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::close)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->close(); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::write)
{

    auto* impl = TRY(impl_from(vm, global_object));

    Vector<String> text;
    text.ensure_capacity(vm.argument_count() - 0);

    for (size_t i = 0; i < vm.argument_count(); ++i) {
        auto to_string_result = TRY(vm.argument(i).to_string(global_object));
        text.append(move(to_string_result));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->write(text); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::writeln)
{

    auto* impl = TRY(impl_from(vm, global_object));

    Vector<String> text;
    text.ensure_capacity(vm.argument_count() - 0);

    for (size_t i = 0; i < vm.argument_count(); ++i) {
        auto to_string_result = TRY(vm.argument(i).to_string(global_object));
        text.append(move(to_string_result));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->writeln(text); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::get_element_by_id)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getElementById");

    auto arg0 = vm.argument(0);

    String id;
    if (arg0.is_null() && false) {
        id = String::empty();
    } else {
        id = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_element_by_id(id); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::get_elements_by_name)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getElementsByName");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_elements_by_name(name); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::get_elements_by_tag_name)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getElementsByTagName");

    auto arg0 = vm.argument(0);

    String tag_name;
    if (arg0.is_null() && false) {
        tag_name = String::empty();
    } else {
        tag_name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_elements_by_tag_name(tag_name); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::get_elements_by_tag_name_ns)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "getElementsByTagNameNS", "2");

    auto arg0 = vm.argument(0);

    String namespace_;
    if (!arg0.is_nullish())
        namespace_ = TRY(arg0.to_string(global_object));

    auto arg1 = vm.argument(1);

    String local_name;
    if (arg1.is_null() && false) {
        local_name = String::empty();
    } else {
        local_name = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_elements_by_tag_name_ns(namespace_, local_name); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::get_elements_by_class_name)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getElementsByClassName");

    auto arg0 = vm.argument(0);

    String class_name;
    if (arg0.is_null() && false) {
        class_name = String::empty();
    } else {
        class_name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_elements_by_class_name(class_name); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_element)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "createElement");

    auto arg0 = vm.argument(0);

    String tag_name;
    if (arg0.is_null() && false) {
        tag_name = String::empty();
    } else {
        tag_name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_element(tag_name); }));

    return wrap(global_object, const_cast<Element&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_element_ns)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "createElementNS", "2");

    auto arg0 = vm.argument(0);

    String namespace_;
    if (!arg0.is_nullish())
        namespace_ = TRY(arg0.to_string(global_object));

    auto arg1 = vm.argument(1);

    String qualified_name;
    if (arg1.is_null() && false) {
        qualified_name = String::empty();
    } else {
        qualified_name = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_element_ns(namespace_, qualified_name); }));

    return wrap(global_object, const_cast<Element&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_document_fragment)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_document_fragment(); }));

    return wrap(global_object, const_cast<DocumentFragment&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_text_node)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "createTextNode");

    auto arg0 = vm.argument(0);

    String data;
    if (arg0.is_null() && false) {
        data = String::empty();
    } else {
        data = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_text_node(data); }));

    return wrap(global_object, const_cast<Text&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_comment)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "createComment");

    auto arg0 = vm.argument(0);

    String data;
    if (arg0.is_null() && false) {
        data = String::empty();
    } else {
        data = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_comment(data); }));

    return wrap(global_object, const_cast<Comment&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_range)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_range(); }));

    return wrap(global_object, const_cast<Range&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_event)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "createEvent");

    auto arg0 = vm.argument(0);

    String interface;
    if (arg0.is_null() && false) {
        interface = String::empty();
    } else {
        interface = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_event(interface); }));

    return wrap(global_object, const_cast<Event&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::import_node)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "importNode");

    auto arg0 = vm.argument(0);

    if (!arg0.is_object() || !is<NodeWrapper>(arg0.as_object()))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Node");

    auto& node = static_cast<NodeWrapper&>(arg0.as_object()).impl();

    auto arg1 = vm.argument(1);

    bool deep;

    if (!arg1.is_undefined())

    deep = arg1.to_boolean();

    else
        deep = false;

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->import_node(node, deep); }));

    return wrap(global_object, const_cast<Node&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::adopt_node)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "adoptNode");

    auto arg0 = vm.argument(0);

    if (!arg0.is_object() || !is<NodeWrapper>(arg0.as_object()))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Node");

    auto& node = static_cast<NodeWrapper&>(arg0.as_object()).impl();

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->adopt_node_binding(node); }));

    return wrap(global_object, const_cast<Node&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::prepend)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0_to_variant = [&global_object, &vm](JS::Value arg0) -> JS::ThrowCompletionOr<Variant<NonnullRefPtr<Node>, String>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg0.is_object()) {
            [[maybe_unused]] auto& arg0_object = arg0.as_object();

            if (is<Wrapper>(arg0_object)) {

                if (is<NodeWrapper>(arg0_object))
                    return NonnullRefPtr<Node> { static_cast<NodeWrapper&>(arg0_object).impl() };

            }

        }

        return TRY(arg0.to_string(global_object));

    };

        Vector<Variant<NonnullRefPtr<Node>, String>> nodes;
        nodes.ensure_capacity(vm.argument_count() - 0);

        for (size_t i = 0; i < vm.argument_count(); ++i) {
            auto result = TRY(arg0_to_variant(vm.argument(i)));
            nodes.append(move(result));
        }
    
    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->prepend(nodes); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::append)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0_to_variant = [&global_object, &vm](JS::Value arg0) -> JS::ThrowCompletionOr<Variant<NonnullRefPtr<Node>, String>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg0.is_object()) {
            [[maybe_unused]] auto& arg0_object = arg0.as_object();

            if (is<Wrapper>(arg0_object)) {

                if (is<NodeWrapper>(arg0_object))
                    return NonnullRefPtr<Node> { static_cast<NodeWrapper&>(arg0_object).impl() };

            }

        }

        return TRY(arg0.to_string(global_object));

    };

        Vector<Variant<NonnullRefPtr<Node>, String>> nodes;
        nodes.ensure_capacity(vm.argument_count() - 0);

        for (size_t i = 0; i < vm.argument_count(); ++i) {
            auto result = TRY(arg0_to_variant(vm.argument(i)));
            nodes.append(move(result));
        }
    
    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->append(nodes); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::replace_children)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0_to_variant = [&global_object, &vm](JS::Value arg0) -> JS::ThrowCompletionOr<Variant<NonnullRefPtr<Node>, String>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg0.is_object()) {
            [[maybe_unused]] auto& arg0_object = arg0.as_object();

            if (is<Wrapper>(arg0_object)) {

                if (is<NodeWrapper>(arg0_object))
                    return NonnullRefPtr<Node> { static_cast<NodeWrapper&>(arg0_object).impl() };

            }

        }

        return TRY(arg0.to_string(global_object));

    };

        Vector<Variant<NonnullRefPtr<Node>, String>> nodes;
        nodes.ensure_capacity(vm.argument_count() - 0);

        for (size_t i = 0; i < vm.argument_count(); ++i) {
            auto result = TRY(arg0_to_variant(vm.argument(i)));
            nodes.append(move(result));
        }
    
    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->replace_children(nodes); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::query_selector)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "querySelector");

    auto arg0 = vm.argument(0);

    String selectors;
    if (arg0.is_null() && false) {
        selectors = String::empty();
    } else {
        selectors = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->query_selector(selectors); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::query_selector_all)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "querySelectorAll");

    auto arg0 = vm.argument(0);

    String selectors;
    if (arg0.is_null() && false) {
        selectors = String::empty();
    } else {
        selectors = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->query_selector_all(selectors); }));

    return wrap(global_object, const_cast<NodeList&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_node_iterator)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "createNodeIterator");

    auto arg0 = vm.argument(0);

    if (!arg0.is_object() || !is<NodeWrapper>(arg0.as_object()))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Node");

    auto& root = static_cast<NodeWrapper&>(arg0.as_object()).impl();

    auto arg1 = vm.argument(1);

    u32 what_to_show;

    if (!arg1.is_undefined())

    what_to_show = TRY(arg1.to_u32(global_object));

    else
        what_to_show = 0xFFFFFFFFUL;

    auto arg2 = vm.argument(2);

    RefPtr<NodeFilter> filter;
    if (!arg2.is_nullish()) {
        if (!arg2.is_object())
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObject, arg2.to_string_without_side_effects());

        CallbackType callback_type(JS::make_handle(&arg2.as_object()), HTML::incumbent_settings_object());
        filter = adopt_ref(*new NodeFilter(move(callback_type)));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_node_iterator(root, what_to_show, filter); }));

    return wrap(global_object, const_cast<NodeIterator&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(DocumentPrototype::create_tree_walker)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "createTreeWalker");

    auto arg0 = vm.argument(0);

    if (!arg0.is_object() || !is<NodeWrapper>(arg0.as_object()))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Node");

    auto& root = static_cast<NodeWrapper&>(arg0.as_object()).impl();

    auto arg1 = vm.argument(1);

    u32 what_to_show;

    if (!arg1.is_undefined())

    what_to_show = TRY(arg1.to_u32(global_object));

    else
        what_to_show = 0xFFFFFFFFUL;

    auto arg2 = vm.argument(2);

    RefPtr<NodeFilter> filter;
    if (!arg2.is_nullish()) {
        if (!arg2.is_object())
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObject, arg2.to_string_without_side_effects());

        CallbackType callback_type(JS::make_handle(&arg2.as_object()), HTML::incumbent_settings_object());
        filter = adopt_ref(*new NodeFilter(move(callback_type)));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->create_tree_walker(root, what_to_show, filter); }));

    return wrap(global_object, const_cast<TreeWalker&>(*retval));

}

} // namespace Web::Bindings

