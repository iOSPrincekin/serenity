
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLAnchorElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLAnchorElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLAnchorElement, HTMLElementWrapper);
public:
    static HTMLAnchorElementWrapper* create(JS::GlobalObject&, HTML::HTMLAnchorElement&);

    HTMLAnchorElementWrapper(JS::GlobalObject&, HTML::HTMLAnchorElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLAnchorElementWrapper() override;

    HTML::HTMLAnchorElement& impl() { return static_cast<HTML::HTMLAnchorElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLAnchorElement const& impl() const { return static_cast<HTML::HTMLAnchorElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

