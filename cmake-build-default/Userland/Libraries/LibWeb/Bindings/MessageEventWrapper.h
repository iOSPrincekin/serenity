
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/MessageEvent.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventWrapper.h>)
#   include <LibWeb/Bindings/EventWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventWrapperFactory.h>)
#   include <LibWeb/Bindings/EventWrapperFactory.h>
#endif

namespace Web::Bindings {

class MessageEventWrapper : public EventWrapper {
    JS_OBJECT(MessageEvent, EventWrapper);
public:
    static MessageEventWrapper* create(JS::GlobalObject&, HTML::MessageEvent&);

    MessageEventWrapper(JS::GlobalObject&, HTML::MessageEvent&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MessageEventWrapper() override;

    HTML::MessageEvent& impl() { return static_cast<HTML::MessageEvent&>(EventWrapper::impl()); }
    HTML::MessageEvent const& impl() const { return static_cast<HTML::MessageEvent const&>(EventWrapper::impl()); }

private:

};

MessageEventWrapper* wrap(JS::GlobalObject&, HTML::MessageEvent&);

} // namespace Web::Bindings

