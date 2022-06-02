
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/UIEvents/UIEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/UIEvents/FocusEvent.h>

#if __has_include(<LibWeb/Bindings/UIEventWrapper.h>)
#   include <LibWeb/Bindings/UIEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/UIEventWrapperFactory.h>)
#   include <LibWeb/Bindings/UIEventWrapperFactory.h>
#endif

namespace Web::Bindings {

class FocusEventWrapper : public UIEventWrapper {
    JS_OBJECT(FocusEvent, UIEventWrapper);
public:
    static FocusEventWrapper* create(JS::GlobalObject&, UIEvents::FocusEvent&);

    FocusEventWrapper(JS::GlobalObject&, UIEvents::FocusEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~FocusEventWrapper() override;

    UIEvents::FocusEvent& impl() { return static_cast<UIEvents::FocusEvent&>(UIEventWrapper::impl()); }
    UIEvents::FocusEvent const& impl() const { return static_cast<UIEvents::FocusEvent const&>(UIEventWrapper::impl()); }

private:

};

FocusEventWrapper* wrap(JS::GlobalObject&, UIEvents::FocusEvent&);

} // namespace Web::Bindings

