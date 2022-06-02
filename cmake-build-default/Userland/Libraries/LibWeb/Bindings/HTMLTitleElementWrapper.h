
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLTitleElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLTitleElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLTitleElement, HTMLElementWrapper);
public:
    static HTMLTitleElementWrapper* create(JS::GlobalObject&, HTML::HTMLTitleElement&);

    HTMLTitleElementWrapper(JS::GlobalObject&, HTML::HTMLTitleElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTitleElementWrapper() override;

    HTML::HTMLTitleElement& impl() { return static_cast<HTML::HTMLTitleElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLTitleElement const& impl() const { return static_cast<HTML::HTMLTitleElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

