
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/CryptoConstructor.h>
#include <LibWeb/Bindings/CryptoPrototype.h>
#include <LibWeb/Bindings/CryptoWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/Crypto.h>)
#    include <LibWeb/Crypto/Crypto.h>
#elif __has_include(<LibWeb/CSS/Crypto.h>)
#    include <LibWeb/CSS/Crypto.h>
#elif __has_include(<LibWeb/DOM/Crypto.h>)
#    include <LibWeb/DOM/Crypto.h>
#elif __has_include(<LibWeb/Encoding/Crypto.h>)
#    include <LibWeb/Encoding/Crypto.h>
#elif __has_include(<LibWeb/Geometry/Crypto.h>)
#    include <LibWeb/Geometry/Crypto.h>
#elif __has_include(<LibWeb/HTML/Crypto.h>)
#    include <LibWeb/HTML/Crypto.h>
#elif __has_include(<LibWeb/UIEvents/Crypto.h>)
#    include <LibWeb/UIEvents/Crypto.h>
#elif __has_include(<LibWeb/HighResolutionTime/Crypto.h>)
#    include <LibWeb/HighResolutionTime/Crypto.h>
#elif __has_include(<LibWeb/IntersectionObserver/Crypto.h>)
#    include <LibWeb/IntersectionObserver/Crypto.h>
#elif __has_include(<LibWeb/NavigationTiming/Crypto.h>)
#    include <LibWeb/NavigationTiming/Crypto.h>
#elif __has_include(<LibWeb/RequestIdleCallback/Crypto.h>)
#    include <LibWeb/RequestIdleCallback/Crypto.h>
#elif __has_include(<LibWeb/ResizeObserver/Crypto.h>)
#    include <LibWeb/ResizeObserver/Crypto.h>
#elif __has_include(<LibWeb/SVG/Crypto.h>)
#    include <LibWeb/SVG/Crypto.h>
#elif __has_include(<LibWeb/Selection/Crypto.h>)
#    include <LibWeb/Selection/Crypto.h>
#elif __has_include(<LibWeb/WebSockets/Crypto.h>)
#    include <LibWeb/WebSockets/Crypto.h>
#elif __has_include(<LibWeb/XHR/Crypto.h>)
#    include <LibWeb/XHR/Crypto.h>
#elif __has_include(<LibWeb/URL/Crypto.h>)
#    include <LibWeb/URL/Crypto.h>
#endif


#include <LibWeb/Crypto/SubtleCrypto.h>

#include <LibWeb/Crypto/Crypto.h>

#include <LibWeb/Crypto/Crypto.h>

#if __has_include(<LibWeb/Bindings/CryptoWrapper.h>)
#   include <LibWeb/Bindings/CryptoWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CryptoWrapperFactory.h>)
#   include <LibWeb/Bindings/CryptoWrapperFactory.h>
#endif

#include <LibWeb/Crypto/SubtleCrypto.h>

#if __has_include(<LibWeb/Bindings/SubtleCryptoWrapper.h>)
#   include <LibWeb/Bindings/SubtleCryptoWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SubtleCryptoWrapperFactory.h>)
#   include <LibWeb/Bindings/SubtleCryptoWrapperFactory.h>
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

CryptoConstructor::CryptoConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

CryptoConstructor::~CryptoConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> CryptoConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "Crypto");
}

JS::ThrowCompletionOr<JS::Object*> CryptoConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "Crypto");

}

void CryptoConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<CryptoPrototype>("Crypto"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

