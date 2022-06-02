
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/IdleDeadlinePrototype.h>
#include <LibWeb/Bindings/IdleDeadlineWrapper.h>
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


#include <LibWeb/RequestIdleCallback/IdleDeadline.h>

#include <LibWeb/RequestIdleCallback/IdleDeadline.h>

#if __has_include(<LibWeb/Bindings/IdleDeadlineWrapper.h>)
#   include <LibWeb/Bindings/IdleDeadlineWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/IdleDeadlineWrapperFactory.h>)
#   include <LibWeb/Bindings/IdleDeadlineWrapperFactory.h>
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

IdleDeadlinePrototype::IdleDeadlinePrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

IdleDeadlinePrototype::~IdleDeadlinePrototype()
{
}

void IdleDeadlinePrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("didTimeout", did_timeout_getter, nullptr, default_attributes);

    define_native_function("timeRemaining", time_remaining, 0, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<RequestIdleCallback::IdleDeadline*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<IdleDeadlineWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "RequestIdleCallback::IdleDeadline");

    return &static_cast<IdleDeadlineWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(IdleDeadlinePrototype::did_timeout_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->did_timeout(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(IdleDeadlinePrototype::time_remaining)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->time_remaining(); }));

    return JS::Value(retval);

}

} // namespace Web::Bindings

