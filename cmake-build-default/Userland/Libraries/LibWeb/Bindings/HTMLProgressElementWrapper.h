
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLProgressElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLProgressElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLProgressElement, HTMLElementWrapper);
public:
    static HTMLProgressElementWrapper* create(JS::GlobalObject&, HTML::HTMLProgressElement&);

    HTMLProgressElementWrapper(JS::GlobalObject&, HTML::HTMLProgressElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLProgressElementWrapper() override;

    HTML::HTMLProgressElement& impl() { return static_cast<HTML::HTMLProgressElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLProgressElement const& impl() const { return static_cast<HTML::HTMLProgressElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

