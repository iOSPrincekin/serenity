
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLAreaElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLAreaElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLAreaElement, HTMLElementWrapper);
public:
    static HTMLAreaElementWrapper* create(JS::GlobalObject&, HTML::HTMLAreaElement&);

    HTMLAreaElementWrapper(JS::GlobalObject&, HTML::HTMLAreaElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLAreaElementWrapper() override;

    HTML::HTMLAreaElement& impl() { return static_cast<HTML::HTMLAreaElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLAreaElement const& impl() const { return static_cast<HTML::HTMLAreaElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

