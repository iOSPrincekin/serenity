
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/URLConstructor.h>
#include <LibWeb/Bindings/URLPrototype.h>
#include <LibWeb/Bindings/URLWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/URL.h>)
#    include <LibWeb/Crypto/URL.h>
#elif __has_include(<LibWeb/CSS/URL.h>)
#    include <LibWeb/CSS/URL.h>
#elif __has_include(<LibWeb/DOM/URL.h>)
#    include <LibWeb/DOM/URL.h>
#elif __has_include(<LibWeb/Encoding/URL.h>)
#    include <LibWeb/Encoding/URL.h>
#elif __has_include(<LibWeb/Geometry/URL.h>)
#    include <LibWeb/Geometry/URL.h>
#elif __has_include(<LibWeb/HTML/URL.h>)
#    include <LibWeb/HTML/URL.h>
#elif __has_include(<LibWeb/UIEvents/URL.h>)
#    include <LibWeb/UIEvents/URL.h>
#elif __has_include(<LibWeb/HighResolutionTime/URL.h>)
#    include <LibWeb/HighResolutionTime/URL.h>
#elif __has_include(<LibWeb/IntersectionObserver/URL.h>)
#    include <LibWeb/IntersectionObserver/URL.h>
#elif __has_include(<LibWeb/NavigationTiming/URL.h>)
#    include <LibWeb/NavigationTiming/URL.h>
#elif __has_include(<LibWeb/RequestIdleCallback/URL.h>)
#    include <LibWeb/RequestIdleCallback/URL.h>
#elif __has_include(<LibWeb/ResizeObserver/URL.h>)
#    include <LibWeb/ResizeObserver/URL.h>
#elif __has_include(<LibWeb/SVG/URL.h>)
#    include <LibWeb/SVG/URL.h>
#elif __has_include(<LibWeb/Selection/URL.h>)
#    include <LibWeb/Selection/URL.h>
#elif __has_include(<LibWeb/WebSockets/URL.h>)
#    include <LibWeb/WebSockets/URL.h>
#elif __has_include(<LibWeb/XHR/URL.h>)
#    include <LibWeb/XHR/URL.h>
#elif __has_include(<LibWeb/URL/URL.h>)
#    include <LibWeb/URL/URL.h>
#endif


#include <LibWeb/URL/URLSearchParams.h>

#include <LibWeb/URL/URL.h>

#include <LibWeb/URL/URL.h>

#if __has_include(<LibWeb/Bindings/URLWrapper.h>)
#   include <LibWeb/Bindings/URLWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLWrapperFactory.h>)
#   include <LibWeb/Bindings/URLWrapperFactory.h>
#endif

#include <LibWeb/URL/URLSearchParams.h>

#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapperFactory.h>
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

URLConstructor::URLConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

URLConstructor::~URLConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> URLConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "URL");
}

JS::ThrowCompletionOr<JS::Object*> URLConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "URL");

    auto arg0 = vm.argument(0);

    String url;
    if (arg0.is_null() && false) {
        url = String::empty();
    } else {
        url = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String base;
    if (!arg1.is_undefined()) {
        if (arg1.is_null() && false)
            base = String::empty();
        else
            base = TRY(arg1.to_string(global_object));
    }

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return URL::URL::create_with_global_object(window, url, base); }));

    return wrap(global_object, *impl);

}

void URLConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<URLPrototype>("URL"), 0);
    define_direct_property(vm.names.length, JS::Value(1), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

