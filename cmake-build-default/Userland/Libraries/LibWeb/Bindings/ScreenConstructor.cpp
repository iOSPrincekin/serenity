
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/ScreenConstructor.h>
#include <LibWeb/Bindings/ScreenPrototype.h>
#include <LibWeb/Bindings/ScreenWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/Screen.h>)
#    include <LibWeb/Crypto/Screen.h>
#elif __has_include(<LibWeb/CSS/Screen.h>)
#    include <LibWeb/CSS/Screen.h>
#elif __has_include(<LibWeb/DOM/Screen.h>)
#    include <LibWeb/DOM/Screen.h>
#elif __has_include(<LibWeb/Encoding/Screen.h>)
#    include <LibWeb/Encoding/Screen.h>
#elif __has_include(<LibWeb/Geometry/Screen.h>)
#    include <LibWeb/Geometry/Screen.h>
#elif __has_include(<LibWeb/HTML/Screen.h>)
#    include <LibWeb/HTML/Screen.h>
#elif __has_include(<LibWeb/UIEvents/Screen.h>)
#    include <LibWeb/UIEvents/Screen.h>
#elif __has_include(<LibWeb/HighResolutionTime/Screen.h>)
#    include <LibWeb/HighResolutionTime/Screen.h>
#elif __has_include(<LibWeb/IntersectionObserver/Screen.h>)
#    include <LibWeb/IntersectionObserver/Screen.h>
#elif __has_include(<LibWeb/NavigationTiming/Screen.h>)
#    include <LibWeb/NavigationTiming/Screen.h>
#elif __has_include(<LibWeb/RequestIdleCallback/Screen.h>)
#    include <LibWeb/RequestIdleCallback/Screen.h>
#elif __has_include(<LibWeb/ResizeObserver/Screen.h>)
#    include <LibWeb/ResizeObserver/Screen.h>
#elif __has_include(<LibWeb/SVG/Screen.h>)
#    include <LibWeb/SVG/Screen.h>
#elif __has_include(<LibWeb/Selection/Screen.h>)
#    include <LibWeb/Selection/Screen.h>
#elif __has_include(<LibWeb/WebSockets/Screen.h>)
#    include <LibWeb/WebSockets/Screen.h>
#elif __has_include(<LibWeb/XHR/Screen.h>)
#    include <LibWeb/XHR/Screen.h>
#elif __has_include(<LibWeb/URL/Screen.h>)
#    include <LibWeb/URL/Screen.h>
#endif


#include <LibWeb/CSS/Screen.h>

#include <LibWeb/CSS/Screen.h>

#if __has_include(<LibWeb/Bindings/ScreenWrapper.h>)
#   include <LibWeb/Bindings/ScreenWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ScreenWrapperFactory.h>)
#   include <LibWeb/Bindings/ScreenWrapperFactory.h>
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

ScreenConstructor::ScreenConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

ScreenConstructor::~ScreenConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> ScreenConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "Screen");
}

JS::ThrowCompletionOr<JS::Object*> ScreenConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "Screen");

}

void ScreenConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<ScreenPrototype>("Screen"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

