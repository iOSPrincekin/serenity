
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLButtonElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLButtonElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLButtonElement, HTMLElementWrapper);
public:
    static HTMLButtonElementWrapper* create(JS::GlobalObject&, HTML::HTMLButtonElement&);

    HTMLButtonElementWrapper(JS::GlobalObject&, HTML::HTMLButtonElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLButtonElementWrapper() override;

    HTML::HTMLButtonElement& impl() { return static_cast<HTML::HTMLButtonElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLButtonElement const& impl() const { return static_cast<HTML::HTMLButtonElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

