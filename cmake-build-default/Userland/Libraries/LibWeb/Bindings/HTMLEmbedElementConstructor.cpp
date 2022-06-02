
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLEmbedElementConstructor.h>
#include <LibWeb/Bindings/HTMLEmbedElementPrototype.h>
#include <LibWeb/Bindings/HTMLEmbedElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLEmbedElement.h>)
#    include <LibWeb/Crypto/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/CSS/HTMLEmbedElement.h>)
#    include <LibWeb/CSS/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/DOM/HTMLEmbedElement.h>)
#    include <LibWeb/DOM/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLEmbedElement.h>)
#    include <LibWeb/Encoding/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLEmbedElement.h>)
#    include <LibWeb/Geometry/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/HTML/HTMLEmbedElement.h>)
#    include <LibWeb/HTML/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLEmbedElement.h>)
#    include <LibWeb/UIEvents/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLEmbedElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLEmbedElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLEmbedElement.h>)
#    include <LibWeb/NavigationTiming/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLEmbedElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLEmbedElement.h>)
#    include <LibWeb/ResizeObserver/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/SVG/HTMLEmbedElement.h>)
#    include <LibWeb/SVG/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/Selection/HTMLEmbedElement.h>)
#    include <LibWeb/Selection/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLEmbedElement.h>)
#    include <LibWeb/WebSockets/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/XHR/HTMLEmbedElement.h>)
#    include <LibWeb/XHR/HTMLEmbedElement.h>
#elif __has_include(<LibWeb/URL/HTMLEmbedElement.h>)
#    include <LibWeb/URL/HTMLEmbedElement.h>
#endif


#include <LibWeb/HTML/HTMLEmbedElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLEmbedElement.h>

#if __has_include(<LibWeb/Bindings/HTMLEmbedElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLEmbedElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLEmbedElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLEmbedElementWrapperFactory.h>
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

HTMLEmbedElementConstructor::HTMLEmbedElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLEmbedElementConstructor::~HTMLEmbedElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLEmbedElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLEmbedElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLEmbedElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLEmbedElement");

}

void HTMLEmbedElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLEmbedElementPrototype>("HTMLEmbedElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

