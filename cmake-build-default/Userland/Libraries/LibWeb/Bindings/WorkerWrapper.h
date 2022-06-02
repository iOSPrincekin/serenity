
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/HTML/Worker.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class WorkerWrapper : public EventTargetWrapper {
    JS_OBJECT(Worker, EventTargetWrapper);
public:
    static WorkerWrapper* create(JS::GlobalObject&, HTML::Worker&);

    WorkerWrapper(JS::GlobalObject&, HTML::Worker&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WorkerWrapper() override;

    HTML::Worker& impl() { return static_cast<HTML::Worker&>(EventTargetWrapper::impl()); }
    HTML::Worker const& impl() const { return static_cast<HTML::Worker const&>(EventTargetWrapper::impl()); }

private:

};

WorkerWrapper* wrap(JS::GlobalObject&, HTML::Worker&);

} // namespace Web::Bindings

