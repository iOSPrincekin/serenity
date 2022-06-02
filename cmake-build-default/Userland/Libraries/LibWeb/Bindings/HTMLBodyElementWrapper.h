
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLBodyElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLBodyElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLBodyElement, HTMLElementWrapper);
public:
    static HTMLBodyElementWrapper* create(JS::GlobalObject&, HTML::HTMLBodyElement&);

    HTMLBodyElementWrapper(JS::GlobalObject&, HTML::HTMLBodyElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLBodyElementWrapper() override;

    HTML::HTMLBodyElement& impl() { return static_cast<HTML::HTMLBodyElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLBodyElement const& impl() const { return static_cast<HTML::HTMLBodyElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

