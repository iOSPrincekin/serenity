
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLHtmlElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLHtmlElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLHtmlElement, HTMLElementWrapper);
public:
    static HTMLHtmlElementWrapper* create(JS::GlobalObject&, HTML::HTMLHtmlElement&);

    HTMLHtmlElementWrapper(JS::GlobalObject&, HTML::HTMLHtmlElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLHtmlElementWrapper() override;

    HTML::HTMLHtmlElement& impl() { return static_cast<HTML::HTMLHtmlElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLHtmlElement const& impl() const { return static_cast<HTML::HTMLHtmlElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

