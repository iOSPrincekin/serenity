
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/ProgressEventConstructor.h>
#include <LibWeb/Bindings/ProgressEventPrototype.h>
#include <LibWeb/Bindings/ProgressEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/ProgressEvent.h>)
#    include <LibWeb/Crypto/ProgressEvent.h>
#elif __has_include(<LibWeb/CSS/ProgressEvent.h>)
#    include <LibWeb/CSS/ProgressEvent.h>
#elif __has_include(<LibWeb/DOM/ProgressEvent.h>)
#    include <LibWeb/DOM/ProgressEvent.h>
#elif __has_include(<LibWeb/Encoding/ProgressEvent.h>)
#    include <LibWeb/Encoding/ProgressEvent.h>
#elif __has_include(<LibWeb/Geometry/ProgressEvent.h>)
#    include <LibWeb/Geometry/ProgressEvent.h>
#elif __has_include(<LibWeb/HTML/ProgressEvent.h>)
#    include <LibWeb/HTML/ProgressEvent.h>
#elif __has_include(<LibWeb/UIEvents/ProgressEvent.h>)
#    include <LibWeb/UIEvents/ProgressEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/ProgressEvent.h>)
#    include <LibWeb/HighResolutionTime/ProgressEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/ProgressEvent.h>)
#    include <LibWeb/IntersectionObserver/ProgressEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/ProgressEvent.h>)
#    include <LibWeb/NavigationTiming/ProgressEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/ProgressEvent.h>)
#    include <LibWeb/RequestIdleCallback/ProgressEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/ProgressEvent.h>)
#    include <LibWeb/ResizeObserver/ProgressEvent.h>
#elif __has_include(<LibWeb/SVG/ProgressEvent.h>)
#    include <LibWeb/SVG/ProgressEvent.h>
#elif __has_include(<LibWeb/Selection/ProgressEvent.h>)
#    include <LibWeb/Selection/ProgressEvent.h>
#elif __has_include(<LibWeb/WebSockets/ProgressEvent.h>)
#    include <LibWeb/WebSockets/ProgressEvent.h>
#elif __has_include(<LibWeb/XHR/ProgressEvent.h>)
#    include <LibWeb/XHR/ProgressEvent.h>
#elif __has_include(<LibWeb/URL/ProgressEvent.h>)
#    include <LibWeb/URL/ProgressEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/XHR/ProgressEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/XHR/ProgressEvent.h>

#if __has_include(<LibWeb/Bindings/ProgressEventWrapper.h>)
#   include <LibWeb/Bindings/ProgressEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ProgressEventWrapperFactory.h>)
#   include <LibWeb/Bindings/ProgressEventWrapperFactory.h>
#endif

#include <LibWeb/DOM/Event.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
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

ProgressEventConstructor::ProgressEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

ProgressEventConstructor::~ProgressEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> ProgressEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "ProgressEvent");
}

JS::ThrowCompletionOr<JS::Object*> ProgressEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "ProgressEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "ProgressEventInit");

    ProgressEventInit event_init_dict {};

    JS::Value length_computable;
    if (arg1.is_nullish()) {
        length_computable = JS::js_undefined();
    } else {
        length_computable = TRY(arg1.as_object().get("lengthComputable"));
    }

    bool length_computable_value;

    if (!length_computable.is_undefined())

    length_computable_value = length_computable.to_boolean();

    else
        length_computable_value = false;

    event_init_dict.length_computable = length_computable_value;

    JS::Value loaded;
    if (arg1.is_nullish()) {
        loaded = JS::js_undefined();
    } else {
        loaded = TRY(arg1.as_object().get("loaded"));
    }

    u32 loaded_value;

    if (!loaded.is_undefined())

    loaded_value = TRY(loaded.to_u32(global_object));

    else
        loaded_value = 0UL;

    event_init_dict.loaded = loaded_value;

    JS::Value total;
    if (arg1.is_nullish()) {
        total = JS::js_undefined();
    } else {
        total = TRY(arg1.as_object().get("total"));
    }

    u32 total_value;

    if (!total.is_undefined())

    total_value = TRY(total.to_u32(global_object));

    else
        total_value = 0UL;

    event_init_dict.total = total_value;

    JS::Value bubbles;
    if (arg1.is_nullish()) {
        bubbles = JS::js_undefined();
    } else {
        bubbles = TRY(arg1.as_object().get("bubbles"));
    }

    bool bubbles_value;

    if (!bubbles.is_undefined())

    bubbles_value = bubbles.to_boolean();

    else
        bubbles_value = false;

    event_init_dict.bubbles = bubbles_value;

    JS::Value cancelable;
    if (arg1.is_nullish()) {
        cancelable = JS::js_undefined();
    } else {
        cancelable = TRY(arg1.as_object().get("cancelable"));
    }

    bool cancelable_value;

    if (!cancelable.is_undefined())

    cancelable_value = cancelable.to_boolean();

    else
        cancelable_value = false;

    event_init_dict.cancelable = cancelable_value;

    JS::Value composed;
    if (arg1.is_nullish()) {
        composed = JS::js_undefined();
    } else {
        composed = TRY(arg1.as_object().get("composed"));
    }

    bool composed_value;

    if (!composed.is_undefined())

    composed_value = composed.to_boolean();

    else
        composed_value = false;

    event_init_dict.composed = composed_value;

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return XHR::ProgressEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void ProgressEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<ProgressEventPrototype>("ProgressEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

