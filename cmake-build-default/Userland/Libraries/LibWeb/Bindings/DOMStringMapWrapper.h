
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/DOMStringMap.h>

namespace Web::Bindings {

class DOMStringMapWrapper : public Wrapper {
    JS_OBJECT(DOMStringMap, Wrapper);
public:
    static DOMStringMapWrapper* create(JS::GlobalObject&, HTML::DOMStringMap&);

    DOMStringMapWrapper(JS::GlobalObject&, HTML::DOMStringMap&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMStringMapWrapper() override;

    virtual JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> internal_get_own_property(JS::PropertyKey const&) const override;
    virtual JS::ThrowCompletionOr<bool> internal_set(JS::PropertyKey const&, JS::Value, JS::Value) override;
    virtual JS::ThrowCompletionOr<bool> internal_define_own_property(JS::PropertyKey const&, JS::PropertyDescriptor const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_delete(JS::PropertyKey const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_prevent_extensions() override;
    virtual JS::ThrowCompletionOr<JS::MarkedVector<JS::Value>> internal_own_property_keys() const override;

    HTML::DOMStringMap& impl() { return *m_impl; }
    HTML::DOMStringMap const& impl() const { return *m_impl; }

private:

    JS::ThrowCompletionOr<bool> is_named_property_exposed_on_object(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_get_own_property_slot(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_set_slot(JS::PropertyKey const&) const;

    NonnullRefPtr<HTML::DOMStringMap> m_impl;
        
};

DOMStringMapWrapper* wrap(JS::GlobalObject&, HTML::DOMStringMap&);

} // namespace Web::Bindings

