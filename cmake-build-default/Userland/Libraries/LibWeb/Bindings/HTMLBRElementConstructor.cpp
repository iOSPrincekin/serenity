
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLBRElementConstructor.h>
#include <LibWeb/Bindings/HTMLBRElementPrototype.h>
#include <LibWeb/Bindings/HTMLBRElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLBRElement.h>)
#    include <LibWeb/Crypto/HTMLBRElement.h>
#elif __has_include(<LibWeb/CSS/HTMLBRElement.h>)
#    include <LibWeb/CSS/HTMLBRElement.h>
#elif __has_include(<LibWeb/DOM/HTMLBRElement.h>)
#    include <LibWeb/DOM/HTMLBRElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLBRElement.h>)
#    include <LibWeb/Encoding/HTMLBRElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLBRElement.h>)
#    include <LibWeb/Geometry/HTMLBRElement.h>
#elif __has_include(<LibWeb/HTML/HTMLBRElement.h>)
#    include <LibWeb/HTML/HTMLBRElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLBRElement.h>)
#    include <LibWeb/UIEvents/HTMLBRElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLBRElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLBRElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLBRElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLBRElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLBRElement.h>)
#    include <LibWeb/NavigationTiming/HTMLBRElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLBRElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLBRElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLBRElement.h>)
#    include <LibWeb/ResizeObserver/HTMLBRElement.h>
#elif __has_include(<LibWeb/SVG/HTMLBRElement.h>)
#    include <LibWeb/SVG/HTMLBRElement.h>
#elif __has_include(<LibWeb/Selection/HTMLBRElement.h>)
#    include <LibWeb/Selection/HTMLBRElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLBRElement.h>)
#    include <LibWeb/WebSockets/HTMLBRElement.h>
#elif __has_include(<LibWeb/XHR/HTMLBRElement.h>)
#    include <LibWeb/XHR/HTMLBRElement.h>
#elif __has_include(<LibWeb/URL/HTMLBRElement.h>)
#    include <LibWeb/URL/HTMLBRElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLBRElement.h>

#include <LibWeb/HTML/HTMLBRElement.h>

#if __has_include(<LibWeb/Bindings/HTMLBRElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLBRElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLBRElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLBRElementWrapperFactory.h>
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

HTMLBRElementConstructor::HTMLBRElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLBRElementConstructor::~HTMLBRElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLBRElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLBRElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLBRElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLBRElement");

}

void HTMLBRElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLBRElementPrototype>("HTMLBRElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

