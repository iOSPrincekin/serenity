
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#include <LibWeb/HTML/HTMLMapElement.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLMapElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLMapElement, HTMLElementWrapper);
public:
    static HTMLMapElementWrapper* create(JS::GlobalObject&, HTML::HTMLMapElement&);

    HTMLMapElementWrapper(JS::GlobalObject&, HTML::HTMLMapElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMapElementWrapper() override;

    HTML::HTMLMapElement& impl() { return static_cast<HTML::HTMLMapElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLMapElement const& impl() const { return static_cast<HTML::HTMLMapElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

