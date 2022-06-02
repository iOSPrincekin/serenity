
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/XMLHttpRequestPrototype.h>
#include <LibWeb/Bindings/XMLHttpRequestWrapper.h>
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

#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetPrototype.h>)
#    include <LibWeb/Bindings/XMLHttpRequestEventTargetPrototype.h>
#endif


#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/XHR/XMLHttpRequest.h>

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/XHR/XMLHttpRequest.h>

#if __has_include(<LibWeb/Bindings/XMLHttpRequestWrapper.h>)
#   include <LibWeb/Bindings/XMLHttpRequestWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/XMLHttpRequestWrapperFactory.h>)
#   include <LibWeb/Bindings/XMLHttpRequestWrapperFactory.h>
#endif

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>)
#   include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapperFactory.h>
#endif

#include <LibWeb/DOM/EventTarget.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/AbortSignalWrapper.h>)
#   include <LibWeb/Bindings/AbortSignalWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/AbortSignalWrapperFactory.h>)
#   include <LibWeb/Bindings/AbortSignalWrapperFactory.h>
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

XMLHttpRequestPrototype::XMLHttpRequestPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(static_cast<WindowObject&>(global_object).ensure_web_prototype<XMLHttpRequestEventTargetPrototype>("XMLHttpRequestEventTarget"))

{
}

XMLHttpRequestPrototype::~XMLHttpRequestPrototype()
{
}

void XMLHttpRequestPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_accessor("readyState", ready_state_getter, nullptr, default_attributes);

    define_native_accessor("status", status_getter, nullptr, default_attributes);

    define_native_accessor("responseText", response_text_getter, nullptr, default_attributes);

    define_native_accessor("response", response_getter, nullptr, default_attributes);

    define_native_accessor("responseType", response_type_getter, response_type_setter, default_attributes);

    define_native_accessor("onreadystatechange", onreadystatechange_getter, onreadystatechange_setter, default_attributes);

    define_direct_property("UNSENT", JS::Value((i32)0), JS::Attribute::Enumerable);

    define_direct_property("OPENED", JS::Value((i32)1), JS::Attribute::Enumerable);

    define_direct_property("HEADERS_RECEIVED", JS::Value((i32)2), JS::Attribute::Enumerable);

    define_direct_property("LOADING", JS::Value((i32)3), JS::Attribute::Enumerable);

    define_direct_property("DONE", JS::Value((i32)4), JS::Attribute::Enumerable);

    define_native_function("send", send, 0, default_attributes);

    define_native_function("getAllResponseHeaders", get_all_response_headers, 0, default_attributes);

    define_native_function("setRequestHeader", set_request_header, 2, default_attributes);

    define_native_function("getResponseHeader", get_response_header, 1, default_attributes);

    define_native_function("open", open, 2, default_attributes);

    define_native_function("overrideMimeType", override_mime_type, 1, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<XHR::XMLHttpRequest*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<XMLHttpRequestWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "XHR::XMLHttpRequest");

    return &static_cast<XMLHttpRequestWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::ready_state_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->ready_state(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::status_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->status(); }));

    return JS::Value((i32)retval);

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::response_text_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->response_text(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::response_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->response(); }));

    return retval;

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::response_type_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->response_type(); }));

    return JS::js_string(global_object.heap(), Bindings::idl_enum_to_string(retval));

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::response_type_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    XMLHttpRequestResponseType cpp_value { XMLHttpRequestResponseType::Empty };
    auto value_string = TRY(value.to_string(global_object));

    if (value_string == ""sv)
        cpp_value = XMLHttpRequestResponseType::Empty;

    else if (value_string == "blob"sv)
        cpp_value = XMLHttpRequestResponseType::Blob;

    else if (value_string == "document"sv)
        cpp_value = XMLHttpRequestResponseType::Document;

    else if (value_string == "json"sv)
        cpp_value = XMLHttpRequestResponseType::Json;

    else if (value_string == "text"sv)
        cpp_value = XMLHttpRequestResponseType::Text;

    else if (value_string == "arraybuffer"sv)
        cpp_value = XMLHttpRequestResponseType::Arraybuffer;

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_response_type(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::onreadystatechange_getter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->onreadystatechange(); }));

    if (!retval) {
        return JS::js_null();
    } else {

  VERIFY(!retval->callback.is_null());
  return retval->callback.cell();

    }

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::onreadystatechange_setter)
{
    auto* impl = TRY(impl_from(vm, global_object));

    auto value = vm.argument(0);

    Optional<Bindings::CallbackType> cpp_value;
    if (value.is_object())
        cpp_value = Bindings::CallbackType { JS::make_handle(&value.as_object()), HTML::incumbent_settings_object() };

    TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_onreadystatechange(cpp_value); }));

    return JS::js_undefined();
}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::open0)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    String method;
    if (arg0.is_null() && false) {
        method = String::empty();
    } else {
        method = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String url;
    if (arg1.is_null() && false) {
        url = String::empty();
    } else {
        url = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->open(method, url); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::open1)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    String method;
    if (arg0.is_null() && false) {
        method = String::empty();
    } else {
        method = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String url;
    if (arg1.is_null() && false) {
        url = String::empty();
    } else {
        url = TRY(arg1.to_string(global_object));
    }

    auto arg2 = vm.argument(2);

    bool async;

    async = arg2.to_boolean();

    auto arg3 = vm.argument(3);

    String username;
    if (!arg3.is_undefined()) {
        if (arg3.is_null() && false)
            username = String::empty();
        else
            username = TRY(arg3.to_string(global_object));
    } else {
        username = {};
    }

    auto arg4 = vm.argument(4);

    String password;
    if (!arg4.is_undefined()) {
        if (arg4.is_null() && false)
            password = String::empty();
        else
            password = TRY(arg4.to_string(global_object));
    } else {
        password = {};
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->open(method, url, async, username, password); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::set_request_header)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "setRequestHeader", "2");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    auto arg1 = vm.argument(1);

    String value;
    if (arg1.is_null() && false) {
        value = String::empty();
    } else {
        value = TRY(arg1.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->set_request_header(name, value); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::send)
{

    auto* impl = TRY(impl_from(vm, global_object));

    auto arg0 = vm.argument(0);

    String body;
    if (!arg0.is_undefined()) {
        if (arg0.is_null() && false)
            body = String::empty();
        else
            body = TRY(arg0.to_string(global_object));
    } else {
        body = {};
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->send(body); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::get_response_header)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "getResponseHeader");

    auto arg0 = vm.argument(0);

    String name;
    if (arg0.is_null() && false) {
        name = String::empty();
    } else {
        name = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_response_header(name); }));

    if (retval.is_null()) {
        return JS::js_null();
    } else {

    return JS::js_string(vm, retval);

    }

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::get_all_response_headers)
{

    auto* impl = TRY(impl_from(vm, global_object));

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->get_all_response_headers(); }));

    return JS::js_string(vm, retval);

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::override_mime_type)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 1)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountOne, "overrideMimeType");

    auto arg0 = vm.argument(0);

    String mime;
    if (arg0.is_null() && false) {
        mime = String::empty();
    } else {
        mime = TRY(arg0.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->override_mime_type(mime); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(XMLHttpRequestPrototype::open)
{

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "open", "2");

    [[maybe_unused]] auto arg0 = vm.argument(0);

    [[maybe_unused]] auto arg1 = vm.argument(1);

    if (vm.argument_count() == 2) {

    return open0(vm, global_object);

    }

    [[maybe_unused]] auto arg2 = vm.argument(2);

    [[maybe_unused]] auto arg3 = vm.argument(3);

    [[maybe_unused]] auto arg4 = vm.argument(4);

    return open1(vm, global_object);

    return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::OverloadResolutionFailed);
}

} // namespace Web::Bindings

