
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/UIEvents/UIEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/UIEvents/KeyboardEvent.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/UIEventWrapper.h>)
#   include <LibWeb/Bindings/UIEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/UIEventWrapperFactory.h>)
#   include <LibWeb/Bindings/UIEventWrapperFactory.h>
#endif

namespace Web::Bindings {

class KeyboardEventWrapper : public UIEventWrapper {
    JS_OBJECT(KeyboardEvent, UIEventWrapper);
public:
    static KeyboardEventWrapper* create(JS::GlobalObject&, UIEvents::KeyboardEvent&);

    KeyboardEventWrapper(JS::GlobalObject&, UIEvents::KeyboardEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~KeyboardEventWrapper() override;

    UIEvents::KeyboardEvent& impl() { return static_cast<UIEvents::KeyboardEvent&>(UIEventWrapper::impl()); }
    UIEvents::KeyboardEvent const& impl() const { return static_cast<UIEvents::KeyboardEvent const&>(UIEventWrapper::impl()); }

private:

};

KeyboardEventWrapper* wrap(JS::GlobalObject&, UIEvents::KeyboardEvent&);

} // namespace Web::Bindings

