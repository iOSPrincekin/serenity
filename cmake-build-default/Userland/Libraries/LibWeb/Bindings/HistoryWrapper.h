
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/History.h>

namespace Web::Bindings {

class HistoryWrapper : public Wrapper {
    JS_OBJECT(History, Wrapper);
public:
    static HistoryWrapper* create(JS::GlobalObject&, HTML::History&);

    HistoryWrapper(JS::GlobalObject&, HTML::History&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HistoryWrapper() override;

    HTML::History& impl() { return *m_impl; }
    HTML::History const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::History> m_impl;
        
};

HistoryWrapper* wrap(JS::GlobalObject&, HTML::History&);

} // namespace Web::Bindings

