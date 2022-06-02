
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/KeyboardEventConstructor.h>
#include <LibWeb/Bindings/KeyboardEventPrototype.h>
#include <LibWeb/Bindings/KeyboardEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/KeyboardEvent.h>)
#    include <LibWeb/Crypto/KeyboardEvent.h>
#elif __has_include(<LibWeb/CSS/KeyboardEvent.h>)
#    include <LibWeb/CSS/KeyboardEvent.h>
#elif __has_include(<LibWeb/DOM/KeyboardEvent.h>)
#    include <LibWeb/DOM/KeyboardEvent.h>
#elif __has_include(<LibWeb/Encoding/KeyboardEvent.h>)
#    include <LibWeb/Encoding/KeyboardEvent.h>
#elif __has_include(<LibWeb/Geometry/KeyboardEvent.h>)
#    include <LibWeb/Geometry/KeyboardEvent.h>
#elif __has_include(<LibWeb/HTML/KeyboardEvent.h>)
#    include <LibWeb/HTML/KeyboardEvent.h>
#elif __has_include(<LibWeb/UIEvents/KeyboardEvent.h>)
#    include <LibWeb/UIEvents/KeyboardEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/KeyboardEvent.h>)
#    include <LibWeb/HighResolutionTime/KeyboardEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/KeyboardEvent.h>)
#    include <LibWeb/IntersectionObserver/KeyboardEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/KeyboardEvent.h>)
#    include <LibWeb/NavigationTiming/KeyboardEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/KeyboardEvent.h>)
#    include <LibWeb/RequestIdleCallback/KeyboardEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/KeyboardEvent.h>)
#    include <LibWeb/ResizeObserver/KeyboardEvent.h>
#elif __has_include(<LibWeb/SVG/KeyboardEvent.h>)
#    include <LibWeb/SVG/KeyboardEvent.h>
#elif __has_include(<LibWeb/Selection/KeyboardEvent.h>)
#    include <LibWeb/Selection/KeyboardEvent.h>
#elif __has_include(<LibWeb/WebSockets/KeyboardEvent.h>)
#    include <LibWeb/WebSockets/KeyboardEvent.h>
#elif __has_include(<LibWeb/XHR/KeyboardEvent.h>)
#    include <LibWeb/XHR/KeyboardEvent.h>
#elif __has_include(<LibWeb/URL/KeyboardEvent.h>)
#    include <LibWeb/URL/KeyboardEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/UIEvents/UIEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/UIEvents/KeyboardEvent.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/UIEvents/KeyboardEvent.h>

#if __has_include(<LibWeb/Bindings/KeyboardEventWrapper.h>)
#   include <LibWeb/Bindings/KeyboardEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/KeyboardEventWrapperFactory.h>)
#   include <LibWeb/Bindings/KeyboardEventWrapperFactory.h>
#endif

#include <LibWeb/UIEvents/UIEvent.h>

#if __has_include(<LibWeb/Bindings/UIEventWrapper.h>)
#   include <LibWeb/Bindings/UIEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/UIEventWrapperFactory.h>)
#   include <LibWeb/Bindings/UIEventWrapperFactory.h>
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

KeyboardEventConstructor::KeyboardEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

KeyboardEventConstructor::~KeyboardEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> KeyboardEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "KeyboardEvent");
}

