
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/SVG/SVGClipPathElement.h>

#if __has_include(<LibWeb/Bindings/SVGElementWrapper.h>)
#   include <LibWeb/Bindings/SVGElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGElementWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class SVGClipPathElementWrapper : public SVGElementWrapper {
    JS_OBJECT(SVGClipPathElement, SVGElementWrapper);
public:
    static SVGClipPathElementWrapper* create(JS::GlobalObject&, SVG::SVGClipPathElement&);

    SVGClipPathElementWrapper(JS::GlobalObject&, SVG::SVGClipPathElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGClipPathElementWrapper() override;

    SVG::SVGClipPathElement& impl() { return static_cast<SVG::SVGClipPathElement&>(SVGElementWrapper::impl()); }
    SVG::SVGClipPathElement const& impl() const { return static_cast<SVG::SVGClipPathElement const&>(SVGElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

