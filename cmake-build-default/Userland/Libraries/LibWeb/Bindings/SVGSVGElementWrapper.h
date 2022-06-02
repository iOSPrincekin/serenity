
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Geometry/DOMRectList.h>

#include <LibWeb/SVG/SVGGraphicsElement.h>

#include <LibWeb/HTML/HTMLScriptElement.h>

#include <LibWeb/DOM/Comment.h>

#include <LibWeb/HTML/HTMLHeadElement.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/DOM/CharacterData.h>

#include <LibWeb/DOM/DOMImplementation.h>

#include <LibWeb/DOM/NodeList.h>

#include <LibWeb/DOM/DocumentType.h>

#include <LibWeb/DOM/HTMLCollection.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Node.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/DOM/Document.h>

#include <LibWeb/SVG/SVGElement.h>

#include <LibWeb/DOM/DocumentFragment.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/Text.h>

#include <LibWeb/DOM/NodeFilter.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/DOM/NamedNodeMap.h>

#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/TreeWalker.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/SVG/SVGSVGElement.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/DOM/Element.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/SVGGraphicsElementWrapper.h>)
#   include <LibWeb/Bindings/SVGGraphicsElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/SVGGraphicsElementWrapperFactory.h>)
#   include <LibWeb/Bindings/SVGGraphicsElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class SVGSVGElementWrapper : public SVGGraphicsElementWrapper {
    JS_OBJECT(SVGSVGElement, SVGGraphicsElementWrapper);
public:
    static SVGSVGElementWrapper* create(JS::GlobalObject&, SVG::SVGSVGElement&);

    SVGSVGElementWrapper(JS::GlobalObject&, SVG::SVGSVGElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SVGSVGElementWrapper() override;

    SVG::SVGSVGElement& impl() { return static_cast<SVG::SVGSVGElement&>(SVGGraphicsElementWrapper::impl()); }
    SVG::SVGSVGElement const& impl() const { return static_cast<SVG::SVGSVGElement const&>(SVGGraphicsElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

