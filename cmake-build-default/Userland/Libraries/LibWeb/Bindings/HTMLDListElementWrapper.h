
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLDListElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLDListElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLDListElement, HTMLElementWrapper);
public:
    static HTMLDListElementWrapper* create(JS::GlobalObject&, HTML::HTMLDListElement&);

    HTMLDListElementWrapper(JS::GlobalObject&, HTML::HTMLDListElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDListElementWrapper() override;

    HTML::HTMLDListElement& impl() { return static_cast<HTML::HTMLDListElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLDListElement const& impl() const { return static_cast<HTML::HTMLDListElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

