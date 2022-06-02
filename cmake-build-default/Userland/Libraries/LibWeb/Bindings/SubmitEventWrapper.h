
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/SubmitEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class SubmitEventWrapper : public EventWrapper {
    JS_OBJECT(SubmitEvent, EventWrapper);
public:
    static SubmitEventWrapper* create(JS::GlobalObject&, HTML::SubmitEvent&);

    SubmitEventWrapper(JS::GlobalObject&, HTML::SubmitEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SubmitEventWrapper() override;

    HTML::SubmitEvent& impl() { return static_cast<HTML::SubmitEvent&>(EventWrapper::impl()); }
    HTML::SubmitEvent const& impl() const { return static_cast<HTML::SubmitEvent const&>(EventWrapper::impl()); }

private:

};

SubmitEventWrapper* wrap(JS::GlobalObject&, HTML::SubmitEvent&);

} // namespace Web::Bindings

