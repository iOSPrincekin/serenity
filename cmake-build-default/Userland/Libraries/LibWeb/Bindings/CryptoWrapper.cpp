
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/CryptoPrototype.h>
#include <LibWeb/Bindings/CryptoWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

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
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;

namespace Web::Bindings {

CryptoWrapper* CryptoWrapper::create(JS::GlobalObject& global_object, Crypto::Crypto& impl)
{
    return global_object.heap().allocate<CryptoWrapper>(global_object, global_object, impl);
}


CryptoWrapper::CryptoWrapper(JS::GlobalObject& global_object, Crypto::Crypto& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<CryptoPrototype>("Crypto"))
    , m_impl(impl)
{
}

void CryptoWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "Crypto"), JS::Attribute::Configurable);
}

CryptoWrapper::~CryptoWrapper()
{
}

CryptoWrapper* wrap(JS::GlobalObject& global_object, Crypto::Crypto& impl)
{
    return static_cast<CryptoWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

