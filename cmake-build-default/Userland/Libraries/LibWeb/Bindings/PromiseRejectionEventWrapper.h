
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/PromiseRejectionEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class PromiseRejectionEventWrapper : public EventWrapper {
    JS_OBJECT(PromiseRejectionEvent, EventWrapper);
public:
    static PromiseRejectionEventWrapper* create(JS::GlobalObject&, HTML::PromiseRejectionEvent&);

    PromiseRejectionEventWrapper(JS::GlobalObject&, HTML::PromiseRejectionEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~PromiseRejectionEventWrapper() override;

    HTML::PromiseRejectionEvent& impl() { return static_cast<HTML::PromiseRejectionEvent&>(EventWrapper::impl()); }
    HTML::PromiseRejectionEvent const& impl() const { return static_cast<HTML::PromiseRejectionEvent const&>(EventWrapper::impl()); }

private:

};

PromiseRejectionEventWrapper* wrap(JS::GlobalObject&, HTML::PromiseRejectionEvent&);

} // namespace Web::Bindings

