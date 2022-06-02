
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Crypto/SubtleCrypto.h>

#include <LibWeb/Crypto/Crypto.h>

namespace Web::Bindings {

class CryptoWrapper : public Wrapper {
    JS_OBJECT(Crypto, Wrapper);
public:
    static CryptoWrapper* create(JS::GlobalObject&, Crypto::Crypto&);

    CryptoWrapper(JS::GlobalObject&, Crypto::Crypto&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CryptoWrapper() override;

    Crypto::Crypto& impl() { return *m_impl; }
    Crypto::Crypto const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<Crypto::Crypto> m_impl;
        
};

CryptoWrapper* wrap(JS::GlobalObject&, Crypto::Crypto&);

} // namespace Web::Bindings

