
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/StyleSheetList.h>

#include <LibWeb/CSS/CSSRule.h>

#include <LibWeb/CSS/CSSRuleList.h>

#include <LibWeb/CSS/CSSStyleSheet.h>

namespace Web::Bindings {

class StyleSheetListWrapper : public Wrapper {
    JS_OBJECT(StyleSheetList, Wrapper);
public:
    static StyleSheetListWrapper* create(JS::GlobalObject&, CSS::StyleSheetList&);

    StyleSheetListWrapper(JS::GlobalObject&, CSS::StyleSheetList&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~StyleSheetListWrapper() override;

    virtual JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> internal_get_own_property(JS::PropertyKey const&) const override;
    virtual JS::ThrowCompletionOr<bool> internal_set(JS::PropertyKey const&, JS::Value, JS::Value) override;
    virtual JS::ThrowCompletionOr<bool> internal_define_own_property(JS::PropertyKey const&, JS::PropertyDescriptor const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_delete(JS::PropertyKey const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_prevent_extensions() override;
    virtual JS::ThrowCompletionOr<JS::MarkedVector<JS::Value>> internal_own_property_keys() const override;

    CSS::StyleSheetList& impl() { return *m_impl; }
    CSS::StyleSheetList const& impl() const { return *m_impl; }

private:

    JS::ThrowCompletionOr<bool> is_named_property_exposed_on_object(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_get_own_property_slot(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_set_slot(JS::PropertyKey const&) const;

    NonnullRefPtr<CSS::StyleSheetList> m_impl;
        
};

StyleSheetListWrapper* wrap(JS::GlobalObject&, CSS::StyleSheetList&);

} // namespace Web::Bindings

