
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLPictureElementPrototype.h>
#include <LibWeb/Bindings/HTMLPictureElementWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/HTML/HTMLPictureElement.h>

#if __has_include(<LibWeb/Bindings/HTMLPictureElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLPictureElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLPictureElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLPictureElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
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

HTMLPictureElementWrapper* HTMLPictureElementWrapper::create(JS::GlobalObject& global_object, HTML::HTMLPictureElement& impl)
{
    return global_object.heap().allocate<HTMLPictureElementWrapper>(global_object, global_object, impl);
}


HTMLPictureElementWrapper::HTMLPictureElementWrapper(JS::GlobalObject& global_object, HTML::HTMLPictureElement& impl)
    : HTMLElementWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLPictureElementPrototype>("HTMLPictureElement"));
}

void HTMLPictureElementWrapper::initialize(JS::GlobalObject& global_object)
{
    HTMLElementWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "HTMLPictureElement"), JS::Attribute::Configurable);
}

HTMLPictureElementWrapper::~HTMLPictureElementWrapper()
{
}

} // namespace Web::Bindings

