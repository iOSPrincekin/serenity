
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/MediaList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSGroupingRule.h>

#include <LibWeb/CSS/CSSConditionRule.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSMediaRule.h>

#if __has_include(<LibWeb/Bindings/CSSConditionRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSConditionRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSConditionRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSConditionRuleWrapperFactory.h>
#endif

namespace Web::Bindings {

class CSSMediaRuleWrapper : public CSSConditionRuleWrapper {
    JS_OBJECT(CSSMediaRule, CSSConditionRuleWrapper);
public:
    static CSSMediaRuleWrapper* create(JS::GlobalObject&, CSS::CSSMediaRule&);

    CSSMediaRuleWrapper(JS::GlobalObject&, CSS::CSSMediaRule&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSMediaRuleWrapper() override;

    CSS::CSSMediaRule& impl() { return static_cast<CSS::CSSMediaRule&>(CSSConditionRuleWrapper::impl()); }
    CSS::CSSMediaRule const& impl() const { return static_cast<CSS::CSSMediaRule const&>(CSSConditionRuleWrapper::impl()); }

private:

};

} // namespace Web::Bindings

