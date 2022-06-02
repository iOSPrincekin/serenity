
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CloseEventPrototype.h>
#include <LibWeb/Bindings/CloseEventWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

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

namespace Web::Bindings {

CloseEventWrapper* CloseEventWrapper::create(JS::GlobalObject& global_object, HTML::CloseEvent& impl)
{
    return global_object.heap().allocate<CloseEventWrapper>(global_object, global_object, impl);
}


CloseEventWrapper::CloseEventWrapper(JS::GlobalObject& global_object, HTML::CloseEvent& impl)
    : EventWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<CloseEventPrototype>("CloseEvent"));
}

void CloseEventWrapper::initialize(JS::GlobalObject& global_object)
{
    EventWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "CloseEvent"), JS::Attribute::Configurable);
}

CloseEventWrapper::~CloseEventWrapper()
{
}

CloseEventWrapper* wrap(JS::GlobalObject& global_object, HTML::CloseEvent& impl)
{
    return static_cast<CloseEventWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

