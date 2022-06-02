
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/MessageChannelConstructor.h>
#include <LibWeb/Bindings/MessageChannelPrototype.h>
#include <LibWeb/Bindings/MessageChannelWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/MessageChannel.h>)
#    include <LibWeb/Crypto/MessageChannel.h>
#elif __has_include(<LibWeb/CSS/MessageChannel.h>)
#    include <LibWeb/CSS/MessageChannel.h>
#elif __has_include(<LibWeb/DOM/MessageChannel.h>)
#    include <LibWeb/DOM/MessageChannel.h>
#elif __has_include(<LibWeb/Encoding/MessageChannel.h>)
#    include <LibWeb/Encoding/MessageChannel.h>
#elif __has_include(<LibWeb/Geometry/MessageChannel.h>)
#    include <LibWeb/Geometry/MessageChannel.h>
#elif __has_include(<LibWeb/HTML/MessageChannel.h>)
#    include <LibWeb/HTML/MessageChannel.h>
#elif __has_include(<LibWeb/UIEvents/MessageChannel.h>)
#    include <LibWeb/UIEvents/MessageChannel.h>
#elif __has_include(<LibWeb/HighResolutionTime/MessageChannel.h>)
#    include <LibWeb/HighResolutionTime/MessageChannel.h>
#elif __has_include(<LibWeb/IntersectionObserver/MessageChannel.h>)
#    include <LibWeb/IntersectionObserver/MessageChannel.h>
#elif __has_include(<LibWeb/NavigationTiming/MessageChannel.h>)
#    include <LibWeb/NavigationTiming/MessageChannel.h>
#elif __has_include(<LibWeb/RequestIdleCallback/MessageChannel.h>)
#    include <LibWeb/RequestIdleCallback/MessageChannel.h>
#elif __has_include(<LibWeb/ResizeObserver/MessageChannel.h>)
#    include <LibWeb/ResizeObserver/MessageChannel.h>
#elif __has_include(<LibWeb/SVG/MessageChannel.h>)
#    include <LibWeb/SVG/MessageChannel.h>
#elif __has_include(<LibWeb/Selection/MessageChannel.h>)
#    include <LibWeb/Selection/MessageChannel.h>
#elif __has_include(<LibWeb/WebSockets/MessageChannel.h>)
#    include <LibWeb/WebSockets/MessageChannel.h>
#elif __has_include(<LibWeb/XHR/MessageChannel.h>)
#    include <LibWeb/XHR/MessageChannel.h>
#elif __has_include(<LibWeb/URL/MessageChannel.h>)
#    include <LibWeb/URL/MessageChannel.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/MessagePort.h>

#include <LibWeb/HTML/MessageChannel.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/MessageChannel.h>

#if __has_include(<LibWeb/Bindings/MessageChannelWrapper.h>)
#   include <LibWeb/Bindings/MessageChannelWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MessageChannelWrapperFactory.h>)
#   include <LibWeb/Bindings/MessageChannelWrapperFactory.h>
#endif

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

MessageChannelConstructor::MessageChannelConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

MessageChannelConstructor::~MessageChannelConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> MessageChannelConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "MessageChannel");
}

JS::ThrowCompletionOr<JS::Object*> MessageChannelConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return HTML::MessageChannel::create_with_global_object(window); }));

    return wrap(global_object, *impl);

}

void MessageChannelConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<MessageChannelPrototype>("MessageChannel"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

