
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLBaseElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLBaseElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLBaseElement, HTMLElementWrapper);
public:
    static HTMLBaseElementWrapper* create(JS::GlobalObject&, HTML::HTMLBaseElement&);

    HTMLBaseElementWrapper(JS::GlobalObject&, HTML::HTMLBaseElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLBaseElementWrapper() override;

    HTML::HTMLBaseElement& impl() { return static_cast<HTML::HTMLBaseElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLBaseElement const& impl() const { return static_cast<HTML::HTMLBaseElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

