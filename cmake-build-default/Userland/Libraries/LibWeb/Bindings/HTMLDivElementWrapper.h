
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLDivElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLDivElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLDivElement, HTMLElementWrapper);
public:
    static HTMLDivElementWrapper* create(JS::GlobalObject&, HTML::HTMLDivElement&);

    HTMLDivElementWrapper(JS::GlobalObject&, HTML::HTMLDivElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDivElementWrapper() override;

    HTML::HTMLDivElement& impl() { return static_cast<HTML::HTMLDivElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLDivElement const& impl() const { return static_cast<HTML::HTMLDivElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

