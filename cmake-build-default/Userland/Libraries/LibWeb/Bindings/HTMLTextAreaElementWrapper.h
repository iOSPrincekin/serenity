
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLTextAreaElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLTextAreaElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLTextAreaElement, HTMLElementWrapper);
public:
    static HTMLTextAreaElementWrapper* create(JS::GlobalObject&, HTML::HTMLTextAreaElement&);

    HTMLTextAreaElementWrapper(JS::GlobalObject&, HTML::HTMLTextAreaElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTextAreaElementWrapper() override;

    HTML::HTMLTextAreaElement& impl() { return static_cast<HTML::HTMLTextAreaElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLTextAreaElement const& impl() const { return static_cast<HTML::HTMLTextAreaElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

