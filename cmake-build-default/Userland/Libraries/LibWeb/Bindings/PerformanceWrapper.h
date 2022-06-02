
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/HighResolutionTime/Performance.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class PerformanceWrapper : public EventTargetWrapper {
    JS_OBJECT(Performance, EventTargetWrapper);
public:
    static PerformanceWrapper* create(JS::GlobalObject&, HighResolutionTime::Performance&);

    PerformanceWrapper(JS::GlobalObject&, HighResolutionTime::Performance&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~PerformanceWrapper() override;

    HighResolutionTime::Performance& impl() { return static_cast<HighResolutionTime::Performance&>(EventTargetWrapper::impl()); }
    HighResolutionTime::Performance const& impl() const { return static_cast<HighResolutionTime::Performance const&>(EventTargetWrapper::impl()); }

private:

};

PerformanceWrapper* wrap(JS::GlobalObject&, HighResolutionTime::Performance&);

} // namespace Web::Bindings

