
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLSlotElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLSlotElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLSlotElement, HTMLElementWrapper);
public:
    static HTMLSlotElementWrapper* create(JS::GlobalObject&, HTML::HTMLSlotElement&);

    HTMLSlotElementWrapper(JS::GlobalObject&, HTML::HTMLSlotElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLSlotElementWrapper() override;

    HTML::HTMLSlotElement& impl() { return static_cast<HTML::HTMLSlotElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLSlotElement const& impl() const { return static_cast<HTML::HTMLSlotElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

