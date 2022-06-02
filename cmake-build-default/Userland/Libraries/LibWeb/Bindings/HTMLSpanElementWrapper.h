
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLSpanElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLSpanElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLSpanElement, HTMLElementWrapper);
public:
    static HTMLSpanElementWrapper* create(JS::GlobalObject&, HTML::HTMLSpanElement&);

    HTMLSpanElementWrapper(JS::GlobalObject&, HTML::HTMLSpanElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLSpanElementWrapper() override;

    HTML::HTMLSpanElement& impl() { return static_cast<HTML::HTMLSpanElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLSpanElement const& impl() const { return static_cast<HTML::HTMLSpanElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

