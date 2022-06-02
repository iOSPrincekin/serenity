
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSGroupingRule.h>

#include <LibWeb/CSS/CSSConditionRule.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#if __has_include(<LibWeb/Bindings/CSSGroupingRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSGroupingRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSGroupingRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSGroupingRuleWrapperFactory.h>
#endif

namespace Web::Bindings {

class CSSConditionRuleWrapper : public CSSGroupingRuleWrapper {
    JS_OBJECT(CSSConditionRule, CSSGroupingRuleWrapper);
public:
    static CSSConditionRuleWrapper* create(JS::GlobalObject&, CSS::CSSConditionRule&);

    CSSConditionRuleWrapper(JS::GlobalObject&, CSS::CSSConditionRule&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSConditionRuleWrapper() override;

    CSS::CSSConditionRule& impl() { return static_cast<CSS::CSSConditionRule&>(CSSGroupingRuleWrapper::impl()); }
    CSS::CSSConditionRule const& impl() const { return static_cast<CSS::CSSConditionRule const&>(CSSGroupingRuleWrapper::impl()); }

private:

};

} // namespace Web::Bindings

