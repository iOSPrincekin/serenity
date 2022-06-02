
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLTableCellElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLTableCellElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLTableCellElement, HTMLElementWrapper);
public:
    static HTMLTableCellElementWrapper* create(JS::GlobalObject&, HTML::HTMLTableCellElement&);

    HTMLTableCellElementWrapper(JS::GlobalObject&, HTML::HTMLTableCellElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTableCellElementWrapper() override;

    HTML::HTMLTableCellElement& impl() { return static_cast<HTML::HTMLTableCellElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLTableCellElement const& impl() const { return static_cast<HTML::HTMLTableCellElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

