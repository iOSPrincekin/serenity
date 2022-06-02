
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLImageElementConstructor.h>
#include <LibWeb/Bindings/HTMLImageElementPrototype.h>
#include <LibWeb/Bindings/HTMLImageElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLImageElement.h>)
#    include <LibWeb/Crypto/HTMLImageElement.h>
#elif __has_include(<LibWeb/CSS/HTMLImageElement.h>)
#    include <LibWeb/CSS/HTMLImageElement.h>
#elif __has_include(<LibWeb/DOM/HTMLImageElement.h>)
#    include <LibWeb/DOM/HTMLImageElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLImageElement.h>)
#    include <LibWeb/Encoding/HTMLImageElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLImageElement.h>)
#    include <LibWeb/Geometry/HTMLImageElement.h>
#elif __has_include(<LibWeb/HTML/HTMLImageElement.h>)
#    include <LibWeb/HTML/HTMLImageElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLImageElement.h>)
#    include <LibWeb/UIEvents/HTMLImageElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLImageElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLImageElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLImageElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLImageElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLImageElement.h>)
#    include <LibWeb/NavigationTiming/HTMLImageElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLImageElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLImageElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLImageElement.h>)
#    include <LibWeb/ResizeObserver/HTMLImageElement.h>
#elif __has_include(<LibWeb/SVG/HTMLImageElement.h>)
#    include <LibWeb/SVG/HTMLImageElement.h>
#elif __has_include(<LibWeb/Selection/HTMLImageElement.h>)
#    include <LibWeb/Selection/HTMLImageElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLImageElement.h>)
#    include <LibWeb/WebSockets/HTMLImageElement.h>
#elif __has_include(<LibWeb/XHR/HTMLImageElement.h>)
#    include <LibWeb/XHR/HTMLImageElement.h>
#elif __has_include(<LibWeb/URL/HTMLImageElement.h>)
#    include <LibWeb/URL/HTMLImageElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLImageElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLImageElement.h>

#if __has_include(<LibWeb/Bindings/HTMLImageElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLImageElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLImageElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLImageElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/HTMLElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/DOMStringMapWrapper.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMStringMapWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMStringMapWrapperFactory.h>
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

HTMLImageElementConstructor::HTMLImageElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLImageElementConstructor::~HTMLImageElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLImageElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLImageElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLImageElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLImageElement");

}

void HTMLImageElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLImageElementPrototype>("HTMLImageElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

