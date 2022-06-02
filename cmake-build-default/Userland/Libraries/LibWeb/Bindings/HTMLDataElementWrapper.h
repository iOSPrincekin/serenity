
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLDataElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLDataElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLDataElement, HTMLElementWrapper);
public:
    static HTMLDataElementWrapper* create(JS::GlobalObject&, HTML::HTMLDataElement&);

    HTMLDataElementWrapper(JS::GlobalObject&, HTML::HTMLDataElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDataElementWrapper() override;

    HTML::HTMLDataElement& impl() { return static_cast<HTML::HTMLDataElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLDataElement const& impl() const { return static_cast<HTML::HTMLDataElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

