
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/Storage.h>

namespace Web::Bindings {

class StorageWrapper : public Wrapper {
    JS_OBJECT(Storage, Wrapper);
public:
    static StorageWrapper* create(JS::GlobalObject&, HTML::Storage&);

    StorageWrapper(JS::GlobalObject&, HTML::Storage&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~StorageWrapper() override;

    virtual JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> internal_get_own_property(JS::PropertyKey const&) const override;
    virtual JS::ThrowCompletionOr<bool> internal_set(JS::PropertyKey const&, JS::Value, JS::Value) override;
    virtual JS::ThrowCompletionOr<bool> internal_define_own_property(JS::PropertyKey const&, JS::PropertyDescriptor const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_delete(JS::PropertyKey const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_prevent_extensions() override;
    virtual JS::ThrowCompletionOr<JS::MarkedVector<JS::Value>> internal_own_property_keys() const override;

    HTML::Storage& impl() { return *m_impl; }
    HTML::Storage const& impl() const { return *m_impl; }

private:

    JS::ThrowCompletionOr<bool> is_named_property_exposed_on_object(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_get_own_property_slot(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_set_slot(JS::PropertyKey const&) const;

    NonnullRefPtr<HTML::Storage> m_impl;
        
};

StorageWrapper* wrap(JS::GlobalObject&, HTML::Storage&);

} // namespace Web::Bindings

