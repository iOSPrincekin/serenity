
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/CustomEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class CustomEventWrapper : public EventWrapper {
    JS_OBJECT(CustomEvent, EventWrapper);
public:
    static CustomEventWrapper* create(JS::GlobalObject&, DOM::CustomEvent&);

    CustomEventWrapper(JS::GlobalObject&, DOM::CustomEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CustomEventWrapper() override;

    virtual void visit_edges(JS::Cell::Visitor&) override;

    DOM::CustomEvent& impl() { return static_cast<DOM::CustomEvent&>(EventWrapper::impl()); }
    DOM::CustomEvent const& impl() const { return static_cast<DOM::CustomEvent const&>(EventWrapper::impl()); }

private:

};

CustomEventWrapper* wrap(JS::GlobalObject&, DOM::CustomEvent&);

} // namespace Web::Bindings

