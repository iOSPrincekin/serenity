
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/MediaQueryListEventConstructor.h>
#include <LibWeb/Bindings/MediaQueryListEventPrototype.h>
#include <LibWeb/Bindings/MediaQueryListEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/MediaQueryListEvent.h>)
#    include <LibWeb/Crypto/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/CSS/MediaQueryListEvent.h>)
#    include <LibWeb/CSS/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/DOM/MediaQueryListEvent.h>)
#    include <LibWeb/DOM/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/Encoding/MediaQueryListEvent.h>)
#    include <LibWeb/Encoding/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/Geometry/MediaQueryListEvent.h>)
#    include <LibWeb/Geometry/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/HTML/MediaQueryListEvent.h>)
#    include <LibWeb/HTML/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/UIEvents/MediaQueryListEvent.h>)
#    include <LibWeb/UIEvents/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/MediaQueryListEvent.h>)
#    include <LibWeb/HighResolutionTime/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/MediaQueryListEvent.h>)
#    include <LibWeb/IntersectionObserver/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/MediaQueryListEvent.h>)
#    include <LibWeb/NavigationTiming/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/MediaQueryListEvent.h>)
#    include <LibWeb/RequestIdleCallback/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/MediaQueryListEvent.h>)
#    include <LibWeb/ResizeObserver/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/SVG/MediaQueryListEvent.h>)
#    include <LibWeb/SVG/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/Selection/MediaQueryListEvent.h>)
#    include <LibWeb/Selection/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/WebSockets/MediaQueryListEvent.h>)
#    include <LibWeb/WebSockets/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/XHR/MediaQueryListEvent.h>)
#    include <LibWeb/XHR/MediaQueryListEvent.h>
#elif __has_include(<LibWeb/URL/MediaQueryListEvent.h>)
#    include <LibWeb/URL/MediaQueryListEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/CSS/MediaQueryListEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/CSS/MediaQueryListEvent.h>

#if __has_include(<LibWeb/Bindings/MediaQueryListEventWrapper.h>)
#   include <LibWeb/Bindings/MediaQueryListEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MediaQueryListEventWrapperFactory.h>)
#   include <LibWeb/Bindings/MediaQueryListEventWrapperFactory.h>
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

MediaQueryListEventConstructor::MediaQueryListEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

MediaQueryListEventConstructor::~MediaQueryListEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> MediaQueryListEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "MediaQueryListEvent");
}

JS::ThrowCompletionOr<JS::Object*> MediaQueryListEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "MediaQueryListEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "MediaQueryListEventInit");

    MediaQueryListEventInit event_init_dict {};

    JS::Value matches;
    if (arg1.is_nullish()) {
        matches = JS::js_undefined();
    } else {
        matches = TRY(arg1.as_object().get("matches"));
    }

    bool matches_value;

    if (!matches.is_undefined())

    matches_value = matches.to_boolean();

    else
        matches_value = false;

    event_init_dict.matches = matches_value;

    JS::Value media;
    if (arg1.is_nullish()) {
        media = JS::js_undefined();
    } else {
        media = TRY(arg1.as_object().get("media"));
    }

    String media_value;
    if (!media.is_undefined()) {
        if (media.is_null() && false)
            media_value = String::empty();
        else
            media_value = TRY(media.to_string(global_object));
    } else {
        media_value = "";
    }

    event_init_dict.media = media_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return CSS::MediaQueryListEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void MediaQueryListEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<MediaQueryListEventPrototype>("MediaQueryListEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

