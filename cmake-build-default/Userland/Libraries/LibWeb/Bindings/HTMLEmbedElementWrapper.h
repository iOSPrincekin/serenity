
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLEmbedElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLEmbedElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLEmbedElement, HTMLElementWrapper);
public:
    static HTMLEmbedElementWrapper* create(JS::GlobalObject&, HTML::HTMLEmbedElement&);

    HTMLEmbedElementWrapper(JS::GlobalObject&, HTML::HTMLEmbedElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLEmbedElementWrapper() override;

    HTML::HTMLEmbedElement& impl() { return static_cast<HTML::HTMLEmbedElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLEmbedElement const& impl() const { return static_cast<HTML::HTMLEmbedElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

