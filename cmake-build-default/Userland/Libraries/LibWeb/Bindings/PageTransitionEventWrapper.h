
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HTML/PageTransitionEvent.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class PageTransitionEventWrapper : public EventWrapper {
    JS_OBJECT(PageTransitionEvent, EventWrapper);
public:
    static PageTransitionEventWrapper* create(JS::GlobalObject&, HTML::PageTransitionEvent&);

    PageTransitionEventWrapper(JS::GlobalObject&, HTML::PageTransitionEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~PageTransitionEventWrapper() override;

    HTML::PageTransitionEvent& impl() { return static_cast<HTML::PageTransitionEvent&>(EventWrapper::impl()); }
    HTML::PageTransitionEvent const& impl() const { return static_cast<HTML::PageTransitionEvent const&>(EventWrapper::impl()); }

private:

};

PageTransitionEventWrapper* wrap(JS::GlobalObject&, HTML::PageTransitionEvent&);

} // namespace Web::Bindings

