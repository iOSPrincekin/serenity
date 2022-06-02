
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/WorkerNavigator.h>

namespace Web::Bindings {

class WorkerNavigatorWrapper : public Wrapper {
    JS_OBJECT(WorkerNavigator, Wrapper);
public:
    static WorkerNavigatorWrapper* create(JS::GlobalObject&, HTML::WorkerNavigator&);

    WorkerNavigatorWrapper(JS::GlobalObject&, HTML::WorkerNavigator&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WorkerNavigatorWrapper() override;

    HTML::WorkerNavigator& impl() { return *m_impl; }
    HTML::WorkerNavigator const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::WorkerNavigator> m_impl;
        
};

WorkerNavigatorWrapper* wrap(JS::GlobalObject&, HTML::WorkerNavigator&);

} // namespace Web::Bindings

