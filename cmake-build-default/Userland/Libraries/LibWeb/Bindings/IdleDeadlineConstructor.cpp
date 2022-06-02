
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/IdleDeadlineConstructor.h>
#include <LibWeb/Bindings/IdleDeadlinePrototype.h>
#include <LibWeb/Bindings/IdleDeadlineWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/IdleDeadline.h>)
#    include <LibWeb/Crypto/IdleDeadline.h>
#elif __has_include(<LibWeb/CSS/IdleDeadline.h>)
#    include <LibWeb/CSS/IdleDeadline.h>
#elif __has_include(<LibWeb/DOM/IdleDeadline.h>)
#    include <LibWeb/DOM/IdleDeadline.h>
#elif __has_include(<LibWeb/Encoding/IdleDeadline.h>)
#    include <LibWeb/Encoding/IdleDeadline.h>
#elif __has_include(<LibWeb/Geometry/IdleDeadline.h>)
#    include <LibWeb/Geometry/IdleDeadline.h>
#elif __has_include(<LibWeb/HTML/IdleDeadline.h>)
#    include <LibWeb/HTML/IdleDeadline.h>
#elif __has_include(<LibWeb/UIEvents/IdleDeadline.h>)
#    include <LibWeb/UIEvents/IdleDeadline.h>
#elif __has_include(<LibWeb/HighResolutionTime/IdleDeadline.h>)
#    include <LibWeb/HighResolutionTime/IdleDeadline.h>
#elif __has_include(<LibWeb/IntersectionObserver/IdleDeadline.h>)
#    include <LibWeb/IntersectionObserver/IdleDeadline.h>
#elif __has_include(<LibWeb/NavigationTiming/IdleDeadline.h>)
#    include <LibWeb/NavigationTiming/IdleDeadline.h>
#elif __has_include(<LibWeb/RequestIdleCallback/IdleDeadline.h>)
#    include <LibWeb/RequestIdleCallback/IdleDeadline.h>
#elif __has_include(<LibWeb/ResizeObserver/IdleDeadline.h>)
#    include <LibWeb/ResizeObserver/IdleDeadline.h>
#elif __has_include(<LibWeb/SVG/IdleDeadline.h>)
#    include <LibWeb/SVG/IdleDeadline.h>
#elif __has_include(<LibWeb/Selection/IdleDeadline.h>)
#    include <LibWeb/Selection/IdleDeadline.h>
#elif __has_include(<LibWeb/WebSockets/IdleDeadline.h>)
#    include <LibWeb/WebSockets/IdleDeadline.h>
#elif __has_include(<LibWeb/XHR/IdleDeadline.h>)
#    include <LibWeb/XHR/IdleDeadline.h>
#elif __has_include(<LibWeb/URL/IdleDeadline.h>)
#    include <LibWeb/URL/IdleDeadline.h>
#endif


#include <LibWeb/RequestIdleCallback/IdleDeadline.h>

#include <LibWeb/RequestIdleCallback/IdleDeadline.h>

#if __has_include(<LibWeb/Bindings/IdleDeadlineWrapper.h>)
#   include <LibWeb/Bindings/IdleDeadlineWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/IdleDeadlineWrapperFactory.h>)
#   include <LibWeb/Bindings/IdleDeadlineWrapperFactory.h>
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

IdleDeadlineConstructor::IdleDeadlineConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

IdleDeadlineConstructor::~IdleDeadlineConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> IdleDeadlineConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "IdleDeadline");
}

JS::ThrowCompletionOr<JS::Object*> IdleDeadlineConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "IdleDeadline");

}

void IdleDeadlineConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<IdleDeadlinePrototype>("IdleDeadline"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

