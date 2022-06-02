
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

namespace Web::Bindings {

class CSSRuleWrapper : public Wrapper {
    JS_OBJECT(CSSRule, Wrapper);
public:
    static CSSRuleWrapper* create(JS::GlobalObject&, CSS::CSSRule&);

    CSSRuleWrapper(JS::GlobalObject&, CSS::CSSRule&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSRuleWrapper() override;

    CSS::CSSRule& impl() { return *m_impl; }
    CSS::CSSRule const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<CSS::CSSRule> m_impl;
        
};

} // namespace Web::Bindings

