
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/AbortSignalConstructor.h>
#include <LibWeb/Bindings/AbortSignalPrototype.h>
#include <LibWeb/Bindings/AbortSignalWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/AbortSignal.h>)
#    include <LibWeb/Crypto/AbortSignal.h>
#elif __has_include(<LibWeb/CSS/AbortSignal.h>)
#    include <LibWeb/CSS/AbortSignal.h>
#elif __has_include(<LibWeb/DOM/AbortSignal.h>)
#    include <LibWeb/DOM/AbortSignal.h>
#elif __has_include(<LibWeb/Encoding/AbortSignal.h>)
#    include <LibWeb/Encoding/AbortSignal.h>
#elif __has_include(<LibWeb/Geometry/AbortSignal.h>)
#    include <LibWeb/Geometry/AbortSignal.h>
#elif __has_include(<LibWeb/HTML/AbortSignal.h>)
#    include <LibWeb/HTML/AbortSignal.h>
#elif __has_include(<LibWeb/UIEvents/AbortSignal.h>)
#    include <LibWeb/UIEvents/AbortSignal.h>
#elif __has_include(<LibWeb/HighResolutionTime/AbortSignal.h>)
#    include <LibWeb/HighResolutionTime/AbortSignal.h>
#elif __has_include(<LibWeb/IntersectionObserver/AbortSignal.h>)
#    include <LibWeb/IntersectionObserver/AbortSignal.h>
#elif __has_include(<LibWeb/NavigationTiming/AbortSignal.h>)
#    include <LibWeb/NavigationTiming/AbortSignal.h>
#elif __has_include(<LibWeb/RequestIdleCallback/AbortSignal.h>)
#    include <LibWeb/RequestIdleCallback/AbortSignal.h>
#elif __has_include(<LibWeb/ResizeObserver/AbortSignal.h>)
#    include <LibWeb/ResizeObserver/AbortSignal.h>
#elif __has_include(<LibWeb/SVG/AbortSignal.h>)
#    include <LibWeb/SVG/AbortSignal.h>
#elif __has_include(<LibWeb/Selection/AbortSignal.h>)
#    include <LibWeb/Selection/AbortSignal.h>
#elif __has_include(<LibWeb/WebSockets/AbortSignal.h>)
#    include <LibWeb/WebSockets/AbortSignal.h>
#elif __has_include(<LibWeb/XHR/AbortSignal.h>)
#    include <LibWeb/XHR/AbortSignal.h>
#elif __has_include(<LibWeb/URL/AbortSignal.h>)
#    include <LibWeb/URL/AbortSignal.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

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

AbortSignalConstructor::AbortSignalConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

AbortSignalConstructor::~AbortSignalConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> AbortSignalConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "AbortSignal");
}

JS::ThrowCompletionOr<JS::Object*> AbortSignalConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "AbortSignal");

}

void AbortSignalConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<AbortSignalPrototype>("AbortSignal"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

