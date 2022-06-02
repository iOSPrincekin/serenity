
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLFieldSetElementConstructor.h>
#include <LibWeb/Bindings/HTMLFieldSetElementPrototype.h>
#include <LibWeb/Bindings/HTMLFieldSetElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLFieldSetElement.h>)
#    include <LibWeb/Crypto/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/CSS/HTMLFieldSetElement.h>)
#    include <LibWeb/CSS/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/DOM/HTMLFieldSetElement.h>)
#    include <LibWeb/DOM/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLFieldSetElement.h>)
#    include <LibWeb/Encoding/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLFieldSetElement.h>)
#    include <LibWeb/Geometry/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/HTML/HTMLFieldSetElement.h>)
#    include <LibWeb/HTML/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLFieldSetElement.h>)
#    include <LibWeb/UIEvents/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLFieldSetElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLFieldSetElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLFieldSetElement.h>)
#    include <LibWeb/NavigationTiming/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLFieldSetElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLFieldSetElement.h>)
#    include <LibWeb/ResizeObserver/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/SVG/HTMLFieldSetElement.h>)
#    include <LibWeb/SVG/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/Selection/HTMLFieldSetElement.h>)
#    include <LibWeb/Selection/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLFieldSetElement.h>)
#    include <LibWeb/WebSockets/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/XHR/HTMLFieldSetElement.h>)
#    include <LibWeb/XHR/HTMLFieldSetElement.h>
#elif __has_include(<LibWeb/URL/HTMLFieldSetElement.h>)
#    include <LibWeb/URL/HTMLFieldSetElement.h>
#endif


#include <LibWeb/HTML/HTMLFieldSetElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLFieldSetElement.h>

#if __has_include(<LibWeb/Bindings/HTMLFieldSetElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLFieldSetElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLFieldSetElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLFieldSetElementWrapperFactory.h>
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

HTMLFieldSetElementConstructor::HTMLFieldSetElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLFieldSetElementConstructor::~HTMLFieldSetElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLFieldSetElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLFieldSetElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLFieldSetElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLFieldSetElement");

}

void HTMLFieldSetElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLFieldSetElementPrototype>("HTMLFieldSetElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

