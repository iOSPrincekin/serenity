
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLLegendElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLLegendElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLLegendElement, HTMLElementWrapper);
public:
    static HTMLLegendElementWrapper* create(JS::GlobalObject&, HTML::HTMLLegendElement&);

    HTMLLegendElementWrapper(JS::GlobalObject&, HTML::HTMLLegendElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLLegendElementWrapper() override;

    HTML::HTMLLegendElement& impl() { return static_cast<HTML::HTMLLegendElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLLegendElement const& impl() const { return static_cast<HTML::HTMLLegendElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

