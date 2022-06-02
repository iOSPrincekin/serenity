
#include <AK/FlyString.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/ImageDataPrototype.h>
#include <LibWeb/Bindings/ImageDataWrapper.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/WindowObject.h>

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

namespace Web::Bindings {

ImageDataWrapper* ImageDataWrapper::create(JS::GlobalObject& global_object, HTML::ImageData& impl)
{
    return global_object.heap().allocate<ImageDataWrapper>(global_object, global_object, impl);
}


ImageDataWrapper::ImageDataWrapper(JS::GlobalObject& global_object, HTML::ImageData& impl)
    : Wrapper(static_cast<WindowObject&>(global_object).ensure_web_prototype<ImageDataPrototype>("ImageData"))
    , m_impl(impl)
{
}

void ImageDataWrapper::initialize(JS::GlobalObject& global_object)
{
    Wrapper::initialize(global_object);

    auto& vm = global_object.vm();
    define_direct_property(*vm.well_known_symbol_to_string_tag(), JS::js_string(vm, "ImageData"), JS::Attribute::Configurable);
}

ImageDataWrapper::~ImageDataWrapper()
{
}

ImageDataWrapper* wrap(JS::GlobalObject& global_object, HTML::ImageData& impl)
{
    return static_cast<ImageDataWrapper*>(wrap_impl(global_object, impl));
}

} // namespace Web::Bindings

