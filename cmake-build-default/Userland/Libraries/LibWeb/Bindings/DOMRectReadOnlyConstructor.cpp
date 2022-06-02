
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/DOMRectReadOnlyConstructor.h>
#include <LibWeb/Bindings/DOMRectReadOnlyPrototype.h>
#include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/DOMRectReadOnly.h>)
#    include <LibWeb/Crypto/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/CSS/DOMRectReadOnly.h>)
#    include <LibWeb/CSS/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/DOM/DOMRectReadOnly.h>)
#    include <LibWeb/DOM/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/Encoding/DOMRectReadOnly.h>)
#    include <LibWeb/Encoding/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/Geometry/DOMRectReadOnly.h>)
#    include <LibWeb/Geometry/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/HTML/DOMRectReadOnly.h>)
#    include <LibWeb/HTML/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/UIEvents/DOMRectReadOnly.h>)
#    include <LibWeb/UIEvents/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/HighResolutionTime/DOMRectReadOnly.h>)
#    include <LibWeb/HighResolutionTime/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/IntersectionObserver/DOMRectReadOnly.h>)
#    include <LibWeb/IntersectionObserver/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/NavigationTiming/DOMRectReadOnly.h>)
#    include <LibWeb/NavigationTiming/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/RequestIdleCallback/DOMRectReadOnly.h>)
#    include <LibWeb/RequestIdleCallback/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/ResizeObserver/DOMRectReadOnly.h>)
#    include <LibWeb/ResizeObserver/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/SVG/DOMRectReadOnly.h>)
#    include <LibWeb/SVG/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/Selection/DOMRectReadOnly.h>)
#    include <LibWeb/Selection/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/WebSockets/DOMRectReadOnly.h>)
#    include <LibWeb/WebSockets/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/XHR/DOMRectReadOnly.h>)
#    include <LibWeb/XHR/DOMRectReadOnly.h>
#elif __has_include(<LibWeb/URL/DOMRectReadOnly.h>)
#    include <LibWeb/URL/DOMRectReadOnly.h>
#endif


#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapper.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>
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

DOMRectReadOnlyConstructor::DOMRectReadOnlyConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

DOMRectReadOnlyConstructor::~DOMRectReadOnlyConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> DOMRectReadOnlyConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "DOMRectReadOnly");
}

JS::ThrowCompletionOr<JS::Object*> DOMRectReadOnlyConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    auto arg0 = vm.argument(0);

    double x;

    if (!arg0.is_undefined())
        x = TRY(arg0.to_double(global_object));

    else
        x = 0;

    auto arg1 = vm.argument(1);

    double y;

    if (!arg1.is_undefined())
        y = TRY(arg1.to_double(global_object));

    else
        y = 0;

    auto arg2 = vm.argument(2);

    double width;

    if (!arg2.is_undefined())
        width = TRY(arg2.to_double(global_object));

    else
        width = 0;

    auto arg3 = vm.argument(3);

    double height;

    if (!arg3.is_undefined())
        height = TRY(arg3.to_double(global_object));

    else
        height = 0;

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return Geometry::DOMRectReadOnly::create_with_global_object(window, x, y, width, height); }));

    return wrap(global_object, *impl);

}

void DOMRectReadOnlyConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<DOMRectReadOnlyPrototype>("DOMRectReadOnly"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

