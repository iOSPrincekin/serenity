
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLLinkElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLLinkElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLLinkElement, HTMLElementWrapper);
public:
    static HTMLLinkElementWrapper* create(JS::GlobalObject&, HTML::HTMLLinkElement&);

    HTMLLinkElementWrapper(JS::GlobalObject&, HTML::HTMLLinkElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLLinkElementWrapper() override;

    HTML::HTMLLinkElement& impl() { return static_cast<HTML::HTMLLinkElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLLinkElement const& impl() const { return static_cast<HTML::HTMLLinkElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

