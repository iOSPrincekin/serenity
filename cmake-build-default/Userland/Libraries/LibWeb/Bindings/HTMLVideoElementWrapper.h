
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLVideoElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLMediaElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLMediaElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLMediaElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLMediaElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLMediaElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLVideoElementWrapper : public HTMLMediaElementWrapper {
    JS_OBJECT(HTMLVideoElement, HTMLMediaElementWrapper);
public:
    static HTMLVideoElementWrapper* create(JS::GlobalObject&, HTML::HTMLVideoElement&);

    HTMLVideoElementWrapper(JS::GlobalObject&, HTML::HTMLVideoElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLVideoElementWrapper() override;

    HTML::HTMLVideoElement& impl() { return static_cast<HTML::HTMLVideoElement&>(HTMLMediaElementWrapper::impl()); }
    HTML::HTMLVideoElement const& impl() const { return static_cast<HTML::HTMLVideoElement const&>(HTMLMediaElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

