
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLDirectoryElementConstructor.h>
#include <LibWeb/Bindings/HTMLDirectoryElementPrototype.h>
#include <LibWeb/Bindings/HTMLDirectoryElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLDirectoryElement.h>)
#    include <LibWeb/Crypto/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/CSS/HTMLDirectoryElement.h>)
#    include <LibWeb/CSS/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/DOM/HTMLDirectoryElement.h>)
#    include <LibWeb/DOM/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLDirectoryElement.h>)
#    include <LibWeb/Encoding/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLDirectoryElement.h>)
#    include <LibWeb/Geometry/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/HTML/HTMLDirectoryElement.h>)
#    include <LibWeb/HTML/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLDirectoryElement.h>)
#    include <LibWeb/UIEvents/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLDirectoryElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLDirectoryElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLDirectoryElement.h>)
#    include <LibWeb/NavigationTiming/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLDirectoryElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLDirectoryElement.h>)
#    include <LibWeb/ResizeObserver/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/SVG/HTMLDirectoryElement.h>)
#    include <LibWeb/SVG/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/Selection/HTMLDirectoryElement.h>)
#    include <LibWeb/Selection/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLDirectoryElement.h>)
#    include <LibWeb/WebSockets/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/XHR/HTMLDirectoryElement.h>)
#    include <LibWeb/XHR/HTMLDirectoryElement.h>
#elif __has_include(<LibWeb/URL/HTMLDirectoryElement.h>)
#    include <LibWeb/URL/HTMLDirectoryElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLDirectoryElement.h>

#include <LibWeb/HTML/HTMLDirectoryElement.h>

#if __has_include(<LibWeb/Bindings/HTMLDirectoryElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLDirectoryElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLDirectoryElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLDirectoryElementWrapperFactory.h>
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

HTMLDirectoryElementConstructor::HTMLDirectoryElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLDirectoryElementConstructor::~HTMLDirectoryElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLDirectoryElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLDirectoryElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLDirectoryElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLDirectoryElement");

}

void HTMLDirectoryElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLDirectoryElementPrototype>("HTMLDirectoryElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

