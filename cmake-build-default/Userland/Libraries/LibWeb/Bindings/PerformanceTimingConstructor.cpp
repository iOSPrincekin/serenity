
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/PerformanceTimingConstructor.h>
#include <LibWeb/Bindings/PerformanceTimingPrototype.h>
#include <LibWeb/Bindings/PerformanceTimingWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/PerformanceTiming.h>)
#    include <LibWeb/Crypto/PerformanceTiming.h>
#elif __has_include(<LibWeb/CSS/PerformanceTiming.h>)
#    include <LibWeb/CSS/PerformanceTiming.h>
#elif __has_include(<LibWeb/DOM/PerformanceTiming.h>)
#    include <LibWeb/DOM/PerformanceTiming.h>
#elif __has_include(<LibWeb/Encoding/PerformanceTiming.h>)
#    include <LibWeb/Encoding/PerformanceTiming.h>
#elif __has_include(<LibWeb/Geometry/PerformanceTiming.h>)
#    include <LibWeb/Geometry/PerformanceTiming.h>
#elif __has_include(<LibWeb/HTML/PerformanceTiming.h>)
#    include <LibWeb/HTML/PerformanceTiming.h>
#elif __has_include(<LibWeb/UIEvents/PerformanceTiming.h>)
#    include <LibWeb/UIEvents/PerformanceTiming.h>
#elif __has_include(<LibWeb/HighResolutionTime/PerformanceTiming.h>)
#    include <LibWeb/HighResolutionTime/PerformanceTiming.h>
#elif __has_include(<LibWeb/IntersectionObserver/PerformanceTiming.h>)
#    include <LibWeb/IntersectionObserver/PerformanceTiming.h>
#elif __has_include(<LibWeb/NavigationTiming/PerformanceTiming.h>)
#    include <LibWeb/NavigationTiming/PerformanceTiming.h>
#elif __has_include(<LibWeb/RequestIdleCallback/PerformanceTiming.h>)
#    include <LibWeb/RequestIdleCallback/PerformanceTiming.h>
#elif __has_include(<LibWeb/ResizeObserver/PerformanceTiming.h>)
#    include <LibWeb/ResizeObserver/PerformanceTiming.h>
#elif __has_include(<LibWeb/SVG/PerformanceTiming.h>)
#    include <LibWeb/SVG/PerformanceTiming.h>
#elif __has_include(<LibWeb/Selection/PerformanceTiming.h>)
#    include <LibWeb/Selection/PerformanceTiming.h>
#elif __has_include(<LibWeb/WebSockets/PerformanceTiming.h>)
#    include <LibWeb/WebSockets/PerformanceTiming.h>
#elif __has_include(<LibWeb/XHR/PerformanceTiming.h>)
#    include <LibWeb/XHR/PerformanceTiming.h>
#elif __has_include(<LibWeb/URL/PerformanceTiming.h>)
#    include <LibWeb/URL/PerformanceTiming.h>
#endif


#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapper.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapperFactory.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapperFactory.h>
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

PerformanceTimingConstructor::PerformanceTimingConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

PerformanceTimingConstructor::~PerformanceTimingConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> PerformanceTimingConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "PerformanceTiming");
}

JS::ThrowCompletionOr<JS::Object*> PerformanceTimingConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "PerformanceTiming");

}

void PerformanceTimingConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<PerformanceTimingPrototype>("PerformanceTiming"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

