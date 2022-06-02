
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLFrameSetElementConstructor.h>
#include <LibWeb/Bindings/HTMLFrameSetElementPrototype.h>
#include <LibWeb/Bindings/HTMLFrameSetElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLFrameSetElement.h>)
#    include <LibWeb/Crypto/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/CSS/HTMLFrameSetElement.h>)
#    include <LibWeb/CSS/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/DOM/HTMLFrameSetElement.h>)
#    include <LibWeb/DOM/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLFrameSetElement.h>)
#    include <LibWeb/Encoding/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLFrameSetElement.h>)
#    include <LibWeb/Geometry/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/HTML/HTMLFrameSetElement.h>)
#    include <LibWeb/HTML/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLFrameSetElement.h>)
#    include <LibWeb/UIEvents/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLFrameSetElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLFrameSetElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLFrameSetElement.h>)
#    include <LibWeb/NavigationTiming/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLFrameSetElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLFrameSetElement.h>)
#    include <LibWeb/ResizeObserver/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/SVG/HTMLFrameSetElement.h>)
#    include <LibWeb/SVG/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/Selection/HTMLFrameSetElement.h>)
#    include <LibWeb/Selection/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLFrameSetElement.h>)
#    include <LibWeb/WebSockets/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/XHR/HTMLFrameSetElement.h>)
#    include <LibWeb/XHR/HTMLFrameSetElement.h>
#elif __has_include(<LibWeb/URL/HTMLFrameSetElement.h>)
#    include <LibWeb/URL/HTMLFrameSetElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLFrameSetElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLFrameSetElement.h>

#if __has_include(<LibWeb/Bindings/HTMLFrameSetElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLFrameSetElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLFrameSetElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLFrameSetElementWrapperFactory.h>
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

HTMLFrameSetElementConstructor::HTMLFrameSetElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLFrameSetElementConstructor::~HTMLFrameSetElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLFrameSetElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLFrameSetElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLFrameSetElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLFrameSetElement");

}

void HTMLFrameSetElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLFrameSetElementPrototype>("HTMLFrameSetElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

