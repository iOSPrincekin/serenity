
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLParagraphElementConstructor.h>
#include <LibWeb/Bindings/HTMLParagraphElementPrototype.h>
#include <LibWeb/Bindings/HTMLParagraphElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLParagraphElement.h>)
#    include <LibWeb/Crypto/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/CSS/HTMLParagraphElement.h>)
#    include <LibWeb/CSS/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/DOM/HTMLParagraphElement.h>)
#    include <LibWeb/DOM/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLParagraphElement.h>)
#    include <LibWeb/Encoding/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLParagraphElement.h>)
#    include <LibWeb/Geometry/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/HTML/HTMLParagraphElement.h>)
#    include <LibWeb/HTML/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLParagraphElement.h>)
#    include <LibWeb/UIEvents/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLParagraphElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLParagraphElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLParagraphElement.h>)
#    include <LibWeb/NavigationTiming/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLParagraphElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLParagraphElement.h>)
#    include <LibWeb/ResizeObserver/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/SVG/HTMLParagraphElement.h>)
#    include <LibWeb/SVG/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/Selection/HTMLParagraphElement.h>)
#    include <LibWeb/Selection/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLParagraphElement.h>)
#    include <LibWeb/WebSockets/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/XHR/HTMLParagraphElement.h>)
#    include <LibWeb/XHR/HTMLParagraphElement.h>
#elif __has_include(<LibWeb/URL/HTMLParagraphElement.h>)
#    include <LibWeb/URL/HTMLParagraphElement.h>
#endif


#include <LibWeb/HTML/HTMLParagraphElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLParagraphElement.h>

#if __has_include(<LibWeb/Bindings/HTMLParagraphElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLParagraphElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLParagraphElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLParagraphElementWrapperFactory.h>
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

HTMLParagraphElementConstructor::HTMLParagraphElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLParagraphElementConstructor::~HTMLParagraphElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLParagraphElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLParagraphElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLParagraphElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLParagraphElement");

}

void HTMLParagraphElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLParagraphElementPrototype>("HTMLParagraphElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

