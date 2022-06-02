
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/UIEvents/MouseEvent.h>

#if __has_include(<LibWeb/Bindings/UIEventWrapper.h>)
#   include <LibWeb/Bindings/UIEventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/UIEventWrapperFactory.h>)
#   include <LibWeb/Bindings/UIEventWrapperFactory.h>
#endif

namespace Web::Bindings {

class MouseEventWrapper : public UIEventWrapper {
    JS_OBJECT(MouseEvent, UIEventWrapper);
public:
    static MouseEventWrapper* create(JS::GlobalObject&, UIEvents::MouseEvent&);

    MouseEventWrapper(JS::GlobalObject&, UIEvents::MouseEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MouseEventWrapper() override;

    UIEvents::MouseEvent& impl() { return static_cast<UIEvents::MouseEvent&>(UIEventWrapper::impl()); }
    UIEvents::MouseEvent const& impl() const { return static_cast<UIEvents::MouseEvent const&>(UIEventWrapper::impl()); }

private:

};

MouseEventWrapper* wrap(JS::GlobalObject&, UIEvents::MouseEvent&);

} // namespace Web::Bindings

