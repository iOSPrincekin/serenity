
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLDialogElementConstructor.h>
#include <LibWeb/Bindings/HTMLDialogElementPrototype.h>
#include <LibWeb/Bindings/HTMLDialogElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLDialogElement.h>)
#    include <LibWeb/Crypto/HTMLDialogElement.h>
#elif __has_include(<LibWeb/CSS/HTMLDialogElement.h>)
#    include <LibWeb/CSS/HTMLDialogElement.h>
#elif __has_include(<LibWeb/DOM/HTMLDialogElement.h>)
#    include <LibWeb/DOM/HTMLDialogElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLDialogElement.h>)
#    include <LibWeb/Encoding/HTMLDialogElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLDialogElement.h>)
#    include <LibWeb/Geometry/HTMLDialogElement.h>
#elif __has_include(<LibWeb/HTML/HTMLDialogElement.h>)
#    include <LibWeb/HTML/HTMLDialogElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLDialogElement.h>)
#    include <LibWeb/UIEvents/HTMLDialogElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLDialogElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLDialogElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLDialogElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLDialogElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLDialogElement.h>)
#    include <LibWeb/NavigationTiming/HTMLDialogElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLDialogElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLDialogElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLDialogElement.h>)
#    include <LibWeb/ResizeObserver/HTMLDialogElement.h>
#elif __has_include(<LibWeb/SVG/HTMLDialogElement.h>)
#    include <LibWeb/SVG/HTMLDialogElement.h>
#elif __has_include(<LibWeb/Selection/HTMLDialogElement.h>)
#    include <LibWeb/Selection/HTMLDialogElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLDialogElement.h>)
#    include <LibWeb/WebSockets/HTMLDialogElement.h>
#elif __has_include(<LibWeb/XHR/HTMLDialogElement.h>)
#    include <LibWeb/XHR/HTMLDialogElement.h>
#elif __has_include(<LibWeb/URL/HTMLDialogElement.h>)
#    include <LibWeb/URL/HTMLDialogElement.h>
#endif


#include <LibWeb/HTML/HTMLDialogElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLDialogElement.h>

#if __has_include(<LibWeb/Bindings/HTMLDialogElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLDialogElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLDialogElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLDialogElementWrapperFactory.h>
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

HTMLDialogElementConstructor::HTMLDialogElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLDialogElementConstructor::~HTMLDialogElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLDialogElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLDialogElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLDialogElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLDialogElement");

}

void HTMLDialogElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLDialogElementPrototype>("HTMLDialogElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

