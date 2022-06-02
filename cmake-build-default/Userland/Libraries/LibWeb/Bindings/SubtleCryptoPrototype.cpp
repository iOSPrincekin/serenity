
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/SubtleCryptoPrototype.h>
#include <LibWeb/Bindings/SubtleCryptoWrapper.h>
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


#include <LibWeb/Crypto/SubtleCrypto.h>

#include <LibWeb/Crypto/SubtleCrypto.h>

#if __has_include(<LibWeb/Bindings/SubtleCryptoWrapper.h>)
#   include <LibWeb/Bindings/SubtleCryptoWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SubtleCryptoWrapperFactory.h>)
#   include <LibWeb/Bindings/SubtleCryptoWrapperFactory.h>
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

SubtleCryptoPrototype::SubtleCryptoPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

SubtleCryptoPrototype::~SubtleCryptoPrototype()
{
}

void SubtleCryptoPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_function("digest", digest, 2, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<Crypto::SubtleCrypto*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<SubtleCryptoWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Crypto::SubtleCrypto");

    return &static_cast<SubtleCryptoWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(SubtleCryptoPrototype::digest)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "digest", "2");

    auto arg0 = vm.argument(0);

    String algorithm;
    if (arg0.is_null() && false) {
        algorithm = String::empty();
    } else {
        algorithm = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    if (!arg1.is_object() || !(is<JS::TypedArrayBase>(arg1.as_object()) || is<JS::ArrayBuffer>(arg1.as_object()) || is<JS::DataView>(arg1.as_object())))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "BufferSource");

    // TODO: Should we make this a Variant?
    auto data = JS::make_handle(&arg1.as_object());

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->digest(algorithm, data); }));

    return retval;

}

} // namespace Web::Bindings

