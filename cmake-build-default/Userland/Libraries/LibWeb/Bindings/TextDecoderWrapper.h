
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/Encoding/TextDecoder.h>

namespace Web::Bindings {

class TextDecoderWrapper : public Wrapper {
    JS_OBJECT(TextDecoder, Wrapper);
public:
    static TextDecoderWrapper* create(JS::GlobalObject&, Encoding::TextDecoder&);

    TextDecoderWrapper(JS::GlobalObject&, Encoding::TextDecoder&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TextDecoderWrapper() override;

    Encoding::TextDecoder& impl() { return *m_impl; }
    Encoding::TextDecoder const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<Encoding::TextDecoder> m_impl;
        
};

TextDecoderWrapper* wrap(JS::GlobalObject&, Encoding::TextDecoder&);

} // namespace Web::Bindings

