
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/SVGLengthConstructor.h>
#include <LibWeb/Bindings/SVGLengthPrototype.h>
#include <LibWeb/Bindings/SVGLengthWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/SVGLength.h>)
#    include <LibWeb/Crypto/SVGLength.h>
#elif __has_include(<LibWeb/CSS/SVGLength.h>)
#    include <LibWeb/CSS/SVGLength.h>
#elif __has_include(<LibWeb/DOM/SVGLength.h>)
#    include <LibWeb/DOM/SVGLength.h>
#elif __has_include(<LibWeb/Encoding/SVGLength.h>)
#    include <LibWeb/Encoding/SVGLength.h>
#elif __has_include(<LibWeb/Geometry/SVGLength.h>)
#    include <LibWeb/Geometry/SVGLength.h>
#elif __has_include(<LibWeb/HTML/SVGLength.h>)
#    include <LibWeb/HTML/SVGLength.h>
#elif __has_include(<LibWeb/UIEvents/SVGLength.h>)
#    include <LibWeb/UIEvents/SVGLength.h>
#elif __has_include(<LibWeb/HighResolutionTime/SVGLength.h>)
#    include <LibWeb/HighResolutionTime/SVGLength.h>
#elif __has_include(<LibWeb/IntersectionObserver/SVGLength.h>)
#    include <LibWeb/IntersectionObserver/SVGLength.h>
#elif __has_include(<LibWeb/NavigationTiming/SVGLength.h>)
#    include <LibWeb/NavigationTiming/SVGLength.h>
#elif __has_include(<LibWeb/RequestIdleCallback/SVGLength.h>)
#    include <LibWeb/RequestIdleCallback/SVGLength.h>
#elif __has_include(<LibWeb/ResizeObserver/SVGLength.h>)
#    include <LibWeb/ResizeObserver/SVGLength.h>
#elif __has_include(<LibWeb/SVG/SVGLength.h>)
#    include <LibWeb/SVG/SVGLength.h>
#elif __has_include(<LibWeb/Selection/SVGLength.h>)
#    include <LibWeb/Selection/SVGLength.h>
#elif __has_include(<LibWeb/WebSockets/SVGLength.h>)
#    include <LibWeb/WebSockets/SVGLength.h>
#elif __has_include(<LibWeb/XHR/SVGLength.h>)
#    include <LibWeb/XHR/SVGLength.h>
#elif __has_include(<LibWeb/URL/SVGLength.h>)
#    include <LibWeb/URL/SVGLength.h>
#endif


#include <LibWeb/SVG/SVGLength.h>

#include <LibWeb/SVG/SVGLength.h>

#if __has_include(<LibWeb/Bindings/SVGLengthWrapper.h>)
#   include <LibWeb/Bindings/SVGLengthWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGLengthWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGLengthWrapperFactory.h>
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

SVGLengthConstructor::SVGLengthConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

SVGLengthConstructor::~SVGLengthConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> SVGLengthConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "SVGLength");
}

JS::ThrowCompletionOr<JS::Object*> SVGLengthConstructor::construct(FunctionObject&)
{

    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::NotAConstructor, "SVGLength");

}

void SVGLengthConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<SVGLengthPrototype>("SVGLength"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


define_direct_property("SVG_LENGTHTYPE_UNKNOWN", JS::Value((i32)0), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_NUMBER", JS::Value((i32)1), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_PERCENTAGE", JS::Value((i32)2), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_EMS", JS::Value((i32)3), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_EXS", JS::Value((i32)4), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_PX", JS::Value((i32)5), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_CM", JS::Value((i32)6), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_MM", JS::Value((i32)7), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_IN", JS::Value((i32)8), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_PT", JS::Value((i32)9), JS::Attribute::Enumerable);

define_direct_property("SVG_LENGTHTYPE_PC", JS::Value((i32)10), JS::Attribute::Enumerable);

}

} // namespace Web::Bindings

