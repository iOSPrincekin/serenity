
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/TextEncoderConstructor.h>
#include <LibWeb/Bindings/TextEncoderPrototype.h>
#include <LibWeb/Bindings/TextEncoderWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/TextEncoder.h>)
#    include <LibWeb/Crypto/TextEncoder.h>
#elif __has_include(<LibWeb/CSS/TextEncoder.h>)
#    include <LibWeb/CSS/TextEncoder.h>
#elif __has_include(<LibWeb/DOM/TextEncoder.h>)
#    include <LibWeb/DOM/TextEncoder.h>
#elif __has_include(<LibWeb/Encoding/TextEncoder.h>)
#    include <LibWeb/Encoding/TextEncoder.h>
#elif __has_include(<LibWeb/Geometry/TextEncoder.h>)
#    include <LibWeb/Geometry/TextEncoder.h>
#elif __has_include(<LibWeb/HTML/TextEncoder.h>)
#    include <LibWeb/HTML/TextEncoder.h>
#elif __has_include(<LibWeb/UIEvents/TextEncoder.h>)
#    include <LibWeb/UIEvents/TextEncoder.h>
#elif __has_include(<LibWeb/HighResolutionTime/TextEncoder.h>)
#    include <LibWeb/HighResolutionTime/TextEncoder.h>
#elif __has_include(<LibWeb/IntersectionObserver/TextEncoder.h>)
#    include <LibWeb/IntersectionObserver/TextEncoder.h>
#elif __has_include(<LibWeb/NavigationTiming/TextEncoder.h>)
#    include <LibWeb/NavigationTiming/TextEncoder.h>
#elif __has_include(<LibWeb/RequestIdleCallback/TextEncoder.h>)
#    include <LibWeb/RequestIdleCallback/TextEncoder.h>
#elif __has_include(<LibWeb/ResizeObserver/TextEncoder.h>)
#    include <LibWeb/ResizeObserver/TextEncoder.h>
#elif __has_include(<LibWeb/SVG/TextEncoder.h>)
#    include <LibWeb/SVG/TextEncoder.h>
#elif __has_include(<LibWeb/Selection/TextEncoder.h>)
#    include <LibWeb/Selection/TextEncoder.h>
#elif __has_include(<LibWeb/WebSockets/TextEncoder.h>)
#    include <LibWeb/WebSockets/TextEncoder.h>
#elif __has_include(<LibWeb/XHR/TextEncoder.h>)
#    include <LibWeb/XHR/TextEncoder.h>
#elif __has_include(<LibWeb/URL/TextEncoder.h>)
#    include <LibWeb/URL/TextEncoder.h>
#endif


#include <LibWeb/Encoding/TextEncoder.h>

#include <LibWeb/Encoding/TextEncoder.h>

#if __has_include(<LibWeb/Bindings/TextEncoderWrapper.h>)
#   include <LibWeb/Bindings/TextEncoderWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TextEncoderWrapperFactory.h>)
#   include <LibWeb/Bindings/TextEncoderWrapperFactory.h>
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

TextEncoderConstructor::TextEncoderConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

TextEncoderConstructor::~TextEncoderConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> TextEncoderConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "TextEncoder");
}

JS::ThrowCompletionOr<JS::Object*> TextEncoderConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return Encoding::TextEncoder::create_with_global_object(window); }));

    return wrap(global_object, *impl);

}

void TextEncoderConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<TextEncoderPrototype>("TextEncoder"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

