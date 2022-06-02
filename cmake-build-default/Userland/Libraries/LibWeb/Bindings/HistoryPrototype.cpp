
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/DataView.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/IteratorOperations.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibJS/Runtime/Value.h>
#include <LibWeb/Bindings/HistoryPrototype.h>
#include <LibWeb/Bindings/HistoryWrapper.h>
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


#include <LibWeb/HTML/History.h>

#include <LibWeb/HTML/History.h>

#if __has_include(<LibWeb/Bindings/HistoryWrapper.h>)
#   include <LibWeb/Bindings/HistoryWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HistoryWrapperFactory.h>)
#   include <LibWeb/Bindings/HistoryWrapperFactory.h>
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

HistoryPrototype::HistoryPrototype([[maybe_unused]] JS::GlobalObject& global_object)
    : Object(*global_object.object_prototype())

{
}

HistoryPrototype::~HistoryPrototype()
{
}

void HistoryPrototype::initialize(JS::GlobalObject& global_object)
{
    [[maybe_unused]] auto& vm = this->vm();
    [[maybe_unused]] u8 default_attributes = JS::Attribute::Enumerable | JS::Attribute::Configurable | JS::Attribute::Writable;


    define_native_function("replaceState", replace_state, 2, default_attributes);

    define_native_function("pushState", push_state, 2, default_attributes);

    Object::initialize(global_object);
}

static JS::ThrowCompletionOr<HTML::History*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto this_value = vm.this_value(global_object);
    JS::Object* this_object = nullptr;
    if (this_value.is_nullish())
        this_object = &vm.current_realm()->global_object();
    else
        this_object = TRY(this_value.to_object(global_object));

    if (!is<HistoryWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "HTML::History");

    return &static_cast<HistoryWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(HistoryPrototype::push_state)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "pushState", "2");

    auto arg0 = vm.argument(0);

    auto data = arg0;

    auto arg1 = vm.argument(1);

    String unused;
    if (arg1.is_null() && false) {
        unused = String::empty();
    } else {
        unused = TRY(arg1.to_string(global_object));
    }

    auto arg2 = vm.argument(2);

    String url;
    if (!arg2.is_undefined()) {
        if (arg2.is_null() && false)
            url = String::empty();
        else
            url = TRY(arg2.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->push_state(data, unused, url); }));

    return JS::js_undefined();

}

JS_DEFINE_NATIVE_FUNCTION(HistoryPrototype::replace_state)
{

    auto* impl = TRY(impl_from(vm, global_object));

    if (vm.argument_count() < 2)
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::BadArgCountMany, "replaceState", "2");

    auto arg0 = vm.argument(0);

    auto data = arg0;

    auto arg1 = vm.argument(1);

    String unused;
    if (arg1.is_null() && false) {
        unused = String::empty();
    } else {
        unused = TRY(arg1.to_string(global_object));
    }

    auto arg2 = vm.argument(2);

    String url;
    if (!arg2.is_undefined()) {
        if (arg2.is_null() && false)
            url = String::empty();
        else
            url = TRY(arg2.to_string(global_object));
    }

    [[maybe_unused]] auto retval = TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->replace_state(data, unused, url); }));

    return JS::js_undefined();

}

} // namespace Web::Bindings

