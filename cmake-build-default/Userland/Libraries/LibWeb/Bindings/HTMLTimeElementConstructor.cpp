
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLTimeElementConstructor.h>
#include <LibWeb/Bindings/HTMLTimeElementPrototype.h>
#include <LibWeb/Bindings/HTMLTimeElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLTimeElement.h>)
#    include <LibWeb/Crypto/HTMLTimeElement.h>
#elif __has_include(<LibWeb/CSS/HTMLTimeElement.h>)
#    include <LibWeb/CSS/HTMLTimeElement.h>
#elif __has_include(<LibWeb/DOM/HTMLTimeElement.h>)
#    include <LibWeb/DOM/HTMLTimeElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLTimeElement.h>)
#    include <LibWeb/Encoding/HTMLTimeElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLTimeElement.h>)
#    include <LibWeb/Geometry/HTMLTimeElement.h>
#elif __has_include(<LibWeb/HTML/HTMLTimeElement.h>)
#    include <LibWeb/HTML/HTMLTimeElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLTimeElement.h>)
#    include <LibWeb/UIEvents/HTMLTimeElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLTimeElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLTimeElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLTimeElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLTimeElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLTimeElement.h>)
#    include <LibWeb/NavigationTiming/HTMLTimeElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLTimeElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLTimeElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLTimeElement.h>)
#    include <LibWeb/ResizeObserver/HTMLTimeElement.h>
#elif __has_include(<LibWeb/SVG/HTMLTimeElement.h>)
#    include <LibWeb/SVG/HTMLTimeElement.h>
#elif __has_include(<LibWeb/Selection/HTMLTimeElement.h>)
#    include <LibWeb/Selection/HTMLTimeElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLTimeElement.h>)
#    include <LibWeb/WebSockets/HTMLTimeElement.h>
#elif __has_include(<LibWeb/XHR/HTMLTimeElement.h>)
#    include <LibWeb/XHR/HTMLTimeElement.h>
#elif __has_include(<LibWeb/URL/HTMLTimeElement.h>)
#    include <LibWeb/URL/HTMLTimeElement.h>
#endif


#include <LibWeb/HTML/HTMLTimeElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLTimeElement.h>

#if __has_include(<LibWeb/Bindings/HTMLTimeElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLTimeElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLTimeElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLTimeElementWrapperFactory.h>
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

HTMLTimeElementConstructor::HTMLTimeElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLTimeElementConstructor::~HTMLTimeElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLTimeElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLTimeElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLTimeElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLTimeElement");

}

void HTMLTimeElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLTimeElementPrototype>("HTMLTimeElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

