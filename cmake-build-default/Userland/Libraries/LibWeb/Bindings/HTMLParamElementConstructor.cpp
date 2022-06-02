
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLParamElementConstructor.h>
#include <LibWeb/Bindings/HTMLParamElementPrototype.h>
#include <LibWeb/Bindings/HTMLParamElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLParamElement.h>)
#    include <LibWeb/Crypto/HTMLParamElement.h>
#elif __has_include(<LibWeb/CSS/HTMLParamElement.h>)
#    include <LibWeb/CSS/HTMLParamElement.h>
#elif __has_include(<LibWeb/DOM/HTMLParamElement.h>)
#    include <LibWeb/DOM/HTMLParamElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLParamElement.h>)
#    include <LibWeb/Encoding/HTMLParamElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLParamElement.h>)
#    include <LibWeb/Geometry/HTMLParamElement.h>
#elif __has_include(<LibWeb/HTML/HTMLParamElement.h>)
#    include <LibWeb/HTML/HTMLParamElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLParamElement.h>)
#    include <LibWeb/UIEvents/HTMLParamElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLParamElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLParamElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLParamElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLParamElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLParamElement.h>)
#    include <LibWeb/NavigationTiming/HTMLParamElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLParamElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLParamElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLParamElement.h>)
#    include <LibWeb/ResizeObserver/HTMLParamElement.h>
#elif __has_include(<LibWeb/SVG/HTMLParamElement.h>)
#    include <LibWeb/SVG/HTMLParamElement.h>
#elif __has_include(<LibWeb/Selection/HTMLParamElement.h>)
#    include <LibWeb/Selection/HTMLParamElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLParamElement.h>)
#    include <LibWeb/WebSockets/HTMLParamElement.h>
#elif __has_include(<LibWeb/XHR/HTMLParamElement.h>)
#    include <LibWeb/XHR/HTMLParamElement.h>
#elif __has_include(<LibWeb/URL/HTMLParamElement.h>)
#    include <LibWeb/URL/HTMLParamElement.h>
#endif


#include <LibWeb/HTML/HTMLParamElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLParamElement.h>

#if __has_include(<LibWeb/Bindings/HTMLParamElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLParamElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLParamElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLParamElementWrapperFactory.h>
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

HTMLParamElementConstructor::HTMLParamElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLParamElementConstructor::~HTMLParamElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLParamElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLParamElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLParamElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLParamElement");

}

void HTMLParamElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLParamElementPrototype>("HTMLParamElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

