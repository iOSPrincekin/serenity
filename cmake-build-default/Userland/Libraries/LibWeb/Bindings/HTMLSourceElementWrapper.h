
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLSourceElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLSourceElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLSourceElement, HTMLElementWrapper);
public:
    static HTMLSourceElementWrapper* create(JS::GlobalObject&, HTML::HTMLSourceElement&);

    HTMLSourceElementWrapper(JS::GlobalObject&, HTML::HTMLSourceElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLSourceElementWrapper() override;

    HTML::HTMLSourceElement& impl() { return static_cast<HTML::HTMLSourceElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLSourceElement const& impl() const { return static_cast<HTML::HTMLSourceElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

