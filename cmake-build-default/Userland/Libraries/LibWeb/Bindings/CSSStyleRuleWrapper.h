
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSStyleRule.h>

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

class CSSStyleRuleWrapper : public CSSRuleWrapper {
    JS_OBJECT(CSSStyleRule, CSSRuleWrapper);
public:
    static CSSStyleRuleWrapper* create(JS::GlobalObject&, CSS::CSSStyleRule&);

    CSSStyleRuleWrapper(JS::GlobalObject&, CSS::CSSStyleRule&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSStyleRuleWrapper() override;

    CSS::CSSStyleRule& impl() { return static_cast<CSS::CSSStyleRule&>(CSSRuleWrapper::impl()); }
    CSS::CSSStyleRule const& impl() const { return static_cast<CSS::CSSStyleRule const&>(CSSRuleWrapper::impl()); }

private:

};

} // namespace Web::Bindings

