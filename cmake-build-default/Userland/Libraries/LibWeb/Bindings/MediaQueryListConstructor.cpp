
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/MediaQueryListConstructor.h>
#include <LibWeb/Bindings/MediaQueryListPrototype.h>
#include <LibWeb/Bindings/MediaQueryListWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/MediaQueryList.h>)
#    include <LibWeb/Crypto/MediaQueryList.h>
#elif __has_include(<LibWeb/CSS/MediaQueryList.h>)
#    include <LibWeb/CSS/MediaQueryList.h>
#elif __has_include(<LibWeb/DOM/MediaQueryList.h>)
#    include <LibWeb/DOM/MediaQueryList.h>
#elif __has_include(<LibWeb/Encoding/MediaQueryList.h>)
#    include <LibWeb/Encoding/MediaQueryList.h>
#elif __has_include(<LibWeb/Geometry/MediaQueryList.h>)
#    include <LibWeb/Geometry/MediaQueryList.h>
#elif __has_include(<LibWeb/HTML/MediaQueryList.h>)
#    include <LibWeb/HTML/MediaQueryList.h>
#elif __has_include(<LibWeb/UIEvents/MediaQueryList.h>)
#    include <LibWeb/UIEvents/MediaQueryList.h>
#elif __has_include(<LibWeb/HighResolutionTime/MediaQueryList.h>)
#    include <LibWeb/HighResolutionTime/MediaQueryList.h>
#elif __has_include(<LibWeb/IntersectionObserver/MediaQueryList.h>)
#    include <LibWeb/IntersectionObserver/MediaQueryList.h>
#elif __has_include(<LibWeb/NavigationTiming/MediaQueryList.h>)
#    include <LibWeb/NavigationTiming/MediaQueryList.h>
#elif __has_include(<LibWeb/RequestIdleCallback/MediaQueryList.h>)
#    include <LibWeb/RequestIdleCallback/MediaQueryList.h>
#elif __has_include(<LibWeb/ResizeObserver/MediaQueryList.h>)
#    include <LibWeb/ResizeObserver/MediaQueryList.h>
#elif __has_include(<LibWeb/SVG/MediaQueryList.h>)
#    include <LibWeb/SVG/MediaQueryList.h>
#elif __has_include(<LibWeb/Selection/MediaQueryList.h>)
#    include <LibWeb/Selection/MediaQueryList.h>
#elif __has_include(<LibWeb/WebSockets/MediaQueryList.h>)
#    include <LibWeb/WebSockets/MediaQueryList.h>
#elif __has_include(<LibWeb/XHR/MediaQueryList.h>)
#    include <LibWeb/XHR/MediaQueryList.h>
#elif __has_include(<LibWeb/URL/MediaQueryList.h>)
#    include <LibWeb/URL/MediaQueryList.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/CSS/MediaQueryList.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/CSS/MediaQueryList.h>

#if __has_include(<LibWeb/Bindings/MediaQueryListWrapper.h>)
#   include <LibWeb/Bindings/MediaQueryListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MediaQueryListWrapperFactory.h>)
#   include <LibWeb/Bindings/MediaQueryListWrapperFactory.h>
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

MediaQueryListConstructor::MediaQueryListConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

MediaQueryListConstructor::~MediaQueryListConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> MediaQueryListConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "MediaQueryList");
}

JS::ThrowCompletionOr<JS::Object*> MediaQueryListConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "MediaQueryList");

}

void MediaQueryListConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<MediaQueryListPrototype>("MediaQueryList"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

