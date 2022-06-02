
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/MessageEventConstructor.h>
#include <LibWeb/Bindings/MessageEventPrototype.h>
#include <LibWeb/Bindings/MessageEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/MessageEvent.h>)
#    include <LibWeb/Crypto/MessageEvent.h>
#elif __has_include(<LibWeb/CSS/MessageEvent.h>)
#    include <LibWeb/CSS/MessageEvent.h>
#elif __has_include(<LibWeb/DOM/MessageEvent.h>)
#    include <LibWeb/DOM/MessageEvent.h>
#elif __has_include(<LibWeb/Encoding/MessageEvent.h>)
#    include <LibWeb/Encoding/MessageEvent.h>
#elif __has_include(<LibWeb/Geometry/MessageEvent.h>)
#    include <LibWeb/Geometry/MessageEvent.h>
#elif __has_include(<LibWeb/HTML/MessageEvent.h>)
#    include <LibWeb/HTML/MessageEvent.h>
#elif __has_include(<LibWeb/UIEvents/MessageEvent.h>)
#    include <LibWeb/UIEvents/MessageEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/MessageEvent.h>)
#    include <LibWeb/HighResolutionTime/MessageEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/MessageEvent.h>)
#    include <LibWeb/IntersectionObserver/MessageEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/MessageEvent.h>)
#    include <LibWeb/NavigationTiming/MessageEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/MessageEvent.h>)
#    include <LibWeb/RequestIdleCallback/MessageEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/MessageEvent.h>)
#    include <LibWeb/ResizeObserver/MessageEvent.h>
#elif __has_include(<LibWeb/SVG/MessageEvent.h>)
#    include <LibWeb/SVG/MessageEvent.h>
#elif __has_include(<LibWeb/Selection/MessageEvent.h>)
#    include <LibWeb/Selection/MessageEvent.h>
#elif __has_include(<LibWeb/WebSockets/MessageEvent.h>)
#    include <LibWeb/WebSockets/MessageEvent.h>
#elif __has_include(<LibWeb/XHR/MessageEvent.h>)
#    include <LibWeb/XHR/MessageEvent.h>
#elif __has_include(<LibWeb/URL/MessageEvent.h>)
#    include <LibWeb/URL/MessageEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/MessageEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/MessageEvent.h>

#if __has_include(<LibWeb/Bindings/MessageEventWrapper.h>)
#   include <LibWeb/Bindings/MessageEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MessageEventWrapperFactory.h>)
#   include <LibWeb/Bindings/MessageEventWrapperFactory.h>
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

MessageEventConstructor::MessageEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

MessageEventConstructor::~MessageEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> MessageEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "MessageEvent");
}

JS::ThrowCompletionOr<JS::Object*> MessageEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "MessageEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "MessageEventInit");

    MessageEventInit event_init_dict {};

    JS::Value data;
    if (arg1.is_nullish()) {
        data = JS::js_undefined();
    } else {
        data = TRY(arg1.as_object().get("data"));
    }

    JS::Value data_value = JS::js_undefined();
    if (!data.is_undefined())
        data_value = data;

    else
        data_value = JS::js_null();

    event_init_dict.data = data_value;

    JS::Value last_event_id;
    if (arg1.is_nullish()) {
        last_event_id = JS::js_undefined();
    } else {
        last_event_id = TRY(arg1.as_object().get("lastEventId"));
    }

    String last_event_id_value;
    if (!last_event_id.is_undefined()) {
        if (last_event_id.is_null() && false)
            last_event_id_value = String::empty();
        else
            last_event_id_value = TRY(last_event_id.to_string(global_object));
    } else {
        last_event_id_value = "";
    }

    event_init_dict.last_event_id = last_event_id_value;

    JS::Value origin;
    if (arg1.is_nullish()) {
        origin = JS::js_undefined();
    } else {
        origin = TRY(arg1.as_object().get("origin"));
    }

    String origin_value;
    if (!origin.is_undefined()) {
        if (origin.is_null() && false)
            origin_value = String::empty();
        else
            origin_value = TRY(origin.to_string(global_object));
    } else {
        origin_value = "";
    }

    event_init_dict.origin = origin_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return HTML::MessageEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void MessageEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<MessageEventPrototype>("MessageEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

