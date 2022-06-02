
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/DOMStringMapConstructor.h>
#include <LibWeb/Bindings/DOMStringMapPrototype.h>
#include <LibWeb/Bindings/DOMStringMapWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/DOMStringMap.h>)
#    include <LibWeb/Crypto/DOMStringMap.h>
#elif __has_include(<LibWeb/CSS/DOMStringMap.h>)
#    include <LibWeb/CSS/DOMStringMap.h>
#elif __has_include(<LibWeb/DOM/DOMStringMap.h>)
#    include <LibWeb/DOM/DOMStringMap.h>
#elif __has_include(<LibWeb/Encoding/DOMStringMap.h>)
#    include <LibWeb/Encoding/DOMStringMap.h>
#elif __has_include(<LibWeb/Geometry/DOMStringMap.h>)
#    include <LibWeb/Geometry/DOMStringMap.h>
#elif __has_include(<LibWeb/HTML/DOMStringMap.h>)
#    include <LibWeb/HTML/DOMStringMap.h>
#elif __has_include(<LibWeb/UIEvents/DOMStringMap.h>)
#    include <LibWeb/UIEvents/DOMStringMap.h>
#elif __has_include(<LibWeb/HighResolutionTime/DOMStringMap.h>)
#    include <LibWeb/HighResolutionTime/DOMStringMap.h>
#elif __has_include(<LibWeb/IntersectionObserver/DOMStringMap.h>)
#    include <LibWeb/IntersectionObserver/DOMStringMap.h>
#elif __has_include(<LibWeb/NavigationTiming/DOMStringMap.h>)
#    include <LibWeb/NavigationTiming/DOMStringMap.h>
#elif __has_include(<LibWeb/RequestIdleCallback/DOMStringMap.h>)
#    include <LibWeb/RequestIdleCallback/DOMStringMap.h>
#elif __has_include(<LibWeb/ResizeObserver/DOMStringMap.h>)
#    include <LibWeb/ResizeObserver/DOMStringMap.h>
#elif __has_include(<LibWeb/SVG/DOMStringMap.h>)
#    include <LibWeb/SVG/DOMStringMap.h>
#elif __has_include(<LibWeb/Selection/DOMStringMap.h>)
#    include <LibWeb/Selection/DOMStringMap.h>
#elif __has_include(<LibWeb/WebSockets/DOMStringMap.h>)
#    include <LibWeb/WebSockets/DOMStringMap.h>
#elif __has_include(<LibWeb/XHR/DOMStringMap.h>)
#    include <LibWeb/XHR/DOMStringMap.h>
#elif __has_include(<LibWeb/URL/DOMStringMap.h>)
#    include <LibWeb/URL/DOMStringMap.h>
#endif


#include <LibWeb/HTML/DOMStringMap.h>

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

DOMStringMapConstructor::DOMStringMapConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

DOMStringMapConstructor::~DOMStringMapConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> DOMStringMapConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "DOMStringMap");
}

JS::ThrowCompletionOr<JS::Object*> DOMStringMapConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "DOMStringMap");

}

void DOMStringMapConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<DOMStringMapPrototype>("DOMStringMap"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

