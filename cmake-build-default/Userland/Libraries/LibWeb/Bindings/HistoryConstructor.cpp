
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HistoryConstructor.h>
#include <LibWeb/Bindings/HistoryPrototype.h>
#include <LibWeb/Bindings/HistoryWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/History.h>)
#    include <LibWeb/Crypto/History.h>
#elif __has_include(<LibWeb/CSS/History.h>)
#    include <LibWeb/CSS/History.h>
#elif __has_include(<LibWeb/DOM/History.h>)
#    include <LibWeb/DOM/History.h>
#elif __has_include(<LibWeb/Encoding/History.h>)
#    include <LibWeb/Encoding/History.h>
#elif __has_include(<LibWeb/Geometry/History.h>)
#    include <LibWeb/Geometry/History.h>
#elif __has_include(<LibWeb/HTML/History.h>)
#    include <LibWeb/HTML/History.h>
#elif __has_include(<LibWeb/UIEvents/History.h>)
#    include <LibWeb/UIEvents/History.h>
#elif __has_include(<LibWeb/HighResolutionTime/History.h>)
#    include <LibWeb/HighResolutionTime/History.h>
#elif __has_include(<LibWeb/IntersectionObserver/History.h>)
#    include <LibWeb/IntersectionObserver/History.h>
#elif __has_include(<LibWeb/NavigationTiming/History.h>)
#    include <LibWeb/NavigationTiming/History.h>
#elif __has_include(<LibWeb/RequestIdleCallback/History.h>)
#    include <LibWeb/RequestIdleCallback/History.h>
#elif __has_include(<LibWeb/ResizeObserver/History.h>)
#    include <LibWeb/ResizeObserver/History.h>
#elif __has_include(<LibWeb/SVG/History.h>)
#    include <LibWeb/SVG/History.h>
#elif __has_include(<LibWeb/Selection/History.h>)
#    include <LibWeb/Selection/History.h>
#elif __has_include(<LibWeb/WebSockets/History.h>)
#    include <LibWeb/WebSockets/History.h>
#elif __has_include(<LibWeb/XHR/History.h>)
#    include <LibWeb/XHR/History.h>
#elif __has_include(<LibWeb/URL/History.h>)
#    include <LibWeb/URL/History.h>
#endif


#include <LibWeb/HTML/History.h>

#include <LibWeb/HTML/History.h>

#if __has_include(<LibWeb/Bindings/HistoryWrapper.h>)
#   include <LibWeb/Bindings/HistoryWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HistoryWrapperFactory.h>)
#   include <LibWeb/Bindings/HistoryWrapperFactory.h>
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

HistoryConstructor::HistoryConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HistoryConstructor::~HistoryConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HistoryConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "History");
}

JS::ThrowCompletionOr<JS::Object*> HistoryConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "History");

}

void HistoryConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HistoryPrototype>("History"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

