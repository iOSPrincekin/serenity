
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/WorkerLocationConstructor.h>
#include <LibWeb/Bindings/WorkerLocationPrototype.h>
#include <LibWeb/Bindings/WorkerLocationWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/WorkerLocation.h>)
#    include <LibWeb/Crypto/WorkerLocation.h>
#elif __has_include(<LibWeb/CSS/WorkerLocation.h>)
#    include <LibWeb/CSS/WorkerLocation.h>
#elif __has_include(<LibWeb/DOM/WorkerLocation.h>)
#    include <LibWeb/DOM/WorkerLocation.h>
#elif __has_include(<LibWeb/Encoding/WorkerLocation.h>)
#    include <LibWeb/Encoding/WorkerLocation.h>
#elif __has_include(<LibWeb/Geometry/WorkerLocation.h>)
#    include <LibWeb/Geometry/WorkerLocation.h>
#elif __has_include(<LibWeb/HTML/WorkerLocation.h>)
#    include <LibWeb/HTML/WorkerLocation.h>
#elif __has_include(<LibWeb/UIEvents/WorkerLocation.h>)
#    include <LibWeb/UIEvents/WorkerLocation.h>
#elif __has_include(<LibWeb/HighResolutionTime/WorkerLocation.h>)
#    include <LibWeb/HighResolutionTime/WorkerLocation.h>
#elif __has_include(<LibWeb/IntersectionObserver/WorkerLocation.h>)
#    include <LibWeb/IntersectionObserver/WorkerLocation.h>
#elif __has_include(<LibWeb/NavigationTiming/WorkerLocation.h>)
#    include <LibWeb/NavigationTiming/WorkerLocation.h>
#elif __has_include(<LibWeb/RequestIdleCallback/WorkerLocation.h>)
#    include <LibWeb/RequestIdleCallback/WorkerLocation.h>
#elif __has_include(<LibWeb/ResizeObserver/WorkerLocation.h>)
#    include <LibWeb/ResizeObserver/WorkerLocation.h>
#elif __has_include(<LibWeb/SVG/WorkerLocation.h>)
#    include <LibWeb/SVG/WorkerLocation.h>
#elif __has_include(<LibWeb/Selection/WorkerLocation.h>)
#    include <LibWeb/Selection/WorkerLocation.h>
#elif __has_include(<LibWeb/WebSockets/WorkerLocation.h>)
#    include <LibWeb/WebSockets/WorkerLocation.h>
#elif __has_include(<LibWeb/XHR/WorkerLocation.h>)
#    include <LibWeb/XHR/WorkerLocation.h>
#elif __has_include(<LibWeb/URL/WorkerLocation.h>)
#    include <LibWeb/URL/WorkerLocation.h>
#endif


#include <LibWeb/HTML/WorkerLocation.h>

#include <LibWeb/HTML/WorkerLocation.h>

#if __has_include(<LibWeb/Bindings/WorkerLocationWrapper.h>)
#   include <LibWeb/Bindings/WorkerLocationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerLocationWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerLocationWrapperFactory.h>
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

WorkerLocationConstructor::WorkerLocationConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

WorkerLocationConstructor::~WorkerLocationConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> WorkerLocationConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "WorkerLocation");
}

JS::ThrowCompletionOr<JS::Object*> WorkerLocationConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "WorkerLocation");

}

void WorkerLocationConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<WorkerLocationPrototype>("WorkerLocation"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

