
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLPreElementConstructor.h>
#include <LibWeb/Bindings/HTMLPreElementPrototype.h>
#include <LibWeb/Bindings/HTMLPreElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLPreElement.h>)
#    include <LibWeb/Crypto/HTMLPreElement.h>
#elif __has_include(<LibWeb/CSS/HTMLPreElement.h>)
#    include <LibWeb/CSS/HTMLPreElement.h>
#elif __has_include(<LibWeb/DOM/HTMLPreElement.h>)
#    include <LibWeb/DOM/HTMLPreElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLPreElement.h>)
#    include <LibWeb/Encoding/HTMLPreElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLPreElement.h>)
#    include <LibWeb/Geometry/HTMLPreElement.h>
#elif __has_include(<LibWeb/HTML/HTMLPreElement.h>)
#    include <LibWeb/HTML/HTMLPreElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLPreElement.h>)
#    include <LibWeb/UIEvents/HTMLPreElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLPreElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLPreElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLPreElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLPreElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLPreElement.h>)
#    include <LibWeb/NavigationTiming/HTMLPreElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLPreElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLPreElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLPreElement.h>)
#    include <LibWeb/ResizeObserver/HTMLPreElement.h>
#elif __has_include(<LibWeb/SVG/HTMLPreElement.h>)
#    include <LibWeb/SVG/HTMLPreElement.h>
#elif __has_include(<LibWeb/Selection/HTMLPreElement.h>)
#    include <LibWeb/Selection/HTMLPreElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLPreElement.h>)
#    include <LibWeb/WebSockets/HTMLPreElement.h>
#elif __has_include(<LibWeb/XHR/HTMLPreElement.h>)
#    include <LibWeb/XHR/HTMLPreElement.h>
#elif __has_include(<LibWeb/URL/HTMLPreElement.h>)
#    include <LibWeb/URL/HTMLPreElement.h>
#endif


#include <LibWeb/HTML/HTMLPreElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLPreElement.h>

#if __has_include(<LibWeb/Bindings/HTMLPreElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLPreElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLPreElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLPreElementWrapperFactory.h>
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

HTMLPreElementConstructor::HTMLPreElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLPreElementConstructor::~HTMLPreElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLPreElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLPreElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLPreElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLPreElement");

}

void HTMLPreElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLPreElementPrototype>("HTMLPreElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

