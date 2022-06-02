
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/TextMetrics.h>

#include <LibWeb/HTML/CanvasRenderingContext2D.h>

#include <LibWeb/HTML/HTMLCanvasElement.h>

#include <LibWeb/HTML/ImageData.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/CanvasGradient.h>

#include <LibWeb/HTML/HTMLImageElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLCanvasElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLCanvasElement, HTMLElementWrapper);
public:
    static HTMLCanvasElementWrapper* create(JS::GlobalObject&, HTML::HTMLCanvasElement&);

    HTMLCanvasElementWrapper(JS::GlobalObject&, HTML::HTMLCanvasElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLCanvasElementWrapper() override;

    HTML::HTMLCanvasElement& impl() { return static_cast<HTML::HTMLCanvasElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLCanvasElement const& impl() const { return static_cast<HTML::HTMLCanvasElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

