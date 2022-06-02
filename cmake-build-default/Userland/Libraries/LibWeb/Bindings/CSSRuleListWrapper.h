
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

namespace Web::Bindings {

class CSSRuleListWrapper : public Wrapper {
    JS_OBJECT(CSSRuleList, Wrapper);
public:
    static CSSRuleListWrapper* create(JS::GlobalObject&, CSS::CSSRuleList&);

    CSSRuleListWrapper(JS::GlobalObject&, CSS::CSSRuleList&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSRuleListWrapper() override;

    virtual JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> internal_get_own_property(JS::PropertyKey const&) const override;
    virtual JS::ThrowCompletionOr<bool> internal_set(JS::PropertyKey const&, JS::Value, JS::Value) override;
    virtual JS::ThrowCompletionOr<bool> internal_define_own_property(JS::PropertyKey const&, JS::PropertyDescriptor const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_delete(JS::PropertyKey const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_prevent_extensions() override;
    virtual JS::ThrowCompletionOr<JS::MarkedVector<JS::Value>> internal_own_property_keys() const override;

    CSS::CSSRuleList& impl() { return *m_impl; }
    CSS::CSSRuleList const& impl() const { return *m_impl; }

private:

    JS::ThrowCompletionOr<bool> is_named_property_exposed_on_object(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_get_own_property_slot(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_set_slot(JS::PropertyKey const&) const;

    NonnullRefPtr<CSS::CSSRuleList> m_impl;
        
};

CSSRuleListWrapper* wrap(JS::GlobalObject&, CSS::CSSRuleList&);

} // namespace Web::Bindings

