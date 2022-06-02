
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CanvasGradientConstructor.h>
#include <LibWeb/Bindings/CanvasGradientPrototype.h>
#include <LibWeb/Bindings/CanvasGradientWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CanvasGradient.h>)
#    include <LibWeb/Crypto/CanvasGradient.h>
#elif __has_include(<LibWeb/CSS/CanvasGradient.h>)
#    include <LibWeb/CSS/CanvasGradient.h>
#elif __has_include(<LibWeb/DOM/CanvasGradient.h>)
#    include <LibWeb/DOM/CanvasGradient.h>
#elif __has_include(<LibWeb/Encoding/CanvasGradient.h>)
#    include <LibWeb/Encoding/CanvasGradient.h>
#elif __has_include(<LibWeb/Geometry/CanvasGradient.h>)
#    include <LibWeb/Geometry/CanvasGradient.h>
#elif __has_include(<LibWeb/HTML/CanvasGradient.h>)
#    include <LibWeb/HTML/CanvasGradient.h>
#elif __has_include(<LibWeb/UIEvents/CanvasGradient.h>)
#    include <LibWeb/UIEvents/CanvasGradient.h>
#elif __has_include(<LibWeb/HighResolutionTime/CanvasGradient.h>)
#    include <LibWeb/HighResolutionTime/CanvasGradient.h>
#elif __has_include(<LibWeb/IntersectionObserver/CanvasGradient.h>)
#    include <LibWeb/IntersectionObserver/CanvasGradient.h>
#elif __has_include(<LibWeb/NavigationTiming/CanvasGradient.h>)
#    include <LibWeb/NavigationTiming/CanvasGradient.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CanvasGradient.h>)
#    include <LibWeb/RequestIdleCallback/CanvasGradient.h>
#elif __has_include(<LibWeb/ResizeObserver/CanvasGradient.h>)
#    include <LibWeb/ResizeObserver/CanvasGradient.h>
#elif __has_include(<LibWeb/SVG/CanvasGradient.h>)
#    include <LibWeb/SVG/CanvasGradient.h>
#elif __has_include(<LibWeb/Selection/CanvasGradient.h>)
#    include <LibWeb/Selection/CanvasGradient.h>
#elif __has_include(<LibWeb/WebSockets/CanvasGradient.h>)
#    include <LibWeb/WebSockets/CanvasGradient.h>
#elif __has_include(<LibWeb/XHR/CanvasGradient.h>)
#    include <LibWeb/XHR/CanvasGradient.h>
#elif __has_include(<LibWeb/URL/CanvasGradient.h>)
#    include <LibWeb/URL/CanvasGradient.h>
#endif


#include <LibWeb/HTML/CanvasGradient.h>

#include <LibWeb/HTML/CanvasGradient.h>

#if __has_include(<LibWeb/Bindings/CanvasGradientWrapper.h>)
#   include <LibWeb/Bindings/CanvasGradientWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CanvasGradientWrapperFactory.h>)
#   include <LibWeb/Bindings/CanvasGradientWrapperFactory.h>
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

CanvasGradientConstructor::CanvasGradientConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CanvasGradientConstructor::~CanvasGradientConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CanvasGradientConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CanvasGradient");
}

JS::ThrowCompletionOr<JS::Object*> CanvasGradientConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CanvasGradient");

}

void CanvasGradientConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CanvasGradientPrototype>("CanvasGradient"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

