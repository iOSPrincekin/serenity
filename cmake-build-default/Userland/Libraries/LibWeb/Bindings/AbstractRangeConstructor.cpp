
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/AbstractRangeConstructor.h>
#include <LibWeb/Bindings/AbstractRangePrototype.h>
#include <LibWeb/Bindings/AbstractRangeWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/AbstractRange.h>)
#    include <LibWeb/Crypto/AbstractRange.h>
#elif __has_include(<LibWeb/CSS/AbstractRange.h>)
#    include <LibWeb/CSS/AbstractRange.h>
#elif __has_include(<LibWeb/DOM/AbstractRange.h>)
#    include <LibWeb/DOM/AbstractRange.h>
#elif __has_include(<LibWeb/Encoding/AbstractRange.h>)
#    include <LibWeb/Encoding/AbstractRange.h>
#elif __has_include(<LibWeb/Geometry/AbstractRange.h>)
#    include <LibWeb/Geometry/AbstractRange.h>
#elif __has_include(<LibWeb/HTML/AbstractRange.h>)
#    include <LibWeb/HTML/AbstractRange.h>
#elif __has_include(<LibWeb/UIEvents/AbstractRange.h>)
#    include <LibWeb/UIEvents/AbstractRange.h>
#elif __has_include(<LibWeb/HighResolutionTime/AbstractRange.h>)
#    include <LibWeb/HighResolutionTime/AbstractRange.h>
#elif __has_include(<LibWeb/IntersectionObserver/AbstractRange.h>)
#    include <LibWeb/IntersectionObserver/AbstractRange.h>
#elif __has_include(<LibWeb/NavigationTiming/AbstractRange.h>)
#    include <LibWeb/NavigationTiming/AbstractRange.h>
#elif __has_include(<LibWeb/RequestIdleCallback/AbstractRange.h>)
#    include <LibWeb/RequestIdleCallback/AbstractRange.h>
#elif __has_include(<LibWeb/ResizeObserver/AbstractRange.h>)
#    include <LibWeb/ResizeObserver/AbstractRange.h>
#elif __has_include(<LibWeb/SVG/AbstractRange.h>)
#    include <LibWeb/SVG/AbstractRange.h>
#elif __has_include(<LibWeb/Selection/AbstractRange.h>)
#    include <LibWeb/Selection/AbstractRange.h>
#elif __has_include(<LibWeb/WebSockets/AbstractRange.h>)
#    include <LibWeb/WebSockets/AbstractRange.h>
#elif __has_include(<LibWeb/XHR/AbstractRange.h>)
#    include <LibWeb/XHR/AbstractRange.h>
#elif __has_include(<LibWeb/URL/AbstractRange.h>)
#    include <LibWeb/URL/AbstractRange.h>
#endif


#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/DOM/AbstractRange.h>

#if __has_include(<LibWeb/Bindings/AbstractRangeWrapper.h>)
#   include <LibWeb/Bindings/AbstractRangeWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbstractRangeWrapperFactory.h>)
#   include <LibWeb/Bindings/AbstractRangeWrapperFactory.h>
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

AbstractRangeConstructor::AbstractRangeConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

AbstractRangeConstructor::~AbstractRangeConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> AbstractRangeConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "AbstractRange");
}

JS::ThrowCompletionOr<JS::Object*> AbstractRangeConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "AbstractRange");

}

void AbstractRangeConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<AbstractRangePrototype>("AbstractRange"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

