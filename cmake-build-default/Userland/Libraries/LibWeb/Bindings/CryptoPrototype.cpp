
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CryptoPrototype.h>
#include <LibWeb/Bindings/CryptoWrapper.h>
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

CryptoPrototype::CryptoPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

CryptoPrototype::~CryptoPrototype()
{
}

void CryptoPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("subtle", subtle_getter, nullptr, default_attributes);

    define_native_function("randomUUID", random_uuid, 0, default_attributes);

    define_native_function("getRandomValues", get_random_values, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<Crypto::Crypto*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<CryptoWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "Crypto::Crypto");

    return &static_cast<CryptoWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(CryptoPrototype::subtle_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->subtle(); }));

    return wrap(global_object, const_cast<SubtleCrypto&>(*retval));

}

JS_DEFINE_NATIVE_FUNCTION(CryptoPrototype::get_random_values)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getRandomValues");

    auto arg0 = vm.argument(0);

    auto array = arg0;

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_random_values(array); }));

    return retval;

}

JS_DEFINE_NATIVE_FUNCTION(CryptoPrototype::random_uuid)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->random_uuid(); }));

    return JS::js_string(vm, retval);

}

} // namespace Web::Bindings

