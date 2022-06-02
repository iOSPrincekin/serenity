
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/ElementPrototype.h>
#include <LibWeb/Bindings/ElementWrapper.h>
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

#include <LibWeb/DOM/Node.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/DOM/CharacterData.h>

#include <LibWeb/DOM/DocumentFragment.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/Text.h>

#include <LibWeb/DOM/NodeFilter.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/NamedNodeMap.h>

#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/TreeWalker.h>

#include <LibWeb/DOM/HTMLCollection.h>

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/DOM/Element.h>

#if __has_include(<LibWeb/Bindings/ElementWrapper.h>)
#   include <LibWeb/Bindings/ElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ElementWrapperFactory.h>)
#   include <LibWeb/Bindings/ElementWrapperFactory.h>
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

#include <LibWeb/DOM/Node.h>

#if __has_include(<LibWeb/Bindings/NodeWrapper.h>)
#   include <LibWeb/Bindings/NodeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/NodeWrapperFactory.h>)
#   include <LibWeb/Bindings/NodeWrapperFactory.h>
#endif

#include <LibWeb/DOM/NodeList.h>

#if __has_include(<LibWeb/Bindings/NodeListWrapper.h>)
#   include <LibWeb/Bindings/NodeListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/NodeListWrapperFactory.h>)
#   include <LibWeb/Bindings/NodeListWrapperFactory.h>
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

#include <LibWeb/DOM/Attribute.h>

#if __has_include(<LibWeb/Bindings/AttributeWrapper.h>)
#   include <LibWeb/Bindings/AttributeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AttributeWrapperFactory.h>)
#   include <LibWeb/Bindings/AttributeWrapperFactory.h>
#endif

#include <LibWeb/DOM/Document.h>

#if __has_include(<LibWeb/Bindings/DocumentWrapper.h>)
#   include <LibWeb/Bindings/DocumentWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DocumentWrapperFactory.h>)
#   include <LibWeb/Bindings/DocumentWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapper.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>
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

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
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

ElementPrototype::ElementPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<NodePrototype>("Node"))

{
}

ElementPrototype::~ElementPrototype()
{
}

void ElementPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    auto* unscopable_object = JS::Object::create(global_object, nullptr);

    define_native_accessor("namespaceURI", namespace_uri_getter, nullptr, default_attributes);

    define_native_accessor("prefix", prefix_getter, nullptr, default_attributes);

    define_native_accessor("localName", local_name_getter, nullptr, default_attributes);

    define_native_accessor("tagName", tag_name_getter, nullptr, default_attributes);

    define_native_accessor("attributes", attributes_getter, nullptr, default_attributes);

    define_native_accessor("innerHTML", inner_html_getter, inner_html_setter, default_attributes);

    define_native_accessor("id", id_getter, id_setter, default_attributes);

    define_native_accessor("className", class_name_getter, class_name_setter, default_attributes);

    define_native_accessor("classList", class_list_getter, nullptr, default_attributes);

    define_native_accessor("nextElementSibling", next_element_sibling_getter, nullptr, default_attributes);

    define_native_accessor("previousElementSibling", previous_element_sibling_getter, nullptr, default_attributes);

    define_native_accessor("style", style_getter, nullptr, default_attributes);

    define_native_accessor("firstElementChild", first_element_child_getter, nullptr, default_attributes);

    define_native_accessor("lastElementChild", last_element_child_getter, nullptr, default_attributes);

    define_native_accessor("childElementCount", child_element_count_getter, nullptr, default_attributes);

    define_native_accessor("children", children_getter, nullptr, default_attributes);

    define_native_accessor("clientTop", client_top_getter, nullptr, default_attributes);

    define_native_accessor("clientLeft", client_left_getter, nullptr, default_attributes);

    define_native_accessor("clientWidth", client_width_getter, nullptr, default_attributes);

    define_native_accessor("clientHeight", client_height_getter, nullptr, default_attributes);

    define_native_function("getElementsByTagNameNS", get_elements_by_tag_name_ns, 2, default_attributes);

    define_native_function("getElementsByClassName", get_elements_by_class_name, 1, default_attributes);

    define_native_function("webkitMatchesSelector", webkit_matches_selector, 1, default_attributes);

    define_native_function("getAttributeNames", get_attribute_names, 0, default_attributes);

    define_native_function("matches", matches, 1, default_attributes);

    define_native_function("getClientRects", get_client_rects, 0, default_attributes);

    MUST(unscopable_object->create_data_property("replaceChildren", JS::Value(true)));

    define_native_function("replaceChildren", replace_children, 0, default_attributes);

    define_native_function("setAttribute", set_attribute, 2, default_attributes);

    MUST(unscopable_object->create_data_property("replaceWith", JS::Value(true)));

    define_native_function("replaceWith", replace_with, 0, default_attributes);

    MUST(unscopable_object->create_data_property("prepend", JS::Value(true)));

    define_native_function("prepend", prepend, 0, default_attributes);

    MUST(unscopable_object->create_data_property("append", JS::Value(true)));

    define_native_function("append", append, 0, default_attributes);

    define_native_function("querySelector", query_selector, 1, default_attributes);

    define_native_function("getBoundingClientRect", get_bounding_client_rect, 0, default_attributes);

    MUST(unscopable_object->create_data_property("after", JS::Value(true)));

    define_native_function("after", after, 0, default_attributes);

    define_native_function("querySelectorAll", query_selector_all, 1, default_attributes);

    define_native_function("hasAttribute", has_attribute, 1, default_attributes);

    MUST(unscopable_object->create_data_property("before", JS::Value(true)));

    define_native_function("before", before, 0, default_attributes);

    MUST(unscopable_object->create_data_property("remove", JS::Value(true)));

    define_native_function("remove", remove, 0, default_attributes);

    define_native_function("hasAttributes", has_attributes, 0, default_attributes);

    define_native_function("toggleAttribute", toggle_attribute, 1, default_attributes);

    define_native_function("closest", closest, 1, default_attributes);

    define_native_function("removeAttribute", remove_attribute, 1, default_attributes);

    define_native_function("getElementsByTagName", get_elements_by_tag_name, 1, default_attributes);

    define_native_function("setAttributeNS", set_attribute_ns, 3, default_attributes);

    define_native_function("getAttribute", get_attribute, 1, default_attributes);

    define_direct_property(*vm.well_known_symbol_unscopables(), unscopable_object, JS::Attribute::Configurable);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<DOM::Element*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<ElementWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "DOM::Element");

    return &static_cast<ElementWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::namespace_uri_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->namespace_uri(); }));

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::prefix_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->prefix(); }));

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::local_name_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->local_name(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::tag_name_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->tag_name(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::attributes_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->attributes(); }));

    return wrap(global_object, const_cast<NamedNodeMap&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::inner_html_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->inner_html(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::inner_html_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && true) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_inner_html(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::id_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::id);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::id_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::id, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::class_name_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = impl->attribute(HTML::AttributeNames::class_);

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::class_name_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    String cpp_value;
    if (value.is_null() && false) {
        cpp_value = String::empty();
    } else {
        cpp_value = TRY(value.to_string(global_object));
    }

    impl->set_attribute(HTML::AttributeNames::class_, cpp_value);

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::class_list_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->class_list(); }));

    return wrap(global_object, const_cast<DOMTokenList&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::next_element_sibling_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->next_element_sibling(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::previous_element_sibling_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->previous_element_sibling(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::style_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->style_for_bindings(); }));

    return wrap(global_object, const_cast<CSSStyleDeclaration&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::first_element_child_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->first_element_child(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::last_element_child_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->last_element_child(); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::child_element_count_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->child_element_count(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::children_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->children(); }));

    return wrap(global_object, const_cast<HTMLCollection&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::client_top_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->client_top(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::client_left_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->client_left(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::client_width_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->client_width(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::client_height_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->client_height(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::get_attribute)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getAttribute");

    auto arg0 = vm.argument(0);

    String qualified_name;
    if (arg0.is_null() && false) {
        qualified_name = String::empty();
    } else {
        qualified_name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_attribute(qualified_name); }));

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::set_attribute)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "setAttribute", "2");

    auto arg0 = vm.argument(0);

    String qualified_name;
    if (arg0.is_null() && false) {
        qualified_name = String::empty();
    } else {
        qualified_name = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String value;
    if (arg1.is_null() && false) {
        value = String::empty();
    } else {
        value = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_attribute(qualified_name, value); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::set_attribute_ns)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 3)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "setAttributeNS", "3");

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

    auto arg2 = vm.argument(2);

    String value;
    if (arg2.is_null() && false) {
        value = String::empty();
    } else {
        value = TRY(arg2.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_attribute_ns(namespace_, qualified_name, value); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::remove_attribute)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "removeAttribute");

    auto arg0 = vm.argument(0);

    String qualified_name;
    if (arg0.is_null() && false) {
        qualified_name = String::empty();
    } else {
        qualified_name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->remove_attribute(qualified_name); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::toggle_attribute)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "toggleAttribute");

    auto arg0 = vm.argument(0);

    String qualified_name;
    if (arg0.is_null() && false) {
        qualified_name = String::empty();
    } else {
        qualified_name = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    Optional<bool> force;

    if (!arg1.is_undefined())

    force = arg1.to_boolean();

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->toggle_attribute(qualified_name, force); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::has_attribute)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "hasAttribute");

    auto arg0 = vm.argument(0);

    String qualified_name;
    if (arg0.is_null() && false) {
        qualified_name = String::empty();
    } else {
        qualified_name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->has_attribute(qualified_name); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::has_attributes)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->has_attributes(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::get_attribute_names)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_attribute_names(); }));

    auto* new_array0 = MUST(JS::Array::create(global_object, 0));

    for (size_t i0 = 0; i0 < retval.size(); ++i0) {
        auto& element0 = retval.at(i0);

    auto wrapped_element0 = JS::js_string(vm, element0);

        auto property_index0 = JS::PropertyKey { i0 };
        MUST(new_array0->create_data_property(property_index0, wrapped_element0));
    }

    return new_array0;

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::get_elements_by_tag_name)
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

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::get_elements_by_tag_name_ns)
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

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::get_elements_by_class_name)
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

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::matches)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "matches");

    auto arg0 = vm.argument(0);

    String selectors;
    if (arg0.is_null() && false) {
        selectors = String::empty();
    } else {
        selectors = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->matches(selectors); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::closest)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "closest");

    auto arg0 = vm.argument(0);

    String selectors;
    if (arg0.is_null() && false) {
        selectors = String::empty();
    } else {
        selectors = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->closest(selectors); }));

    if (!retval) {
        return JS::js_null();
    } else {

    return wrap(global_object, const_cast<Element&>(*retval));

    }

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::webkit_matches_selector)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "webkitMatchesSelector");

    auto arg0 = vm.argument(0);

    String selectors;
    if (arg0.is_null() && false) {
        selectors = String::empty();
    } else {
        selectors = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->matches(selectors); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::prepend)
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

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::append)
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

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::replace_children)
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

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::query_selector)
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

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::query_selector_all)
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

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::get_bounding_client_rect)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_bounding_client_rect(); }));

    return wrap(global_object, const_cast<DOMRect&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::get_client_rects)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_client_rects(); }));

    return wrap(global_object, const_cast<DOMRectList&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::before)
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
    
    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->before(nodes); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::after)
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
    
    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->after(nodes); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::replace_with)
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
    
    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->replace_with(nodes); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(ElementPrototype::remove)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->remove_binding(); }));

    return JS::js_undefined();

}

} // namespace Web::Bindings

