
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/SVGDefsElementConstructor.h>
#include <LibWeb/Bindings/SVGDefsElementPrototype.h>
#include <LibWeb/Bindings/SVGDefsElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/SVGDefsElement.h>)
#    include <LibWeb/Crypto/SVGDefsElement.h>
#elif __has_include(<LibWeb/CSS/SVGDefsElement.h>)
#    include <LibWeb/CSS/SVGDefsElement.h>
#elif __has_include(<LibWeb/DOM/SVGDefsElement.h>)
#    include <LibWeb/DOM/SVGDefsElement.h>
#elif __has_include(<LibWeb/Encoding/SVGDefsElement.h>)
#    include <LibWeb/Encoding/SVGDefsElement.h>
#elif __has_include(<LibWeb/Geometry/SVGDefsElement.h>)
#    include <LibWeb/Geometry/SVGDefsElement.h>
#elif __has_include(<LibWeb/HTML/SVGDefsElement.h>)
#    include <LibWeb/HTML/SVGDefsElement.h>
#elif __has_include(<LibWeb/UIEvents/SVGDefsElement.h>)
#    include <LibWeb/UIEvents/SVGDefsElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/SVGDefsElement.h>)
#    include <LibWeb/HighResolutionTime/SVGDefsElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/SVGDefsElement.h>)
#    include <LibWeb/IntersectionObserver/SVGDefsElement.h>
#elif __has_include(<LibWeb/NavigationTiming/SVGDefsElement.h>)
#    include <LibWeb/NavigationTiming/SVGDefsElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/SVGDefsElement.h>)
#    include <LibWeb/RequestIdleCallback/SVGDefsElement.h>
#elif __has_include(<LibWeb/ResizeObserver/SVGDefsElement.h>)
#    include <LibWeb/ResizeObserver/SVGDefsElement.h>
#elif __has_include(<LibWeb/SVG/SVGDefsElement.h>)
#    include <LibWeb/SVG/SVGDefsElement.h>
#elif __has_include(<LibWeb/Selection/SVGDefsElement.h>)
#    include <LibWeb/Selection/SVGDefsElement.h>
#elif __has_include(<LibWeb/WebSockets/SVGDefsElement.h>)
#    include <LibWeb/WebSockets/SVGDefsElement.h>
#elif __has_include(<LibWeb/XHR/SVGDefsElement.h>)
#    include <LibWeb/XHR/SVGDefsElement.h>
#elif __has_include(<LibWeb/URL/SVGDefsElement.h>)
#    include <LibWeb/URL/SVGDefsElement.h>
#endif


#include <LibWeb/SVG/SVGDefsElement.h>

#include <LibWeb/SVG/SVGDefsElement.h>

#if __has_include(<LibWeb/Bindings/SVGDefsElementWrapper.h>)
#   include <LibWeb/Bindings/SVGDefsElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGDefsElementWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGDefsElementWrapperFactory.h>
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

SVGDefsElementConstructor::SVGDefsElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

SVGDefsElementConstructor::~SVGDefsElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> SVGDefsElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "SVGDefsElement");
}

JS::ThrowCompletionOr<JS::Object*> SVGDefsElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "SVGDefsElement");

}

void SVGDefsElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<SVGDefsElementPrototype>("SVGDefsElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

