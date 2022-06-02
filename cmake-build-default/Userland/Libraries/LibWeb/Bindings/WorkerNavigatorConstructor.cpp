
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/WorkerNavigatorConstructor.h>
#include <LibWeb/Bindings/WorkerNavigatorPrototype.h>
#include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/WorkerNavigator.h>)
#    include <LibWeb/Crypto/WorkerNavigator.h>
#elif __has_include(<LibWeb/CSS/WorkerNavigator.h>)
#    include <LibWeb/CSS/WorkerNavigator.h>
#elif __has_include(<LibWeb/DOM/WorkerNavigator.h>)
#    include <LibWeb/DOM/WorkerNavigator.h>
#elif __has_include(<LibWeb/Encoding/WorkerNavigator.h>)
#    include <LibWeb/Encoding/WorkerNavigator.h>
#elif __has_include(<LibWeb/Geometry/WorkerNavigator.h>)
#    include <LibWeb/Geometry/WorkerNavigator.h>
#elif __has_include(<LibWeb/HTML/WorkerNavigator.h>)
#    include <LibWeb/HTML/WorkerNavigator.h>
#elif __has_include(<LibWeb/UIEvents/WorkerNavigator.h>)
#    include <LibWeb/UIEvents/WorkerNavigator.h>
#elif __has_include(<LibWeb/HighResolutionTime/WorkerNavigator.h>)
#    include <LibWeb/HighResolutionTime/WorkerNavigator.h>
#elif __has_include(<LibWeb/IntersectionObserver/WorkerNavigator.h>)
#    include <LibWeb/IntersectionObserver/WorkerNavigator.h>
#elif __has_include(<LibWeb/NavigationTiming/WorkerNavigator.h>)
#    include <LibWeb/NavigationTiming/WorkerNavigator.h>
#elif __has_include(<LibWeb/RequestIdleCallback/WorkerNavigator.h>)
#    include <LibWeb/RequestIdleCallback/WorkerNavigator.h>
#elif __has_include(<LibWeb/ResizeObserver/WorkerNavigator.h>)
#    include <LibWeb/ResizeObserver/WorkerNavigator.h>
#elif __has_include(<LibWeb/SVG/WorkerNavigator.h>)
#    include <LibWeb/SVG/WorkerNavigator.h>
#elif __has_include(<LibWeb/Selection/WorkerNavigator.h>)
#    include <LibWeb/Selection/WorkerNavigator.h>
#elif __has_include(<LibWeb/WebSockets/WorkerNavigator.h>)
#    include <LibWeb/WebSockets/WorkerNavigator.h>
#elif __has_include(<LibWeb/XHR/WorkerNavigator.h>)
#    include <LibWeb/XHR/WorkerNavigator.h>
#elif __has_include(<LibWeb/URL/WorkerNavigator.h>)
#    include <LibWeb/URL/WorkerNavigator.h>
#endif


#include <LibWeb/HTML/WorkerNavigator.h>

#include <LibWeb/HTML/WorkerNavigator.h>

#if __has_include(<LibWeb/Bindings/WorkerNavigatorWrapper.h>)
#   include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/WorkerNavigatorWrapperFactory.h>)
#   include <LibWeb/Bindings/WorkerNavigatorWrapperFactory.h>
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

WorkerNavigatorConstructor::WorkerNavigatorConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

WorkerNavigatorConstructor::~WorkerNavigatorConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> WorkerNavigatorConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "WorkerNavigator");
}

JS::ThrowCompletionOr<JS::Object*> WorkerNavigatorConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "WorkerNavigator");

}

void WorkerNavigatorConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<WorkerNavigatorPrototype>("WorkerNavigator"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

