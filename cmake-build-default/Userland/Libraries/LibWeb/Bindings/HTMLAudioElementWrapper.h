
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLAudioElement.h>

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

class HTMLAudioElementWrapper : public HTMLMediaElementWrapper {
    JS_OBJECT(HTMLAudioElement, HTMLMediaElementWrapper);
public:
    static HTMLAudioElementWrapper* create(JS::GlobalObject&, HTML::HTMLAudioElement&);

    HTMLAudioElementWrapper(JS::GlobalObject&, HTML::HTMLAudioElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLAudioElementWrapper() override;

    HTML::HTMLAudioElement& impl() { return static_cast<HTML::HTMLAudioElement&>(HTMLMediaElementWrapper::impl()); }
    HTML::HTMLAudioElement const& impl() const { return static_cast<HTML::HTMLAudioElement const&>(HTMLMediaElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

