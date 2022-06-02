
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/MediaList.h>

#include <LibWeb/DOM/Element.h>

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

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/Text.h>

#include <LibWeb/DOM/NodeFilter.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/NamedNodeMap.h>

#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/TreeWalker.h>

#include <LibWeb/DOM/HTMLCollection.h>

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/CSS/StyleSheet.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/Geometry/DOMRectList.h>

#include <LibWeb/HTML/DOMStringMap.h>

namespace Web::Bindings {

class StyleSheetWrapper : public Wrapper {
    JS_OBJECT(StyleSheet, Wrapper);
public:
    static StyleSheetWrapper* create(JS::GlobalObject&, CSS::StyleSheet&);

    StyleSheetWrapper(JS::GlobalObject&, CSS::StyleSheet&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~StyleSheetWrapper() override;

    CSS::StyleSheet& impl() { return *m_impl; }
    CSS::StyleSheet const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<CSS::StyleSheet> m_impl;
        
};

StyleSheetWrapper* wrap(JS::GlobalObject&, CSS::StyleSheet&);

} // namespace Web::Bindings

