
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/HTML/CloseEvent.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class CloseEventWrapper : public EventWrapper {
    JS_OBJECT(CloseEvent, EventWrapper);
public:
    static CloseEventWrapper* create(JS::GlobalObject&, HTML::CloseEvent&);

    CloseEventWrapper(JS::GlobalObject&, HTML::CloseEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CloseEventWrapper() override;

    HTML::CloseEvent& impl() { return static_cast<HTML::CloseEvent&>(EventWrapper::impl()); }
    HTML::CloseEvent const& impl() const { return static_cast<HTML::CloseEvent const&>(EventWrapper::impl()); }

private:

};

CloseEventWrapper* wrap(JS::GlobalObject&, HTML::CloseEvent&);

} // namespace Web::Bindings

