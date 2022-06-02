
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/NavigationTiming/PerformanceTiming.h>

namespace Web::Bindings {

class PerformanceTimingWrapper : public Wrapper {
    JS_OBJECT(PerformanceTiming, Wrapper);
public:
    static PerformanceTimingWrapper* create(JS::GlobalObject&, NavigationTiming::PerformanceTiming&);

    PerformanceTimingWrapper(JS::GlobalObject&, NavigationTiming::PerformanceTiming&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~PerformanceTimingWrapper() override;

    NavigationTiming::PerformanceTiming& impl() { return *m_impl; }
    NavigationTiming::PerformanceTiming const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<NavigationTiming::PerformanceTiming> m_impl;
        
};

PerformanceTimingWrapper* wrap(JS::GlobalObject&, NavigationTiming::PerformanceTiming&);

} // namespace Web::Bindings

