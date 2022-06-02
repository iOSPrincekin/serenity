
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/TextMetrics.h>

#include <LibWeb/HTML/CanvasRenderingContext2D.h>

#include <LibWeb/HTML/HTMLCanvasElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/ImageData.h>

#include <LibWeb/HTML/CanvasGradient.h>

#include <LibWeb/HTML/HTMLImageElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

namespace Web::Bindings {

class CanvasRenderingContext2DWrapper : public Wrapper {
    JS_OBJECT(CanvasRenderingContext2D, Wrapper);
public:
    static CanvasRenderingContext2DWrapper* create(JS::GlobalObject&, HTML::CanvasRenderingContext2D&);

    CanvasRenderingContext2DWrapper(JS::GlobalObject&, HTML::CanvasRenderingContext2D&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CanvasRenderingContext2DWrapper() override;

    HTML::CanvasRenderingContext2D& impl() { return *m_impl; }
    HTML::CanvasRenderingContext2D const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::CanvasRenderingContext2D> m_impl;
        
};

CanvasRenderingContext2DWrapper* wrap(JS::GlobalObject&, HTML::CanvasRenderingContext2D&);

} // namespace Web::Bindings

