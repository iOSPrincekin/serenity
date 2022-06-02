
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/MediaListConstructor.h>
#include <LibWeb/Bindings/MediaListPrototype.h>
#include <LibWeb/Bindings/MediaListWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/MediaList.h>)
#    include <LibWeb/Crypto/MediaList.h>
#elif __has_include(<LibWeb/CSS/MediaList.h>)
#    include <LibWeb/CSS/MediaList.h>
#elif __has_include(<LibWeb/DOM/MediaList.h>)
#    include <LibWeb/DOM/MediaList.h>
#elif __has_include(<LibWeb/Encoding/MediaList.h>)
#    include <LibWeb/Encoding/MediaList.h>
#elif __has_include(<LibWeb/Geometry/MediaList.h>)
#    include <LibWeb/Geometry/MediaList.h>
#elif __has_include(<LibWeb/HTML/MediaList.h>)
#    include <LibWeb/HTML/MediaList.h>
#elif __has_include(<LibWeb/UIEvents/MediaList.h>)
#    include <LibWeb/UIEvents/MediaList.h>
#elif __has_include(<LibWeb/HighResolutionTime/MediaList.h>)
#    include <LibWeb/HighResolutionTime/MediaList.h>
#elif __has_include(<LibWeb/IntersectionObserver/MediaList.h>)
#    include <LibWeb/IntersectionObserver/MediaList.h>
#elif __has_include(<LibWeb/NavigationTiming/MediaList.h>)
#    include <LibWeb/NavigationTiming/MediaList.h>
#elif __has_include(<LibWeb/RequestIdleCallback/MediaList.h>)
#    include <LibWeb/RequestIdleCallback/MediaList.h>
#elif __has_include(<LibWeb/ResizeObserver/MediaList.h>)
#    include <LibWeb/ResizeObserver/MediaList.h>
#elif __has_include(<LibWeb/SVG/MediaList.h>)
#    include <LibWeb/SVG/MediaList.h>
#elif __has_include(<LibWeb/Selection/MediaList.h>)
#    include <LibWeb/Selection/MediaList.h>
#elif __has_include(<LibWeb/WebSockets/MediaList.h>)
#    include <LibWeb/WebSockets/MediaList.h>
#elif __has_include(<LibWeb/XHR/MediaList.h>)
#    include <LibWeb/XHR/MediaList.h>
#elif __has_include(<LibWeb/URL/MediaList.h>)
#    include <LibWeb/URL/MediaList.h>
#endif


#include <LibWeb/CSS/MediaList.h>

#include <LibWeb/CSS/MediaList.h>

#if __has_include(<LibWeb/Bindings/MediaListWrapper.h>)
#   include <LibWeb/Bindings/MediaListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MediaListWrapperFactory.h>)
#   include <LibWeb/Bindings/MediaListWrapperFactory.h>
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

MediaListConstructor::MediaListConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

MediaListConstructor::~MediaListConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> MediaListConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "MediaList");
}

JS::ThrowCompletionOr<JS::Object*> MediaListConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "MediaList");

}

void MediaListConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<MediaListPrototype>("MediaList"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

