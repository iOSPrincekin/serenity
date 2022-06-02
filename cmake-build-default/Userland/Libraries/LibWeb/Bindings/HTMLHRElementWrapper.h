
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLHRElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLHRElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLHRElement, HTMLElementWrapper);
public:
    static HTMLHRElementWrapper* create(JS::GlobalObject&, HTML::HTMLHRElement&);

    HTMLHRElementWrapper(JS::GlobalObject&, HTML::HTMLHRElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLHRElementWrapper() override;

    HTML::HTMLHRElement& impl() { return static_cast<HTML::HTMLHRElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLHRElement const& impl() const { return static_cast<HTML::HTMLHRElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

