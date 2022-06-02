
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/DOMException.h>

namespace Web::Bindings {

class DOMExceptionWrapper : public Wrapper {
    JS_OBJECT(DOMException, Wrapper);
public:
    static DOMExceptionWrapper* create(JS::GlobalObject&, DOM::DOMException&);

    DOMExceptionWrapper(JS::GlobalObject&, DOM::DOMException&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMExceptionWrapper() override;

    DOM::DOMException& impl() { return *m_impl; }
    DOM::DOMException const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<DOM::DOMException> m_impl;
        
};

DOMExceptionWrapper* wrap(JS::GlobalObject&, DOM::DOMException&);

} // namespace Web::Bindings

