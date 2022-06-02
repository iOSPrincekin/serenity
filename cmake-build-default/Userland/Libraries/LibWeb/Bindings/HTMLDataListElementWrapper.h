
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLDataListElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLDataListElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLDataListElement, HTMLElementWrapper);
public:
    static HTMLDataListElementWrapper* create(JS::GlobalObject&, HTML::HTMLDataListElement&);

    HTMLDataListElementWrapper(JS::GlobalObject&, HTML::HTMLDataListElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDataListElementWrapper() override;

    HTML::HTMLDataListElement& impl() { return static_cast<HTML::HTMLDataListElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLDataListElement const& impl() const { return static_cast<HTML::HTMLDataListElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

