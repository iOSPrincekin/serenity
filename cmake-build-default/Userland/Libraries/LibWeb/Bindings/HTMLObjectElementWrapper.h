
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLObjectElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLObjectElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLObjectElement, HTMLElementWrapper);
public:
    static HTMLObjectElementWrapper* create(JS::GlobalObject&, HTML::HTMLObjectElement&);

    HTMLObjectElementWrapper(JS::GlobalObject&, HTML::HTMLObjectElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLObjectElementWrapper() override;

    HTML::HTMLObjectElement& impl() { return static_cast<HTML::HTMLObjectElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLObjectElement const& impl() const { return static_cast<HTML::HTMLObjectElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

