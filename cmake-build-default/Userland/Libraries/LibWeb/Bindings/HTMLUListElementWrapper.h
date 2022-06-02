
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLUListElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLUListElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLUListElement, HTMLElementWrapper);
public:
    static HTMLUListElementWrapper* create(JS::GlobalObject&, HTML::HTMLUListElement&);

    HTMLUListElementWrapper(JS::GlobalObject&, HTML::HTMLUListElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLUListElementWrapper() override;

    HTML::HTMLUListElement& impl() { return static_cast<HTML::HTMLUListElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLUListElement const& impl() const { return static_cast<HTML::HTMLUListElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

