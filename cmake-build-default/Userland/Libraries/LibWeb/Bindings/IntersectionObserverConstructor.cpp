
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/IntersectionObserverConstructor.h>
#include <LibWeb/Bindings/IntersectionObserverPrototype.h>
#include <LibWeb/Bindings/IntersectionObserverWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/IntersectionObserver.h>)
#    include <LibWeb/Crypto/IntersectionObserver.h>
#elif __has_include(<LibWeb/CSS/IntersectionObserver.h>)
#    include <LibWeb/CSS/IntersectionObserver.h>
#elif __has_include(<LibWeb/DOM/IntersectionObserver.h>)
#    include <LibWeb/DOM/IntersectionObserver.h>
#elif __has_include(<LibWeb/Encoding/IntersectionObserver.h>)
#    include <LibWeb/Encoding/IntersectionObserver.h>
#elif __has_include(<LibWeb/Geometry/IntersectionObserver.h>)
#    include <LibWeb/Geometry/IntersectionObserver.h>
#elif __has_include(<LibWeb/HTML/IntersectionObserver.h>)
#    include <LibWeb/HTML/IntersectionObserver.h>
#elif __has_include(<LibWeb/UIEvents/IntersectionObserver.h>)
#    include <LibWeb/UIEvents/IntersectionObserver.h>
#elif __has_include(<LibWeb/HighResolutionTime/IntersectionObserver.h>)
#    include <LibWeb/HighResolutionTime/IntersectionObserver.h>
#elif __has_include(<LibWeb/IntersectionObserver/IntersectionObserver.h>)
#    include <LibWeb/IntersectionObserver/IntersectionObserver.h>
#elif __has_include(<LibWeb/NavigationTiming/IntersectionObserver.h>)
#    include <LibWeb/NavigationTiming/IntersectionObserver.h>
#elif __has_include(<LibWeb/RequestIdleCallback/IntersectionObserver.h>)
#    include <LibWeb/RequestIdleCallback/IntersectionObserver.h>
#elif __has_include(<LibWeb/ResizeObserver/IntersectionObserver.h>)
#    include <LibWeb/ResizeObserver/IntersectionObserver.h>
#elif __has_include(<LibWeb/SVG/IntersectionObserver.h>)
#    include <LibWeb/SVG/IntersectionObserver.h>
#elif __has_include(<LibWeb/Selection/IntersectionObserver.h>)
#    include <LibWeb/Selection/IntersectionObserver.h>
#elif __has_include(<LibWeb/WebSockets/IntersectionObserver.h>)
#    include <LibWeb/WebSockets/IntersectionObserver.h>
#elif __has_include(<LibWeb/XHR/IntersectionObserver.h>)
#    include <LibWeb/XHR/IntersectionObserver.h>
#elif __has_include(<LibWeb/URL/IntersectionObserver.h>)
#    include <LibWeb/URL/IntersectionObserver.h>
#endif


#include <LibWeb/Geometry/DOMRectList.h>

#include <LibWeb/DOM/Element.h>

#include <LibWeb/HTML/HTMLScriptElement.h>

#include <LibWeb/DOM/Comment.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLHeadElement.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/DOM/CharacterData.h>

#include <LibWeb/DOM/DOMImplementation.h>

#include <LibWeb/DOM/NodeList.h>

#include <LibWeb/DOM/DocumentType.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/DOM/Document.h>

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

#include <LibWeb/IntersectionObserver/IntersectionObserver.h>

#include <LibWeb/DOM/HTMLCollection.h>

#include <LibWeb/DOM/Node.h>

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/IntersectionObserver/IntersectionObserver.h>

#if __has_include(<LibWeb/Bindings/IntersectionObserverWrapper.h>)
#   include <LibWeb/Bindings/IntersectionObserverWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/IntersectionObserverWrapperFactory.h>)
#   include <LibWeb/Bindings/IntersectionObserverWrapperFactory.h>
#endif

#include <LibWeb/DOM/Document.h>

#if __has_include(<LibWeb/Bindings/DocumentWrapper.h>)
#   include <LibWeb/Bindings/DocumentWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DocumentWrapperFactory.h>)
#   include <LibWeb/Bindings/DocumentWrapperFactory.h>
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
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;
using namespace Web::UIEvents;
using namespace Web::XHR;

