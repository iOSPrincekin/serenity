
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/CanvasGradient.h>

namespace Web::Bindings {

class CanvasGradientWrapper : public Wrapper {
    JS_OBJECT(CanvasGradient, Wrapper);
public:
    static CanvasGradientWrapper* create(JS::GlobalObject&, HTML::CanvasGradient&);

    CanvasGradientWrapper(JS::GlobalObject&, HTML::CanvasGradient&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CanvasGradientWrapper() override;

    HTML::CanvasGradient& impl() { return *m_impl; }
    HTML::CanvasGradient const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::CanvasGradient> m_impl;
        
};

CanvasGradientWrapper* wrap(JS::GlobalObject&, HTML::CanvasGradient&);

} // namespace Web::Bindings

