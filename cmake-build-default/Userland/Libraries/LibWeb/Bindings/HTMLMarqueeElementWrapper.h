
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLMarqueeElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLMarqueeElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLMarqueeElement, HTMLElementWrapper);
public:
    static HTMLMarqueeElementWrapper* create(JS::GlobalObject&, HTML::HTMLMarqueeElement&);

    HTMLMarqueeElementWrapper(JS::GlobalObject&, HTML::HTMLMarqueeElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMarqueeElementWrapper() override;

    HTML::HTMLMarqueeElement& impl() { return static_cast<HTML::HTMLMarqueeElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLMarqueeElement const& impl() const { return static_cast<HTML::HTMLMarqueeElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

