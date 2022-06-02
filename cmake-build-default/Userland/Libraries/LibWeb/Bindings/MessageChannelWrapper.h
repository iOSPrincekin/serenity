
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/MessagePort.h>

#include <LibWeb/HTML/MessageChannel.h>

#include <LibWeb/DOM/AbortSignal.h>

namespace Web::Bindings {

class MessageChannelWrapper : public Wrapper {
    JS_OBJECT(MessageChannel, Wrapper);
public:
    static MessageChannelWrapper* create(JS::GlobalObject&, HTML::MessageChannel&);

    MessageChannelWrapper(JS::GlobalObject&, HTML::MessageChannel&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MessageChannelWrapper() override;

    HTML::MessageChannel& impl() { return *m_impl; }
    HTML::MessageChannel const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::MessageChannel> m_impl;
        
};

MessageChannelWrapper* wrap(JS::GlobalObject&, HTML::MessageChannel&);

} // namespace Web::Bindings

