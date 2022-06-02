
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/TextDecoderConstructor.h>
#include <LibWeb/Bindings/TextDecoderPrototype.h>
#include <LibWeb/Bindings/TextDecoderWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/TextDecoder.h>)
#    include <LibWeb/Crypto/TextDecoder.h>
#elif __has_include(<LibWeb/CSS/TextDecoder.h>)
#    include <LibWeb/CSS/TextDecoder.h>
#elif __has_include(<LibWeb/DOM/TextDecoder.h>)
#    include <LibWeb/DOM/TextDecoder.h>
#elif __has_include(<LibWeb/Encoding/TextDecoder.h>)
#    include <LibWeb/Encoding/TextDecoder.h>
#elif __has_include(<LibWeb/Geometry/TextDecoder.h>)
#    include <LibWeb/Geometry/TextDecoder.h>
#elif __has_include(<LibWeb/HTML/TextDecoder.h>)
#    include <LibWeb/HTML/TextDecoder.h>
#elif __has_include(<LibWeb/UIEvents/TextDecoder.h>)
#    include <LibWeb/UIEvents/TextDecoder.h>
#elif __has_include(<LibWeb/HighResolutionTime/TextDecoder.h>)
#    include <LibWeb/HighResolutionTime/TextDecoder.h>
#elif __has_include(<LibWeb/IntersectionObserver/TextDecoder.h>)
#    include <LibWeb/IntersectionObserver/TextDecoder.h>
#elif __has_include(<LibWeb/NavigationTiming/TextDecoder.h>)
#    include <LibWeb/NavigationTiming/TextDecoder.h>
#elif __has_include(<LibWeb/RequestIdleCallback/TextDecoder.h>)
#    include <LibWeb/RequestIdleCallback/TextDecoder.h>
#elif __has_include(<LibWeb/ResizeObserver/TextDecoder.h>)
#    include <LibWeb/ResizeObserver/TextDecoder.h>
#elif __has_include(<LibWeb/SVG/TextDecoder.h>)
#    include <LibWeb/SVG/TextDecoder.h>
#elif __has_include(<LibWeb/Selection/TextDecoder.h>)
#    include <LibWeb/Selection/TextDecoder.h>
#elif __has_include(<LibWeb/WebSockets/TextDecoder.h>)
#    include <LibWeb/WebSockets/TextDecoder.h>
#elif __has_include(<LibWeb/XHR/TextDecoder.h>)
#    include <LibWeb/XHR/TextDecoder.h>
#elif __has_include(<LibWeb/URL/TextDecoder.h>)
#    include <LibWeb/URL/TextDecoder.h>
#endif


#include <LibWeb/Encoding/TextDecoder.h>

#include <LibWeb/Encoding/TextDecoder.h>

#if __has_include(<LibWeb/Bindings/TextDecoderWrapper.h>)
#   include <LibWeb/Bindings/TextDecoderWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/TextDecoderWrapperFactory.h>)
#   include <LibWeb/Bindings/TextDecoderWrapperFactory.h>
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

TextDecoderConstructor::TextDecoderConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

TextDecoderConstructor::~TextDecoderConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> TextDecoderConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "TextDecoder");
}

JS::ThrowCompletionOr<JS::Object*> TextDecoderConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    auto arg0 = vm.argument(0);

    String label;
    if (!arg0.is_undefined()) {
        if (arg0.is_null() && false)
            label = String::empty();
        else
            label = TRY(arg0.to_string(global_object));
    } else {
        label = "utf-8";
    }

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return Encoding::TextDecoder::create_with_global_object(window, label); }));

    return wrap(global_object, *impl);

}

void TextDecoderConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<TextDecoderPrototype>("TextDecoder"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


}

} // namespace Web::Bindings

