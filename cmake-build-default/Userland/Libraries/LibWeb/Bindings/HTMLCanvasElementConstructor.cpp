
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLCanvasElementConstructor.h>
#include <LibWeb/Bindings/HTMLCanvasElementPrototype.h>
#include <LibWeb/Bindings/HTMLCanvasElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLCanvasElement.h>)
#    include <LibWeb/Crypto/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/CSS/HTMLCanvasElement.h>)
#    include <LibWeb/CSS/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/DOM/HTMLCanvasElement.h>)
#    include <LibWeb/DOM/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLCanvasElement.h>)
#    include <LibWeb/Encoding/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLCanvasElement.h>)
#    include <LibWeb/Geometry/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/HTML/HTMLCanvasElement.h>)
#    include <LibWeb/HTML/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLCanvasElement.h>)
#    include <LibWeb/UIEvents/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLCanvasElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLCanvasElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLCanvasElement.h>)
#    include <LibWeb/NavigationTiming/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLCanvasElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLCanvasElement.h>)
#    include <LibWeb/ResizeObserver/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/SVG/HTMLCanvasElement.h>)
#    include <LibWeb/SVG/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/Selection/HTMLCanvasElement.h>)
#    include <LibWeb/Selection/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLCanvasElement.h>)
#    include <LibWeb/WebSockets/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/XHR/HTMLCanvasElement.h>)
#    include <LibWeb/XHR/HTMLCanvasElement.h>
#elif __has_include(<LibWeb/URL/HTMLCanvasElement.h>)
#    include <LibWeb/URL/HTMLCanvasElement.h>
#endif


#include <LibWeb/HTML/TextMetrics.h>

#include <LibWeb/HTML/CanvasRenderingContext2D.h>

#include <LibWeb/HTML/HTMLCanvasElement.h>

#include <LibWeb/HTML/ImageData.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/CanvasGradient.h>

#include <LibWeb/HTML/HTMLImageElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

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
using namespace Web::UIEvents;
using namespace Web::XHR;

namespace Web::Bindings {

HTMLCanvasElementConstructor::HTMLCanvasElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLCanvasElementConstructor::~HTMLCanvasElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLCanvasElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLCanvasElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLCanvasElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLCanvasElement");

}

void HTMLCanvasElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLCanvasElementPrototype>("HTMLCanvasElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

