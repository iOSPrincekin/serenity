
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Geometry/DOMRectList.h>

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

#include <LibWeb/Geometry/DOMRect.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/DOM/Document.h>

#include <LibWeb/DOM/DocumentFragment.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/DOM/AbortSignal.h>

#include <LibWeb/DOM/Text.h>

#include <LibWeb/DOM/NodeFilter.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/DOM/Event.h>

#include <LibWeb/DOM/NamedNodeMap.h>

#include <LibWeb/HTML/DOMParser.h>

#include <LibWeb/DOM/DOMTokenList.h>

#include <LibWeb/DOM/TreeWalker.h>

#include <LibWeb/DOM/HTMLCollection.h>

#include <LibWeb/DOM/Node.h>

#include <LibWeb/DOM/Attribute.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/HTML/DOMStringMap.h>

namespace Web::Bindings {

class DOMParserWrapper : public Wrapper {
    JS_OBJECT(DOMParser, Wrapper);
public:
    static DOMParserWrapper* create(JS::GlobalObject&, HTML::DOMParser&);

    DOMParserWrapper(JS::GlobalObject&, HTML::DOMParser&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMParserWrapper() override;

    HTML::DOMParser& impl() { return *m_impl; }
    HTML::DOMParser const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::DOMParser> m_impl;
        
};

enum class DOMParserSupportedType {

    Application_Xhtml_Xml,

    Text_Xml,

    Image_Svg_Xml,

    Application_Xml,

    Text_Html,

};
inline String idl_enum_to_string(DOMParserSupportedType value) {
    switch(value) {

    case DOMParserSupportedType::Application_Xhtml_Xml: return "application/xhtml+xml";

    case DOMParserSupportedType::Text_Xml: return "text/xml";

    case DOMParserSupportedType::Image_Svg_Xml: return "image/svg+xml";

    case DOMParserSupportedType::Application_Xml: return "application/xml";

    case DOMParserSupportedType::Text_Html: return "text/html";

    default: return "<unknown>";
    };
}

DOMParserWrapper* wrap(JS::GlobalObject&, HTML::DOMParser&);

} // namespace Web::Bindings

