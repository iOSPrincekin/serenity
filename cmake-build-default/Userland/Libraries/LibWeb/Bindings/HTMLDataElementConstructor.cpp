
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLDataElementConstructor.h>
#include <LibWeb/Bindings/HTMLDataElementPrototype.h>
#include <LibWeb/Bindings/HTMLDataElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLDataElement.h>)
#    include <LibWeb/Crypto/HTMLDataElement.h>
#elif __has_include(<LibWeb/CSS/HTMLDataElement.h>)
#    include <LibWeb/CSS/HTMLDataElement.h>
#elif __has_include(<LibWeb/DOM/HTMLDataElement.h>)
#    include <LibWeb/DOM/HTMLDataElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLDataElement.h>)
#    include <LibWeb/Encoding/HTMLDataElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLDataElement.h>)
#    include <LibWeb/Geometry/HTMLDataElement.h>
#elif __has_include(<LibWeb/HTML/HTMLDataElement.h>)
#    include <LibWeb/HTML/HTMLDataElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLDataElement.h>)
#    include <LibWeb/UIEvents/HTMLDataElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLDataElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLDataElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLDataElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLDataElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLDataElement.h>)
#    include <LibWeb/NavigationTiming/HTMLDataElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLDataElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLDataElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLDataElement.h>)
#    include <LibWeb/ResizeObserver/HTMLDataElement.h>
#elif __has_include(<LibWeb/SVG/HTMLDataElement.h>)
#    include <LibWeb/SVG/HTMLDataElement.h>
#elif __has_include(<LibWeb/Selection/HTMLDataElement.h>)
#    include <LibWeb/Selection/HTMLDataElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLDataElement.h>)
#    include <LibWeb/WebSockets/HTMLDataElement.h>
#elif __has_include(<LibWeb/XHR/HTMLDataElement.h>)
#    include <LibWeb/XHR/HTMLDataElement.h>
#elif __has_include(<LibWeb/URL/HTMLDataElement.h>)
#    include <LibWeb/URL/HTMLDataElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLDataElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLDataElement.h>

#if __has_include(<LibWeb/Bindings/HTMLDataElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLDataElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLDataElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLDataElementWrapperFactory.h>
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

HTMLDataElementConstructor::HTMLDataElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLDataElementConstructor::~HTMLDataElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLDataElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLDataElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLDataElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLDataElement");

}

void HTMLDataElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLDataElementPrototype>("HTMLDataElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

