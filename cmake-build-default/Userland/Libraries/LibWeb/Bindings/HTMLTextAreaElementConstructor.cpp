
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLTextAreaElementConstructor.h>
#include <LibWeb/Bindings/HTMLTextAreaElementPrototype.h>
#include <LibWeb/Bindings/HTMLTextAreaElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLTextAreaElement.h>)
#    include <LibWeb/Crypto/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/CSS/HTMLTextAreaElement.h>)
#    include <LibWeb/CSS/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/DOM/HTMLTextAreaElement.h>)
#    include <LibWeb/DOM/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLTextAreaElement.h>)
#    include <LibWeb/Encoding/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLTextAreaElement.h>)
#    include <LibWeb/Geometry/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/HTML/HTMLTextAreaElement.h>)
#    include <LibWeb/HTML/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLTextAreaElement.h>)
#    include <LibWeb/UIEvents/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLTextAreaElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLTextAreaElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLTextAreaElement.h>)
#    include <LibWeb/NavigationTiming/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLTextAreaElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLTextAreaElement.h>)
#    include <LibWeb/ResizeObserver/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/SVG/HTMLTextAreaElement.h>)
#    include <LibWeb/SVG/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/Selection/HTMLTextAreaElement.h>)
#    include <LibWeb/Selection/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLTextAreaElement.h>)
#    include <LibWeb/WebSockets/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/XHR/HTMLTextAreaElement.h>)
#    include <LibWeb/XHR/HTMLTextAreaElement.h>
#elif __has_include(<LibWeb/URL/HTMLTextAreaElement.h>)
#    include <LibWeb/URL/HTMLTextAreaElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLTextAreaElement.h>

#include <LibWeb/HTML/HTMLTextAreaElement.h>

#if __has_include(<LibWeb/Bindings/HTMLTextAreaElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLTextAreaElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLTextAreaElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLTextAreaElementWrapperFactory.h>
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

HTMLTextAreaElementConstructor::HTMLTextAreaElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLTextAreaElementConstructor::~HTMLTextAreaElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLTextAreaElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLTextAreaElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLTextAreaElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLTextAreaElement");

}

void HTMLTextAreaElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLTextAreaElementPrototype>("HTMLTextAreaElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

