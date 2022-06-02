
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLParagraphElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLParagraphElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLParagraphElement, HTMLElementWrapper);
public:
    static HTMLParagraphElementWrapper* create(JS::GlobalObject&, HTML::HTMLParagraphElement&);

    HTMLParagraphElementWrapper(JS::GlobalObject&, HTML::HTMLParagraphElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLParagraphElementWrapper() override;

    HTML::HTMLParagraphElement& impl() { return static_cast<HTML::HTMLParagraphElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLParagraphElement const& impl() const { return static_cast<HTML::HTMLParagraphElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

