
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLPictureElementConstructor.h>
#include <LibWeb/Bindings/HTMLPictureElementPrototype.h>
#include <LibWeb/Bindings/HTMLPictureElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLPictureElement.h>)
#    include <LibWeb/Crypto/HTMLPictureElement.h>
#elif __has_include(<LibWeb/CSS/HTMLPictureElement.h>)
#    include <LibWeb/CSS/HTMLPictureElement.h>
#elif __has_include(<LibWeb/DOM/HTMLPictureElement.h>)
#    include <LibWeb/DOM/HTMLPictureElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLPictureElement.h>)
#    include <LibWeb/Encoding/HTMLPictureElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLPictureElement.h>)
#    include <LibWeb/Geometry/HTMLPictureElement.h>
#elif __has_include(<LibWeb/HTML/HTMLPictureElement.h>)
#    include <LibWeb/HTML/HTMLPictureElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLPictureElement.h>)
#    include <LibWeb/UIEvents/HTMLPictureElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLPictureElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLPictureElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLPictureElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLPictureElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLPictureElement.h>)
#    include <LibWeb/NavigationTiming/HTMLPictureElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLPictureElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLPictureElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLPictureElement.h>)
#    include <LibWeb/ResizeObserver/HTMLPictureElement.h>
#elif __has_include(<LibWeb/SVG/HTMLPictureElement.h>)
#    include <LibWeb/SVG/HTMLPictureElement.h>
#elif __has_include(<LibWeb/Selection/HTMLPictureElement.h>)
#    include <LibWeb/Selection/HTMLPictureElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLPictureElement.h>)
#    include <LibWeb/WebSockets/HTMLPictureElement.h>
#elif __has_include(<LibWeb/XHR/HTMLPictureElement.h>)
#    include <LibWeb/XHR/HTMLPictureElement.h>
#elif __has_include(<LibWeb/URL/HTMLPictureElement.h>)
#    include <LibWeb/URL/HTMLPictureElement.h>
#endif


#include <LibWeb/HTML/HTMLPictureElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLPictureElement.h>

#if __has_include(<LibWeb/Bindings/HTMLPictureElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLPictureElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLPictureElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLPictureElementWrapperFactory.h>
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

HTMLPictureElementConstructor::HTMLPictureElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLPictureElementConstructor::~HTMLPictureElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLPictureElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLPictureElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLPictureElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLPictureElement");

}

void HTMLPictureElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLPictureElementPrototype>("HTMLPictureElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

