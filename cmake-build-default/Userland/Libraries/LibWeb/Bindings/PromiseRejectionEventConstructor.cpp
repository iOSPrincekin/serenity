
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/PromiseRejectionEventConstructor.h>
#include <LibWeb/Bindings/PromiseRejectionEventPrototype.h>
#include <LibWeb/Bindings/PromiseRejectionEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/PromiseRejectionEvent.h>)
#    include <LibWeb/Crypto/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/CSS/PromiseRejectionEvent.h>)
#    include <LibWeb/CSS/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/DOM/PromiseRejectionEvent.h>)
#    include <LibWeb/DOM/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/Encoding/PromiseRejectionEvent.h>)
#    include <LibWeb/Encoding/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/Geometry/PromiseRejectionEvent.h>)
#    include <LibWeb/Geometry/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/HTML/PromiseRejectionEvent.h>)
#    include <LibWeb/HTML/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/UIEvents/PromiseRejectionEvent.h>)
#    include <LibWeb/UIEvents/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/PromiseRejectionEvent.h>)
#    include <LibWeb/HighResolutionTime/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/PromiseRejectionEvent.h>)
#    include <LibWeb/IntersectionObserver/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/PromiseRejectionEvent.h>)
#    include <LibWeb/NavigationTiming/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/PromiseRejectionEvent.h>)
#    include <LibWeb/RequestIdleCallback/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/PromiseRejectionEvent.h>)
#    include <LibWeb/ResizeObserver/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/SVG/PromiseRejectionEvent.h>)
#    include <LibWeb/SVG/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/Selection/PromiseRejectionEvent.h>)
#    include <LibWeb/Selection/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/WebSockets/PromiseRejectionEvent.h>)
#    include <LibWeb/WebSockets/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/XHR/PromiseRejectionEvent.h>)
#    include <LibWeb/XHR/PromiseRejectionEvent.h>
#elif __has_include(<LibWeb/URL/PromiseRejectionEvent.h>)
#    include <LibWeb/URL/PromiseRejectionEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/PromiseRejectionEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/PromiseRejectionEvent.h>

#if __has_include(<LibWeb/Bindings/PromiseRejectionEventWrapper.h>)
#   include <LibWeb/Bindings/PromiseRejectionEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/PromiseRejectionEventWrapperFactory.h>)
#   include <LibWeb/Bindings/PromiseRejectionEventWrapperFactory.h>
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

PromiseRejectionEventConstructor::PromiseRejectionEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

PromiseRejectionEventConstructor::~PromiseRejectionEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> PromiseRejectionEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "PromiseRejectionEvent");
}

JS::ThrowCompletionOr<JS::Object*> PromiseRejectionEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "PromiseRejectionEvent", "2");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "PromiseRejectionEventInit");

    PromiseRejectionEventInit event_init_dict {};

    JS::Value promise;
    if (arg1.is_nullish()) {
        promise = JS::js_undefined();
    } else {
        promise = TRY(arg1.as_object().get("promise"));
    }

    if (promise.is_undefined())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::MissingRequiredProperty, "promise");

    if (!promise.is_object() || !is<JS::Promise>(promise.as_object())) {
        auto* new_promise = JS::Promise::create(global_object);
        new_promise->fulfill(promise);
        promise = new_promise;
    }
    auto promise_value = JS::make_handle(&static_cast<JS::Promise&>(promise.as_object()));

    event_init_dict.promise = promise_value;

    JS::Value reason;
    if (arg1.is_nullish()) {
        reason = JS::js_undefined();
    } else {
        reason = TRY(arg1.as_object().get("reason"));
    }

    JS::Value reason_value = JS::js_undefined();
    if (!reason.is_undefined())
        reason_value = reason;

    event_init_dict.reason = reason_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return HTML::PromiseRejectionEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void PromiseRejectionEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<PromiseRejectionEventPrototype>("PromiseRejectionEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(2), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

