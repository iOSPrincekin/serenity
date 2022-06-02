
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/SVGClipPathElementConstructor.h>
#include <LibWeb/Bindings/SVGClipPathElementPrototype.h>
#include <LibWeb/Bindings/SVGClipPathElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/SVGClipPathElement.h>)
#    include <LibWeb/Crypto/SVGClipPathElement.h>
#elif __has_include(<LibWeb/CSS/SVGClipPathElement.h>)
#    include <LibWeb/CSS/SVGClipPathElement.h>
#elif __has_include(<LibWeb/DOM/SVGClipPathElement.h>)
#    include <LibWeb/DOM/SVGClipPathElement.h>
#elif __has_include(<LibWeb/Encoding/SVGClipPathElement.h>)
#    include <LibWeb/Encoding/SVGClipPathElement.h>
#elif __has_include(<LibWeb/Geometry/SVGClipPathElement.h>)
#    include <LibWeb/Geometry/SVGClipPathElement.h>
#elif __has_include(<LibWeb/HTML/SVGClipPathElement.h>)
#    include <LibWeb/HTML/SVGClipPathElement.h>
#elif __has_include(<LibWeb/UIEvents/SVGClipPathElement.h>)
#    include <LibWeb/UIEvents/SVGClipPathElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/SVGClipPathElement.h>)
#    include <LibWeb/HighResolutionTime/SVGClipPathElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/SVGClipPathElement.h>)
#    include <LibWeb/IntersectionObserver/SVGClipPathElement.h>
#elif __has_include(<LibWeb/NavigationTiming/SVGClipPathElement.h>)
#    include <LibWeb/NavigationTiming/SVGClipPathElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/SVGClipPathElement.h>)
#    include <LibWeb/RequestIdleCallback/SVGClipPathElement.h>
#elif __has_include(<LibWeb/ResizeObserver/SVGClipPathElement.h>)
#    include <LibWeb/ResizeObserver/SVGClipPathElement.h>
#elif __has_include(<LibWeb/SVG/SVGClipPathElement.h>)
#    include <LibWeb/SVG/SVGClipPathElement.h>
#elif __has_include(<LibWeb/Selection/SVGClipPathElement.h>)
#    include <LibWeb/Selection/SVGClipPathElement.h>
#elif __has_include(<LibWeb/WebSockets/SVGClipPathElement.h>)
#    include <LibWeb/WebSockets/SVGClipPathElement.h>
#elif __has_include(<LibWeb/XHR/SVGClipPathElement.h>)
#    include <LibWeb/XHR/SVGClipPathElement.h>
#elif __has_include(<LibWeb/URL/SVGClipPathElement.h>)
#    include <LibWeb/URL/SVGClipPathElement.h>
#endif


#include <LibWeb/SVG/SVGClipPathElement.h>

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
using namespace Web::UIEvents;
using namespace Web::XHR;

namespace Web::Bindings {

SVGClipPathElementConstructor::SVGClipPathElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

SVGClipPathElementConstructor::~SVGClipPathElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> SVGClipPathElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "SVGClipPathElement");
}

JS::ThrowCompletionOr<JS::Object*> SVGClipPathElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "SVGClipPathElement");

}

void SVGClipPathElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<SVGClipPathElementPrototype>("SVGClipPathElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

