
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/DOMExceptionPrototype.h>
#include <LibWeb/Bindings/DOMExceptionWrapper.h>
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


#include <LibWeb/DOM/DOMException.h>

#include <LibWeb/DOM/DOMException.h>

#if __has_include(<LibWeb/Bindings/DOMExceptionWrapper.h>)
#   include <LibWeb/Bindings/DOMExceptionWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMExceptionWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMExceptionWrapperFactory.h>
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

DOMExceptionPrototype::DOMExceptionPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.error_prototype())

{
}

DOMExceptionPrototype::~DOMExceptionPrototype()
{
}

void DOMExceptionPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("name", name_getter, nullptr, default_attributes);

    define_native_accessor("message", message_getter, nullptr, default_attributes);

    define_native_accessor("code", code_getter, nullptr, default_attributes);

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

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<DOM::DOMException*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<DOMExceptionWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "DOM::DOMException");

    return &static_cast<DOMExceptionWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(DOMExceptionPrototype::name_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->name(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMExceptionPrototype::message_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->message(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(DOMExceptionPrototype::code_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->code(); }));

    return JS::Value((i32)retval);

}

} // namespace Web::Bindings

