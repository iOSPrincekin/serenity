
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapper.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>)
#   include <LibWeb/Bindings/DOMRectReadOnlyWrapperFactory.h>
#endif

namespace Web::Bindings {

class DOMRectWrapper : public DOMRectReadOnlyWrapper {
    JS_OBJECT(DOMRect, DOMRectReadOnlyWrapper);
public:
    static DOMRectWrapper* create(JS::GlobalObject&, Geometry::DOMRect&);

    DOMRectWrapper(JS::GlobalObject&, Geometry::DOMRect&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMRectWrapper() override;

    Geometry::DOMRect& impl() { return static_cast<Geometry::DOMRect&>(DOMRectReadOnlyWrapper::impl()); }
    Geometry::DOMRect const& impl() const { return static_cast<Geometry::DOMRect const&>(DOMRectReadOnlyWrapper::impl()); }

private:

};

DOMRectWrapper* wrap(JS::GlobalObject&, Geometry::DOMRect&);

} // namespace Web::Bindings

