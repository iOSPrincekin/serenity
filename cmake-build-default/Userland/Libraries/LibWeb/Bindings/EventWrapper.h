
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/AbortSignal.h>

namespace Web::Bindings {

class EventWrapper : public Wrapper {
    JS_OBJECT(Event, Wrapper);
public:
    static EventWrapper* create(JS::GlobalObject&, DOM::Event&);

    EventWrapper(JS::GlobalObject&, DOM::Event&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~EventWrapper() override;

    DOM::Event& impl() { return *m_impl; }
    DOM::Event const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<DOM::Event> m_impl;
        
};

} // namespace Web::Bindings

