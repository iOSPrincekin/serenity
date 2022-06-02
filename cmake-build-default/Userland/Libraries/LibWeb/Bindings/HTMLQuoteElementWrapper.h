
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLQuoteElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLQuoteElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLQuoteElement, HTMLElementWrapper);
public:
    static HTMLQuoteElementWrapper* create(JS::GlobalObject&, HTML::HTMLQuoteElement&);

    HTMLQuoteElementWrapper(JS::GlobalObject&, HTML::HTMLQuoteElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLQuoteElementWrapper() override;

    HTML::HTMLQuoteElement& impl() { return static_cast<HTML::HTMLQuoteElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLQuoteElement const& impl() const { return static_cast<HTML::HTMLQuoteElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

