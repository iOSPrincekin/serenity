
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLDetailsElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLDetailsElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLDetailsElement, HTMLElementWrapper);
public:
    static HTMLDetailsElementWrapper* create(JS::GlobalObject&, HTML::HTMLDetailsElement&);

    HTMLDetailsElementWrapper(JS::GlobalObject&, HTML::HTMLDetailsElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDetailsElementWrapper() override;

    HTML::HTMLDetailsElement& impl() { return static_cast<HTML::HTMLDetailsElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLDetailsElement const& impl() const { return static_cast<HTML::HTMLDetailsElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

