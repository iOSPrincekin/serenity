
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLScriptElement.h>

#include <LibWeb/SVG/SVGAnimatedLength.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/DOM/DOMImplementation.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Node.h>

#include <LibWeb/DOM/Document.h>

#include <LibWeb/SVG/SVGElement.h>

#include <LibWeb/DOM/DocumentFragment.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/Text.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/DOM/NamedNodeMap.h>

#include <LibWeb/SVG/SVGGraphicsElement.h>

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/SVG/SVGLength.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/Geometry/DOMRectList.h>

#include <LibWeb/DOM/CharacterData.h>

#include <LibWeb/DOM/Comment.h>

#include <LibWeb/HTML/HTMLHeadElement.h>

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/DOM/NodeList.h>

#include <LibWeb/DOM/DocumentType.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/SVG/SVGRectElement.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/DOM/NodeFilter.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/TreeWalker.h>

#include <LibWeb/DOM/HTMLCollection.h>

#include <LibWeb/DOM/Element.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/SVG/SVGGeometryElement.h>

#if __has_include(<LibWeb/Bindings/SVGGeometryElementWrapper.h>)
#   include <LibWeb/Bindings/SVGGeometryElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGGeometryElementWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGGeometryElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class SVGRectElementWrapper : public SVGGeometryElementWrapper {
    JS_OBJECT(SVGRectElement, SVGGeometryElementWrapper);
public:
    static SVGRectElementWrapper* create(JS::GlobalObject&, SVG::SVGRectElement&);

    SVGRectElementWrapper(JS::GlobalObject&, SVG::SVGRectElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGRectElementWrapper() override;

    SVG::SVGRectElement& impl() { return static_cast<SVG::SVGRectElement&>(SVGGeometryElementWrapper::impl()); }
    SVG::SVGRectElement const& impl() const { return static_cast<SVG::SVGRectElement const&>(SVGGeometryElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

