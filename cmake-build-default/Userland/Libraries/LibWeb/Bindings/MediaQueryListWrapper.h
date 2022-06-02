
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/CSS/MediaQueryList.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class MediaQueryListWrapper : public EventTargetWrapper {
    JS_OBJECT(MediaQueryList, EventTargetWrapper);
public:
    static MediaQueryListWrapper* create(JS::GlobalObject&, CSS::MediaQueryList&);

    MediaQueryListWrapper(JS::GlobalObject&, CSS::MediaQueryList&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MediaQueryListWrapper() override;

    CSS::MediaQueryList& impl() { return static_cast<CSS::MediaQueryList&>(EventTargetWrapper::impl()); }
    CSS::MediaQueryList const& impl() const { return static_cast<CSS::MediaQueryList const&>(EventTargetWrapper::impl()); }

private:

};

MediaQueryListWrapper* wrap(JS::GlobalObject&, CSS::MediaQueryList&);

} // namespace Web::Bindings

