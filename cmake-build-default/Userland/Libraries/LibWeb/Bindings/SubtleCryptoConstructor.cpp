
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/SubtleCryptoConstructor.h>
#include <LibWeb/Bindings/SubtleCryptoPrototype.h>
#include <LibWeb/Bindings/SubtleCryptoWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/SubtleCrypto.h>)
#    include <LibWeb/Crypto/SubtleCrypto.h>
#elif __has_include(<LibWeb/CSS/SubtleCrypto.h>)
#    include <LibWeb/CSS/SubtleCrypto.h>
#elif __has_include(<LibWeb/DOM/SubtleCrypto.h>)
#    include <LibWeb/DOM/SubtleCrypto.h>
#elif __has_include(<LibWeb/Encoding/SubtleCrypto.h>)
#    include <LibWeb/Encoding/SubtleCrypto.h>
#elif __has_include(<LibWeb/Geometry/SubtleCrypto.h>)
#    include <LibWeb/Geometry/SubtleCrypto.h>
#elif __has_include(<LibWeb/HTML/SubtleCrypto.h>)
#    include <LibWeb/HTML/SubtleCrypto.h>
#elif __has_include(<LibWeb/UIEvents/SubtleCrypto.h>)
#    include <LibWeb/UIEvents/SubtleCrypto.h>
#elif __has_include(<LibWeb/HighResolutionTime/SubtleCrypto.h>)
#    include <LibWeb/HighResolutionTime/SubtleCrypto.h>
#elif __has_include(<LibWeb/IntersectionObserver/SubtleCrypto.h>)
#    include <LibWeb/IntersectionObserver/SubtleCrypto.h>
#elif __has_include(<LibWeb/NavigationTiming/SubtleCrypto.h>)
#    include <LibWeb/NavigationTiming/SubtleCrypto.h>
#elif __has_include(<LibWeb/RequestIdleCallback/SubtleCrypto.h>)
#    include <LibWeb/RequestIdleCallback/SubtleCrypto.h>
#elif __has_include(<LibWeb/ResizeObserver/SubtleCrypto.h>)
#    include <LibWeb/ResizeObserver/SubtleCrypto.h>
#elif __has_include(<LibWeb/SVG/SubtleCrypto.h>)
#    include <LibWeb/SVG/SubtleCrypto.h>
#elif __has_include(<LibWeb/Selection/SubtleCrypto.h>)
#    include <LibWeb/Selection/SubtleCrypto.h>
#elif __has_include(<LibWeb/WebSockets/SubtleCrypto.h>)
#    include <LibWeb/WebSockets/SubtleCrypto.h>
#elif __has_include(<LibWeb/XHR/SubtleCrypto.h>)
#    include <LibWeb/XHR/SubtleCrypto.h>
#elif __has_include(<LibWeb/URL/SubtleCrypto.h>)
#    include <LibWeb/URL/SubtleCrypto.h>
#endif


#include <LibWeb/Crypto/SubtleCrypto.h>

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

SubtleCryptoConstructor::SubtleCryptoConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

SubtleCryptoConstructor::~SubtleCryptoConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> SubtleCryptoConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "SubtleCrypto");
}

JS::ThrowCompletionOr<JS::Object*> SubtleCryptoConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "SubtleCrypto");

}

void SubtleCryptoConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<SubtleCryptoPrototype>("SubtleCrypto"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

