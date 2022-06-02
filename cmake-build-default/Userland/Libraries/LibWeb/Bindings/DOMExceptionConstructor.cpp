
#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibWeb/Bindings/DOMExceptionConstructor.h>
#include <LibWeb/Bindings/DOMExceptionPrototype.h>
#include <LibWeb/Bindings/DOMExceptionWrapper.h>
#include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#include <LibWeb/Bindings/EventWrapperFactory.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/NodeWrapper.h>
#include <LibWeb/Bindings/NodeWrapperFactory.h>
#include <LibWeb/Bindings/WindowObject.h>
#if __has_include(<LibWeb/Crypto/DOMException.h>)
#    include <LibWeb/Crypto/DOMException.h>
#elif __has_include(<LibWeb/CSS/DOMException.h>)
#    include <LibWeb/CSS/DOMException.h>
#elif __has_include(<LibWeb/DOM/DOMException.h>)
#    include <LibWeb/DOM/DOMException.h>
#elif __has_include(<LibWeb/Encoding/DOMException.h>)
#    include <LibWeb/Encoding/DOMException.h>
#elif __has_include(<LibWeb/Geometry/DOMException.h>)
#    include <LibWeb/Geometry/DOMException.h>
#elif __has_include(<LibWeb/HTML/DOMException.h>)
#    include <LibWeb/HTML/DOMException.h>
#elif __has_include(<LibWeb/UIEvents/DOMException.h>)
#    include <LibWeb/UIEvents/DOMException.h>
#elif __has_include(<LibWeb/HighResolutionTime/DOMException.h>)
#    include <LibWeb/HighResolutionTime/DOMException.h>
#elif __has_include(<LibWeb/IntersectionObserver/DOMException.h>)
#    include <LibWeb/IntersectionObserver/DOMException.h>
#elif __has_include(<LibWeb/NavigationTiming/DOMException.h>)
#    include <LibWeb/NavigationTiming/DOMException.h>
#elif __has_include(<LibWeb/RequestIdleCallback/DOMException.h>)
#    include <LibWeb/RequestIdleCallback/DOMException.h>
#elif __has_include(<LibWeb/ResizeObserver/DOMException.h>)
#    include <LibWeb/ResizeObserver/DOMException.h>
#elif __has_include(<LibWeb/SVG/DOMException.h>)
#    include <LibWeb/SVG/DOMException.h>
#elif __has_include(<LibWeb/Selection/DOMException.h>)
#    include <LibWeb/Selection/DOMException.h>
#elif __has_include(<LibWeb/WebSockets/DOMException.h>)
#    include <LibWeb/WebSockets/DOMException.h>
#elif __has_include(<LibWeb/XHR/DOMException.h>)
#    include <LibWeb/XHR/DOMException.h>
#elif __has_include(<LibWeb/URL/DOMException.h>)
#    include <LibWeb/URL/DOMException.h>
#endif


#include <LibWeb/DOM/DOMException.h>

#include <LibWeb/DOM/DOMException.h>

#if __has_include(<LibWeb/Bindings/DOMExceptionWrapper.h>)
#   include <LibWeb/Bindings/DOMExceptionWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMExceptionWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMExceptionWrapperFactory.h>
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

DOMExceptionConstructor::DOMExceptionConstructor(JS::GlobalObject& global_object)
    : NativeFunction(*global_object.function_prototype())
{
}

DOMExceptionConstructor::~DOMExceptionConstructor()
{
}

JS::ThrowCompletionOr<JS::Value> DOMExceptionConstructor::call()
{
    return vm().throw_completion<JS::TypeError>(global_object(), JS::ErrorType::ConstructorWithoutNew, "DOMException");
}

