
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLFrameElementConstructor.h>
#include <LibWeb/Bindings/HTMLFrameElementPrototype.h>
#include <LibWeb/Bindings/HTMLFrameElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLFrameElement.h>)
#    include <LibWeb/Crypto/HTMLFrameElement.h>
#elif __has_include(<LibWeb/CSS/HTMLFrameElement.h>)
#    include <LibWeb/CSS/HTMLFrameElement.h>
#elif __has_include(<LibWeb/DOM/HTMLFrameElement.h>)
#    include <LibWeb/DOM/HTMLFrameElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLFrameElement.h>)
#    include <LibWeb/Encoding/HTMLFrameElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLFrameElement.h>)
#    include <LibWeb/Geometry/HTMLFrameElement.h>
#elif __has_include(<LibWeb/HTML/HTMLFrameElement.h>)
#    include <LibWeb/HTML/HTMLFrameElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLFrameElement.h>)
#    include <LibWeb/UIEvents/HTMLFrameElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLFrameElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLFrameElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLFrameElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLFrameElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLFrameElement.h>)
#    include <LibWeb/NavigationTiming/HTMLFrameElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLFrameElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLFrameElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLFrameElement.h>)
#    include <LibWeb/ResizeObserver/HTMLFrameElement.h>
#elif __has_include(<LibWeb/SVG/HTMLFrameElement.h>)
#    include <LibWeb/SVG/HTMLFrameElement.h>
#elif __has_include(<LibWeb/Selection/HTMLFrameElement.h>)
#    include <LibWeb/Selection/HTMLFrameElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLFrameElement.h>)
#    include <LibWeb/WebSockets/HTMLFrameElement.h>
#elif __has_include(<LibWeb/XHR/HTMLFrameElement.h>)
#    include <LibWeb/XHR/HTMLFrameElement.h>
#elif __has_include(<LibWeb/URL/HTMLFrameElement.h>)
#    include <LibWeb/URL/HTMLFrameElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLFrameElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLFrameElement.h>

#if __has_include(<LibWeb/Bindings/HTMLFrameElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLFrameElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLFrameElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLFrameElementWrapperFactory.h>
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

HTMLFrameElementConstructor::HTMLFrameElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLFrameElementConstructor::~HTMLFrameElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLFrameElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLFrameElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLFrameElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLFrameElement");

}

void HTMLFrameElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLFrameElementPrototype>("HTMLFrameElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

