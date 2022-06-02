
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLLIElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLLIElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLLIElement, HTMLElementWrapper);
public:
    static HTMLLIElementWrapper* create(JS::GlobalObject&, HTML::HTMLLIElement&);

    HTMLLIElementWrapper(JS::GlobalObject&, HTML::HTMLLIElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLLIElementWrapper() override;

    HTML::HTMLLIElement& impl() { return static_cast<HTML::HTMLLIElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLLIElement const& impl() const { return static_cast<HTML::HTMLLIElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

