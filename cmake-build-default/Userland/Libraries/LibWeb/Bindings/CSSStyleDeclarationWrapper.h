
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/CSSStyleDeclaration.h>

namespace Web::Bindings {

class CSSStyleDeclarationWrapper : public Wrapper {
    JS_OBJECT(CSSStyleDeclaration, Wrapper);
public:
    static CSSStyleDeclarationWrapper* create(JS::GlobalObject&, CSS::CSSStyleDeclaration&);

    CSSStyleDeclarationWrapper(JS::GlobalObject&, CSS::CSSStyleDeclaration&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CSSStyleDeclarationWrapper() override;

    virtual JS::ThrowCompletionOr<JS::Value> internal_get(JS::PropertyKey const&, JS::Value receiver) const override;

    virtual JS::ThrowCompletionOr<bool> internal_set(JS::PropertyKey const&, JS::Value, JS::Value receiver) override;

    virtual JS::ThrowCompletionOr<bool> internal_has_property(JS::PropertyKey const&) const override;

    CSS::CSSStyleDeclaration& impl() { return *m_impl; }
    CSS::CSSStyleDeclaration const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<CSS::CSSStyleDeclaration> m_impl;
        
};

CSSStyleDeclarationWrapper* wrap(JS::GlobalObject&, CSS::CSSStyleDeclaration&);

} // namespace Web::Bindings

