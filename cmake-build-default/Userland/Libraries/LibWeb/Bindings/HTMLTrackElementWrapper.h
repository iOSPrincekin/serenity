
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLTrackElement.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLTrackElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLTrackElement, HTMLElementWrapper);
public:
    static HTMLTrackElementWrapper* create(JS::GlobalObject&, HTML::HTMLTrackElement&);

    HTMLTrackElementWrapper(JS::GlobalObject&, HTML::HTMLTrackElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLTrackElementWrapper() override;

    HTML::HTMLTrackElement& impl() { return static_cast<HTML::HTMLTrackElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLTrackElement const& impl() const { return static_cast<HTML::HTMLTrackElement const&>(HTMLElementWrapper::impl()); }

private:

};

} // namespace Web::Bindings

