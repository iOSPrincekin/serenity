
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

namespace Web::Bindings {

class DOMRectReadOnlyWrapper : public Wrapper {
    JS_OBJECT(DOMRectReadOnly, Wrapper);
public:
    static DOMRectReadOnlyWrapper* create(JS::GlobalObject&, Geometry::DOMRectReadOnly&);

    DOMRectReadOnlyWrapper(JS::GlobalObject&, Geometry::DOMRectReadOnly&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMRectReadOnlyWrapper() override;

    Geometry::DOMRectReadOnly& impl() { return *m_impl; }
    Geometry::DOMRectReadOnly const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<Geometry::DOMRectReadOnly> m_impl;
        
};

DOMRectReadOnlyWrapper* wrap(JS::GlobalObject&, Geometry::DOMRectReadOnly&);

} // namespace Web::Bindings

