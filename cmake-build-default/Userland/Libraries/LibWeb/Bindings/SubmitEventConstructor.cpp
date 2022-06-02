
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/SubmitEventConstructor.h>
#include <LibWeb/Bindings/SubmitEventPrototype.h>
#include <LibWeb/Bindings/SubmitEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/SubmitEvent.h>)
#    include <LibWeb/Crypto/SubmitEvent.h>
#elif __has_include(<LibWeb/CSS/SubmitEvent.h>)
#    include <LibWeb/CSS/SubmitEvent.h>
#elif __has_include(<LibWeb/DOM/SubmitEvent.h>)
#    include <LibWeb/DOM/SubmitEvent.h>
#elif __has_include(<LibWeb/Encoding/SubmitEvent.h>)
#    include <LibWeb/Encoding/SubmitEvent.h>
#elif __has_include(<LibWeb/Geometry/SubmitEvent.h>)
#    include <LibWeb/Geometry/SubmitEvent.h>
#elif __has_include(<LibWeb/HTML/SubmitEvent.h>)
#    include <LibWeb/HTML/SubmitEvent.h>
#elif __has_include(<LibWeb/UIEvents/SubmitEvent.h>)
#    include <LibWeb/UIEvents/SubmitEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/SubmitEvent.h>)
#    include <LibWeb/HighResolutionTime/SubmitEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/SubmitEvent.h>)
#    include <LibWeb/IntersectionObserver/SubmitEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/SubmitEvent.h>)
#    include <LibWeb/NavigationTiming/SubmitEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/SubmitEvent.h>)
#    include <LibWeb/RequestIdleCallback/SubmitEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/SubmitEvent.h>)
#    include <LibWeb/ResizeObserver/SubmitEvent.h>
#elif __has_include(<LibWeb/SVG/SubmitEvent.h>)
#    include <LibWeb/SVG/SubmitEvent.h>
#elif __has_include(<LibWeb/Selection/SubmitEvent.h>)
#    include <LibWeb/Selection/SubmitEvent.h>
#elif __has_include(<LibWeb/WebSockets/SubmitEvent.h>)
#    include <LibWeb/WebSockets/SubmitEvent.h>
#elif __has_include(<LibWeb/XHR/SubmitEvent.h>)
#    include <LibWeb/XHR/SubmitEvent.h>
#elif __has_include(<LibWeb/URL/SubmitEvent.h>)
#    include <LibWeb/URL/SubmitEvent.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/SubmitEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/SubmitEvent.h>

#if __has_include(<LibWeb/Bindings/SubmitEventWrapper.h>)
#   include <LibWeb/Bindings/SubmitEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SubmitEventWrapperFactory.h>)
#   include <LibWeb/Bindings/SubmitEventWrapperFactory.h>
#endif

#include <LibWeb/DOM/Event.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
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

SubmitEventConstructor::SubmitEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

SubmitEventConstructor::~SubmitEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> SubmitEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "SubmitEvent");
}

JS::ThrowCompletionOr<JS::Object*> SubmitEventConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "SubmitEvent");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "SubmitEventInit");

    SubmitEventInit event_init_dict {};

    JS::Value submitter;
    if (arg1.is_nullish()) {
        submitter = JS::js_undefined();
    } else {
        submitter = TRY(arg1.as_object().get("submitter"));
    }

    HTMLElement* submitter_value = nullptr;
    if (!submitter.is_nullish()) {
        if (!submitter.is_object() || !is<HTMLElementWrapper>(submitter.as_object()))
            return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTMLElement");

        submitter_value = &static_cast<HTMLElementWrapper&>(submitter.as_object()).impl();
    }

    event_init_dict.submitter = submitter_value;

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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return HTML::SubmitEvent::create_with_global_object(window, type, event_init_dict); }));

    return wrap(global_object, *impl);

}

void SubmitEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<SubmitEventPrototype>("SubmitEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

