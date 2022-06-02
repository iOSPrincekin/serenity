
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLAreaElementConstructor.h>
#include <LibWeb/Bindings/HTMLAreaElementPrototype.h>
#include <LibWeb/Bindings/HTMLAreaElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLAreaElement.h>)
#    include <LibWeb/Crypto/HTMLAreaElement.h>
#elif __has_include(<LibWeb/CSS/HTMLAreaElement.h>)
#    include <LibWeb/CSS/HTMLAreaElement.h>
#elif __has_include(<LibWeb/DOM/HTMLAreaElement.h>)
#    include <LibWeb/DOM/HTMLAreaElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLAreaElement.h>)
#    include <LibWeb/Encoding/HTMLAreaElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLAreaElement.h>)
#    include <LibWeb/Geometry/HTMLAreaElement.h>
#elif __has_include(<LibWeb/HTML/HTMLAreaElement.h>)
#    include <LibWeb/HTML/HTMLAreaElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLAreaElement.h>)
#    include <LibWeb/UIEvents/HTMLAreaElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLAreaElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLAreaElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLAreaElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLAreaElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLAreaElement.h>)
#    include <LibWeb/NavigationTiming/HTMLAreaElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLAreaElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLAreaElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLAreaElement.h>)
#    include <LibWeb/ResizeObserver/HTMLAreaElement.h>
#elif __has_include(<LibWeb/SVG/HTMLAreaElement.h>)
#    include <LibWeb/SVG/HTMLAreaElement.h>
#elif __has_include(<LibWeb/Selection/HTMLAreaElement.h>)
#    include <LibWeb/Selection/HTMLAreaElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLAreaElement.h>)
#    include <LibWeb/WebSockets/HTMLAreaElement.h>
#elif __has_include(<LibWeb/XHR/HTMLAreaElement.h>)
#    include <LibWeb/XHR/HTMLAreaElement.h>
#elif __has_include(<LibWeb/URL/HTMLAreaElement.h>)
#    include <LibWeb/URL/HTMLAreaElement.h>
#endif


#include <LibWeb/HTML/HTMLAreaElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLAreaElement.h>

#if __has_include(<LibWeb/Bindings/HTMLAreaElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLAreaElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLAreaElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLAreaElementWrapperFactory.h>
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

HTMLAreaElementConstructor::HTMLAreaElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLAreaElementConstructor::~HTMLAreaElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLAreaElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLAreaElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLAreaElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLAreaElement");

}

void HTMLAreaElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLAreaElementPrototype>("HTMLAreaElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