namespace Web::Bindings {

IntersectionObserverConstructor::IntersectionObserverConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

IntersectionObserverConstructor::~IntersectionObserverConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> IntersectionObserverConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "IntersectionObserver");
}

JS::ThrowCompletionOr<JS::Object*> IntersectionObserverConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "IntersectionObserver");

    auto arg0 = vm.argument(0);

    if (!arg0.is_function())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAFunction, arg0.to_string_without_side_effects());

    auto callback = Bindings::CallbackType { JS::make_handle(&arg0.as_object()), HTML::incumbent_settings_object() };

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "IntersectionObserverInit");

    IntersectionObserverInit options {};

    JS::Value root;
    if (arg1.is_nullish()) {
        root = JS::js_undefined();
    } else {
        root = TRY(arg1.as_object().get("root"));
    }

    auto root_to_variant = [&global_object, &vm](JS::Value root) -> JS::ThrowCompletionOr<Variant<NonnullRefPtr<Element>, NonnullRefPtr<Document>>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (root.is_object()) {
            [[maybe_unused]] auto& root_object = root.as_object();

            if (is<Wrapper>(root_object)) {

                if (is<ElementWrapper>(root_object))
                    return NonnullRefPtr<Element> { static_cast<ElementWrapper&>(root_object).impl() };

                if (is<DocumentWrapper>(root_object))
                    return NonnullRefPtr<Document> { static_cast<DocumentWrapper&>(root_object).impl() };

            }

        }

        return vm.throw_completion<JS::TypeError>(global_object, "No union types matched");

    };

    Optional<Variant<NonnullRefPtr<Element>, NonnullRefPtr<Document>>> root_value;
    if (!root.is_undefined())
        root_value = TRY(root_to_variant(root));

    options.root = root_value;

    JS::Value root_margin;
    if (arg1.is_nullish()) {
        root_margin = JS::js_undefined();
    } else {
        root_margin = TRY(arg1.as_object().get("rootMargin"));
    }

    String root_margin_value;
    if (!root_margin.is_undefined()) {
        if (root_margin.is_null() && false)
            root_margin_value = String::empty();
        else
            root_margin_value = TRY(root_margin.to_string(global_object));
    } else {
        root_margin_value = "0px";
    }

    options.root_margin = root_margin_value;

    JS::Value threshold;
    if (arg1.is_nullish()) {
        threshold = JS::js_undefined();
    } else {
        threshold = TRY(arg1.as_object().get("threshold"));
    }

    auto threshold_to_variant = [&global_object, &vm](JS::Value threshold) -> JS::ThrowCompletionOr<Variant<double, Vector<double>>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (threshold.is_object()) {
            [[maybe_unused]] auto& threshold_object = threshold.as_object();

        auto* method = TRY(threshold.get_method(global_object, *vm.well_known_symbol_iterator()));

        if (method) {

    auto iterator1 = TRY(JS::get_iterator(global_object, threshold, JS::IteratorHint::Sync, method));

    Vector<double> threshold_value;

    for (;;) {
        auto* next1 = TRY(JS::iterator_step(global_object, iterator1));
        if (!next1)
            break;

        auto next_item1 = TRY(JS::iterator_value(global_object, *next1));

    double sequence_item1 = TRY(next_item1.to_double(global_object));

        threshold_value.append(sequence_item1);
    }


            return threshold_value;
        }

        }

        if (threshold.is_number()) {

    double threshold_number = TRY(threshold.to_double(global_object));

            return threshold_number;
        }

    double threshold_number = TRY(threshold.to_double(global_object));

        return threshold_number;

    };

    Variant<double, Vector<double>> threshold_value = threshold.is_undefined() ? 0 : TRY(threshold_to_variant(threshold));

    options.threshold = threshold_value;

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return IntersectionObserver::IntersectionObserver::create_with_global_object(window, callback, options); }));

    return wrap(global_object, *impl);

}

void IntersectionObserverConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<IntersectionObserverPrototype>("IntersectionObserver"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

