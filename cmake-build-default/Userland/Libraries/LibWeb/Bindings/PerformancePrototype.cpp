
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/PerformancePrototype.h>
#include <LibWeb/Bindings/PerformanceWrapper.h>
#include <LibWeb/Bindings/EventWrapper.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/LocationObject.h>
#include <LibWeb/Bindings/WindowObject.h>
#include <LibWeb/Bindings/WorkerLocationWrapper.h>
#include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#include <LibWeb/Bindings/WorkerWrapper.h>
#include <LibWeb/DOM/Element.h>
#include <LibWeb/DOM/Event.h>
#include <LibWeb/DOM/IDLEventListener.h>
#include <LibWeb/DOM/NodeFilter.h>
#include <LibWeb/DOM/Range.h>
#include <LibWeb/HTML/Scripting/Environments.h>
#include <LibWeb/HTML/Window.h>
#include <LibWeb/Origin.h>

#if __has_include(<LibWeb/Bindings/EventTargetPrototype.h>)
#    include <LibWeb/Bindings/EventTargetPrototype.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HighResolutionTime/Performance.h>

#include <LibWeb/HighResolutionTime/Performance.h>

#if __has_include(<LibWeb/Bindings/PerformanceWrapper.h>)
#   include <LibWeb/Bindings/PerformanceWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/PerformanceWrapperFactory.h>)
#   include <LibWeb/Bindings/PerformanceWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapper.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapperFactory.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
#endif


// FIXME: This is a total hack until we can figure out the namespace for a given type somehow.
using namespace Web::Crypto;
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::NavigationTiming;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;
using namespace Web::SVG;
using namespace Web::URL;
using namespace Web::WebSockets;
using namespace Web::XHR;

namespace Web::Bindings {

PerformancePrototype::PerformancePrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<EventTargetPrototype>("EventTarget"))

{
}

PerformancePrototype::~PerformancePrototype()
{
}

void PerformancePrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("timeOrigin", time_origin_getter, nullptr, default_attributes);

    define_native_accessor("timing", timing_getter, nullptr, default_attributes);

    define_native_function("now", now, 0, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HighResolutionTime::Performance*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<PerformanceWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HighResolutionTime::Performance");

    return &static_cast<PerformanceWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(PerformancePrototype::time_origin_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->time_origin(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformancePrototype::timing_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->timing(); }));

    return wrap(global_object, const_cast<PerformanceTiming&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(PerformancePrototype::now)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->now(); }));

    return JS::Value(retval);

}

} // namespace Web::Bindings

