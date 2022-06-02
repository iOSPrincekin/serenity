
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLTableColElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLTableColElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLTableColElement, HTMLElementWrapper);
public:
    static HTMLTableColElementWrapper* create(JS::GlobalObject&, HTML::HTMLTableColElement&);

    HTMLTableColElementWrapper(JS::GlobalObject&, HTML::HTMLTableColElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTableColElementWrapper() override;

    HTML::HTMLTableColElement& impl() { return static_cast<HTML::HTMLTableColElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLTableColElement const& impl() const { return static_cast<HTML::HTMLTableColElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

