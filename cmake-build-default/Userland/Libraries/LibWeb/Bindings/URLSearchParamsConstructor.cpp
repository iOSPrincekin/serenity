
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/URLSearchParamsConstructor.h>
#include <LibWeb/Bindings/URLSearchParamsPrototype.h>
#include <LibWeb/Bindings/URLSearchParamsWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/URLSearchParams.h>)
#    include <LibWeb/Crypto/URLSearchParams.h>
#elif __has_include(<LibWeb/CSS/URLSearchParams.h>)
#    include <LibWeb/CSS/URLSearchParams.h>
#elif __has_include(<LibWeb/DOM/URLSearchParams.h>)
#    include <LibWeb/DOM/URLSearchParams.h>
#elif __has_include(<LibWeb/Encoding/URLSearchParams.h>)
#    include <LibWeb/Encoding/URLSearchParams.h>
#elif __has_include(<LibWeb/Geometry/URLSearchParams.h>)
#    include <LibWeb/Geometry/URLSearchParams.h>
#elif __has_include(<LibWeb/HTML/URLSearchParams.h>)
#    include <LibWeb/HTML/URLSearchParams.h>
#elif __has_include(<LibWeb/UIEvents/URLSearchParams.h>)
#    include <LibWeb/UIEvents/URLSearchParams.h>
#elif __has_include(<LibWeb/HighResolutionTime/URLSearchParams.h>)
#    include <LibWeb/HighResolutionTime/URLSearchParams.h>
#elif __has_include(<LibWeb/IntersectionObserver/URLSearchParams.h>)
#    include <LibWeb/IntersectionObserver/URLSearchParams.h>
#elif __has_include(<LibWeb/NavigationTiming/URLSearchParams.h>)
#    include <LibWeb/NavigationTiming/URLSearchParams.h>
#elif __has_include(<LibWeb/RequestIdleCallback/URLSearchParams.h>)
#    include <LibWeb/RequestIdleCallback/URLSearchParams.h>
#elif __has_include(<LibWeb/ResizeObserver/URLSearchParams.h>)
#    include <LibWeb/ResizeObserver/URLSearchParams.h>
#elif __has_include(<LibWeb/SVG/URLSearchParams.h>)
#    include <LibWeb/SVG/URLSearchParams.h>
#elif __has_include(<LibWeb/Selection/URLSearchParams.h>)
#    include <LibWeb/Selection/URLSearchParams.h>
#elif __has_include(<LibWeb/WebSockets/URLSearchParams.h>)
#    include <LibWeb/WebSockets/URLSearchParams.h>
#elif __has_include(<LibWeb/XHR/URLSearchParams.h>)
#    include <LibWeb/XHR/URLSearchParams.h>
#elif __has_include(<LibWeb/URL/URLSearchParams.h>)
#    include <LibWeb/URL/URLSearchParams.h>
#endif


#include <LibWeb/URL/URLSearchParams.h>

#include <LibWeb/URL/URLSearchParams.h>

//#if __has_include(<LibWeb/URL/URLSearchParamsIterator.h>)
#   include <LibWeb/URL/URLSearchParamsIterator.h>
//#endif
#if __has_include(<LibWeb/URL/URLSearchParamsIteratorFactory.h>)
#   include <LibWeb/URL/URLSearchParamsIteratorFactory.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsIteratorWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsIteratorWrapperFactory.h>
#endif

#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapperFactory.h>
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

URLSearchParamsConstructor::URLSearchParamsConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

URLSearchParamsConstructor::~URLSearchParamsConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> URLSearchParamsConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "URLSearchParams");
}

JS::ThrowCompletionOr<JS::Object*> URLSearchParamsConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    auto arg0 = vm.argument(0);

    auto arg0_to_variant = [&global_object, &vm](JS::Value arg0) -> JS::ThrowCompletionOr<Variant<Vector<Vector<String>>, OrderedHashMap<String, String>, String>> {
        // These might be unused.
        (void)global_object;
        (void)vm;

        if (arg0.is_object()) {
            [[maybe_unused]] auto& arg0_object = arg0.as_object();

        auto* method = TRY(arg0.get_method(global_object, *vm.well_known_symbol_iterator()));

        if (method) {

    auto iterator1 = TRY(JS::get_iterator(global_object, arg0, JS::IteratorHint::Sync, method));

    Vector<Vector<String>> init;

    for (;;) {
        auto* next1 = TRY(JS::iterator_step(global_object, iterator1));
        if (!next1)
            break;

        auto next_item1 = TRY(JS::iterator_value(global_object, *next1));

    if (!next_item1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObject, next_item1.to_string_without_side_effects());

    auto* iterator_method1 = TRY(next_item1.get_method(global_object, *vm.well_known_symbol_iterator()));
    if (!iterator_method1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotIterable, next_item1.to_string_without_side_effects());

    auto iterator2 = TRY(JS::get_iterator(global_object, next_item1, JS::IteratorHint::Sync, iterator_method1));

    Vector<String> sequence_item1;

    for (;;) {
        auto* next2 = TRY(JS::iterator_step(global_object, iterator2));
        if (!next2)
            break;

        auto next_item2 = TRY(JS::iterator_value(global_object, *next2));

    String sequence_item2;
    if (next_item2.is_null() && false) {
        sequence_item2 = String::empty();
    } else {
        sequence_item2 = TRY(next_item2.to_string(global_object));
    }

        sequence_item1.append(sequence_item2);
    }

        init.append(sequence_item1);
    }


            return init;
        }

    OrderedHashMap<String, String> record_union_type;

    auto record_keys1 = TRY(arg0_object.internal_own_property_keys());

    for (auto& key1 : record_keys1) {
        auto property_key1 = MUST(JS::PropertyKey::from_value(global_object, key1));

        auto descriptor1 = TRY(arg0_object.internal_get_own_property(property_key1));

        if (!descriptor1.has_value() || !descriptor1->enumerable.has_value() || !descriptor1->enumerable.value())
            continue;

    String typed_key1;
    if (key1.is_null() && false) {
        typed_key1 = String::empty();
    } else {
        typed_key1 = TRY(key1.to_string(global_object));
    }

        auto value1 = TRY(arg0_object.get(property_key1));

    String typed_value1;
    if (value1.is_null() && false) {
        typed_value1 = String::empty();
    } else {
        typed_value1 = TRY(value1.to_string(global_object));
    }

        record_union_type.set(typed_key1, typed_value1);
    }

        return record_union_type;

        }

        return TRY(arg0.to_string(global_object));

    };

    Variant<Vector<Vector<String>>, OrderedHashMap<String, String>, String> init = arg0.is_undefined() ? String::empty() : TRY(arg0_to_variant(arg0));

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return URL::URLSearchParams::create_with_global_object(window, init); }));

    return wrap(global_object, *impl);

}

void URLSearchParamsConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<URLSearchParamsPrototype>("URLSearchParams"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

