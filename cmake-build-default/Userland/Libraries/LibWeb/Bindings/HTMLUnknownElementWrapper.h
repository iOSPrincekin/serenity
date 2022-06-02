
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLUnknownElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLUnknownElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLUnknownElement, HTMLElementWrapper);
public:
    static HTMLUnknownElementWrapper* create(JS::GlobalObject&, HTML::HTMLUnknownElement&);

    HTMLUnknownElementWrapper(JS::GlobalObject&, HTML::HTMLUnknownElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLUnknownElementWrapper() override;

    HTML::HTMLUnknownElement& impl() { return static_cast<HTML::HTMLUnknownElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLUnknownElement const& impl() const { return static_cast<HTML::HTMLUnknownElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

