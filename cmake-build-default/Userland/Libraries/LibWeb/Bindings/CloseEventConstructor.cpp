
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CloseEventConstructor.h>
#include <LibWeb/Bindings/CloseEventPrototype.h>
#include <LibWeb/Bindings/CloseEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CloseEvent.h>)
#    include <LibWeb/Crypto/CloseEvent.h>
#elif __has_include(<LibWeb/CSS/CloseEvent.h>)
#    include <LibWeb/CSS/CloseEvent.h>
#elif __has_include(<LibWeb/DOM/CloseEvent.h>)
#    include <LibWeb/DOM/CloseEvent.h>
#elif __has_include(<LibWeb/Encoding/CloseEvent.h>)
#    include <LibWeb/Encoding/CloseEvent.h>
#elif __has_include(<LibWeb/Geometry/CloseEvent.h>)
#    include <LibWeb/Geometry/CloseEvent.h>
#elif __has_include(<LibWeb/HTML/CloseEvent.h>)
#    include <LibWeb/HTML/CloseEvent.h>
#elif __has_include(<LibWeb/UIEvents/CloseEvent.h>)
#    include <LibWeb/UIEvents/CloseEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/CloseEvent.h>)
#    include <LibWeb/HighResolutionTime/CloseEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/CloseEvent.h>)
#    include <LibWeb/IntersectionObserver/CloseEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/CloseEvent.h>)
#    include <LibWeb/NavigationTiming/CloseEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CloseEvent.h>)
#    include <LibWeb/RequestIdleCallback/CloseEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/CloseEvent.h>)
#    include <LibWeb/ResizeObserver/CloseEvent.h>
#elif __has_include(<LibWeb/SVG/CloseEvent.h>)
#    include <LibWeb/SVG/CloseEvent.h>
#elif __has_include(<LibWeb/Selection/CloseEvent.h>)
#    include <LibWeb/Selection/CloseEvent.h>
#elif __has_include(<LibWeb/WebSockets/CloseEvent.h>)
#    include <LibWeb/WebSockets/CloseEvent.h>
#elif __has_include(<LibWeb/XHR/CloseEvent.h>)
#    include <LibWeb/XHR/CloseEvent.h>
#elif __has_include(<LibWeb/URL/CloseEvent.h>)
#    include <LibWeb/URL/CloseEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/HTML/CloseEvent.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/CloseEvent.h>

#if __has_include(<LibWeb/Bindings/CloseEventWrapper.h>)
#   include <LibWeb/Bindings/CloseEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CloseEventWrapperFactory.h>)
#   include <LibWeb/Bindings/CloseEventWrapperFactory.h>
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

CloseEventConstructor::CloseEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CloseEventConstructor::~CloseEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CloseEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CloseEvent");
}

JS::ThrowCompletionOr<JS::Object*> CloseEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "CloseEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "CloseEventInit");

    CloseEventInit event_init_dict {};

    JS::Value code;
    if (arg1.is_nullish()) {
        code = JS::js_undefined();
    } else {
        code = TRY(arg1.as_object().get("code"));
    }

    u16 code_value;

    if (!code.is_undefined())

    code_value = TRY(code.to_u16(global_object));

    else
        code_value = 0;

    event_init_dict.code = code_value;

    JS::Value reason;
    if (arg1.is_nullish()) {
        reason = JS::js_undefined();
    } else {
        reason = TRY(arg1.as_object().get("reason"));
    }

    String reason_value;
    if (!reason.is_undefined()) {
        if (reason.is_null() && false)
            reason_value = String::empty();
        else
            reason_value = TRY(reason.to_string(global_object));
    } else {
        reason_value = "";
    }

    event_init_dict.reason = reason_value;

    JS::Value was_clean;
    if (arg1.is_nullish()) {
        was_clean = JS::js_undefined();
    } else {
        was_clean = TRY(arg1.as_object().get("wasClean"));
    }

    bool was_clean_value;

    if (!was_clean.is_undefined())

    was_clean_value = was_clean.to_boolean();

    else
        was_clean_value = false;

    event_init_dict.was_clean = was_clean_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return HTML::CloseEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void CloseEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CloseEventPrototype>("CloseEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

