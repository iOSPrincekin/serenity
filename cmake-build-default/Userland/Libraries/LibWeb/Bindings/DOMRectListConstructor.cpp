
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/DOMRectListConstructor.h>
#include <LibWeb/Bindings/DOMRectListPrototype.h>
#include <LibWeb/Bindings/DOMRectListWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/DOMRectList.h>)
#    include <LibWeb/Crypto/DOMRectList.h>
#elif __has_include(<LibWeb/CSS/DOMRectList.h>)
#    include <LibWeb/CSS/DOMRectList.h>
#elif __has_include(<LibWeb/DOM/DOMRectList.h>)
#    include <LibWeb/DOM/DOMRectList.h>
#elif __has_include(<LibWeb/Encoding/DOMRectList.h>)
#    include <LibWeb/Encoding/DOMRectList.h>
#elif __has_include(<LibWeb/Geometry/DOMRectList.h>)
#    include <LibWeb/Geometry/DOMRectList.h>
#elif __has_include(<LibWeb/HTML/DOMRectList.h>)
#    include <LibWeb/HTML/DOMRectList.h>
#elif __has_include(<LibWeb/UIEvents/DOMRectList.h>)
#    include <LibWeb/UIEvents/DOMRectList.h>
#elif __has_include(<LibWeb/HighResolutionTime/DOMRectList.h>)
#    include <LibWeb/HighResolutionTime/DOMRectList.h>
#elif __has_include(<LibWeb/IntersectionObserver/DOMRectList.h>)
#    include <LibWeb/IntersectionObserver/DOMRectList.h>
#elif __has_include(<LibWeb/NavigationTiming/DOMRectList.h>)
#    include <LibWeb/NavigationTiming/DOMRectList.h>
#elif __has_include(<LibWeb/RequestIdleCallback/DOMRectList.h>)
#    include <LibWeb/RequestIdleCallback/DOMRectList.h>
#elif __has_include(<LibWeb/ResizeObserver/DOMRectList.h>)
#    include <LibWeb/ResizeObserver/DOMRectList.h>
#elif __has_include(<LibWeb/SVG/DOMRectList.h>)
#    include <LibWeb/SVG/DOMRectList.h>
#elif __has_include(<LibWeb/Selection/DOMRectList.h>)
#    include <LibWeb/Selection/DOMRectList.h>
#elif __has_include(<LibWeb/WebSockets/DOMRectList.h>)
#    include <LibWeb/WebSockets/DOMRectList.h>
#elif __has_include(<LibWeb/XHR/DOMRectList.h>)
#    include <LibWeb/XHR/DOMRectList.h>
#elif __has_include(<LibWeb/URL/DOMRectList.h>)
#    include <LibWeb/URL/DOMRectList.h>
#endif


#include <LibWeb/Geometry/DOMRectList.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/Geometry/DOMRectList.h>

#if __has_include(<LibWeb/Bindings/DOMRectListWrapper.h>)
#   include <LibWeb/Bindings/DOMRectListWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectListWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectListWrapperFactory.h>
#endif

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

DOMRectListConstructor::DOMRectListConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

DOMRectListConstructor::~DOMRectListConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> DOMRectListConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "DOMRectList");
}

JS::ThrowCompletionOr<JS::Object*> DOMRectListConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "DOMRectList");

}

void DOMRectListConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<DOMRectListPrototype>("DOMRectList"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

