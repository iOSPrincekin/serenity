
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/SubtleCryptoPrototype.h>
#include <LibWeb/Bindings/SubtleCryptoWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

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

namespace Web::Bindings {

SubtleCryptoWrapper* SubtleCryptoWrapper::create(JS::GlobalObject& global_object, Crypto::SubtleCrypto& impl)
{
    return global_object.heap().allocate<SubtleCryptoWrapper>(global_object, global_object, impl);
}


SubtleCryptoWrapper::SubtleCryptoWrapper(JS::GlobalObject& global_object, Crypto::SubtleCrypto& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<SubtleCryptoPrototype>("SubtleCrypto"))
    , m_impl(impl)
{
}

void SubtleCryptoWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "SubtleCrypto"), JS::Attribute::Configurable);
}

SubtleCryptoWrapper::~SubtleCryptoWrapper()
{
}

SubtleCryptoWrapper* wrap(JS::GlobalObject& global_object, Crypto::SubtleCrypto& impl)
{
    return static_cast<SubtleCryptoWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

