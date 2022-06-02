
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/SVG/SVGDefsElement.h>

#if __has_include(<LibWeb/Bindings/SVGGraphicsElementWrapper.h>)
#   include <LibWeb/Bindings/SVGGraphicsElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGGraphicsElementWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGGraphicsElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class SVGDefsElementWrapper : public SVGGraphicsElementWrapper {
    JS_OBJECT(SVGDefsElement, SVGGraphicsElementWrapper);
public:
    static SVGDefsElementWrapper* create(JS::GlobalObject&, SVG::SVGDefsElement&);

    SVGDefsElementWrapper(JS::GlobalObject&, SVG::SVGDefsElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGDefsElementWrapper() override;

    SVG::SVGDefsElement& impl() { return static_cast<SVG::SVGDefsElement&>(SVGGraphicsElementWrapper::impl()); }
    SVG::SVGDefsElement const& impl() const { return static_cast<SVG::SVGDefsElement const&>(SVGGraphicsElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

