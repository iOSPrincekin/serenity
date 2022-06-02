
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLMarqueeElementConstructor.h>
#include <LibWeb/Bindings/HTMLMarqueeElementPrototype.h>
#include <LibWeb/Bindings/HTMLMarqueeElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLMarqueeElement.h>)
#    include <LibWeb/Crypto/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/CSS/HTMLMarqueeElement.h>)
#    include <LibWeb/CSS/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/DOM/HTMLMarqueeElement.h>)
#    include <LibWeb/DOM/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLMarqueeElement.h>)
#    include <LibWeb/Encoding/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLMarqueeElement.h>)
#    include <LibWeb/Geometry/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/HTML/HTMLMarqueeElement.h>)
#    include <LibWeb/HTML/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLMarqueeElement.h>)
#    include <LibWeb/UIEvents/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLMarqueeElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLMarqueeElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLMarqueeElement.h>)
#    include <LibWeb/NavigationTiming/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLMarqueeElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLMarqueeElement.h>)
#    include <LibWeb/ResizeObserver/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/SVG/HTMLMarqueeElement.h>)
#    include <LibWeb/SVG/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/Selection/HTMLMarqueeElement.h>)
#    include <LibWeb/Selection/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLMarqueeElement.h>)
#    include <LibWeb/WebSockets/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/XHR/HTMLMarqueeElement.h>)
#    include <LibWeb/XHR/HTMLMarqueeElement.h>
#elif __has_include(<LibWeb/URL/HTMLMarqueeElement.h>)
#    include <LibWeb/URL/HTMLMarqueeElement.h>
#endif


#include <LibWeb/HTML/HTMLMarqueeElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMarqueeElement.h>

#if __has_include(<LibWeb/Bindings/HTMLMarqueeElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMarqueeElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMarqueeElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMarqueeElementWrapperFactory.h>
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

HTMLMarqueeElementConstructor::HTMLMarqueeElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLMarqueeElementConstructor::~HTMLMarqueeElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLMarqueeElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLMarqueeElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLMarqueeElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLMarqueeElement");

}

void HTMLMarqueeElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLMarqueeElementPrototype>("HTMLMarqueeElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

