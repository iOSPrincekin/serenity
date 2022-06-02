
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Geometry/DOMRectList.h>

#include <LibWeb/Geometry/DOMRectReadOnly.h>

#include <LibWeb/Geometry/DOMRect.h>

namespace Web::Bindings {

class DOMRectListWrapper : public Wrapper {
    JS_OBJECT(DOMRectList, Wrapper);
public:
    static DOMRectListWrapper* create(JS::GlobalObject&, Geometry::DOMRectList&);

    DOMRectListWrapper(JS::GlobalObject&, Geometry::DOMRectList&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMRectListWrapper() override;

    virtual JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> internal_get_own_property(JS::PropertyKey const&) const override;
    virtual JS::ThrowCompletionOr<bool> internal_set(JS::PropertyKey const&, JS::Value, JS::Value) override;
    virtual JS::ThrowCompletionOr<bool> internal_define_own_property(JS::PropertyKey const&, JS::PropertyDescriptor const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_delete(JS::PropertyKey const&) override;
    virtual JS::ThrowCompletionOr<bool> internal_prevent_extensions() override;
    virtual JS::ThrowCompletionOr<JS::MarkedVector<JS::Value>> internal_own_property_keys() const override;

    Geometry::DOMRectList& impl() { return *m_impl; }
    Geometry::DOMRectList const& impl() const { return *m_impl; }

private:

    JS::ThrowCompletionOr<bool> is_named_property_exposed_on_object(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_get_own_property_slot(JS::PropertyKey const&) const;
    JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> legacy_platform_object_get_own_property_for_set_slot(JS::PropertyKey const&) const;

    NonnullRefPtr<Geometry::DOMRectList> m_impl;
        
};

DOMRectListWrapper* wrap(JS::GlobalObject&, Geometry::DOMRectList&);

} // namespace Web::Bindings

