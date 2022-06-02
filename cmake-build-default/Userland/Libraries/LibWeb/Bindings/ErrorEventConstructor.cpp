
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/ErrorEventConstructor.h>
#include <LibWeb/Bindings/ErrorEventPrototype.h>
#include <LibWeb/Bindings/ErrorEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/ErrorEvent.h>)
#    include <LibWeb/Crypto/ErrorEvent.h>
#elif __has_include(<LibWeb/CSS/ErrorEvent.h>)
#    include <LibWeb/CSS/ErrorEvent.h>
#elif __has_include(<LibWeb/DOM/ErrorEvent.h>)
#    include <LibWeb/DOM/ErrorEvent.h>
#elif __has_include(<LibWeb/Encoding/ErrorEvent.h>)
#    include <LibWeb/Encoding/ErrorEvent.h>
#elif __has_include(<LibWeb/Geometry/ErrorEvent.h>)
#    include <LibWeb/Geometry/ErrorEvent.h>
#elif __has_include(<LibWeb/HTML/ErrorEvent.h>)
#    include <LibWeb/HTML/ErrorEvent.h>
#elif __has_include(<LibWeb/UIEvents/ErrorEvent.h>)
#    include <LibWeb/UIEvents/ErrorEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/ErrorEvent.h>)
#    include <LibWeb/HighResolutionTime/ErrorEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/ErrorEvent.h>)
#    include <LibWeb/IntersectionObserver/ErrorEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/ErrorEvent.h>)
#    include <LibWeb/NavigationTiming/ErrorEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/ErrorEvent.h>)
#    include <LibWeb/RequestIdleCallback/ErrorEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/ErrorEvent.h>)
#    include <LibWeb/ResizeObserver/ErrorEvent.h>
#elif __has_include(<LibWeb/SVG/ErrorEvent.h>)
#    include <LibWeb/SVG/ErrorEvent.h>
#elif __has_include(<LibWeb/Selection/ErrorEvent.h>)
#    include <LibWeb/Selection/ErrorEvent.h>
#elif __has_include(<LibWeb/WebSockets/ErrorEvent.h>)
#    include <LibWeb/WebSockets/ErrorEvent.h>
#elif __has_include(<LibWeb/XHR/ErrorEvent.h>)
#    include <LibWeb/XHR/ErrorEvent.h>
#elif __has_include(<LibWeb/URL/ErrorEvent.h>)
#    include <LibWeb/URL/ErrorEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/ErrorEvent.h>

#include <LibWeb/HTML/ErrorEvent.h>

#if __has_include(<LibWeb/Bindings/ErrorEventWrapper.h>)
#   include <LibWeb/Bindings/ErrorEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ErrorEventWrapperFactory.h>)
#   include <LibWeb/Bindings/ErrorEventWrapperFactory.h>
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

ErrorEventConstructor::ErrorEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

ErrorEventConstructor::~ErrorEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> ErrorEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "ErrorEvent");
}

JS::ThrowCompletionOr<JS::Object*> ErrorEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "ErrorEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "ErrorEventInit");

    ErrorEventInit event_init_dict {};

    JS::Value colno;
    if (arg1.is_nullish()) {
        colno = JS::js_undefined();
    } else {
        colno = TRY(arg1.as_object().get("colno"));
    }

    u32 colno_value;

    if (!colno.is_undefined())

    colno_value = TRY(colno.to_u32(global_object));

    else
        colno_value = 0UL;

    event_init_dict.colno = colno_value;

    JS::Value error;
    if (arg1.is_nullish()) {
        error = JS::js_undefined();
    } else {
        error = TRY(arg1.as_object().get("error"));
    }

    JS::Value error_value = JS::js_undefined();
    if (!error.is_undefined())
        error_value = error;

    else
        error_value = JS::js_null();

    event_init_dict.error = error_value;

    JS::Value filename;
    if (arg1.is_nullish()) {
        filename = JS::js_undefined();
    } else {
        filename = TRY(arg1.as_object().get("filename"));
    }

    String filename_value;
    if (!filename.is_undefined()) {
        if (filename.is_null() && false)
            filename_value = String::empty();
        else
            filename_value = TRY(filename.to_string(global_object));
    } else {
        filename_value = "";
    }

    event_init_dict.filename = filename_value;

    JS::Value lineno;
    if (arg1.is_nullish()) {
        lineno = JS::js_undefined();
    } else {
        lineno = TRY(arg1.as_object().get("lineno"));
    }

    u32 lineno_value;

    if (!lineno.is_undefined())

    lineno_value = TRY(lineno.to_u32(global_object));

    else
        lineno_value = 0UL;

    event_init_dict.lineno = lineno_value;

    JS::Value message;
    if (arg1.is_nullish()) {
        message = JS::js_undefined();
    } else {
        message = TRY(arg1.as_object().get("message"));
    }

    String message_value;
    if (!message.is_undefined()) {
        if (message.is_null() && false)
            message_value = String::empty();
        else
            message_value = TRY(message.to_string(global_object));
    } else {
        message_value = "";
    }

    event_init_dict.message = message_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return HTML::ErrorEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void ErrorEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<ErrorEventPrototype>("ErrorEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

