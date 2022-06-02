
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLParamElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLParamElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLParamElement, HTMLElementWrapper);
public:
    static HTMLParamElementWrapper* create(JS::GlobalObject&, HTML::HTMLParamElement&);

    HTMLParamElementWrapper(JS::GlobalObject&, HTML::HTMLParamElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLParamElementWrapper() override;

    HTML::HTMLParamElement& impl() { return static_cast<HTML::HTMLParamElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLParamElement const& impl() const { return static_cast<HTML::HTMLParamElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

