
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLScriptElementConstructor.h>
#include <LibWeb/Bindings/HTMLScriptElementPrototype.h>
#include <LibWeb/Bindings/HTMLScriptElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLScriptElement.h>)
#    include <LibWeb/Crypto/HTMLScriptElement.h>
#elif __has_include(<LibWeb/CSS/HTMLScriptElement.h>)
#    include <LibWeb/CSS/HTMLScriptElement.h>
#elif __has_include(<LibWeb/DOM/HTMLScriptElement.h>)
#    include <LibWeb/DOM/HTMLScriptElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLScriptElement.h>)
#    include <LibWeb/Encoding/HTMLScriptElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLScriptElement.h>)
#    include <LibWeb/Geometry/HTMLScriptElement.h>
#elif __has_include(<LibWeb/HTML/HTMLScriptElement.h>)
#    include <LibWeb/HTML/HTMLScriptElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLScriptElement.h>)
#    include <LibWeb/UIEvents/HTMLScriptElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLScriptElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLScriptElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLScriptElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLScriptElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLScriptElement.h>)
#    include <LibWeb/NavigationTiming/HTMLScriptElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLScriptElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLScriptElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLScriptElement.h>)
#    include <LibWeb/ResizeObserver/HTMLScriptElement.h>
#elif __has_include(<LibWeb/SVG/HTMLScriptElement.h>)
#    include <LibWeb/SVG/HTMLScriptElement.h>
#elif __has_include(<LibWeb/Selection/HTMLScriptElement.h>)
#    include <LibWeb/Selection/HTMLScriptElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLScriptElement.h>)
#    include <LibWeb/WebSockets/HTMLScriptElement.h>
#elif __has_include(<LibWeb/XHR/HTMLScriptElement.h>)
#    include <LibWeb/XHR/HTMLScriptElement.h>
#elif __has_include(<LibWeb/URL/HTMLScriptElement.h>)
#    include <LibWeb/URL/HTMLScriptElement.h>
#endif


#include <LibWeb/HTML/HTMLScriptElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLScriptElement.h>

#if __has_include(<LibWeb/Bindings/HTMLScriptElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLScriptElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLScriptElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLScriptElementWrapperFactory.h>
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

HTMLScriptElementConstructor::HTMLScriptElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLScriptElementConstructor::~HTMLScriptElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLScriptElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLScriptElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLScriptElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLScriptElement");

}

void HTMLScriptElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLScriptElementPrototype>("HTMLScriptElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


    define_native_function("supports", supports, 1, default_attributes);

}

JS_DEFINE_NATIVE_FUNCTION(HTMLScriptElementConstructor::supports)
{

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "supports");

    auto arg0 = vm.argument(0);

    String type;
    if (arg0.is_null() && false) {
        type = String::empty();
    } else {
        type = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return HTML::HTMLScriptElement::supports(type); }));

    return JS::Value(retval);

}

} // namespace Web::Bindings

