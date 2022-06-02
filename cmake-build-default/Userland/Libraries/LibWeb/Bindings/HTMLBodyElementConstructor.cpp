
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLBodyElementConstructor.h>
#include <LibWeb/Bindings/HTMLBodyElementPrototype.h>
#include <LibWeb/Bindings/HTMLBodyElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLBodyElement.h>)
#    include <LibWeb/Crypto/HTMLBodyElement.h>
#elif __has_include(<LibWeb/CSS/HTMLBodyElement.h>)
#    include <LibWeb/CSS/HTMLBodyElement.h>
#elif __has_include(<LibWeb/DOM/HTMLBodyElement.h>)
#    include <LibWeb/DOM/HTMLBodyElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLBodyElement.h>)
#    include <LibWeb/Encoding/HTMLBodyElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLBodyElement.h>)
#    include <LibWeb/Geometry/HTMLBodyElement.h>
#elif __has_include(<LibWeb/HTML/HTMLBodyElement.h>)
#    include <LibWeb/HTML/HTMLBodyElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLBodyElement.h>)
#    include <LibWeb/UIEvents/HTMLBodyElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLBodyElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLBodyElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLBodyElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLBodyElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLBodyElement.h>)
#    include <LibWeb/NavigationTiming/HTMLBodyElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLBodyElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLBodyElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLBodyElement.h>)
#    include <LibWeb/ResizeObserver/HTMLBodyElement.h>
#elif __has_include(<LibWeb/SVG/HTMLBodyElement.h>)
#    include <LibWeb/SVG/HTMLBodyElement.h>
#elif __has_include(<LibWeb/Selection/HTMLBodyElement.h>)
#    include <LibWeb/Selection/HTMLBodyElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLBodyElement.h>)
#    include <LibWeb/WebSockets/HTMLBodyElement.h>
#elif __has_include(<LibWeb/XHR/HTMLBodyElement.h>)
#    include <LibWeb/XHR/HTMLBodyElement.h>
#elif __has_include(<LibWeb/URL/HTMLBodyElement.h>)
#    include <LibWeb/URL/HTMLBodyElement.h>
#endif


#include <LibWeb/HTML/HTMLBodyElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLBodyElement.h>

#if __has_include(<LibWeb/Bindings/HTMLBodyElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLBodyElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLBodyElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLBodyElementWrapperFactory.h>
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

HTMLBodyElementConstructor::HTMLBodyElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLBodyElementConstructor::~HTMLBodyElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLBodyElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLBodyElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLBodyElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLBodyElement");

}

void HTMLBodyElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLBodyElementPrototype>("HTMLBodyElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

