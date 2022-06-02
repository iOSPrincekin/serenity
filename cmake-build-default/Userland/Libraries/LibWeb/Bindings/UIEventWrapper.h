
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/UIEvents/UIEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class UIEventWrapper : public EventWrapper {
    JS_OBJECT(UIEvent, EventWrapper);
public:
    static UIEventWrapper* create(JS::GlobalObject&, UIEvents::UIEvent&);

    UIEventWrapper(JS::GlobalObject&, UIEvents::UIEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~UIEventWrapper() override;

    UIEvents::UIEvent& impl() { return static_cast<UIEvents::UIEvent&>(EventWrapper::impl()); }
    UIEvents::UIEvent const& impl() const { return static_cast<UIEvents::UIEvent const&>(EventWrapper::impl()); }

private:

};

UIEventWrapper* wrap(JS::GlobalObject&, UIEvents::UIEvent&);

} // namespace Web::Bindings

