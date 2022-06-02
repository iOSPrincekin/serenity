
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/MediaQueryListPrototype.h>
#include <LibWeb/Bindings/MediaQueryListWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/CSS/MediaQueryList.h>

#if __has_include(<LibWeb/Bindings/MediaQueryListWrapper.h>)
#   include <LibWeb/Bindings/MediaQueryListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MediaQueryListWrapperFactory.h>)
#   include <LibWeb/Bindings/MediaQueryListWrapperFactory.h>
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

MediaQueryListWrapper* MediaQueryListWrapper::create(JS::GlobalObject& global_object, CSS::MediaQueryList& impl)
{
    return global_object.heap().allocate<MediaQueryListWrapper>(global_object, global_object, impl);
}


MediaQueryListWrapper::MediaQueryListWrapper(JS::GlobalObject& global_object, CSS::MediaQueryList& impl)
    : EventTargetWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<MediaQueryListPrototype>("MediaQueryList"));
}

void MediaQueryListWrapper::initialize(JS::GlobalObject& global_object)
{
    EventTargetWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "MediaQueryList"), JS::Attribute::Configurable);
}

MediaQueryListWrapper::~MediaQueryListWrapper()
{
}

MediaQueryListWrapper* wrap(JS::GlobalObject& global_object, CSS::MediaQueryList& impl)
{
    return static_cast<MediaQueryListWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

