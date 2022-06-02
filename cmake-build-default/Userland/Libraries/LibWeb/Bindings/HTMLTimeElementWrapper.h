
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLTimeElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLTimeElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLTimeElement, HTMLElementWrapper);
public:
    static HTMLTimeElementWrapper* create(JS::GlobalObject&, HTML::HTMLTimeElement&);

    HTMLTimeElementWrapper(JS::GlobalObject&, HTML::HTMLTimeElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTimeElementWrapper() override;

    HTML::HTMLTimeElement& impl() { return static_cast<HTML::HTMLTimeElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLTimeElement const& impl() const { return static_cast<HTML::HTMLTimeElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

