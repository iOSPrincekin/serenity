
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/DOMRectConstructor.h>
#include <LibWeb/Bindings/DOMRectPrototype.h>
#include <LibWeb/Bindings/DOMRectWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/DOMRect.h>)
#    include <LibWeb/Crypto/DOMRect.h>
#elif __has_include(<LibWeb/CSS/DOMRect.h>)
#    include <LibWeb/CSS/DOMRect.h>
#elif __has_include(<LibWeb/DOM/DOMRect.h>)
#    include <LibWeb/DOM/DOMRect.h>
#elif __has_include(<LibWeb/Encoding/DOMRect.h>)
#    include <LibWeb/Encoding/DOMRect.h>
#elif __has_include(<LibWeb/Geometry/DOMRect.h>)
#    include <LibWeb/Geometry/DOMRect.h>
#elif __has_include(<LibWeb/HTML/DOMRect.h>)
#    include <LibWeb/HTML/DOMRect.h>
#elif __has_include(<LibWeb/UIEvents/DOMRect.h>)
#    include <LibWeb/UIEvents/DOMRect.h>
#elif __has_include(<LibWeb/HighResolutionTime/DOMRect.h>)
#    include <LibWeb/HighResolutionTime/DOMRect.h>
#elif __has_include(<LibWeb/IntersectionObserver/DOMRect.h>)
#    include <LibWeb/IntersectionObserver/DOMRect.h>
#elif __has_include(<LibWeb/NavigationTiming/DOMRect.h>)
#    include <LibWeb/NavigationTiming/DOMRect.h>
#elif __has_include(<LibWeb/RequestIdleCallback/DOMRect.h>)
#    include <LibWeb/RequestIdleCallback/DOMRect.h>
#elif __has_include(<LibWeb/ResizeObserver/DOMRect.h>)
#    include <LibWeb/ResizeObserver/DOMRect.h>
#elif __has_include(<LibWeb/SVG/DOMRect.h>)
#    include <LibWeb/SVG/DOMRect.h>
#elif __has_include(<LibWeb/Selection/DOMRect.h>)
#    include <LibWeb/Selection/DOMRect.h>
#elif __has_include(<LibWeb/WebSockets/DOMRect.h>)
#    include <LibWeb/WebSockets/DOMRect.h>
#elif __has_include(<LibWeb/XHR/DOMRect.h>)
#    include <LibWeb/XHR/DOMRect.h>
#elif __has_include(<LibWeb/URL/DOMRect.h>)
#    include <LibWeb/URL/DOMRect.h>
#endif


#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/Geometry/DOMRect.h>

#if __has_include(<LibWeb/Bindings/DOMRectWrapper.h>)
#   include <LibWeb/Bindings/DOMRectWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectWrapperFactory.h>
#endif

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

DOMRectConstructor::DOMRectConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

DOMRectConstructor::~DOMRectConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> DOMRectConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "DOMRect");
}

JS::ThrowCompletionOr<JS::Object*> DOMRectConstructor::construct(FunctionObject&)
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

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return Geometry::DOMRect::create_with_global_object(window, x, y, width, height); }));

    return wrap(global_object, *impl);

}

void DOMRectConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<DOMRectPrototype>("DOMRect"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

