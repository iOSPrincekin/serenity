
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Encoding/TextEncoder.h>

namespace Web::Bindings {

class TextEncoderWrapper : public Wrapper {
    JS_OBJECT(TextEncoder, Wrapper);
public:
    static TextEncoderWrapper* create(JS::GlobalObject&, Encoding::TextEncoder&);

    TextEncoderWrapper(JS::GlobalObject&, Encoding::TextEncoder&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TextEncoderWrapper() override;

    Encoding::TextEncoder& impl() { return *m_impl; }
    Encoding::TextEncoder const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<Encoding::TextEncoder> m_impl;
        
};

TextEncoderWrapper* wrap(JS::GlobalObject&, Encoding::TextEncoder&);

} // namespace Web::Bindings

