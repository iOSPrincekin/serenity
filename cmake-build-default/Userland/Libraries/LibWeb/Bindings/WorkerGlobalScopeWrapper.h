
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/WorkerNavigator.h>

#include <LibWeb/HTML/WorkerGlobalScope.h>

#include <LibWeb/HTML/WorkerLocation.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class WorkerGlobalScopeWrapper : public EventTargetWrapper {
    JS_OBJECT(WorkerGlobalScope, EventTargetWrapper);
public:
    static WorkerGlobalScopeWrapper* create(JS::GlobalObject&, HTML::WorkerGlobalScope&);

    WorkerGlobalScopeWrapper(JS::GlobalObject&, HTML::WorkerGlobalScope&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WorkerGlobalScopeWrapper() override;

    HTML::WorkerGlobalScope& impl() { return static_cast<HTML::WorkerGlobalScope&>(EventTargetWrapper::impl()); }
    HTML::WorkerGlobalScope const& impl() const { return static_cast<HTML::WorkerGlobalScope const&>(EventTargetWrapper::impl()); }

private:

};

WorkerGlobalScopeWrapper* wrap(JS::GlobalObject&, HTML::WorkerGlobalScope&);

} // namespace Web::Bindings

