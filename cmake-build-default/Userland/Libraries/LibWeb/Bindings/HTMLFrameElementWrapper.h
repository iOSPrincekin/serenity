
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLFrameElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLFrameElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLFrameElement, HTMLElementWrapper);
public:
    static HTMLFrameElementWrapper* create(JS::GlobalObject&, HTML::HTMLFrameElement&);

    HTMLFrameElementWrapper(JS::GlobalObject&, HTML::HTMLFrameElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFrameElementWrapper() override;

    HTML::HTMLFrameElement& impl() { return static_cast<HTML::HTMLFrameElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLFrameElement const& impl() const { return static_cast<HTML::HTMLFrameElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

