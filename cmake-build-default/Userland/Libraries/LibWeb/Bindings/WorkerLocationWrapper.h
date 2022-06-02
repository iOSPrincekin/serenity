
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/WorkerLocation.h>

namespace Web::Bindings {

class WorkerLocationWrapper : public Wrapper {
    JS_OBJECT(WorkerLocation, Wrapper);
public:
    static WorkerLocationWrapper* create(JS::GlobalObject&, HTML::WorkerLocation&);

    WorkerLocationWrapper(JS::GlobalObject&, HTML::WorkerLocation&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WorkerLocationWrapper() override;

    HTML::WorkerLocation& impl() { return *m_impl; }
    HTML::WorkerLocation const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::WorkerLocation> m_impl;
        
};

WorkerLocationWrapper* wrap(JS::GlobalObject&, HTML::WorkerLocation&);

} // namespace Web::Bindings

