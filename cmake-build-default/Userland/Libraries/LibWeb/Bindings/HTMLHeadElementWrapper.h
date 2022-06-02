
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLHeadElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLHeadElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLHeadElement, HTMLElementWrapper);
public:
    static HTMLHeadElementWrapper* create(JS::GlobalObject&, HTML::HTMLHeadElement&);

    HTMLHeadElementWrapper(JS::GlobalObject&, HTML::HTMLHeadElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLHeadElementWrapper() override;

    HTML::HTMLHeadElement& impl() { return static_cast<HTML::HTMLHeadElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLHeadElement const& impl() const { return static_cast<HTML::HTMLHeadElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

