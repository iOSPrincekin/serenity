
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLHeadingElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLHeadingElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLHeadingElement, HTMLElementWrapper);
public:
    static HTMLHeadingElementWrapper* create(JS::GlobalObject&, HTML::HTMLHeadingElement&);

    HTMLHeadingElementWrapper(JS::GlobalObject&, HTML::HTMLHeadingElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLHeadingElementWrapper() override;

    HTML::HTMLHeadingElement& impl() { return static_cast<HTML::HTMLHeadingElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLHeadingElement const& impl() const { return static_cast<HTML::HTMLHeadingElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

