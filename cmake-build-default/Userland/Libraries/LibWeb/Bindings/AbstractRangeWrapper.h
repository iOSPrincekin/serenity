
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/DOM/AbstractRange.h>

namespace Web::Bindings {

class AbstractRangeWrapper : public Wrapper {
    JS_OBJECT(AbstractRange, Wrapper);
public:
    static AbstractRangeWrapper* create(JS::GlobalObject&, DOM::AbstractRange&);

    AbstractRangeWrapper(JS::GlobalObject&, DOM::AbstractRange&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~AbstractRangeWrapper() override;

    DOM::AbstractRange& impl() { return *m_impl; }
    DOM::AbstractRange const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<DOM::AbstractRange> m_impl;
        
};

AbstractRangeWrapper* wrap(JS::GlobalObject&, DOM::AbstractRange&);

} // namespace Web::Bindings