JS::ThrowCompletionOr<JS::Object*> KeyboardEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "KeyboardEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "KeyboardEventInit");

    KeyboardEventInit event_init_dict {};

    JS::Value char_code;
    if (arg1.is_nullish()) {
        char_code = JS::js_undefined();
    } else {
        char_code = TRY(arg1.as_object().get("charCode"));
    }

    u32 char_code_value;

    if (!char_code.is_undefined())

    char_code_value = TRY(char_code.to_u32(global_object));

    else
        char_code_value = 0UL;

    event_init_dict.char_code = char_code_value;

    JS::Value code;
    if (arg1.is_nullish()) {
        code = JS::js_undefined();
    } else {
        code = TRY(arg1.as_object().get("code"));
    }

    String code_value;
    if (!code.is_undefined()) {
        if (code.is_null() && false)
            code_value = String::empty();
        else
            code_value = TRY(code.to_string(global_object));
    } else {
        code_value = "";
    }

    event_init_dict.code = code_value;

    JS::Value is_composing;
    if (arg1.is_nullish()) {
        is_composing = JS::js_undefined();
    } else {
        is_composing = TRY(arg1.as_object().get("isComposing"));
    }

    bool is_composing_value;

    if (!is_composing.is_undefined())

    is_composing_value = is_composing.to_boolean();

    else
        is_composing_value = false;

    event_init_dict.is_composing = is_composing_value;

    JS::Value key;
    if (arg1.is_nullish()) {
        key = JS::js_undefined();
    } else {
        key = TRY(arg1.as_object().get("key"));
    }

    String key_value;
    if (!key.is_undefined()) {
        if (key.is_null() && false)
            key_value = String::empty();
        else
            key_value = TRY(key.to_string(global_object));
    } else {
        key_value = "";
    }

    event_init_dict.key = key_value;

    JS::Value key_code;
    if (arg1.is_nullish()) {
        key_code = JS::js_undefined();
    } else {
        key_code = TRY(arg1.as_object().get("keyCode"));
    }

    u32 key_code_value;

    if (!key_code.is_undefined())

    key_code_value = TRY(key_code.to_u32(global_object));

    else
        key_code_value = 0UL;

    event_init_dict.key_code = key_code_value;

    JS::Value location;
    if (arg1.is_nullish()) {
        location = JS::js_undefined();
    } else {
        location = TRY(arg1.as_object().get("location"));
    }

    u32 location_value;

    if (!location.is_undefined())

    location_value = TRY(location.to_u32(global_object));

    else
        location_value = 0UL;

    event_init_dict.location = location_value;

    JS::Value repeat;
    if (arg1.is_nullish()) {
        repeat = JS::js_undefined();
    } else {
        repeat = TRY(arg1.as_object().get("repeat"));
    }

    bool repeat_value;

    if (!repeat.is_undefined())

    repeat_value = repeat.to_boolean();

    else
        repeat_value = false;

    event_init_dict.repeat = repeat_value;

    JS::Value alt_key;
    if (arg1.is_nullish()) {
        alt_key = JS::js_undefined();
    } else {
        alt_key = TRY(arg1.as_object().get("altKey"));
    }

    bool alt_key_value;

    if (!alt_key.is_undefined())

    alt_key_value = alt_key.to_boolean();

    else
        alt_key_value = false;

    event_init_dict.alt_key = alt_key_value;

    JS::Value ctrl_key;
    if (arg1.is_nullish()) {
        ctrl_key = JS::js_undefined();
    } else {
        ctrl_key = TRY(arg1.as_object().get("ctrlKey"));
    }

    bool ctrl_key_value;

    if (!ctrl_key.is_undefined())

    ctrl_key_value = ctrl_key.to_boolean();

    else
        ctrl_key_value = false;

    event_init_dict.ctrl_key = ctrl_key_value;

    JS::Value meta_key;
    if (arg1.is_nullish()) {
        meta_key = JS::js_undefined();
    } else {
        meta_key = TRY(arg1.as_object().get("metaKey"));
    }

    bool meta_key_value;

    if (!meta_key.is_undefined())

    meta_key_value = meta_key.to_boolean();

    else
        meta_key_value = false;

    event_init_dict.meta_key = meta_key_value;

    JS::Value shift_key;
    if (arg1.is_nullish()) {
        shift_key = JS::js_undefined();
    } else {
        shift_key = TRY(arg1.as_object().get("shiftKey"));
    }

    bool shift_key_value;

    if (!shift_key.is_undefined())

    shift_key_value = shift_key.to_boolean();

    else
        shift_key_value = false;

    event_init_dict.shift_key = shift_key_value;

    JS::Value detail;
    if (arg1.is_nullish()) {
        detail = JS::js_undefined();
    } else {
        detail = TRY(arg1.as_object().get("detail"));
    }

    i32 detail_value;

    if (!detail.is_undefined())

    detail_value = TRY(detail.to_i32(global_object));

    else
        detail_value = 0L;

    event_init_dict.detail = detail_value;

    JS::Value view;
    if (arg1.is_nullish()) {
        view = JS::js_undefined();
    } else {
        view = TRY(arg1.as_object().get("view"));
    }

    Window* view_value = nullptr;
    if (!view.is_nullish()) {
        if (!view.is_object() || !is<WindowObject>(view.as_object()))
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Window");

        view_value = &static_cast<WindowObject&>(view.as_object()).impl();
    }

    event_init_dict.view = view_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return UIEvents::KeyboardEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void KeyboardEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<KeyboardEventPrototype>("KeyboardEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


define_direct_property("DOM_KEY_LOCATION_STANDARD", JS::Value((i32)0x00), JS::Attribute::Enumerable);

define_direct_property("DOM_KEY_LOCATION_LEFT", JS::Value((i32)0x01), JS::Attribute::Enumerable);

define_direct_property("DOM_KEY_LOCATION_RIGHT", JS::Value((i32)0x02), JS::Attribute::Enumerable);

define_direct_property("DOM_KEY_LOCATION_NUMPAD", JS::Value((i32)0x03), JS::Attribute::Enumerable);

}

} // namespace Web::Bindings

