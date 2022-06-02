
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLStyleElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLStyleElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLStyleElement, HTMLElementWrapper);
public:
    static HTMLStyleElementWrapper* create(JS::GlobalObject&, HTML::HTMLStyleElement&);

    HTMLStyleElementWrapper(JS::GlobalObject&, HTML::HTMLStyleElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLStyleElementWrapper() override;

    HTML::HTMLStyleElement& impl() { return static_cast<HTML::HTMLStyleElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLStyleElement const& impl() const { return static_cast<HTML::HTMLStyleElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

