
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

#include <LibWeb/DOM/Node.h>

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

#include <LibWeb/ResizeObserver/ResizeObserver.h>

#include <LibWeb/DOM/AbstractRange.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/DOM/Range.h>

#include <LibWeb/DOM/NodeIterator.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/HTML/DOMStringMap.h>

namespace Web::Bindings {

class ResizeObserverWrapper : public Wrapper {
    JS_OBJECT(ResizeObserver, Wrapper);
public:
    static ResizeObserverWrapper* create(JS::GlobalObject&, ResizeObserver::ResizeObserver&);

    ResizeObserverWrapper(JS::GlobalObject&, ResizeObserver::ResizeObserver&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ResizeObserverWrapper() override;

    ResizeObserver::ResizeObserver& impl() { return *m_impl; }
    ResizeObserver::ResizeObserver const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<ResizeObserver::ResizeObserver> m_impl;
        
};

enum class ResizeObserverBoxOptions {

    ContentBox,

    BorderBox,

    DevicePixelContentBox,

};
inline String idl_enum_to_string(ResizeObserverBoxOptions value) {
    switch(value) {

    case ResizeObserverBoxOptions::ContentBox: return "content-box";

    case ResizeObserverBoxOptions::BorderBox: return "border-box";

    case ResizeObserverBoxOptions::DevicePixelContentBox: return "device-pixel-content-box";

    default: return "<unknown>";
    };
}

ResizeObserverWrapper* wrap(JS::GlobalObject&, ResizeObserver::ResizeObserver&);

} // namespace Web::Bindings

