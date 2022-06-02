
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSGroupingRule.h>

#if __has_include(<LibWeb/Bindings/CSSRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#endif

namespace Web::Bindings {

class CSSGroupingRuleWrapper : public CSSRuleWrapper {
    JS_OBJECT(CSSGroupingRule, CSSRuleWrapper);
public:
    static CSSGroupingRuleWrapper* create(JS::GlobalObject&, CSS::CSSGroupingRule&);

    CSSGroupingRuleWrapper(JS::GlobalObject&, CSS::CSSGroupingRule&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSGroupingRuleWrapper() override;

    CSS::CSSGroupingRule& impl() { return static_cast<CSS::CSSGroupingRule&>(CSSRuleWrapper::impl()); }
    CSS::CSSGroupingRule const& impl() const { return static_cast<CSS::CSSGroupingRule const&>(CSSRuleWrapper::impl()); }

private:

};

} // namespace Web::Bindings

