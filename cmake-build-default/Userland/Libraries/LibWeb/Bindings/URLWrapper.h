
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/URL/URLSearchParams.h>

#include <LibWeb/URL/URL.h>

namespace Web::Bindings {

class URLWrapper : public Wrapper {
    JS_OBJECT(URL, Wrapper);
public:
    static URLWrapper* create(JS::GlobalObject&, URL::URL&);

    URLWrapper(JS::GlobalObject&, URL::URL&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~URLWrapper() override;

    URL::URL& impl() { return *m_impl; }
    URL::URL const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<URL::URL> m_impl;
        
};

URLWrapper* wrap(JS::GlobalObject&, URL::URL&);

} // namespace Web::Bindings

