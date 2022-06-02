
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/CSS/MediaQueryListEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class MediaQueryListEventWrapper : public EventWrapper {
    JS_OBJECT(MediaQueryListEvent, EventWrapper);
public:
    static MediaQueryListEventWrapper* create(JS::GlobalObject&, CSS::MediaQueryListEvent&);

    MediaQueryListEventWrapper(JS::GlobalObject&, CSS::MediaQueryListEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MediaQueryListEventWrapper() override;

    CSS::MediaQueryListEvent& impl() { return static_cast<CSS::MediaQueryListEvent&>(EventWrapper::impl()); }
    CSS::MediaQueryListEvent const& impl() const { return static_cast<CSS::MediaQueryListEvent const&>(EventWrapper::impl()); }

private:

};

MediaQueryListEventWrapper* wrap(JS::GlobalObject&, CSS::MediaQueryListEvent&);

} // namespace Web::Bindings

