
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLSpanElementPrototype.h>
#include <LibWeb/Bindings/HTMLSpanElementWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/HTML/HTMLSpanElement.h>

#if __has_include(<LibWeb/Bindings/HTMLSpanElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLSpanElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLSpanElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLSpanElementWrapperFactory.h>
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

HTMLSpanElementWrapper* HTMLSpanElementWrapper::create(JS::GlobalObject& global_object, HTML::HTMLSpanElement& impl)
{
    return global_object.heap().allocate<HTMLSpanElementWrapper>(global_object, global_object, impl);
}


HTMLSpanElementWrapper::HTMLSpanElementWrapper(JS::GlobalObject& global_object, HTML::HTMLSpanElement& impl)
    : HTMLElementWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLSpanElementPrototype>("HTMLSpanElement"));
}

void HTMLSpanElementWrapper::initialize(JS::GlobalObject& global_object)
{
    HTMLElementWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "HTMLSpanElement"), JS::Attribute::Configurable);
}

HTMLSpanElementWrapper::~HTMLSpanElementWrapper()
{
}

} // namespace Web::Bindings

