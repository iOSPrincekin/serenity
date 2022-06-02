
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLScriptElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLScriptElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLScriptElement, HTMLElementWrapper);
public:
    static HTMLScriptElementWrapper* create(JS::GlobalObject&, HTML::HTMLScriptElement&);

    HTMLScriptElementWrapper(JS::GlobalObject&, HTML::HTMLScriptElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLScriptElementWrapper() override;

    HTML::HTMLScriptElement& impl() { return static_cast<HTML::HTMLScriptElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLScriptElement const& impl() const { return static_cast<HTML::HTMLScriptElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

