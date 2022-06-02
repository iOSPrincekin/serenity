
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/XHR/ProgressEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class ProgressEventWrapper : public EventWrapper {
    JS_OBJECT(ProgressEvent, EventWrapper);
public:
    static ProgressEventWrapper* create(JS::GlobalObject&, XHR::ProgressEvent&);

    ProgressEventWrapper(JS::GlobalObject&, XHR::ProgressEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ProgressEventWrapper() override;

    XHR::ProgressEvent& impl() { return static_cast<XHR::ProgressEvent&>(EventWrapper::impl()); }
    XHR::ProgressEvent const& impl() const { return static_cast<XHR::ProgressEvent const&>(EventWrapper::impl()); }

private:

};

ProgressEventWrapper* wrap(JS::GlobalObject&, XHR::ProgressEvent&);

} // namespace Web::Bindings

