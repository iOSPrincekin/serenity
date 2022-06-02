
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/MessagePortConstructor.h>
#include <LibWeb/Bindings/MessagePortPrototype.h>
#include <LibWeb/Bindings/MessagePortWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/MessagePort.h>)
#    include <LibWeb/Crypto/MessagePort.h>
#elif __has_include(<LibWeb/CSS/MessagePort.h>)
#    include <LibWeb/CSS/MessagePort.h>
#elif __has_include(<LibWeb/DOM/MessagePort.h>)
#    include <LibWeb/DOM/MessagePort.h>
#elif __has_include(<LibWeb/Encoding/MessagePort.h>)
#    include <LibWeb/Encoding/MessagePort.h>
#elif __has_include(<LibWeb/Geometry/MessagePort.h>)
#    include <LibWeb/Geometry/MessagePort.h>
#elif __has_include(<LibWeb/HTML/MessagePort.h>)
#    include <LibWeb/HTML/MessagePort.h>
#elif __has_include(<LibWeb/UIEvents/MessagePort.h>)
#    include <LibWeb/UIEvents/MessagePort.h>
#elif __has_include(<LibWeb/HighResolutionTime/MessagePort.h>)
#    include <LibWeb/HighResolutionTime/MessagePort.h>
#elif __has_include(<LibWeb/IntersectionObserver/MessagePort.h>)
#    include <LibWeb/IntersectionObserver/MessagePort.h>
#elif __has_include(<LibWeb/NavigationTiming/MessagePort.h>)
#    include <LibWeb/NavigationTiming/MessagePort.h>
#elif __has_include(<LibWeb/RequestIdleCallback/MessagePort.h>)
#    include <LibWeb/RequestIdleCallback/MessagePort.h>
#elif __has_include(<LibWeb/ResizeObserver/MessagePort.h>)
#    include <LibWeb/ResizeObserver/MessagePort.h>
#elif __has_include(<LibWeb/SVG/MessagePort.h>)
#    include <LibWeb/SVG/MessagePort.h>
#elif __has_include(<LibWeb/Selection/MessagePort.h>)
#    include <LibWeb/Selection/MessagePort.h>
#elif __has_include(<LibWeb/WebSockets/MessagePort.h>)
#    include <LibWeb/WebSockets/MessagePort.h>
#elif __has_include(<LibWeb/XHR/MessagePort.h>)
#    include <LibWeb/XHR/MessagePort.h>
#elif __has_include(<LibWeb/URL/MessagePort.h>)
#    include <LibWeb/URL/MessagePort.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/MessagePort.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/MessagePort.h>

#if __has_include(<LibWeb/Bindings/MessagePortWrapper.h>)
#   include <LibWeb/Bindings/MessagePortWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MessagePortWrapperFactory.h>)
#   include <LibWeb/Bindings/MessagePortWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
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

MessagePortConstructor::MessagePortConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

MessagePortConstructor::~MessagePortConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> MessagePortConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "MessagePort");
}

JS::ThrowCompletionOr<JS::Object*> MessagePortConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "MessagePort");

}

void MessagePortConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<MessagePortPrototype>("MessagePort"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

