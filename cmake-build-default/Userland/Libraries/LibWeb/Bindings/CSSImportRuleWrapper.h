
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/MediaList.h>

#include <LibWeb/CSS/CSSImportRule.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#if __has_include(<LibWeb/Bindings/CSSRuleWrapper.h>)
#   include <LibWeb/Bindings/CSSRuleWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/CSSRuleWrapperFactory.h>)
#   include <LibWeb/Bindings/CSSRuleWrapperFactory.h>
#endif

namespace Web::Bindings {

class CSSImportRuleWrapper : public CSSRuleWrapper {
    JS_OBJECT(CSSImportRule, CSSRuleWrapper);
public:
    static CSSImportRuleWrapper* create(JS::GlobalObject&, CSS::CSSImportRule&);

    CSSImportRuleWrapper(JS::GlobalObject&, CSS::CSSImportRule&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSImportRuleWrapper() override;

    CSS::CSSImportRule& impl() { return static_cast<CSS::CSSImportRule&>(CSSRuleWrapper::impl()); }
    CSS::CSSImportRule const& impl() const { return static_cast<CSS::CSSImportRule const&>(CSSRuleWrapper::impl()); }

private:

};

} // namespace Web::Bindings

