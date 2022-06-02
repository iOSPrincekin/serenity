
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/ImageDataConstructor.h>
#include <LibWeb/Bindings/ImageDataPrototype.h>
#include <LibWeb/Bindings/ImageDataWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/ImageData.h>)
#    include <LibWeb/Crypto/ImageData.h>
#elif __has_include(<LibWeb/CSS/ImageData.h>)
#    include <LibWeb/CSS/ImageData.h>
#elif __has_include(<LibWeb/DOM/ImageData.h>)
#    include <LibWeb/DOM/ImageData.h>
#elif __has_include(<LibWeb/Encoding/ImageData.h>)
#    include <LibWeb/Encoding/ImageData.h>
#elif __has_include(<LibWeb/Geometry/ImageData.h>)
#    include <LibWeb/Geometry/ImageData.h>
#elif __has_include(<LibWeb/HTML/ImageData.h>)
#    include <LibWeb/HTML/ImageData.h>
#elif __has_include(<LibWeb/UIEvents/ImageData.h>)
#    include <LibWeb/UIEvents/ImageData.h>
#elif __has_include(<LibWeb/HighResolutionTime/ImageData.h>)
#    include <LibWeb/HighResolutionTime/ImageData.h>
#elif __has_include(<LibWeb/IntersectionObserver/ImageData.h>)
#    include <LibWeb/IntersectionObserver/ImageData.h>
#elif __has_include(<LibWeb/NavigationTiming/ImageData.h>)
#    include <LibWeb/NavigationTiming/ImageData.h>
#elif __has_include(<LibWeb/RequestIdleCallback/ImageData.h>)
#    include <LibWeb/RequestIdleCallback/ImageData.h>
#elif __has_include(<LibWeb/ResizeObserver/ImageData.h>)
#    include <LibWeb/ResizeObserver/ImageData.h>
#elif __has_include(<LibWeb/SVG/ImageData.h>)
#    include <LibWeb/SVG/ImageData.h>
#elif __has_include(<LibWeb/Selection/ImageData.h>)
#    include <LibWeb/Selection/ImageData.h>
#elif __has_include(<LibWeb/WebSockets/ImageData.h>)
#    include <LibWeb/WebSockets/ImageData.h>
#elif __has_include(<LibWeb/XHR/ImageData.h>)
#    include <LibWeb/XHR/ImageData.h>
#elif __has_include(<LibWeb/URL/ImageData.h>)
#    include <LibWeb/URL/ImageData.h>
#endif


#include <LibWeb/HTML/ImageData.h>

#include <LibWeb/HTML/ImageData.h>

#if __has_include(<LibWeb/Bindings/ImageDataWrapper.h>)
#   include <LibWeb/Bindings/ImageDataWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ImageDataWrapperFactory.h>)
#   include <LibWeb/Bindings/ImageDataWrapperFactory.h>
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

ImageDataConstructor::ImageDataConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

ImageDataConstructor::~ImageDataConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> ImageDataConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "ImageData");
}

JS::ThrowCompletionOr<JS::Object*> ImageDataConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "ImageData");

}

void ImageDataConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<ImageDataPrototype>("ImageData"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

