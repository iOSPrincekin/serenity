
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/WorkerConstructor.h>
#include <LibWeb/Bindings/WorkerPrototype.h>
#include <LibWeb/Bindings/WorkerWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/Worker.h>)
#    include <LibWeb/Crypto/Worker.h>
#elif __has_include(<LibWeb/CSS/Worker.h>)
#    include <LibWeb/CSS/Worker.h>
#elif __has_include(<LibWeb/DOM/Worker.h>)
#    include <LibWeb/DOM/Worker.h>
#elif __has_include(<LibWeb/Encoding/Worker.h>)
#    include <LibWeb/Encoding/Worker.h>
#elif __has_include(<LibWeb/Geometry/Worker.h>)
#    include <LibWeb/Geometry/Worker.h>
#elif __has_include(<LibWeb/HTML/Worker.h>)
#    include <LibWeb/HTML/Worker.h>
#elif __has_include(<LibWeb/UIEvents/Worker.h>)
#    include <LibWeb/UIEvents/Worker.h>
#elif __has_include(<LibWeb/HighResolutionTime/Worker.h>)
#    include <LibWeb/HighResolutionTime/Worker.h>
#elif __has_include(<LibWeb/IntersectionObserver/Worker.h>)
#    include <LibWeb/IntersectionObserver/Worker.h>
#elif __has_include(<LibWeb/NavigationTiming/Worker.h>)
#    include <LibWeb/NavigationTiming/Worker.h>
#elif __has_include(<LibWeb/RequestIdleCallback/Worker.h>)
#    include <LibWeb/RequestIdleCallback/Worker.h>
#elif __has_include(<LibWeb/ResizeObserver/Worker.h>)
#    include <LibWeb/ResizeObserver/Worker.h>
#elif __has_include(<LibWeb/SVG/Worker.h>)
#    include <LibWeb/SVG/Worker.h>
#elif __has_include(<LibWeb/Selection/Worker.h>)
#    include <LibWeb/Selection/Worker.h>
#elif __has_include(<LibWeb/WebSockets/Worker.h>)
#    include <LibWeb/WebSockets/Worker.h>
#elif __has_include(<LibWeb/XHR/Worker.h>)
#    include <LibWeb/XHR/Worker.h>
#elif __has_include(<LibWeb/URL/Worker.h>)
#    include <LibWeb/URL/Worker.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/Worker.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/Worker.h>

#if __has_include(<LibWeb/Bindings/WorkerWrapper.h>)
#   include <LibWeb/Bindings/WorkerWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerWrapperFactory.h>
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

WorkerConstructor::WorkerConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

WorkerConstructor::~WorkerConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> WorkerConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "Worker");
}

JS::ThrowCompletionOr<JS::Object*> WorkerConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "Worker");

    auto arg0 = vm.argument(0);

    String script_url;
    if (arg0.is_null() && false) {
        script_url = String::empty();
    } else {
        script_url = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_nullish() && !arg1.is_object())
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "WorkerOptions");

    WorkerOptions options {};

    JS::Value credentials;
    if (arg1.is_nullish()) {
        credentials = JS::js_undefined();
    } else {
        credentials = TRY(arg1.as_object().get("credentials"));
    }

    String credentials_value;
    if (!credentials.is_undefined()) {
        if (credentials.is_null() && false)
            credentials_value = String::empty();
        else
            credentials_value = TRY(credentials.to_string(global_object));
    } else {
        credentials_value = "same-origin";
    }

    options.credentials = credentials_value;

    JS::Value name;
    if (arg1.is_nullish()) {
        name = JS::js_undefined();
    } else {
        name = TRY(arg1.as_object().get("name"));
    }

    String name_value;
    if (!name.is_undefined()) {
        if (name.is_null() && false)
            name_value = String::empty();
        else
            name_value = TRY(name.to_string(global_object));
    } else {
        name_value = "";
    }

    options.name = name_value;

    JS::Value type;
    if (arg1.is_nullish()) {
        type = JS::js_undefined();
    } else {
        type = TRY(arg1.as_object().get("type"));
    }

    String type_value;
    if (!type.is_undefined()) {
        if (type.is_null() && false)
            type_value = String::empty();
        else
            type_value = TRY(type.to_string(global_object));
    } else {
        type_value = "classic";
    }

    options.type = type_value;

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return HTML::Worker::create_with_global_object(window, script_url, options); }));

    return wrap(global_object, *impl);

}

void WorkerConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<WorkerPrototype>("Worker"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

