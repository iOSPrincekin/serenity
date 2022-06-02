
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/StorageConstructor.h>
#include <LibWeb/Bindings/StoragePrototype.h>
#include <LibWeb/Bindings/StorageWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/Storage.h>)
#    include <LibWeb/Crypto/Storage.h>
#elif __has_include(<LibWeb/CSS/Storage.h>)
#    include <LibWeb/CSS/Storage.h>
#elif __has_include(<LibWeb/DOM/Storage.h>)
#    include <LibWeb/DOM/Storage.h>
#elif __has_include(<LibWeb/Encoding/Storage.h>)
#    include <LibWeb/Encoding/Storage.h>
#elif __has_include(<LibWeb/Geometry/Storage.h>)
#    include <LibWeb/Geometry/Storage.h>
#elif __has_include(<LibWeb/HTML/Storage.h>)
#    include <LibWeb/HTML/Storage.h>
#elif __has_include(<LibWeb/UIEvents/Storage.h>)
#    include <LibWeb/UIEvents/Storage.h>
#elif __has_include(<LibWeb/HighResolutionTime/Storage.h>)
#    include <LibWeb/HighResolutionTime/Storage.h>
#elif __has_include(<LibWeb/IntersectionObserver/Storage.h>)
#    include <LibWeb/IntersectionObserver/Storage.h>
#elif __has_include(<LibWeb/NavigationTiming/Storage.h>)
#    include <LibWeb/NavigationTiming/Storage.h>
#elif __has_include(<LibWeb/RequestIdleCallback/Storage.h>)
#    include <LibWeb/RequestIdleCallback/Storage.h>
#elif __has_include(<LibWeb/ResizeObserver/Storage.h>)
#    include <LibWeb/ResizeObserver/Storage.h>
#elif __has_include(<LibWeb/SVG/Storage.h>)
#    include <LibWeb/SVG/Storage.h>
#elif __has_include(<LibWeb/Selection/Storage.h>)
#    include <LibWeb/Selection/Storage.h>
#elif __has_include(<LibWeb/WebSockets/Storage.h>)
#    include <LibWeb/WebSockets/Storage.h>
#elif __has_include(<LibWeb/XHR/Storage.h>)
#    include <LibWeb/XHR/Storage.h>
#elif __has_include(<LibWeb/URL/Storage.h>)
#    include <LibWeb/URL/Storage.h>
#endif


#include <LibWeb/HTML/Storage.h>

#include <LibWeb/HTML/Storage.h>

#if __has_include(<LibWeb/Bindings/StorageWrapper.h>)
#   include <LibWeb/Bindings/StorageWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/StorageWrapperFactory.h>)
#   include <LibWeb/Bindings/StorageWrapperFactory.h>
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

StorageConstructor::StorageConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

StorageConstructor::~StorageConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> StorageConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "Storage");
}

JS::ThrowCompletionOr<JS::Object*> StorageConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "Storage");

}

void StorageConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<StoragePrototype>("Storage"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

