
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/DOMTokenListConstructor.h>
#include <LibWeb/Bindings/DOMTokenListPrototype.h>
#include <LibWeb/Bindings/DOMTokenListWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/DOMTokenList.h>)
#    include <LibWeb/Crypto/DOMTokenList.h>
#elif __has_include(<LibWeb/CSS/DOMTokenList.h>)
#    include <LibWeb/CSS/DOMTokenList.h>
#elif __has_include(<LibWeb/DOM/DOMTokenList.h>)
#    include <LibWeb/DOM/DOMTokenList.h>
#elif __has_include(<LibWeb/Encoding/DOMTokenList.h>)
#    include <LibWeb/Encoding/DOMTokenList.h>
#elif __has_include(<LibWeb/Geometry/DOMTokenList.h>)
#    include <LibWeb/Geometry/DOMTokenList.h>
#elif __has_include(<LibWeb/HTML/DOMTokenList.h>)
#    include <LibWeb/HTML/DOMTokenList.h>
#elif __has_include(<LibWeb/UIEvents/DOMTokenList.h>)
#    include <LibWeb/UIEvents/DOMTokenList.h>
#elif __has_include(<LibWeb/HighResolutionTime/DOMTokenList.h>)
#    include <LibWeb/HighResolutionTime/DOMTokenList.h>
#elif __has_include(<LibWeb/IntersectionObserver/DOMTokenList.h>)
#    include <LibWeb/IntersectionObserver/DOMTokenList.h>
#elif __has_include(<LibWeb/NavigationTiming/DOMTokenList.h>)
#    include <LibWeb/NavigationTiming/DOMTokenList.h>
#elif __has_include(<LibWeb/RequestIdleCallback/DOMTokenList.h>)
#    include <LibWeb/RequestIdleCallback/DOMTokenList.h>
#elif __has_include(<LibWeb/ResizeObserver/DOMTokenList.h>)
#    include <LibWeb/ResizeObserver/DOMTokenList.h>
#elif __has_include(<LibWeb/SVG/DOMTokenList.h>)
#    include <LibWeb/SVG/DOMTokenList.h>
#elif __has_include(<LibWeb/Selection/DOMTokenList.h>)
#    include <LibWeb/Selection/DOMTokenList.h>
#elif __has_include(<LibWeb/WebSockets/DOMTokenList.h>)
#    include <LibWeb/WebSockets/DOMTokenList.h>
#elif __has_include(<LibWeb/XHR/DOMTokenList.h>)
#    include <LibWeb/XHR/DOMTokenList.h>
#elif __has_include(<LibWeb/URL/DOMTokenList.h>)
#    include <LibWeb/URL/DOMTokenList.h>
#endif


#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/DOMTokenList.h>

#if __has_include(<LibWeb/Bindings/DOMTokenListWrapper.h>)
#   include <LibWeb/Bindings/DOMTokenListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMTokenListWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMTokenListWrapperFactory.h>
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

DOMTokenListConstructor::DOMTokenListConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

DOMTokenListConstructor::~DOMTokenListConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> DOMTokenListConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "DOMTokenList");
}

JS::ThrowCompletionOr<JS::Object*> DOMTokenListConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "DOMTokenList");

}

void DOMTokenListConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<DOMTokenListPrototype>("DOMTokenList"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

