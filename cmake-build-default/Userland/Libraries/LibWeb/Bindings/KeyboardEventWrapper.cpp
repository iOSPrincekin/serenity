
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/KeyboardEventPrototype.h>
#include <LibWeb/Bindings/KeyboardEventWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

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

namespace Web::Bindings {

KeyboardEventWrapper* KeyboardEventWrapper::create(JS::GlobalObject& global_object, UIEvents::KeyboardEvent& impl)
{
    return global_object.heap().allocate<KeyboardEventWrapper>(global_object, global_object, impl);
}


KeyboardEventWrapper::KeyboardEventWrapper(JS::GlobalObject& global_object, UIEvents::KeyboardEvent& impl)
    : UIEventWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<KeyboardEventPrototype>("KeyboardEvent"));
}

void KeyboardEventWrapper::initialize(JS::GlobalObject& global_object)
{
    UIEventWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "KeyboardEvent"), JS::Attribute::Configurable);
}

KeyboardEventWrapper::~KeyboardEventWrapper()
{
}

KeyboardEventWrapper* wrap(JS::GlobalObject& global_object, UIEvents::KeyboardEvent& impl)
{
    return static_cast<KeyboardEventWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

