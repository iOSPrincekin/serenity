
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/MouseEventPrototype.h>
#include <LibWeb/Bindings/MouseEventWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/UIEvents/MouseEvent.h>

#if __has_include(<LibWeb/Bindings/MouseEventWrapper.h>)
#   include <LibWeb/Bindings/MouseEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MouseEventWrapperFactory.h>)
#   include <LibWeb/Bindings/MouseEventWrapperFactory.h>
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

MouseEventWrapper* MouseEventWrapper::create(JS::GlobalObject& global_object, UIEvents::MouseEvent& impl)
{
    return global_object.heap().allocate<MouseEventWrapper>(global_object, global_object, impl);
}


MouseEventWrapper::MouseEventWrapper(JS::GlobalObject& global_object, UIEvents::MouseEvent& impl)
    : UIEventWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<MouseEventPrototype>("MouseEvent"));
}

void MouseEventWrapper::initialize(JS::GlobalObject& global_object)
{
    UIEventWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "MouseEvent"), JS::Attribute::Configurable);
}

MouseEventWrapper::~MouseEventWrapper()
{
}

MouseEventWrapper* wrap(JS::GlobalObject& global_object, UIEvents::MouseEvent& impl)
{
    return static_cast<MouseEventWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

