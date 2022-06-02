
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/EventTarget.h>

#include <LibWeb/DOM/AbortController.h>

#include <LibWeb/DOM/AbortSignal.h>

namespace Web::Bindings {

class AbortControllerWrapper : public Wrapper {
    JS_OBJECT(AbortController, Wrapper);
public:
    static AbortControllerWrapper* create(JS::GlobalObject&, DOM::AbortController&);

    AbortControllerWrapper(JS::GlobalObject&, DOM::AbortController&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~AbortControllerWrapper() override;

    DOM::AbortController& impl() { return *m_impl; }
    DOM::AbortController const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<DOM::AbortController> m_impl;
        
};

AbortControllerWrapper* wrap(JS::GlobalObject&, DOM::AbortController&);

} // namespace Web::Bindings

