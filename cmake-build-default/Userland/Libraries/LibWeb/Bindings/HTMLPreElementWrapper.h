
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLPreElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLPreElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLPreElement, HTMLElementWrapper);
public:
    static HTMLPreElementWrapper* create(JS::GlobalObject&, HTML::HTMLPreElement&);

    HTMLPreElementWrapper(JS::GlobalObject&, HTML::HTMLPreElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLPreElementWrapper() override;

    HTML::HTMLPreElement& impl() { return static_cast<HTML::HTMLPreElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLPreElement const& impl() const { return static_cast<HTML::HTMLPreElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

