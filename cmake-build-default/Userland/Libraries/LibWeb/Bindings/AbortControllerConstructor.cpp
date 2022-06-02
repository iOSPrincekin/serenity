
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/AbortControllerConstructor.h>
#include <LibWeb/Bindings/AbortControllerPrototype.h>
#include <LibWeb/Bindings/AbortControllerWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/AbortController.h>)
#    include <LibWeb/Crypto/AbortController.h>
#elif __has_include(<LibWeb/CSS/AbortController.h>)
#    include <LibWeb/CSS/AbortController.h>
#elif __has_include(<LibWeb/DOM/AbortController.h>)
#    include <LibWeb/DOM/AbortController.h>
#elif __has_include(<LibWeb/Encoding/AbortController.h>)
#    include <LibWeb/Encoding/AbortController.h>
#elif __has_include(<LibWeb/Geometry/AbortController.h>)
#    include <LibWeb/Geometry/AbortController.h>
#elif __has_include(<LibWeb/HTML/AbortController.h>)
#    include <LibWeb/HTML/AbortController.h>
#elif __has_include(<LibWeb/UIEvents/AbortController.h>)
#    include <LibWeb/UIEvents/AbortController.h>
#elif __has_include(<LibWeb/HighResolutionTime/AbortController.h>)
#    include <LibWeb/HighResolutionTime/AbortController.h>
#elif __has_include(<LibWeb/IntersectionObserver/AbortController.h>)
#    include <LibWeb/IntersectionObserver/AbortController.h>
#elif __has_include(<LibWeb/NavigationTiming/AbortController.h>)
#    include <LibWeb/NavigationTiming/AbortController.h>
#elif __has_include(<LibWeb/RequestIdleCallback/AbortController.h>)
#    include <LibWeb/RequestIdleCallback/AbortController.h>
#elif __has_include(<LibWeb/ResizeObserver/AbortController.h>)
#    include <LibWeb/ResizeObserver/AbortController.h>
#elif __has_include(<LibWeb/SVG/AbortController.h>)
#    include <LibWeb/SVG/AbortController.h>
#elif __has_include(<LibWeb/Selection/AbortController.h>)
#    include <LibWeb/Selection/AbortController.h>
#elif __has_include(<LibWeb/WebSockets/AbortController.h>)
#    include <LibWeb/WebSockets/AbortController.h>
#elif __has_include(<LibWeb/XHR/AbortController.h>)
#    include <LibWeb/XHR/AbortController.h>
#elif __has_include(<LibWeb/URL/AbortController.h>)
#    include <LibWeb/URL/AbortController.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/AbortController.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/AbortController.h>

#if __has_include(<LibWeb/Bindings/AbortControllerWrapper.h>)
#   include <LibWeb/Bindings/AbortControllerWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortControllerWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortControllerWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
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

AbortControllerConstructor::AbortControllerConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

AbortControllerConstructor::~AbortControllerConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> AbortControllerConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "AbortController");
}

JS::ThrowCompletionOr<JS::Object*> AbortControllerConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return DOM::AbortController::create_with_global_object(window); }));

    return wrap(global_object, *impl);

}

void AbortControllerConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<AbortControllerPrototype>("AbortController"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

