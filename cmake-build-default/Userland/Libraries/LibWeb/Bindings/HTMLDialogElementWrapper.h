
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLDialogElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLDialogElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLDialogElement, HTMLElementWrapper);
public:
    static HTMLDialogElementWrapper* create(JS::GlobalObject&, HTML::HTMLDialogElement&);

    HTMLDialogElementWrapper(JS::GlobalObject&, HTML::HTMLDialogElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDialogElementWrapper() override;

    HTML::HTMLDialogElement& impl() { return static_cast<HTML::HTMLDialogElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLDialogElement const& impl() const { return static_cast<HTML::HTMLDialogElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

