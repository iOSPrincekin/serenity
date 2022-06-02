
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLMetaElementConstructor.h>
#include <LibWeb/Bindings/HTMLMetaElementPrototype.h>
#include <LibWeb/Bindings/HTMLMetaElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLMetaElement.h>)
#    include <LibWeb/Crypto/HTMLMetaElement.h>
#elif __has_include(<LibWeb/CSS/HTMLMetaElement.h>)
#    include <LibWeb/CSS/HTMLMetaElement.h>
#elif __has_include(<LibWeb/DOM/HTMLMetaElement.h>)
#    include <LibWeb/DOM/HTMLMetaElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLMetaElement.h>)
#    include <LibWeb/Encoding/HTMLMetaElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLMetaElement.h>)
#    include <LibWeb/Geometry/HTMLMetaElement.h>
#elif __has_include(<LibWeb/HTML/HTMLMetaElement.h>)
#    include <LibWeb/HTML/HTMLMetaElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLMetaElement.h>)
#    include <LibWeb/UIEvents/HTMLMetaElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLMetaElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLMetaElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLMetaElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLMetaElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLMetaElement.h>)
#    include <LibWeb/NavigationTiming/HTMLMetaElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLMetaElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLMetaElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLMetaElement.h>)
#    include <LibWeb/ResizeObserver/HTMLMetaElement.h>
#elif __has_include(<LibWeb/SVG/HTMLMetaElement.h>)
#    include <LibWeb/SVG/HTMLMetaElement.h>
#elif __has_include(<LibWeb/Selection/HTMLMetaElement.h>)
#    include <LibWeb/Selection/HTMLMetaElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLMetaElement.h>)
#    include <LibWeb/WebSockets/HTMLMetaElement.h>
#elif __has_include(<LibWeb/XHR/HTMLMetaElement.h>)
#    include <LibWeb/XHR/HTMLMetaElement.h>
#elif __has_include(<LibWeb/URL/HTMLMetaElement.h>)
#    include <LibWeb/URL/HTMLMetaElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMetaElement.h>

#include <LibWeb/HTML/HTMLMetaElement.h>

#if __has_include(<LibWeb/Bindings/HTMLMetaElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMetaElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMetaElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMetaElementWrapperFactory.h>
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

HTMLMetaElementConstructor::HTMLMetaElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLMetaElementConstructor::~HTMLMetaElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLMetaElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLMetaElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLMetaElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLMetaElement");

}

void HTMLMetaElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLMetaElementPrototype>("HTMLMetaElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

