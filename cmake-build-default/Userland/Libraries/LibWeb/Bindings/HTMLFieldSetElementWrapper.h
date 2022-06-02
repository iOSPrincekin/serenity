
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLFieldSetElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLFieldSetElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLFieldSetElement, HTMLElementWrapper);
public:
    static HTMLFieldSetElementWrapper* create(JS::GlobalObject&, HTML::HTMLFieldSetElement&);

    HTMLFieldSetElementWrapper(JS::GlobalObject&, HTML::HTMLFieldSetElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLFieldSetElementWrapper() override;

    HTML::HTMLFieldSetElement& impl() { return static_cast<HTML::HTMLFieldSetElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLFieldSetElement const& impl() const { return static_cast<HTML::HTMLFieldSetElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

