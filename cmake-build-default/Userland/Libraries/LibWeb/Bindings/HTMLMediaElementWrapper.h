
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/HTMLElement.h>

#include <LibWeb/HTML/HTMLMediaElement.h>

#include <LibWeb/HTML/DOMStringMap.h>

#if __has_include(<LibWeb/Bindings/HTMLElementWrapper.h>)
#   include <LibWeb/Bindings/HTMLElementWrapper.h>
#endif
#if __has_include(<LibWeb/Bindings/HTMLElementWrapperFactory.h>)
#   include <LibWeb/Bindings/HTMLElementWrapperFactory.h>
#endif

namespace Web::Bindings {

class HTMLMediaElementWrapper : public HTMLElementWrapper {
    JS_OBJECT(HTMLMediaElement, HTMLElementWrapper);
public:
    static HTMLMediaElementWrapper* create(JS::GlobalObject&, HTML::HTMLMediaElement&);

    HTMLMediaElementWrapper(JS::GlobalObject&, HTML::HTMLMediaElement&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLMediaElementWrapper() override;

    HTML::HTMLMediaElement& impl() { return static_cast<HTML::HTMLMediaElement&>(HTMLElementWrapper::impl()); }
    HTML::HTMLMediaElement const& impl() const { return static_cast<HTML::HTMLMediaElement const&>(HTMLElementWrapper::impl()); }

private:

};

enum class CanPlayTypeResult {

    Empty,

    Maybe,

    Probably,

};
inline String idl_enum_to_string(CanPlayTypeResult value) {
    switch(value) {

    case CanPlayTypeResult::Empty: return "";

    case CanPlayTypeResult::Maybe: return "maybe";

    case CanPlayTypeResult::Probably: return "probably";

    default: return "<unknown>";
    };
}

} // namespace Web::Bindings

