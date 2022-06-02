
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLTitleElementConstructor.h>
#include <LibWeb/Bindings/HTMLTitleElementPrototype.h>
#include <LibWeb/Bindings/HTMLTitleElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLTitleElement.h>)
#    include <LibWeb/Crypto/HTMLTitleElement.h>
#elif __has_include(<LibWeb/CSS/HTMLTitleElement.h>)
#    include <LibWeb/CSS/HTMLTitleElement.h>
#elif __has_include(<LibWeb/DOM/HTMLTitleElement.h>)
#    include <LibWeb/DOM/HTMLTitleElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLTitleElement.h>)
#    include <LibWeb/Encoding/HTMLTitleElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLTitleElement.h>)
#    include <LibWeb/Geometry/HTMLTitleElement.h>
#elif __has_include(<LibWeb/HTML/HTMLTitleElement.h>)
#    include <LibWeb/HTML/HTMLTitleElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLTitleElement.h>)
#    include <LibWeb/UIEvents/HTMLTitleElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLTitleElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLTitleElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLTitleElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLTitleElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLTitleElement.h>)
#    include <LibWeb/NavigationTiming/HTMLTitleElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLTitleElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLTitleElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLTitleElement.h>)
#    include <LibWeb/ResizeObserver/HTMLTitleElement.h>
#elif __has_include(<LibWeb/SVG/HTMLTitleElement.h>)
#    include <LibWeb/SVG/HTMLTitleElement.h>
#elif __has_include(<LibWeb/Selection/HTMLTitleElement.h>)
#    include <LibWeb/Selection/HTMLTitleElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLTitleElement.h>)
#    include <LibWeb/WebSockets/HTMLTitleElement.h>
#elif __has_include(<LibWeb/XHR/HTMLTitleElement.h>)
#    include <LibWeb/XHR/HTMLTitleElement.h>
#elif __has_include(<LibWeb/URL/HTMLTitleElement.h>)
#    include <LibWeb/URL/HTMLTitleElement.h>
#endif


#include <LibWeb/HTML/HTMLTitleElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLTitleElement.h>

#if __has_include(<LibWeb/Bindings/HTMLTitleElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLTitleElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLTitleElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLTitleElementWrapperFactory.h>
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

HTMLTitleElementConstructor::HTMLTitleElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLTitleElementConstructor::~HTMLTitleElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLTitleElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLTitleElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLTitleElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLTitleElement");

}

void HTMLTitleElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLTitleElementPrototype>("HTMLTitleElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

