
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLVideoElementPrototype.h>
#include <LibWeb/Bindings/HTMLVideoElementWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/HTML/HTMLVideoElement.h>

#if __has_include(<LibWeb/Bindings/HTMLVideoElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLVideoElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLVideoElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLVideoElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLMediaElement.h>

#if __has_include(<LibWeb/Bindings/HTMLMediaElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMediaElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMediaElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMediaElementWrapperFactory.h>
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

HTMLVideoElementWrapper* HTMLVideoElementWrapper::create(JS::GlobalObject& global_object, HTML::HTMLVideoElement& impl)
{
    return global_object.heap().allocate<HTMLVideoElementWrapper>(global_object, global_object, impl);
}


HTMLVideoElementWrapper::HTMLVideoElementWrapper(JS::GlobalObject& global_object, HTML::HTMLVideoElement& impl)
    : HTMLMediaElementWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLVideoElementPrototype>("HTMLVideoElement"));
}

void HTMLVideoElementWrapper::initialize(JS::GlobalObject& global_object)
{
    HTMLMediaElementWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "HTMLVideoElement"), JS::Attribute::Configurable);
}

HTMLVideoElementWrapper::~HTMLVideoElementWrapper()
{
}

} // namespace Web::Bindings

