
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Crypto/SubtleCrypto.h>

namespace Web::Bindings {

class SubtleCryptoWrapper : public Wrapper {
    JS_OBJECT(SubtleCrypto, Wrapper);
public:
    static SubtleCryptoWrapper* create(JS::GlobalObject&, Crypto::SubtleCrypto&);

    SubtleCryptoWrapper(JS::GlobalObject&, Crypto::SubtleCrypto&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~SubtleCryptoWrapper() override;

    Crypto::SubtleCrypto& impl() { return *m_impl; }
    Crypto::SubtleCrypto const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<Crypto::SubtleCrypto> m_impl;
        
};

SubtleCryptoWrapper* wrap(JS::GlobalObject&, Crypto::SubtleCrypto&);

} // namespace Web::Bindings

