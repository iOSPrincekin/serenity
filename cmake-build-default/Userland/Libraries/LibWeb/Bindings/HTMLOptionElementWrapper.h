
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLOptionElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLOptionElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLOptionElement, HTMLElementWrapper);
public:
    static HTMLOptionElementWrapper* create(JS::GlobalObject&, HTML::HTMLOptionElement&);

    HTMLOptionElementWrapper(JS::GlobalObject&, HTML::HTMLOptionElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLOptionElementWrapper() override;

    HTML::HTMLOptionElement& impl() { return static_cast<HTML::HTMLOptionElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLOptionElement const& impl() const { return static_cast<HTML::HTMLOptionElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

