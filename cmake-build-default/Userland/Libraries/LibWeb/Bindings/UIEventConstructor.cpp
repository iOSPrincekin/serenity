
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/UIEventConstructor.h>
#include <LibWeb/Bindings/UIEventPrototype.h>
#include <LibWeb/Bindings/UIEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/UIEvent.h>)
#    include <LibWeb/Crypto/UIEvent.h>
#elif __has_include(<LibWeb/CSS/UIEvent.h>)
#    include <LibWeb/CSS/UIEvent.h>
#elif __has_include(<LibWeb/DOM/UIEvent.h>)
#    include <LibWeb/DOM/UIEvent.h>
#elif __has_include(<LibWeb/Encoding/UIEvent.h>)
#    include <LibWeb/Encoding/UIEvent.h>
#elif __has_include(<LibWeb/Geometry/UIEvent.h>)
#    include <LibWeb/Geometry/UIEvent.h>
#elif __has_include(<LibWeb/HTML/UIEvent.h>)
#    include <LibWeb/HTML/UIEvent.h>
#elif __has_include(<LibWeb/UIEvents/UIEvent.h>)
#    include <LibWeb/UIEvents/UIEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/UIEvent.h>)
#    include <LibWeb/HighResolutionTime/UIEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/UIEvent.h>)
#    include <LibWeb/IntersectionObserver/UIEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/UIEvent.h>)
#    include <LibWeb/NavigationTiming/UIEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/UIEvent.h>)
#    include <LibWeb/RequestIdleCallback/UIEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/UIEvent.h>)
#    include <LibWeb/ResizeObserver/UIEvent.h>
#elif __has_include(<LibWeb/SVG/UIEvent.h>)
#    include <LibWeb/SVG/UIEvent.h>
#elif __has_include(<LibWeb/Selection/UIEvent.h>)
#    include <LibWeb/Selection/UIEvent.h>
#elif __has_include(<LibWeb/WebSockets/UIEvent.h>)
#    include <LibWeb/WebSockets/UIEvent.h>
#elif __has_include(<LibWeb/XHR/UIEvent.h>)
#    include <LibWeb/XHR/UIEvent.h>
#elif __has_include(<LibWeb/URL/UIEvent.h>)
#    include <LibWeb/URL/UIEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/UIEvents/UIEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

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

UIEventConstructor::UIEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

UIEventConstructor::~UIEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> UIEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "UIEvent");
}

JS::ThrowCompletionOr<JS::Object*> UIEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "UIEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "UIEventInit");

    UIEventInit event_init_dict {};

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return UIEvents::UIEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void UIEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<UIEventPrototype>("UIEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

