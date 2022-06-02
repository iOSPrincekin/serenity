
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLBRElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLBRElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLBRElement, HTMLElementWrapper);
public:
    static HTMLBRElementWrapper* create(JS::GlobalObject&, HTML::HTMLBRElement&);

    HTMLBRElementWrapper(JS::GlobalObject&, HTML::HTMLBRElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLBRElementWrapper() override;

    HTML::HTMLBRElement& impl() { return static_cast<HTML::HTMLBRElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLBRElement const& impl() const { return static_cast<HTML::HTMLBRElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

