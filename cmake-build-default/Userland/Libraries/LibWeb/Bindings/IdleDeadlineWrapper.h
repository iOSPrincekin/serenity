
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/RequestIdleCallback/IdleDeadline.h>

namespace Web::Bindings {

class IdleDeadlineWrapper : public Wrapper {
    JS_OBJECT(IdleDeadline, Wrapper);
public:
    static IdleDeadlineWrapper* create(JS::GlobalObject&, RequestIdleCallback::IdleDeadline&);

    IdleDeadlineWrapper(JS::GlobalObject&, RequestIdleCallback::IdleDeadline&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~IdleDeadlineWrapper() override;

    RequestIdleCallback::IdleDeadline& impl() { return *m_impl; }
    RequestIdleCallback::IdleDeadline const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<RequestIdleCallback::IdleDeadline> m_impl;
        
};

IdleDeadlineWrapper* wrap(JS::GlobalObject&, RequestIdleCallback::IdleDeadline&);

} // namespace Web::Bindings

