
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLMapElementConstructor.h>
#include <LibWeb/Bindings/HTMLMapElementPrototype.h>
#include <LibWeb/Bindings/HTMLMapElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLMapElement.h>)
#    include <LibWeb/Crypto/HTMLMapElement.h>
#elif __has_include(<LibWeb/CSS/HTMLMapElement.h>)
#    include <LibWeb/CSS/HTMLMapElement.h>
#elif __has_include(<LibWeb/DOM/HTMLMapElement.h>)
#    include <LibWeb/DOM/HTMLMapElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLMapElement.h>)
#    include <LibWeb/Encoding/HTMLMapElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLMapElement.h>)
#    include <LibWeb/Geometry/HTMLMapElement.h>
#elif __has_include(<LibWeb/HTML/HTMLMapElement.h>)
#    include <LibWeb/HTML/HTMLMapElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLMapElement.h>)
#    include <LibWeb/UIEvents/HTMLMapElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLMapElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLMapElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLMapElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLMapElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLMapElement.h>)
#    include <LibWeb/NavigationTiming/HTMLMapElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLMapElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLMapElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLMapElement.h>)
#    include <LibWeb/ResizeObserver/HTMLMapElement.h>
#elif __has_include(<LibWeb/SVG/HTMLMapElement.h>)
#    include <LibWeb/SVG/HTMLMapElement.h>
#elif __has_include(<LibWeb/Selection/HTMLMapElement.h>)
#    include <LibWeb/Selection/HTMLMapElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLMapElement.h>)
#    include <LibWeb/WebSockets/HTMLMapElement.h>
#elif __has_include(<LibWeb/XHR/HTMLMapElement.h>)
#    include <LibWeb/XHR/HTMLMapElement.h>
#elif __has_include(<LibWeb/URL/HTMLMapElement.h>)
#    include <LibWeb/URL/HTMLMapElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMapElement.h>

#include <LibWeb/HTML/HTMLMapElement.h>

#if __has_include(<LibWeb/Bindings/HTMLMapElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMapElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMapElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMapElementWrapperFactory.h>
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

HTMLMapElementConstructor::HTMLMapElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLMapElementConstructor::~HTMLMapElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLMapElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLMapElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLMapElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLMapElement");

}

void HTMLMapElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLMapElementPrototype>("HTMLMapElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

