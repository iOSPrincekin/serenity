
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#if __has_include(<LibWeb/Bindings/StyleSheetWrapper.h>)
#   include <LibWeb/Bindings/StyleSheetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/StyleSheetWrapperFactory.h>)
#   include <LibWeb/Bindings/StyleSheetWrapperFactory.h>
#endif

namespace Web::Bindings {

class CSSStyleSheetWrapper : public StyleSheetWrapper {
    JS_OBJECT(CSSStyleSheet, StyleSheetWrapper);
public:
    static CSSStyleSheetWrapper* create(JS::GlobalObject&, CSS::CSSStyleSheet&);

    CSSStyleSheetWrapper(JS::GlobalObject&, CSS::CSSStyleSheet&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSStyleSheetWrapper() override;

    CSS::CSSStyleSheet& impl() { return static_cast<CSS::CSSStyleSheet&>(StyleSheetWrapper::impl()); }
    CSS::CSSStyleSheet const& impl() const { return static_cast<CSS::CSSStyleSheet const&>(StyleSheetWrapper::impl()); }

private:

};

CSSStyleSheetWrapper* wrap(JS::GlobalObject&, CSS::CSSStyleSheet&);

} // namespace Web::Bindings

