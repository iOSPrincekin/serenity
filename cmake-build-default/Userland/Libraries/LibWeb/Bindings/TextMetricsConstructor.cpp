
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/TextMetricsConstructor.h>
#include <LibWeb/Bindings/TextMetricsPrototype.h>
#include <LibWeb/Bindings/TextMetricsWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/TextMetrics.h>)
#    include <LibWeb/Crypto/TextMetrics.h>
#elif __has_include(<LibWeb/CSS/TextMetrics.h>)
#    include <LibWeb/CSS/TextMetrics.h>
#elif __has_include(<LibWeb/DOM/TextMetrics.h>)
#    include <LibWeb/DOM/TextMetrics.h>
#elif __has_include(<LibWeb/Encoding/TextMetrics.h>)
#    include <LibWeb/Encoding/TextMetrics.h>
#elif __has_include(<LibWeb/Geometry/TextMetrics.h>)
#    include <LibWeb/Geometry/TextMetrics.h>
#elif __has_include(<LibWeb/HTML/TextMetrics.h>)
#    include <LibWeb/HTML/TextMetrics.h>
#elif __has_include(<LibWeb/UIEvents/TextMetrics.h>)
#    include <LibWeb/UIEvents/TextMetrics.h>
#elif __has_include(<LibWeb/HighResolutionTime/TextMetrics.h>)
#    include <LibWeb/HighResolutionTime/TextMetrics.h>
#elif __has_include(<LibWeb/IntersectionObserver/TextMetrics.h>)
#    include <LibWeb/IntersectionObserver/TextMetrics.h>
#elif __has_include(<LibWeb/NavigationTiming/TextMetrics.h>)
#    include <LibWeb/NavigationTiming/TextMetrics.h>
#elif __has_include(<LibWeb/RequestIdleCallback/TextMetrics.h>)
#    include <LibWeb/RequestIdleCallback/TextMetrics.h>
#elif __has_include(<LibWeb/ResizeObserver/TextMetrics.h>)
#    include <LibWeb/ResizeObserver/TextMetrics.h>
#elif __has_include(<LibWeb/SVG/TextMetrics.h>)
#    include <LibWeb/SVG/TextMetrics.h>
#elif __has_include(<LibWeb/Selection/TextMetrics.h>)
#    include <LibWeb/Selection/TextMetrics.h>
#elif __has_include(<LibWeb/WebSockets/TextMetrics.h>)
#    include <LibWeb/WebSockets/TextMetrics.h>
#elif __has_include(<LibWeb/XHR/TextMetrics.h>)
#    include <LibWeb/XHR/TextMetrics.h>
#elif __has_include(<LibWeb/URL/TextMetrics.h>)
#    include <LibWeb/URL/TextMetrics.h>
#endif


#include <LibWeb/HTML/TextMetrics.h>

#include <LibWeb/HTML/TextMetrics.h>

#if __has_include(<LibWeb/Bindings/TextMetricsWrapper.h>)
#   include <LibWeb/Bindings/TextMetricsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TextMetricsWrapperFactory.h>)
#   include <LibWeb/Bindings/TextMetricsWrapperFactory.h>
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

TextMetricsConstructor::TextMetricsConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

TextMetricsConstructor::~TextMetricsConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> TextMetricsConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "TextMetrics");
}

JS::ThrowCompletionOr<JS::Object*> TextMetricsConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "TextMetrics");

}

void TextMetricsConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<TextMetricsPrototype>("TextMetrics"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

