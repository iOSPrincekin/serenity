
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/SVGClipPathElementPrototype.h>
#include <LibWeb/Bindings/SVGClipPathElementWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/SVG/SVGClipPathElement.h>

#if __has_include(<LibWeb/Bindings/SVGClipPathElementWrapper.h>)
#   include <LibWeb/Bindings/SVGClipPathElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGClipPathElementWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGClipPathElementWrapperFactory.h>
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

SVGClipPathElementWrapper* SVGClipPathElementWrapper::create(JS::GlobalObject& global_object, SVG::SVGClipPathElement& impl)
{
    return global_object.heap().allocate<SVGClipPathElementWrapper>(global_object, global_object, impl);
}


SVGClipPathElementWrapper::SVGClipPathElementWrapper(JS::GlobalObject& global_object, SVG::SVGClipPathElement& impl)
    : SVGElementWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<SVGClipPathElementPrototype>("SVGClipPathElement"));
}

void SVGClipPathElementWrapper::initialize(JS::GlobalObject& global_object)
{
    SVGElementWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "SVGClipPathElement"), JS::Attribute::Configurable);
}

SVGClipPathElementWrapper::~SVGClipPathElementWrapper()
{
}

} // namespace Web::Bindings

