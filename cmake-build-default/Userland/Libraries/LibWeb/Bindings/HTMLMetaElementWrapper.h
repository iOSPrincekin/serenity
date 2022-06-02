
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMetaElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLMetaElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLMetaElement, HTMLElementWrapper);
public:
    static HTMLMetaElementWrapper* create(JS::GlobalObject&, HTML::HTMLMetaElement&);

    HTMLMetaElementWrapper(JS::GlobalObject&, HTML::HTMLMetaElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMetaElementWrapper() override;

    HTML::HTMLMetaElement& impl() { return static_cast<HTML::HTMLMetaElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLMetaElement const& impl() const { return static_cast<HTML::HTMLMetaElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

