
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/EventTargetWrapper.h>)
#   include <LibWeb/Bindings/EventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/EventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/EventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class XMLHttpRequestEventTargetWrapper : public EventTargetWrapper {
    JS_OBJECT(XMLHttpRequestEventTarget, EventTargetWrapper);
public:
    static XMLHttpRequestEventTargetWrapper* create(JS::GlobalObject&, XHR::XMLHttpRequestEventTarget&);

    XMLHttpRequestEventTargetWrapper(JS::GlobalObject&, XHR::XMLHttpRequestEventTarget&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~XMLHttpRequestEventTargetWrapper() override;

    XHR::XMLHttpRequestEventTarget& impl() { return static_cast<XHR::XMLHttpRequestEventTarget&>(EventTargetWrapper::impl()); }
    XHR::XMLHttpRequestEventTarget const& impl() const { return static_cast<XHR::XMLHttpRequestEventTarget const&>(EventTargetWrapper::impl()); }

private:

};

XMLHttpRequestEventTargetWrapper* wrap(JS::GlobalObject&, XHR::XMLHttpRequestEventTarget&);

} // namespace Web::Bindings

