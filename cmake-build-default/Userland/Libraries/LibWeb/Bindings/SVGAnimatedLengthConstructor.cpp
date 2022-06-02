
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/SVGAnimatedLengthConstructor.h>
#include <LibWeb/Bindings/SVGAnimatedLengthPrototype.h>
#include <LibWeb/Bindings/SVGAnimatedLengthWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/SVGAnimatedLength.h>)
#    include <LibWeb/Crypto/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/CSS/SVGAnimatedLength.h>)
#    include <LibWeb/CSS/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/DOM/SVGAnimatedLength.h>)
#    include <LibWeb/DOM/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/Encoding/SVGAnimatedLength.h>)
#    include <LibWeb/Encoding/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/Geometry/SVGAnimatedLength.h>)
#    include <LibWeb/Geometry/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/HTML/SVGAnimatedLength.h>)
#    include <LibWeb/HTML/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/UIEvents/SVGAnimatedLength.h>)
#    include <LibWeb/UIEvents/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/HighResolutionTime/SVGAnimatedLength.h>)
#    include <LibWeb/HighResolutionTime/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/IntersectionObserver/SVGAnimatedLength.h>)
#    include <LibWeb/IntersectionObserver/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/NavigationTiming/SVGAnimatedLength.h>)
#    include <LibWeb/NavigationTiming/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/RequestIdleCallback/SVGAnimatedLength.h>)
#    include <LibWeb/RequestIdleCallback/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/ResizeObserver/SVGAnimatedLength.h>)
#    include <LibWeb/ResizeObserver/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/SVG/SVGAnimatedLength.h>)
#    include <LibWeb/SVG/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/Selection/SVGAnimatedLength.h>)
#    include <LibWeb/Selection/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/WebSockets/SVGAnimatedLength.h>)
#    include <LibWeb/WebSockets/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/XHR/SVGAnimatedLength.h>)
#    include <LibWeb/XHR/SVGAnimatedLength.h>
#elif __has_include(<LibWeb/URL/SVGAnimatedLength.h>)
#    include <LibWeb/URL/SVGAnimatedLength.h>
#endif


#include <LibWeb/SVG/SVGLength.h>

#include <LibWeb/SVG/SVGAnimatedLength.h>

#include <LibWeb/SVG/SVGAnimatedLength.h>

#if __has_include(<LibWeb/Bindings/SVGAnimatedLengthWrapper.h>)
#   include <LibWeb/Bindings/SVGAnimatedLengthWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGAnimatedLengthWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGAnimatedLengthWrapperFactory.h>
#endif

#include <LibWeb/SVG/SVGLength.h>

#if __has_include(<LibWeb/Bindings/SVGLengthWrapper.h>)
#   include <LibWeb/Bindings/SVGLengthWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGLengthWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGLengthWrapperFactory.h>
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

SVGAnimatedLengthConstructor::SVGAnimatedLengthConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

SVGAnimatedLengthConstructor::~SVGAnimatedLengthConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> SVGAnimatedLengthConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "SVGAnimatedLength");
}

JS::ThrowCompletionOr<JS::Object*> SVGAnimatedLengthConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "SVGAnimatedLength");

}

void SVGAnimatedLengthConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<SVGAnimatedLengthPrototype>("SVGAnimatedLength"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

