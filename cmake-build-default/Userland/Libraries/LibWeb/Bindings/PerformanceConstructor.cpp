
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/PerformanceConstructor.h>
#include <LibWeb/Bindings/PerformancePrototype.h>
#include <LibWeb/Bindings/PerformanceWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/Performance.h>)
#    include <LibWeb/Crypto/Performance.h>
#elif __has_include(<LibWeb/CSS/Performance.h>)
#    include <LibWeb/CSS/Performance.h>
#elif __has_include(<LibWeb/DOM/Performance.h>)
#    include <LibWeb/DOM/Performance.h>
#elif __has_include(<LibWeb/Encoding/Performance.h>)
#    include <LibWeb/Encoding/Performance.h>
#elif __has_include(<LibWeb/Geometry/Performance.h>)
#    include <LibWeb/Geometry/Performance.h>
#elif __has_include(<LibWeb/HTML/Performance.h>)
#    include <LibWeb/HTML/Performance.h>
#elif __has_include(<LibWeb/UIEvents/Performance.h>)
#    include <LibWeb/UIEvents/Performance.h>
#elif __has_include(<LibWeb/HighResolutionTime/Performance.h>)
#    include <LibWeb/HighResolutionTime/Performance.h>
#elif __has_include(<LibWeb/IntersectionObserver/Performance.h>)
#    include <LibWeb/IntersectionObserver/Performance.h>
#elif __has_include(<LibWeb/NavigationTiming/Performance.h>)
#    include <LibWeb/NavigationTiming/Performance.h>
#elif __has_include(<LibWeb/RequestIdleCallback/Performance.h>)
#    include <LibWeb/RequestIdleCallback/Performance.h>
#elif __has_include(<LibWeb/ResizeObserver/Performance.h>)
#    include <LibWeb/ResizeObserver/Performance.h>
#elif __has_include(<LibWeb/SVG/Performance.h>)
#    include <LibWeb/SVG/Performance.h>
#elif __has_include(<LibWeb/Selection/Performance.h>)
#    include <LibWeb/Selection/Performance.h>
#elif __has_include(<LibWeb/WebSockets/Performance.h>)
#    include <LibWeb/WebSockets/Performance.h>
#elif __has_include(<LibWeb/XHR/Performance.h>)
#    include <LibWeb/XHR/Performance.h>
#elif __has_include(<LibWeb/URL/Performance.h>)
#    include <LibWeb/URL/Performance.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HighResolutionTime/Performance.h>

#include <LibWeb/HighResolutionTime/Performance.h>

#if __has_include(<LibWeb/Bindings/PerformanceWrapper.h>)
#   include <LibWeb/Bindings/PerformanceWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/PerformanceWrapperFactory.h>)
#   include <LibWeb/Bindings/PerformanceWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapper.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/PerformanceTimingWrapperFactory.h>)
#   include <LibWeb/Bindings/PerformanceTimingWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
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

PerformanceConstructor::PerformanceConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

PerformanceConstructor::~PerformanceConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> PerformanceConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "Performance");
}

JS::ThrowCompletionOr<JS::Object*> PerformanceConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "Performance");

}

void PerformanceConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<PerformancePrototype>("Performance"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