JS::ThrowCompletionOr<JS::Object*> DOMExceptionConstructor::construct(FunctionObject&)
{

    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] auto& global_object = this->global_object();

    auto& window = static_cast<WindowObject&>(global_object);

    auto arg0 = vm.argument(0);

    String message;
    if (!arg0.is_undefined()) {
        if (arg0.is_null() && false)
            message = String::empty();
        else
            message = TRY(arg0.to_string(global_object));
    } else {
        message = "";
    }

    auto arg1 = vm.argument(1);

    String name;
    if (!arg1.is_undefined()) {
        if (arg1.is_null() && false)
            name = String::empty();
        else
            name = TRY(arg1.to_string(global_object));
    } else {
        name = "Error";
    }

    auto impl = TRY(throw_dom_exception_if_needed(global_object, [&] { return DOM::DOMException::create_with_global_object(window, message, name); }));

    return wrap(global_object, *impl);

}

void DOMExceptionConstructor::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    auto& window = static_cast<WindowObject&>(global_object);
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable;

    NativeFunction::initialize(global_object);
    define_direct_property(vm.names.prototype, &window.ensure_web_prototype<DOMExceptionPrototype>("DOMException"), 0);
    define_direct_property(vm.names.length, JS::Value(0), JS::Attribute::Configurable);


define_direct_property("INDEX_SIZE_ERR", JS::Value((i32)1), JS::Attribute::Enumerable);

define_direct_property("DOMSTRING_SIZE_ERR", JS::Value((i32)2), JS::Attribute::Enumerable);

define_direct_property("HIERARCHY_REQUEST_ERR", JS::Value((i32)3), JS::Attribute::Enumerable);

define_direct_property("WRONG_DOCUMENT_ERR", JS::Value((i32)4), JS::Attribute::Enumerable);

define_direct_property("INVALID_CHARACTER_ERR", JS::Value((i32)5), JS::Attribute::Enumerable);

define_direct_property("NO_DATA_ALLOWED_ERR", JS::Value((i32)6), JS::Attribute::Enumerable);

define_direct_property("NO_MODIFICATION_ALLOWED_ERR", JS::Value((i32)7), JS::Attribute::Enumerable);

define_direct_property("NOT_FOUND_ERR", JS::Value((i32)8), JS::Attribute::Enumerable);

define_direct_property("NOT_SUPPORTED_ERR", JS::Value((i32)9), JS::Attribute::Enumerable);

define_direct_property("INUSE_ATTRIBUTE_ERR", JS::Value((i32)10), JS::Attribute::Enumerable);

define_direct_property("INVALID_STATE_ERR", JS::Value((i32)11), JS::Attribute::Enumerable);

define_direct_property("SYNTAX_ERR", JS::Value((i32)12), JS::Attribute::Enumerable);

define_direct_property("INVALID_MODIFICATION_ERR", JS::Value((i32)13), JS::Attribute::Enumerable);

define_direct_property("NAMESPACE_ERR", JS::Value((i32)14), JS::Attribute::Enumerable);

define_direct_property("INVALID_ACCESS_ERR", JS::Value((i32)15), JS::Attribute::Enumerable);

define_direct_property("VALIDATION_ERR", JS::Value((i32)16), JS::Attribute::Enumerable);

define_direct_property("TYPE_MISMATCH_ERR", JS::Value((i32)17), JS::Attribute::Enumerable);

define_direct_property("SECURITY_ERR", JS::Value((i32)18), JS::Attribute::Enumerable);

define_direct_property("NETWORK_ERR", JS::Value((i32)19), JS::Attribute::Enumerable);

define_direct_property("ABORT_ERR", JS::Value((i32)20), JS::Attribute::Enumerable);

define_direct_property("URL_MISMATCH_ERR", JS::Value((i32)21), JS::Attribute::Enumerable);

define_direct_property("QUOTA_EXCEEDED_ERR", JS::Value((i32)22), JS::Attribute::Enumerable);

define_direct_property("TIMEOUT_ERR", JS::Value((i32)23), JS::Attribute::Enumerable);

define_direct_property("INVALID_NODE_TYPE_ERR", JS::Value((i32)24), JS::Attribute::Enumerable);

define_direct_property("DATA_CLONE_ERR", JS::Value((i32)25), JS::Attribute::Enumerable);

}

} // namespace Web::Bindings

