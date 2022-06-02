
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLOutputElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLOutputElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLOutputElement, HTMLElementWrapper);
public:
    static HTMLOutputElementWrapper* create(JS::GlobalObject&, HTML::HTMLOutputElement&);

    HTMLOutputElementWrapper(JS::GlobalObject&, HTML::HTMLOutputElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLOutputElementWrapper() override;

    HTML::HTMLOutputElement& impl() { return static_cast<HTML::HTMLOutputElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLOutputElement const& impl() const { return static_cast<HTML::HTMLOutputElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

