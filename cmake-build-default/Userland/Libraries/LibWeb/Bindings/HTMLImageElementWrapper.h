
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLImageElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLImageElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLImageElement, HTMLElementWrapper);
public:
    static HTMLImageElementWrapper* create(JS::GlobalObject&, HTML::HTMLImageElement&);

    HTMLImageElementWrapper(JS::GlobalObject&, HTML::HTMLImageElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLImageElementWrapper() override;

    HTML::HTMLImageElement& impl() { return static_cast<HTML::HTMLImageElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLImageElement const& impl() const { return static_cast<HTML::HTMLImageElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

