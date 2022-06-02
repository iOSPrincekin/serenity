
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSFontFaceRule.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

#include <LibWeb/CSS/CSSRuleList.h>

#if __has_include(<LibWeb/Bindings/CSSRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#endif

namespace Web::Bindings {

class CSSFontFaceRuleWrapper : public CSSRuleWrapper {
    JS_OBJECT(CSSFontFaceRule, CSSRuleWrapper);
public:
    static CSSFontFaceRuleWrapper* create(JS::GlobalObject&, CSS::CSSFontFaceRule&);

    CSSFontFaceRuleWrapper(JS::GlobalObject&, CSS::CSSFontFaceRule&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSFontFaceRuleWrapper() override;

    CSS::CSSFontFaceRule& impl() { return static_cast<CSS::CSSFontFaceRule&>(CSSRuleWrapper::impl()); }
    CSS::CSSFontFaceRule const& impl() const { return static_cast<CSS::CSSFontFaceRule const&>(CSSRuleWrapper::impl()); }

private:

};

} // namespace Web::Bindings

