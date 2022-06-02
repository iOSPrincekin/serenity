
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/MessagePort.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class MessagePortWrapper : public EventTargetWrapper {
    JS_OBJECT(MessagePort, EventTargetWrapper);
public:
    static MessagePortWrapper* create(JS::GlobalObject&, HTML::MessagePort&);

    MessagePortWrapper(JS::GlobalObject&, HTML::MessagePort&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MessagePortWrapper() override;

    HTML::MessagePort& impl() { return static_cast<HTML::MessagePort&>(EventTargetWrapper::impl()); }
    HTML::MessagePort const& impl() const { return static_cast<HTML::MessagePort const&>(EventTargetWrapper::impl()); }

private:

};

MessagePortWrapper* wrap(JS::GlobalObject&, HTML::MessagePort&);

} // namespace Web::Bindings

