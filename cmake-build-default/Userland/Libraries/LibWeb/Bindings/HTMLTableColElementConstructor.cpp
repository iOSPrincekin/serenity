
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLTableColElementConstructor.h>
#include <LibWeb/Bindings/HTMLTableColElementPrototype.h>
#include <LibWeb/Bindings/HTMLTableColElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLTableColElement.h>)
#    include <LibWeb/Crypto/HTMLTableColElement.h>
#elif __has_include(<LibWeb/CSS/HTMLTableColElement.h>)
#    include <LibWeb/CSS/HTMLTableColElement.h>
#elif __has_include(<LibWeb/DOM/HTMLTableColElement.h>)
#    include <LibWeb/DOM/HTMLTableColElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLTableColElement.h>)
#    include <LibWeb/Encoding/HTMLTableColElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLTableColElement.h>)
#    include <LibWeb/Geometry/HTMLTableColElement.h>
#elif __has_include(<LibWeb/HTML/HTMLTableColElement.h>)
#    include <LibWeb/HTML/HTMLTableColElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLTableColElement.h>)
#    include <LibWeb/UIEvents/HTMLTableColElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLTableColElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLTableColElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLTableColElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLTableColElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLTableColElement.h>)
#    include <LibWeb/NavigationTiming/HTMLTableColElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLTableColElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLTableColElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLTableColElement.h>)
#    include <LibWeb/ResizeObserver/HTMLTableColElement.h>
#elif __has_include(<LibWeb/SVG/HTMLTableColElement.h>)
#    include <LibWeb/SVG/HTMLTableColElement.h>
#elif __has_include(<LibWeb/Selection/HTMLTableColElement.h>)
#    include <LibWeb/Selection/HTMLTableColElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLTableColElement.h>)
#    include <LibWeb/WebSockets/HTMLTableColElement.h>
#elif __has_include(<LibWeb/XHR/HTMLTableColElement.h>)
#    include <LibWeb/XHR/HTMLTableColElement.h>
#elif __has_include(<LibWeb/URL/HTMLTableColElement.h>)
#    include <LibWeb/URL/HTMLTableColElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLTableColElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLTableColElement.h>

#if __has_include(<LibWeb/Bindings/HTMLTableColElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLTableColElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLTableColElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLTableColElementWrapperFactory.h>
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

HTMLTableColElementConstructor::HTMLTableColElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLTableColElementConstructor::~HTMLTableColElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLTableColElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLTableColElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLTableColElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLTableColElement");

}

void HTMLTableColElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLTableColElementPrototype>("HTMLTableColElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

