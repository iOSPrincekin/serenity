
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLFontElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLFontElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLFontElement, HTMLElementWrapper);
public:
    static HTMLFontElementWrapper* create(JS::GlobalObject&, HTML::HTMLFontElement&);

    HTMLFontElementWrapper(JS::GlobalObject&, HTML::HTMLFontElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFontElementWrapper() override;

    HTML::HTMLFontElement& impl() { return static_cast<HTML::HTMLFontElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLFontElement const& impl() const { return static_cast<HTML::HTMLFontElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

