
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLLabelElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLLabelElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLLabelElement, HTMLElementWrapper);
public:
    static HTMLLabelElementWrapper* create(JS::GlobalObject&, HTML::HTMLLabelElement&);

    HTMLLabelElementWrapper(JS::GlobalObject&, HTML::HTMLLabelElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLLabelElementWrapper() override;

    HTML::HTMLLabelElement& impl() { return static_cast<HTML::HTMLLabelElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLLabelElement const& impl() const { return static_cast<HTML::HTMLLabelElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

