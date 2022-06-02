
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLLIElementConstructor.h>
#include <LibWeb/Bindings/HTMLLIElementPrototype.h>
#include <LibWeb/Bindings/HTMLLIElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLLIElement.h>)
#    include <LibWeb/Crypto/HTMLLIElement.h>
#elif __has_include(<LibWeb/CSS/HTMLLIElement.h>)
#    include <LibWeb/CSS/HTMLLIElement.h>
#elif __has_include(<LibWeb/DOM/HTMLLIElement.h>)
#    include <LibWeb/DOM/HTMLLIElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLLIElement.h>)
#    include <LibWeb/Encoding/HTMLLIElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLLIElement.h>)
#    include <LibWeb/Geometry/HTMLLIElement.h>
#elif __has_include(<LibWeb/HTML/HTMLLIElement.h>)
#    include <LibWeb/HTML/HTMLLIElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLLIElement.h>)
#    include <LibWeb/UIEvents/HTMLLIElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLLIElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLLIElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLLIElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLLIElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLLIElement.h>)
#    include <LibWeb/NavigationTiming/HTMLLIElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLLIElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLLIElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLLIElement.h>)
#    include <LibWeb/ResizeObserver/HTMLLIElement.h>
#elif __has_include(<LibWeb/SVG/HTMLLIElement.h>)
#    include <LibWeb/SVG/HTMLLIElement.h>
#elif __has_include(<LibWeb/Selection/HTMLLIElement.h>)
#    include <LibWeb/Selection/HTMLLIElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLLIElement.h>)
#    include <LibWeb/WebSockets/HTMLLIElement.h>
#elif __has_include(<LibWeb/XHR/HTMLLIElement.h>)
#    include <LibWeb/XHR/HTMLLIElement.h>
#elif __has_include(<LibWeb/URL/HTMLLIElement.h>)
#    include <LibWeb/URL/HTMLLIElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLLIElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLLIElement.h>

#if __has_include(<LibWeb/Bindings/HTMLLIElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLLIElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLLIElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLLIElementWrapperFactory.h>
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

HTMLLIElementConstructor::HTMLLIElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLLIElementConstructor::~HTMLLIElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLLIElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLLIElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLLIElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLLIElement");

}

void HTMLLIElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLLIElementPrototype>("HTMLLIElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

