
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class AbortSignalWrapper : public EventTargetWrapper {
    JS_OBJECT(AbortSignal, EventTargetWrapper);
public:
    static AbortSignalWrapper* create(JS::GlobalObject&, DOM::AbortSignal&);

    AbortSignalWrapper(JS::GlobalObject&, DOM::AbortSignal&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~AbortSignalWrapper() override;

    virtual void visit_edges(JS::Cell::Visitor&) override;

    DOM::AbortSignal& impl() { return static_cast<DOM::AbortSignal&>(EventTargetWrapper::impl()); }
    DOM::AbortSignal const& impl() const { return static_cast<DOM::AbortSignal const&>(EventTargetWrapper::impl()); }

private:

};

AbortSignalWrapper* wrap(JS::GlobalObject&, DOM::AbortSignal&);

} // namespace Web::Bindings

