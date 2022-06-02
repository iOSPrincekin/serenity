
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/XHR/XMLHttpRequest.h>

#include <LibWeb/XHR/XMLHttpRequestEventTarget.h>

#include <LibWeb/DOM/AbortSignal.h>

#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>)
#   include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/XMLHttpRequestEventTargetWrapperFactory.h>)
#   include <LibWeb/Bindings/XMLHttpRequestEventTargetWrapperFactory.h>
#endif

namespace Web::Bindings {

class XMLHttpRequestWrapper : public XMLHttpRequestEventTargetWrapper {
    JS_OBJECT(XMLHttpRequest, XMLHttpRequestEventTargetWrapper);
public:
    static XMLHttpRequestWrapper* create(JS::GlobalObject&, XHR::XMLHttpRequest&);

    XMLHttpRequestWrapper(JS::GlobalObject&, XHR::XMLHttpRequest&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~XMLHttpRequestWrapper() override;

    XHR::XMLHttpRequest& impl() { return static_cast<XHR::XMLHttpRequest&>(XMLHttpRequestEventTargetWrapper::impl()); }
    XHR::XMLHttpRequest const& impl() const { return static_cast<XHR::XMLHttpRequest const&>(XMLHttpRequestEventTargetWrapper::impl()); }

private:

};

enum class XMLHttpRequestResponseType {

    Empty,

    Blob,

    Document,

    Json,

    Text,

    Arraybuffer,

};
inline String idl_enum_to_string(XMLHttpRequestResponseType value) {
    switch(value) {

    case XMLHttpRequestResponseType::Empty: return "";

    case XMLHttpRequestResponseType::Blob: return "blob";

    case XMLHttpRequestResponseType::Document: return "document";

    case XMLHttpRequestResponseType::Json: return "json";

    case XMLHttpRequestResponseType::Text: return "text";

    case XMLHttpRequestResponseType::Arraybuffer: return "arraybuffer";

    default: return "<unknown>";
    };
}

XMLHttpRequestWrapper* wrap(JS::GlobalObject&, XHR::XMLHttpRequest&);

} // namespace Web::Bindings

