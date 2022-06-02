
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLOListElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLOListElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLOListElement, HTMLElementWrapper);
public:
    static HTMLOListElementWrapper* create(JS::GlobalObject&, HTML::HTMLOListElement&);

    HTMLOListElementWrapper(JS::GlobalObject&, HTML::HTMLOListElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLOListElementWrapper() override;

    HTML::HTMLOListElement& impl() { return static_cast<HTML::HTMLOListElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLOListElement const& impl() const { return static_cast<HTML::HTMLOListElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

