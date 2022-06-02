
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/TextPrototype.h>
#include <LibWeb/Bindings/TextWrapper.h>
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

#if __has_include(<LibWeb/Bindings/CharacterDataPrototype.h>)
#    include <LibWeb/Bindings/CharacterDataPrototype.h>
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

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/DOM/Text.h>

#if __has_include(<LibWeb/Bindings/TextWrapper.h>)
#   include <LibWeb/Bindings/TextWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TextWrapperFactory.h>)
#   include <LibWeb/Bindings/TextWrapperFactory.h>
#endif

#include <LibWeb/DOM/CharacterData.h>

#if __has_include(<LibWeb/Bindings/CharacterDataWrapper.h>)
#   include <LibWeb/Bindings/CharacterDataWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CharacterDataWrapperFactory.h>)
#   include <LibWeb/Bindings/CharacterDataWrapperFactory.h>
#endif

#include <LibWeb/DOM/Element.h>

#if __has_include(<LibWeb/Bindings/ElementWrapper.h>)
#   include <LibWeb/Bindings/ElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ElementWrapperFactory.h>)
#   include <LibWeb/Bindings/ElementWrapperFactory.h>
#endif

#include <LibWeb/DOM/Node.h>

#if __has_include(<LibWeb/Bindings/NodeWrapper.h>)
#   include <LibWeb/Bindings/NodeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/NodeWrapperFactory.h>)
#   include <LibWeb/Bindings/NodeWrapperFactory.h>
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

TextPrototype::TextPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<CharacterDataPrototype>("CharacterData"))

{
}

TextPrototype::~TextPrototype()
{
}

void TextPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_function("splitText", split_text, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<DOM::Text*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<TextWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "DOM::Text");

    return &static_cast<TextWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(TextPrototype::split_text)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "splitText");

    auto arg0 = vm.argument(0);

    u32 offset;

    offset = TRY(arg0.to_u32(global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->split_text(offset); }));

    return wrap(global_object, const_cast<Text&>(*retval));

}

} // namespace Web::Bindings

