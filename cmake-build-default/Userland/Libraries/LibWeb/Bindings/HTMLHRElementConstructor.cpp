
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLHRElementConstructor.h>
#include <LibWeb/Bindings/HTMLHRElementPrototype.h>
#include <LibWeb/Bindings/HTMLHRElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLHRElement.h>)
#    include <LibWeb/Crypto/HTMLHRElement.h>
#elif __has_include(<LibWeb/CSS/HTMLHRElement.h>)
#    include <LibWeb/CSS/HTMLHRElement.h>
#elif __has_include(<LibWeb/DOM/HTMLHRElement.h>)
#    include <LibWeb/DOM/HTMLHRElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLHRElement.h>)
#    include <LibWeb/Encoding/HTMLHRElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLHRElement.h>)
#    include <LibWeb/Geometry/HTMLHRElement.h>
#elif __has_include(<LibWeb/HTML/HTMLHRElement.h>)
#    include <LibWeb/HTML/HTMLHRElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLHRElement.h>)
#    include <LibWeb/UIEvents/HTMLHRElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLHRElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLHRElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLHRElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLHRElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLHRElement.h>)
#    include <LibWeb/NavigationTiming/HTMLHRElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLHRElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLHRElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLHRElement.h>)
#    include <LibWeb/ResizeObserver/HTMLHRElement.h>
#elif __has_include(<LibWeb/SVG/HTMLHRElement.h>)
#    include <LibWeb/SVG/HTMLHRElement.h>
#elif __has_include(<LibWeb/Selection/HTMLHRElement.h>)
#    include <LibWeb/Selection/HTMLHRElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLHRElement.h>)
#    include <LibWeb/WebSockets/HTMLHRElement.h>
#elif __has_include(<LibWeb/XHR/HTMLHRElement.h>)
#    include <LibWeb/XHR/HTMLHRElement.h>
#elif __has_include(<LibWeb/URL/HTMLHRElement.h>)
#    include <LibWeb/URL/HTMLHRElement.h>
#endif


#include <LibWeb/HTML/HTMLHRElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLHRElement.h>

#if __has_include(<LibWeb/Bindings/HTMLHRElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLHRElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLHRElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLHRElementWrapperFactory.h>
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

HTMLHRElementConstructor::HTMLHRElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLHRElementConstructor::~HTMLHRElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLHRElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLHRElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLHRElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLHRElement");

}

void HTMLHRElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLHRElementPrototype>("HTMLHRElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

