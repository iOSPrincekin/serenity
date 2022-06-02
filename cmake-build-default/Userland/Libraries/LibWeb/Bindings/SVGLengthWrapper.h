
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/SVG/SVGLength.h>

namespace Web::Bindings {

class SVGLengthWrapper : public Wrapper {
    JS_OBJECT(SVGLength, Wrapper);
public:
    static SVGLengthWrapper* create(JS::GlobalObject&, SVG::SVGLength&);

    SVGLengthWrapper(JS::GlobalObject&, SVG::SVGLength&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGLengthWrapper() override;

    SVG::SVGLength& impl() { return *m_impl; }
    SVG::SVGLength const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<SVG::SVGLength> m_impl;
        
};

SVGLengthWrapper* wrap(JS::GlobalObject&, SVG::SVGLength&);

} // namespace Web::Bindings

