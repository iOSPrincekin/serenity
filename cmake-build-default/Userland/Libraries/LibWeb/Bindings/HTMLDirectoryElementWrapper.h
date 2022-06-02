
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLDirectoryElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLDirectoryElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLDirectoryElement, HTMLElementWrapper);
public:
    static HTMLDirectoryElementWrapper* create(JS::GlobalObject&, HTML::HTMLDirectoryElement&);

    HTMLDirectoryElementWrapper(JS::GlobalObject&, HTML::HTMLDirectoryElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLDirectoryElementWrapper() override;

    HTML::HTMLDirectoryElement& impl() { return static_cast<HTML::HTMLDirectoryElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLDirectoryElement const& impl() const { return static_cast<HTML::HTMLDirectoryElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

