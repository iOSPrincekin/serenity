
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/URL/URLSearchParams.h>

namespace Web::Bindings {

class URLSearchParamsWrapper : public Wrapper {
    JS_OBJECT(URLSearchParams, Wrapper);
public:
    static URLSearchParamsWrapper* create(JS::GlobalObject&, URL::URLSearchParams&);

    URLSearchParamsWrapper(JS::GlobalObject&, URL::URLSearchParams&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~URLSearchParamsWrapper() override;

    URL::URLSearchParams& impl() { return *m_impl; }
    URL::URLSearchParams const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<URL::URLSearchParams> m_impl;
        
};

URLSearchParamsWrapper* wrap(JS::GlobalObject&, URL::URLSearchParams&);

} // namespace Web::Bindings

