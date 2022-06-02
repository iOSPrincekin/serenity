
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/ElementWrapper.h>)
#   include <LibWeb/Bindings/ElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/ElementWrapperFactory.h>)
#   include <LibWeb/Bindings/ElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLElementWrapper : public ElementWrapper {
    JS_OBJECT(HTMLElement, ElementWrapper);
public:
    static HTMLElementWrapper* create(JS::GlobalObject&, HTML::HTMLElement&);

    HTMLElementWrapper(JS::GlobalObject&, HTML::HTMLElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLElementWrapper() override;

    HTML::HTMLElement& impl() { return static_cast<HTML::HTMLElement&>(ElementWrapper::impl()); }
    HTML::HTMLElement const& impl() const { return static_cast<HTML::HTMLElement const&>(ElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

