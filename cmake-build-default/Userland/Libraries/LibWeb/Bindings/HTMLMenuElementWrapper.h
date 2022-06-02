
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLMenuElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLMenuElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLMenuElement, HTMLElementWrapper);
public:
    static HTMLMenuElementWrapper* create(JS::GlobalObject&, HTML::HTMLMenuElement&);

    HTMLMenuElementWrapper(JS::GlobalObject&, HTML::HTMLMenuElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMenuElementWrapper() override;

    HTML::HTMLMenuElement& impl() { return static_cast<HTML::HTMLMenuElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLMenuElement const& impl() const { return static_cast<HTML::HTMLMenuElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

