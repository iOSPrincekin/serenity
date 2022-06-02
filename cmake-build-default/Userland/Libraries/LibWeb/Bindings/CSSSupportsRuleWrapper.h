
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSSupportsRule.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSGroupingRule.h>

#include <LibWeb/CSS/CSSConditionRule.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#if __has_include(<LibWeb/Bindings/CSSConditionRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSConditionRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSConditionRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSConditionRuleWrapperFactory.h>
#endif

namespace Web::Bindings {

class CSSSupportsRuleWrapper : public CSSConditionRuleWrapper {
    JS_OBJECT(CSSSupportsRule, CSSConditionRuleWrapper);
public:
    static CSSSupportsRuleWrapper* create(JS::GlobalObject&, CSS::CSSSupportsRule&);

    CSSSupportsRuleWrapper(JS::GlobalObject&, CSS::CSSSupportsRule&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSSupportsRuleWrapper() override;

    CSS::CSSSupportsRule& impl() { return static_cast<CSS::CSSSupportsRule&>(CSSConditionRuleWrapper::impl()); }
    CSS::CSSSupportsRule const& impl() const { return static_cast<CSS::CSSSupportsRule const&>(CSSConditionRuleWrapper::impl()); }

private:

};

} // namespace Web::Bindings

