
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/ErrorEvent.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class ErrorEventWrapper : public EventWrapper {
    JS_OBJECT(ErrorEvent, EventWrapper);
public:
    static ErrorEventWrapper* create(JS::GlobalObject&, HTML::ErrorEvent&);

    ErrorEventWrapper(JS::GlobalObject&, HTML::ErrorEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ErrorEventWrapper() override;

    HTML::ErrorEvent& impl() { return static_cast<HTML::ErrorEvent&>(EventWrapper::impl()); }
    HTML::ErrorEvent const& impl() const { return static_cast<HTML::ErrorEvent const&>(EventWrapper::impl()); }

private:

};

ErrorEventWrapper* wrap(JS::GlobalObject&, HTML::ErrorEvent&);

} // namespace Web::Bindings

