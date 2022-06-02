
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/WorkerGlobalScopeConstructor.h>
#include <LibWeb/Bindings/WorkerGlobalScopePrototype.h>
#include <LibWeb/Bindings/WorkerGlobalScopeWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/WorkerGlobalScope.h>)
#    include <LibWeb/Crypto/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/CSS/WorkerGlobalScope.h>)
#    include <LibWeb/CSS/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/DOM/WorkerGlobalScope.h>)
#    include <LibWeb/DOM/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/Encoding/WorkerGlobalScope.h>)
#    include <LibWeb/Encoding/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/Geometry/WorkerGlobalScope.h>)
#    include <LibWeb/Geometry/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/HTML/WorkerGlobalScope.h>)
#    include <LibWeb/HTML/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/UIEvents/WorkerGlobalScope.h>)
#    include <LibWeb/UIEvents/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/HighResolutionTime/WorkerGlobalScope.h>)
#    include <LibWeb/HighResolutionTime/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/IntersectionObserver/WorkerGlobalScope.h>)
#    include <LibWeb/IntersectionObserver/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/NavigationTiming/WorkerGlobalScope.h>)
#    include <LibWeb/NavigationTiming/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/RequestIdleCallback/WorkerGlobalScope.h>)
#    include <LibWeb/RequestIdleCallback/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/ResizeObserver/WorkerGlobalScope.h>)
#    include <LibWeb/ResizeObserver/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/SVG/WorkerGlobalScope.h>)
#    include <LibWeb/SVG/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/Selection/WorkerGlobalScope.h>)
#    include <LibWeb/Selection/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/WebSockets/WorkerGlobalScope.h>)
#    include <LibWeb/WebSockets/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/XHR/WorkerGlobalScope.h>)
#    include <LibWeb/XHR/WorkerGlobalScope.h>
#elif __has_include(<LibWeb/URL/WorkerGlobalScope.h>)
#    include <LibWeb/URL/WorkerGlobalScope.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/WorkerNavigator.h>

#include <LibWeb/HTML/WorkerGlobalScope.h>

#include <LibWeb/HTML/WorkerLocation.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/WorkerGlobalScope.h>

#if __has_include(<LibWeb/Bindings/WorkerGlobalScopeWrapper.h>)
#   include <LibWeb/Bindings/WorkerGlobalScopeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerGlobalScopeWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerGlobalScopeWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/HTML/WorkerLocation.h>

#if __has_include(<LibWeb/Bindings/WorkerLocationWrapper.h>)
#   include <LibWeb/Bindings/WorkerLocationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerLocationWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerLocationWrapperFactory.h>
#endif

#include <LibWeb/HTML/WorkerNavigator.h>

#if __has_include(<LibWeb/Bindings/WorkerNavigatorWrapper.h>)
#   include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerNavigatorWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerNavigatorWrapperFactory.h>
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

WorkerGlobalScopeConstructor::WorkerGlobalScopeConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

WorkerGlobalScopeConstructor::~WorkerGlobalScopeConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> WorkerGlobalScopeConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "WorkerGlobalScope");
}

JS::ThrowCompletionOr<JS::Object*> WorkerGlobalScopeConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "WorkerGlobalScope");

}

void WorkerGlobalScopeConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<WorkerGlobalScopePrototype>("WorkerGlobalScope"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

