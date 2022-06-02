
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLPictureElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLPictureElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLPictureElement, HTMLElementWrapper);
public:
    static HTMLPictureElementWrapper* create(JS::GlobalObject&, HTML::HTMLPictureElement&);

    HTMLPictureElementWrapper(JS::GlobalObject&, HTML::HTMLPictureElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLPictureElementWrapper() override;

    HTML::HTMLPictureElement& impl() { return static_cast<HTML::HTMLPictureElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLPictureElement const& impl() const { return static_cast<HTML::HTMLPictureElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

