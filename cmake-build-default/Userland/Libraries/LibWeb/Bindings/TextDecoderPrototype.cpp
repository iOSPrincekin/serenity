
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/TextDecoderPrototype.h>
#include <LibWeb/Bindings/TextDecoderWrapper.h>
#include <LibWeb/Bindings/EventWrapper.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/LocationObject.h>
#include <LibWeb/Bindings/WindowObject.h>
#include <LibWeb/Bindings/WorkerLocationWrapper.h>
#include <LibWeb/Bindings/WorkerNavigatorWrapper.h>
#include <LibWeb/Bindings/WorkerWrapper.h>
#include <LibWeb/DOM/Element.h>
#include <LibWeb/DOM/Event.h>
#include <LibWeb/DOM/IDLEventListener.h>
#include <LibWeb/DOM/NodeFilter.h>
#include <LibWeb/DOM/Range.h>
#include <LibWeb/HTML/Scripting/Environments.h>
#include <LibWeb/HTML/Window.h>
#include <LibWeb/Origin.h>

#if __has_include(<LibWeb/Bindings/ObjectPrototype.h>)
#    include <LibWeb/Bindings/ObjectPrototype.h>
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
using namespace Web::Crypto;
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::NavigationTiming;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;
using namespace Web::SVG;
using namespace Web::URL;
using namespace Web::WebSockets;
using namespace Web::XHR;

namespace Web::Bindings {

TextDecoderPrototype::TextDecoderPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

TextDecoderPrototype::~TextDecoderPrototype()
{
}

void TextDecoderPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("encoding", encoding_getter, nullptr, default_attributes);

    define_native_accessor("fatal", fatal_getter, nullptr, default_attributes);

    define_native_accessor("ignoreBOM", ignore_bom_getter, nullptr, default_attributes);

    define_native_function("decode", decode, 0, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<Encoding::TextDecoder*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<TextDecoderWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Encoding::TextDecoder");

    return &static_cast<TextDecoderWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(TextDecoderPrototype::encoding_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->encoding(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextDecoderPrototype::fatal_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->fatal(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextDecoderPrototype::ignore_bom_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ignore_bom(); }));

    return JS::Value(retval);

}

JS_DEFINE_NATIVE_FUNCTION(TextDecoderPrototype::decode)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    if (!arg0.is_object() || !(is<JS::TypedArrayBase>(arg0.as_object()) || is<JS::ArrayBuffer>(arg0.as_object()) || is<JS::DataView>(arg0.as_object())))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "BufferSource");

    // TODO: Should we make this a Variant?
    auto input = JS::make_handle(&arg0.as_object());

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->decode(input); }));

    return JS::js_string(vm, retval);

}

} // namespace Web::Bindings

