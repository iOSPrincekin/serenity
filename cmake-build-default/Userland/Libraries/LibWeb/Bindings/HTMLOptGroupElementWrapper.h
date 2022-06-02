
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLOptGroupElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLOptGroupElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLOptGroupElement, HTMLElementWrapper);
public:
    static HTMLOptGroupElementWrapper* create(JS::GlobalObject&, HTML::HTMLOptGroupElement&);

    HTMLOptGroupElementWrapper(JS::GlobalObject&, HTML::HTMLOptGroupElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLOptGroupElementWrapper() override;

    HTML::HTMLOptGroupElement& impl() { return static_cast<HTML::HTMLOptGroupElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLOptGroupElement const& impl() const { return static_cast<HTML::HTMLOptGroupElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

