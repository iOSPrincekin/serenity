
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLTableCaptionElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLTableCaptionElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLTableCaptionElement, HTMLElementWrapper);
public:
    static HTMLTableCaptionElementWrapper* create(JS::GlobalObject&, HTML::HTMLTableCaptionElement&);

    HTMLTableCaptionElementWrapper(JS::GlobalObject&, HTML::HTMLTableCaptionElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTableCaptionElementWrapper() override;

    HTML::HTMLTableCaptionElement& impl() { return static_cast<HTML::HTMLTableCaptionElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLTableCaptionElement const& impl() const { return static_cast<HTML::HTMLTableCaptionElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

