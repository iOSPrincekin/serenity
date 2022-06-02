
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Geometry/DOMRectList.h>

#include <LibWeb/HTML/HTMLTableCaptionElement.h>

#include <LibWeb/HTML/HTMLScriptElement.h>

#include <LibWeb/DOM/Comment.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLHeadElement.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/DOM/CharacterData.h>

#include <LibWeb/DOM/DOMImplementation.h>

#include <LibWeb/DOM/NodeList.h>

#include <LibWeb/DOM/DocumentType.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/Node.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/DOM/Document.h>

#include <LibWeb/DOM/DocumentFragment.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/Text.h>

#include <LibWeb/DOM/NodeFilter.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/NamedNodeMap.h>

#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/TreeWalker.h>

#include <LibWeb/HTML/HTMLTableElement.h>

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/DOM/Element.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/HTML/HTMLTableSectionElement.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/HTML/HTMLTableRowElement.h>

#include <LibWeb/DOM/HTMLCollection.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLTableElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLTableElement, HTMLElementWrapper);
public:
    static HTMLTableElementWrapper* create(JS::GlobalObject&, HTML::HTMLTableElement&);

    HTMLTableElementWrapper(JS::GlobalObject&, HTML::HTMLTableElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTableElementWrapper() override;

    HTML::HTMLTableElement& impl() { return static_cast<HTML::HTMLTableElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLTableElement const& impl() const { return static_cast<HTML::HTMLTableElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

