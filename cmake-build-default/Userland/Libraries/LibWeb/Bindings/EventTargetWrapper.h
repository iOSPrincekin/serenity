
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

namespace Web::Bindings {

class EventTargetWrapper : public Wrapper {
    JS_OBJECT(EventTarget, Wrapper);
public:
    static EventTargetWrapper* create(JS::GlobalObject&, DOM::EventTarget&);

    EventTargetWrapper(JS::GlobalObject&, DOM::EventTarget&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~EventTargetWrapper() override;

    DOM::EventTarget& impl() { return *m_impl; }
    DOM::EventTarget const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<DOM::EventTarget> m_impl;
        
};

} // namespace Web::Bindings

