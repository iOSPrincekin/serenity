
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLBaseElementConstructor.h>
#include <LibWeb/Bindings/HTMLBaseElementPrototype.h>
#include <LibWeb/Bindings/HTMLBaseElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLBaseElement.h>)
#    include <LibWeb/Crypto/HTMLBaseElement.h>
#elif __has_include(<LibWeb/CSS/HTMLBaseElement.h>)
#    include <LibWeb/CSS/HTMLBaseElement.h>
#elif __has_include(<LibWeb/DOM/HTMLBaseElement.h>)
#    include <LibWeb/DOM/HTMLBaseElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLBaseElement.h>)
#    include <LibWeb/Encoding/HTMLBaseElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLBaseElement.h>)
#    include <LibWeb/Geometry/HTMLBaseElement.h>
#elif __has_include(<LibWeb/HTML/HTMLBaseElement.h>)
#    include <LibWeb/HTML/HTMLBaseElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLBaseElement.h>)
#    include <LibWeb/UIEvents/HTMLBaseElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLBaseElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLBaseElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLBaseElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLBaseElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLBaseElement.h>)
#    include <LibWeb/NavigationTiming/HTMLBaseElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLBaseElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLBaseElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLBaseElement.h>)
#    include <LibWeb/ResizeObserver/HTMLBaseElement.h>
#elif __has_include(<LibWeb/SVG/HTMLBaseElement.h>)
#    include <LibWeb/SVG/HTMLBaseElement.h>
#elif __has_include(<LibWeb/Selection/HTMLBaseElement.h>)
#    include <LibWeb/Selection/HTMLBaseElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLBaseElement.h>)
#    include <LibWeb/WebSockets/HTMLBaseElement.h>
#elif __has_include(<LibWeb/XHR/HTMLBaseElement.h>)
#    include <LibWeb/XHR/HTMLBaseElement.h>
#elif __has_include(<LibWeb/URL/HTMLBaseElement.h>)
#    include <LibWeb/URL/HTMLBaseElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLBaseElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLBaseElement.h>

#if __has_include(<LibWeb/Bindings/HTMLBaseElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLBaseElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLBaseElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLBaseElementWrapperFactory.h>
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

HTMLBaseElementConstructor::HTMLBaseElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLBaseElementConstructor::~HTMLBaseElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLBaseElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLBaseElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLBaseElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLBaseElement");

}

void HTMLBaseElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLBaseElementPrototype>("HTMLBaseElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

