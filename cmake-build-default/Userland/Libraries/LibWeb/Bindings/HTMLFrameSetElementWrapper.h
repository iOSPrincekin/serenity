
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLFrameSetElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLFrameSetElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLFrameSetElement, HTMLElementWrapper);
public:
    static HTMLFrameSetElementWrapper* create(JS::GlobalObject&, HTML::HTMLFrameSetElement&);

    HTMLFrameSetElementWrapper(JS::GlobalObject&, HTML::HTMLFrameSetElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFrameSetElementWrapper() override;

    HTML::HTMLFrameSetElement& impl() { return static_cast<HTML::HTMLFrameSetElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLFrameSetElement const& impl() const { return static_cast<HTML::HTMLFrameSetElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

