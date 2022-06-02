
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HTMLCanvasElementPrototype.h>
#include <LibWeb/Bindings/HTMLCanvasElementWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

#include <LibWeb/HTML/HTMLCanvasElement.h>

#if __has_include(<LibWeb/Bindings/HTMLCanvasElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLCanvasElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLCanvasElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLCanvasElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/CanvasRenderingContext2D.h>

#if __has_include(<LibWeb/Bindings/CanvasRenderingContext2DWrapper.h>)
#   include <LibWeb/Bindings/CanvasRenderingContext2DWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CanvasRenderingContext2DWrapperFactory.h>)
#   include <LibWeb/Bindings/CanvasRenderingContext2DWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLImageElement.h>

#if __has_include(<LibWeb/Bindings/HTMLImageElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLImageElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLImageElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLImageElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/ImageData.h>

#if __has_include(<LibWeb/Bindings/ImageDataWrapper.h>)
#   include <LibWeb/Bindings/ImageDataWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ImageDataWrapperFactory.h>)
#   include <LibWeb/Bindings/ImageDataWrapperFactory.h>
#endif

#include <LibWeb/HTML/TextMetrics.h>

#if __has_include(<LibWeb/Bindings/TextMetricsWrapper.h>)
#   include <LibWeb/Bindings/TextMetricsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TextMetricsWrapperFactory.h>)
#   include <LibWeb/Bindings/TextMetricsWrapperFactory.h>
#endif

#include <LibWeb/HTML/CanvasGradient.h>

#if __has_include(<LibWeb/Bindings/CanvasGradientWrapper.h>)
#   include <LibWeb/Bindings/CanvasGradientWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CanvasGradientWrapperFactory.h>)
#   include <LibWeb/Bindings/CanvasGradientWrapperFactory.h>
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

HTMLCanvasElementWrapper* HTMLCanvasElementWrapper::create(JS::GlobalObject& global_object, HTML::HTMLCanvasElement& impl)
{
    return global_object.heap().allocate<HTMLCanvasElementWrapper>(global_object, global_object, impl);
}


HTMLCanvasElementWrapper::HTMLCanvasElementWrapper(JS::GlobalObject& global_object, HTML::HTMLCanvasElement& impl)
    : HTMLElementWrapper(global_object, impl)
{
    set_prototype(&static_cast<WindowObject&>(global_object).ensure_web_prototype<HTMLCanvasElementPrototype>("HTMLCanvasElement"));
}

void HTMLCanvasElementWrapper::initialize(JS::GlobalObject& global_object)
{
    HTMLElementWrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "HTMLCanvasElement"), JS::Attribute::Configurable);
}

HTMLCanvasElementWrapper::~HTMLCanvasElementWrapper()
{
}

} // namespace Web::Bindings

