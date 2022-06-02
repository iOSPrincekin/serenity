
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CSSStyleDeclarationConstructor.h>
#include <LibWeb/Bindings/CSSStyleDeclarationPrototype.h>
#include <LibWeb/Bindings/CSSStyleDeclarationWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/CSSStyleDeclaration.h>)
#    include <LibWeb/Crypto/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/CSS/CSSStyleDeclaration.h>)
#    include <LibWeb/CSS/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/DOM/CSSStyleDeclaration.h>)
#    include <LibWeb/DOM/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/Encoding/CSSStyleDeclaration.h>)
#    include <LibWeb/Encoding/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/Geometry/CSSStyleDeclaration.h>)
#    include <LibWeb/Geometry/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/HTML/CSSStyleDeclaration.h>)
#    include <LibWeb/HTML/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/UIEvents/CSSStyleDeclaration.h>)
#    include <LibWeb/UIEvents/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/HighResolutionTime/CSSStyleDeclaration.h>)
#    include <LibWeb/HighResolutionTime/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/IntersectionObserver/CSSStyleDeclaration.h>)
#    include <LibWeb/IntersectionObserver/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/NavigationTiming/CSSStyleDeclaration.h>)
#    include <LibWeb/NavigationTiming/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/RequestIdleCallback/CSSStyleDeclaration.h>)
#    include <LibWeb/RequestIdleCallback/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/ResizeObserver/CSSStyleDeclaration.h>)
#    include <LibWeb/ResizeObserver/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/SVG/CSSStyleDeclaration.h>)
#    include <LibWeb/SVG/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/Selection/CSSStyleDeclaration.h>)
#    include <LibWeb/Selection/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/WebSockets/CSSStyleDeclaration.h>)
#    include <LibWeb/WebSockets/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/XHR/CSSStyleDeclaration.h>)
#    include <LibWeb/XHR/CSSStyleDeclaration.h>
#elif __has_include(<LibWeb/URL/CSSStyleDeclaration.h>)
#    include <LibWeb/URL/CSSStyleDeclaration.h>
#endif


#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapper.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSStyleDeclarationWrapperFactory.h>
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

CSSStyleDeclarationConstructor::CSSStyleDeclarationConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CSSStyleDeclarationConstructor::~CSSStyleDeclarationConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CSSStyleDeclarationConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "CSSStyleDeclaration");
}

JS::ThrowCompletionOr<JS::Object*> CSSStyleDeclarationConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "CSSStyleDeclaration");

}

void CSSStyleDeclarationConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CSSStyleDeclarationPrototype>("CSSStyleDeclaration"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

