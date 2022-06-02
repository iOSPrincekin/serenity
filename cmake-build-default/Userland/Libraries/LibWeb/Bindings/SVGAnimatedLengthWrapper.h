
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/SVG/SVGLength.h>

#include <LibWeb/SVG/SVGAnimatedLength.h>

namespace Web::Bindings {

class SVGAnimatedLengthWrapper : public Wrapper {
    JS_OBJECT(SVGAnimatedLength, Wrapper);
public:
    static SVGAnimatedLengthWrapper* create(JS::GlobalObject&, SVG::SVGAnimatedLength&);

    SVGAnimatedLengthWrapper(JS::GlobalObject&, SVG::SVGAnimatedLength&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGAnimatedLengthWrapper() override;

    SVG::SVGAnimatedLength& impl() { return *m_impl; }
    SVG::SVGAnimatedLength const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<SVG::SVGAnimatedLength> m_impl;
        
};

SVGAnimatedLengthWrapper* wrap(JS::GlobalObject&, SVG::SVGAnimatedLength&);

} // namespace Web::Bindings

