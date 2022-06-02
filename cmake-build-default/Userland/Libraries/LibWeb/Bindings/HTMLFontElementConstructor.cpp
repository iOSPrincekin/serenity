
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/HTMLFontElementConstructor.h>
#include <LibWeb/Bindings/HTMLFontElementPrototype.h>
#include <LibWeb/Bindings/HTMLFontElementWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/HTMLFontElement.h>)
#    include <LibWeb/Crypto/HTMLFontElement.h>
#elif __has_include(<LibWeb/CSS/HTMLFontElement.h>)
#    include <LibWeb/CSS/HTMLFontElement.h>
#elif __has_include(<LibWeb/DOM/HTMLFontElement.h>)
#    include <LibWeb/DOM/HTMLFontElement.h>
#elif __has_include(<LibWeb/Encoding/HTMLFontElement.h>)
#    include <LibWeb/Encoding/HTMLFontElement.h>
#elif __has_include(<LibWeb/Geometry/HTMLFontElement.h>)
#    include <LibWeb/Geometry/HTMLFontElement.h>
#elif __has_include(<LibWeb/HTML/HTMLFontElement.h>)
#    include <LibWeb/HTML/HTMLFontElement.h>
#elif __has_include(<LibWeb/UIEvents/HTMLFontElement.h>)
#    include <LibWeb/UIEvents/HTMLFontElement.h>
#elif __has_include(<LibWeb/HighResolutionTime/HTMLFontElement.h>)
#    include <LibWeb/HighResolutionTime/HTMLFontElement.h>
#elif __has_include(<LibWeb/IntersectionObserver/HTMLFontElement.h>)
#    include <LibWeb/IntersectionObserver/HTMLFontElement.h>
#elif __has_include(<LibWeb/NavigationTiming/HTMLFontElement.h>)
#    include <LibWeb/NavigationTiming/HTMLFontElement.h>
#elif __has_include(<LibWeb/RequestIdleCallback/HTMLFontElement.h>)
#    include <LibWeb/RequestIdleCallback/HTMLFontElement.h>
#elif __has_include(<LibWeb/ResizeObserver/HTMLFontElement.h>)
#    include <LibWeb/ResizeObserver/HTMLFontElement.h>
#elif __has_include(<LibWeb/SVG/HTMLFontElement.h>)
#    include <LibWeb/SVG/HTMLFontElement.h>
#elif __has_include(<LibWeb/Selection/HTMLFontElement.h>)
#    include <LibWeb/Selection/HTMLFontElement.h>
#elif __has_include(<LibWeb/WebSockets/HTMLFontElement.h>)
#    include <LibWeb/WebSockets/HTMLFontElement.h>
#elif __has_include(<LibWeb/XHR/HTMLFontElement.h>)
#    include <LibWeb/XHR/HTMLFontElement.h>
#elif __has_include(<LibWeb/URL/HTMLFontElement.h>)
#    include <LibWeb/URL/HTMLFontElement.h>
#endif


#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLFontElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLFontElement.h>

#if __has_include(<LibWeb/Bindings/HTMLFontElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLFontElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLFontElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLFontElementWrapperFactory.h>
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

HTMLFontElementConstructor::HTMLFontElementConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

HTMLFontElementConstructor::~HTMLFontElementConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> HTMLFontElementConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "HTMLFontElement");
}

JS::ThrowCompletionOr<JS::Object*> HTMLFontElementConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "HTMLFontElement");

}

void HTMLFontElementConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<HTMLFontElementPrototype>("HTMLFontElement"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

