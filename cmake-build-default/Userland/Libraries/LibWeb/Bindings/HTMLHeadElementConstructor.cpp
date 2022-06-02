
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLHeadElementConstructor.h>
#include <LibWeb/Bindings/HTMLHeadElementPrototype.h>
#include <LibWeb/Bindings/HTMLHeadElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLHeadElement.h>)
#    include <LibWeb/Crypto/HTMLHeadElement.h>
#elif __has_include(<LibWeb/CSS/HTMLHeadElement.h>)
#    include <LibWeb/CSS/HTMLHeadElement.h>
#elif __has_include(<LibWeb/DOM/HTMLHeadElement.h>)
#    include <LibWeb/DOM/HTMLHeadElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLHeadElement.h>)
#    include <LibWeb/Encoding/HTMLHeadElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLHeadElement.h>)
#    include <LibWeb/Geometry/HTMLHeadElement.h>
#elif __has_include(<LibWeb/HTML/HTMLHeadElement.h>)
#    include <LibWeb/HTML/HTMLHeadElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLHeadElement.h>)
#    include <LibWeb/UIEvents/HTMLHeadElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLHeadElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLHeadElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLHeadElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLHeadElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLHeadElement.h>)
#    include <LibWeb/NavigationTiming/HTMLHeadElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLHeadElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLHeadElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLHeadElement.h>)
#    include <LibWeb/ResizeObserver/HTMLHeadElement.h>
#elif __has_include(<LibWeb/SVG/HTMLHeadElement.h>)
#    include <LibWeb/SVG/HTMLHeadElement.h>
#elif __has_include(<LibWeb/Selection/HTMLHeadElement.h>)
#    include <LibWeb/Selection/HTMLHeadElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLHeadElement.h>)
#    include <LibWeb/WebSockets/HTMLHeadElement.h>
#elif __has_include(<LibWeb/XHR/HTMLHeadElement.h>)
#    include <LibWeb/XHR/HTMLHeadElement.h>
#elif __has_include(<LibWeb/URL/HTMLHeadElement.h>)
#    include <LibWeb/URL/HTMLHeadElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLHeadElement.h>

#include <LibWeb/HTML/HTMLHeadElement.h>

#if __has_include(<LibWeb/Bindings/HTMLHeadElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLHeadElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLHeadElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLHeadElementWrapperFactory.h>
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

HTMLHeadElementConstructor::HTMLHeadElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLHeadElementConstructor::~HTMLHeadElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLHeadElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLHeadElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLHeadElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLHeadElement");

}

void HTMLHeadElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLHeadElementPrototype>("HTMLHeadElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

