
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/TextEncoderPrototype.h>
#include <LibWeb/Bindings/TextEncoderWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

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

namespace Web::Bindings {

TextEncoderWrapper* TextEncoderWrapper::create(JS::GlobalObject& global_object, Encoding::TextEncoder& impl)
{
    return global_object.heap().allocate<TextEncoderWrapper>(global_object, global_object, impl);
}


TextEncoderWrapper::TextEncoderWrapper(JS::GlobalObject& global_object, Encoding::TextEncoder& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<TextEncoderPrototype>("TextEncoder"))
    , m_impl(impl)
{
}

void TextEncoderWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "TextEncoder"), JS::Attribute::Configurable);
}

TextEncoderWrapper::~TextEncoderWrapper()
{
}

TextEncoderWrapper* wrap(JS::GlobalObject& global_object, Encoding::TextEncoder& impl)
{
    return static_cast<TextEncoderWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

