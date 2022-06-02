
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLModElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLModElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLModElement, HTMLElementWrapper);
public:
    static HTMLModElementWrapper* create(JS::GlobalObject&, HTML::HTMLModElement&);

    HTMLModElementWrapper(JS::GlobalObject&, HTML::HTMLModElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLModElementWrapper() override;

    HTML::HTMLModElement& impl() { return static_cast<HTML::HTMLModElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLModElement const& impl() const { return static_cast<HTML::HTMLModElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

