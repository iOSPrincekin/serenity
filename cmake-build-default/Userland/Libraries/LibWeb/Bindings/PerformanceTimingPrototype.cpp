
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/PerformanceTimingPrototype.h>
#include <LibWeb/Bindings/PerformanceTimingWrapper.h>
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

#if __has_include(<LibWeb/Bindings/ObjectPrototype.h>)
#    include <LibWeb/Bindings/ObjectPrototype.h>
#endif


#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapper.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapperFactory.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapperFactory.h>
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

PerformanceTimingPrototype::PerformanceTimingPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

PerformanceTimingPrototype::~PerformanceTimingPrototype()
{
}

void PerformanceTimingPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("navigationStart", navigation_start_getter, nullptr, default_attributes);

    define_native_accessor("unloadEventStart", unload_event_start_getter, nullptr, default_attributes);

    define_native_accessor("unloadEventEnd", unload_event_end_getter, nullptr, default_attributes);

    define_native_accessor("redirectStart", redirect_start_getter, nullptr, default_attributes);

    define_native_accessor("redirectEnd", redirect_end_getter, nullptr, default_attributes);

    define_native_accessor("fetchStart", fetch_start_getter, nullptr, default_attributes);

    define_native_accessor("domainLookupStart", domain_lookup_start_getter, nullptr, default_attributes);

    define_native_accessor("domainLookupEnd", domain_lookup_end_getter, nullptr, default_attributes);

    define_native_accessor("connectStart", connect_start_getter, nullptr, default_attributes);

    define_native_accessor("connectEnd", connect_end_getter, nullptr, default_attributes);

    define_native_accessor("secureConnectionStart", secure_connection_start_getter, nullptr, default_attributes);

    define_native_accessor("requestStart", request_start_getter, nullptr, default_attributes);

    define_native_accessor("responseStart", response_start_getter, nullptr, default_attributes);

    define_native_accessor("responseEnd", response_end_getter, nullptr, default_attributes);

    define_native_accessor("domLoading", dom_loading_getter, nullptr, default_attributes);

    define_native_accessor("domInteractive", dom_interactive_getter, nullptr, default_attributes);

    define_native_accessor("domContentLoadedEventStart", dom_content_loaded_event_start_getter, nullptr, default_attributes);

    define_native_accessor("domContentLoadedEventEnd", dom_content_loaded_event_end_getter, nullptr, default_attributes);

    define_native_accessor("domComplete", dom_complete_getter, nullptr, default_attributes);

    define_native_accessor("loadEventStart", load_event_start_getter, nullptr, default_attributes);

    define_native_accessor("loadEventEnd", load_event_end_getter, nullptr, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<NavigationTiming::PerformanceTiming*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<PerformanceTimingWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "NavigationTiming::PerformanceTiming");

    return &static_cast<PerformanceTimingWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::navigation_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->navigation_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::unload_event_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->unload_event_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::unload_event_end_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->unload_event_end(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::redirect_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->redirect_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::redirect_end_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->redirect_end(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::fetch_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->fetch_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::domain_lookup_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->domain_lookup_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::domain_lookup_end_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->domain_lookup_end(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::connect_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->connect_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::connect_end_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->connect_end(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::secure_connection_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->secure_connection_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::request_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->request_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::response_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->response_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::response_end_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->response_end(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::dom_loading_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->dom_loading(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::dom_interactive_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->dom_interactive(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::dom_content_loaded_event_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->dom_content_loaded_event_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::dom_content_loaded_event_end_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->dom_content_loaded_event_end(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::dom_complete_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->dom_complete(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::load_event_start_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->load_event_start(); }));

    return JS::Value((u32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(PerformanceTimingPrototype::load_event_end_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->load_event_end(); }));

    return JS::Value((u32)retval);

}

} // namespace Web::Bindings

