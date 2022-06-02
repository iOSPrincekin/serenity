
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLTableCellElementConstructor.h>
#include <LibWeb/Bindings/HTMLTableCellElementPrototype.h>
#include <LibWeb/Bindings/HTMLTableCellElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLTableCellElement.h>)
#    include <LibWeb/Crypto/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/CSS/HTMLTableCellElement.h>)
#    include <LibWeb/CSS/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/DOM/HTMLTableCellElement.h>)
#    include <LibWeb/DOM/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLTableCellElement.h>)
#    include <LibWeb/Encoding/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLTableCellElement.h>)
#    include <LibWeb/Geometry/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/HTML/HTMLTableCellElement.h>)
#    include <LibWeb/HTML/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLTableCellElement.h>)
#    include <LibWeb/UIEvents/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLTableCellElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLTableCellElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLTableCellElement.h>)
#    include <LibWeb/NavigationTiming/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLTableCellElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLTableCellElement.h>)
#    include <LibWeb/ResizeObserver/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/SVG/HTMLTableCellElement.h>)
#    include <LibWeb/SVG/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/Selection/HTMLTableCellElement.h>)
#    include <LibWeb/Selection/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLTableCellElement.h>)
#    include <LibWeb/WebSockets/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/XHR/HTMLTableCellElement.h>)
#    include <LibWeb/XHR/HTMLTableCellElement.h>
#elif __has_include(<LibWeb/URL/HTMLTableCellElement.h>)
#    include <LibWeb/URL/HTMLTableCellElement.h>
#endif


#include <LibWeb/HTML/HTMLTableCellElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLTableCellElement.h>

#if __has_include(<LibWeb/Bindings/HTMLTableCellElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLTableCellElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLTableCellElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLTableCellElementWrapperFactory.h>
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

HTMLTableCellElementConstructor::HTMLTableCellElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLTableCellElementConstructor::~HTMLTableCellElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLTableCellElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLTableCellElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLTableCellElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLTableCellElement");

}

void HTMLTableCellElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLTableCellElementPrototype>("HTMLTableCellElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

