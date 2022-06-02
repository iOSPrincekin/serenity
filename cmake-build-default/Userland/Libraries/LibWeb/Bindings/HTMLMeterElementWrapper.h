
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLMeterElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLMeterElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLMeterElement, HTMLElementWrapper);
public:
    static HTMLMeterElementWrapper* create(JS::GlobalObject&, HTML::HTMLMeterElement&);

    HTMLMeterElementWrapper(JS::GlobalObject&, HTML::HTMLMeterElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMeterElementWrapper() override;

    HTML::HTMLMeterElement& impl() { return static_cast<HTML::HTMLMeterElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLMeterElement const& impl() const { return static_cast<HTML::HTMLMeterElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

