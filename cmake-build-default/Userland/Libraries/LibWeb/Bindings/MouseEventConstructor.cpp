
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/MouseEventConstructor.h>
#include <LibWeb/Bindings/MouseEventPrototype.h>
#include <LibWeb/Bindings/MouseEventWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/MouseEvent.h>)
#    include <LibWeb/Crypto/MouseEvent.h>
#elif __has_include(<LibWeb/CSS/MouseEvent.h>)
#    include <LibWeb/CSS/MouseEvent.h>
#elif __has_include(<LibWeb/DOM/MouseEvent.h>)
#    include <LibWeb/DOM/MouseEvent.h>
#elif __has_include(<LibWeb/Encoding/MouseEvent.h>)
#    include <LibWeb/Encoding/MouseEvent.h>
#elif __has_include(<LibWeb/Geometry/MouseEvent.h>)
#    include <LibWeb/Geometry/MouseEvent.h>
#elif __has_include(<LibWeb/HTML/MouseEvent.h>)
#    include <LibWeb/HTML/MouseEvent.h>
#elif __has_include(<LibWeb/UIEvents/MouseEvent.h>)
#    include <LibWeb/UIEvents/MouseEvent.h>
#elif __has_include(<LibWeb/HighResolutionTime/MouseEvent.h>)
#    include <LibWeb/HighResolutionTime/MouseEvent.h>
#elif __has_include(<LibWeb/IntersectionObserver/MouseEvent.h>)
#    include <LibWeb/IntersectionObserver/MouseEvent.h>
#elif __has_include(<LibWeb/NavigationTiming/MouseEvent.h>)
#    include <LibWeb/NavigationTiming/MouseEvent.h>
#elif __has_include(<LibWeb/RequestIdleCallback/MouseEvent.h>)
#    include <LibWeb/RequestIdleCallback/MouseEvent.h>
#elif __has_include(<LibWeb/ResizeObserver/MouseEvent.h>)
#    include <LibWeb/ResizeObserver/MouseEvent.h>
#elif __has_include(<LibWeb/SVG/MouseEvent.h>)
#    include <LibWeb/SVG/MouseEvent.h>
#elif __has_include(<LibWeb/Selection/MouseEvent.h>)
#    include <LibWeb/Selection/MouseEvent.h>
#elif __has_include(<LibWeb/WebSockets/MouseEvent.h>)
#    include <LibWeb/WebSockets/MouseEvent.h>
#elif __has_include(<LibWeb/XHR/MouseEvent.h>)
#    include <LibWeb/XHR/MouseEvent.h>
#elif __has_include(<LibWeb/URL/MouseEvent.h>)
#    include <LibWeb/URL/MouseEvent.h>
#endif


#include <LibWeb/UIEvents/MouseEvent.h>

#include <LibWeb/UIEvents/MouseEvent.h>

#if __has_include(<LibWeb/Bindings/MouseEventWrapper.h>)
#   include <LibWeb/Bindings/MouseEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/MouseEventWrapperFactory.h>)
#   include <LibWeb/Bindings/MouseEventWrapperFactory.h>
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

MouseEventConstructor::MouseEventConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

MouseEventConstructor::~MouseEventConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> MouseEventConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "MouseEvent");
}

JS::ThrowCompletionOr<JS::Object*> MouseEventConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "MouseEvent");

}

void MouseEventConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<MouseEventPrototype>("MouseEvent"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

