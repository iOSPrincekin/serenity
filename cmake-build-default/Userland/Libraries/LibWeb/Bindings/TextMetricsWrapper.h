
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/TextMetrics.h>

namespace Web::Bindings {

class TextMetricsWrapper : public Wrapper {
    JS_OBJECT(TextMetrics, Wrapper);
public:
    static TextMetricsWrapper* create(JS::GlobalObject&, HTML::TextMetrics&);

    TextMetricsWrapper(JS::GlobalObject&, HTML::TextMetrics&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TextMetricsWrapper() override;

    HTML::TextMetrics& impl() { return *m_impl; }
    HTML::TextMetrics const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::TextMetrics> m_impl;
        
};

TextMetricsWrapper* wrap(JS::GlobalObject&, HTML::TextMetrics&);

} // namespace Web::Bindings

