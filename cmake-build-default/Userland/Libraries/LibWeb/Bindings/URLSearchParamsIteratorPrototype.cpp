
#include <AK/Function.h>
#include <LibJS/Runtime/Array.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/FunctionObject.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/TypedArray.h>
#include <LibWeb/Bindings/URLSearchParamsIteratorPrototype.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/WindowObject.h>

#if __has_include(<LibWeb/URLSearchParamsIterator.h>)
#    include <LibWeb/URLSearchParamsIterator.h>
#endif

#include <LibWeb/URL/URLSearchParams.h>

//#if __has_include(<LibWeb/URL/URLSearchParamsIterator.h>)
#   include <LibWeb/URL/URLSearchParamsIterator.h>
//#endif
#if __has_include(<LibWeb/URL/URLSearchParamsIteratorFactory.h>)
#   include <LibWeb/URL/URLSearchParamsIteratorFactory.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsIteratorWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsIteratorWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsIteratorWrapperFactory.h>
#endif

#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapper.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/URLSearchParamsWrapperFactory.h>)
#   include <LibWeb/Bindings/URLSearchParamsWrapperFactory.h>
#endif

// FIXME: This is a total hack until we can figure out the namespace for a given type somehow.
using namespace Web::CSS;
using namespace Web::DOM;
using namespace Web::Geometry;
using namespace Web::HTML;
using namespace Web::IntersectionObserver;
using namespace Web::NavigationTiming;
using namespace Web::RequestIdleCallback;
using namespace Web::ResizeObserver;
using namespace Web::Selection;
using namespace Web::XHR;
using namespace Web::URL;

namespace Web::Bindings {

URLSearchParamsIteratorPrototype::URLSearchParamsIteratorPrototype(JS::GlobalObject& global_object)
    : Object(*global_object.iterator_prototype())
{
}

URLSearchParamsIteratorPrototype::~URLSearchParamsIteratorPrototype()
{
}

void URLSearchParamsIteratorPrototype::initialize(JS::GlobalObject& global_object)
{
    auto& vm = this->vm();
    Object::initialize(global_object);

    define_native_function(vm.names.next, next, 0, JS::Attribute::Configurable | JS::Attribute::Writable);
    define_direct_property(*vm.well_known_symbol_to_string_tag(), js_string(vm, "Iterator"), JS::Attribute::Configurable);
}

static JS::ThrowCompletionOr<URL::URLSearchParamsIterator*> impl_from(JS::VM& vm, JS::GlobalObject& global_object)
{
    auto* this_object = TRY(vm.this_value(global_object).to_object(global_object));
    if (!is<URLSearchParamsIteratorWrapper>(this_object))
        return vm.throw_completion<JS::TypeError>(global_object, JS::ErrorType::NotAnObjectOfType, "URL::URLSearchParamsIterator");
    return &static_cast<URLSearchParamsIteratorWrapper*>(this_object)->impl();
}

JS_DEFINE_NATIVE_FUNCTION(URLSearchParamsIteratorPrototype::next)
{
    auto* impl = TRY(impl_from(vm, global_object));
    return TRY(throw_dom_exception_if_needed(global_object, [&] { return impl->next(); }));
}

} // namespace Web::Bindings

